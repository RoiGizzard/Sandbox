#ifndef ZOOM_LIST_H
#define ZOOM_LIST_H

#include <vector>
#include <utility>

#include "zoom.h"

class ZoomList
{
public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double, double> apply(int x, int y);

private:
	double m_xCenter{ 0.0 };
	double m_yCenter{ 0.0 };
	double m_scale{ 1.0 };
	int m_width{ 0 };
	int m_height{ 0 };
	std::vector<Zoom> m_zooms;
};

#endif // ZOOM_LIST_H