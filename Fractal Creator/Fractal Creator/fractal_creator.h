#ifndef FRACTAL_CREATOR_H
#define FRACTAL_CREATOR_H

#include <string>
#include <vector>

#include "bitmap.h"
#include "zoom.h"
#include "zoom_list.h"
#include "rgb.h"

class FractalCreator
{
public:
	FractalCreator(int width, int height);
	void generate(const std::string& filename);
	void addZoom(const Zoom& zoom);
	void addRange(double rangeEnd, const RGB& rgb, bool needInitialization = false);

private:
	void calculateIteration();
	void calculateTotalIteration();
	void calculateRangeTotals();
	void drawFractal();
	void writeBitmap(const std::string& filename);
	int getRange(int iterations) const;

	int m_total { 0 };
	int m_width;
	int m_height;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	std::vector<int>  m_ranges;
	std::vector<RGB> m_colors;
	std::vector<int> m_rangeTotals;
};

#endif // FRACTAL_CREATOR_H