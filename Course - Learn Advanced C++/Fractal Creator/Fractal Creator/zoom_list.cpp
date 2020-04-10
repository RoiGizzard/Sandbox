#include "zoom_list.h"

ZoomList::ZoomList(int width, int height)
	: m_width(width)
	, m_height(height)
{
}

void ZoomList::add(const Zoom& zoom)
{
	m_zooms.push_back(zoom);

	m_xCenter += (zoom.x - m_width / 2) * m_scale;
	m_yCenter += -(zoom.y - m_height / 2) * m_scale;

	m_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::apply(int x, int y)
{
	double xFractal = (x - m_width / 2) * m_scale + m_xCenter;
	double yFractal = (y - m_height / 2) * m_scale + m_yCenter;
	return std::pair<double, double>(xFractal, yFractal);
}
