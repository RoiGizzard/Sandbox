#include "fractal_creator.h"

#include <cassert>

#include "mandelbrot.h"

FractalCreator::FractalCreator(int width, int height)
	: m_width(width)
	, m_height(height)
	, m_bitmap(width, height)
	, m_zoomList(width, height)
	, m_histogram(new int[Mandelbrot::MAX_ITERATIONS]{})
	, m_fractal(new int[width * height]{})
{
	addZoom(Zoom{ m_width / 2, m_height / 2, 4.0 / m_width });
	addRange(0.0, RGB{ 0, 0, 0 }, true);
}

void FractalCreator::generate(const std::string& filename)
{	
	calculateIteration();
	calculateTotalIteration();
	calculateRangeTotals();
	drawFractal();
	writeBitmap(filename);
}

void FractalCreator::calculateIteration()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			auto coords = m_zoomList.apply(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			m_fractal[y * m_width + x] = iterations;

			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				m_histogram[iterations]++;
			}
		}
	}
}

void FractalCreator::calculateTotalIteration()
{
	m_total = 0;
	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		m_total += m_histogram[i];
	}
}

void FractalCreator::calculateRangeTotals()
{
	int rangeIndex = 0;

	for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++)
	{
		int pixels = m_histogram[i];

		if (i >= m_ranges[rangeIndex + 1])
		{
			rangeIndex++;
		}

		m_rangeTotals[rangeIndex] += pixels;
	}
}

void FractalCreator::drawFractal()
{
	for (int y = 0; y < m_height; y++)
	{
		for (int x = 0; x < m_width; x++)
		{
			int iterations = m_fractal[y * m_width + x];

			int range = getRange(iterations);
			int rangeTotal = m_rangeTotals[range];
			int rangeStart = m_ranges[range];

			auto startColor = m_colors[range];
			auto endColor = m_colors[range + 1];
			auto colorDiff = endColor - startColor;

			uint8_t red = 0;
			uint8_t green = 0;
			uint8_t blue = 0;

			if (iterations != Mandelbrot::MAX_ITERATIONS)
			{
				int totalPixels = 0;
				for (int i = rangeStart; i <= iterations; i++)
				{
					totalPixels += m_histogram[i];
				}
				red = (uint8_t)(startColor.r + colorDiff.r * (double)totalPixels / rangeTotal);
				green = (uint8_t)(startColor.g + colorDiff.g * (double)totalPixels / rangeTotal);
				blue = (uint8_t)(startColor.b + colorDiff.b * (double)totalPixels / rangeTotal);
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::addZoom(const Zoom& zoom)
{
	m_zoomList.add(zoom);
}

void FractalCreator::addRange(double rangeEnd, const RGB& rgb, bool needInitialization)
{
	m_ranges.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
	m_colors.push_back(rgb);
	
	if (needInitialization)
	{
		m_rangeTotals.push_back(0);
	}

	for (int value : m_rangeTotals)
	{

	}
}

void FractalCreator::writeBitmap(const std::string& filename)
{
	m_bitmap.write(filename);
}

int FractalCreator::getRange(int iterations) const
{
	int range = 0;

	for (int i = 1; i < m_ranges.size(); i++)
	{
		range = i;

		if (m_ranges[i] > iterations)
		{
			break;
		}
	}

	range--;

	assert(range > -1);
	assert(range < m_ranges.size());

	return range;
}