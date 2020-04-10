#include <cstdint>
#include <iostream>
#include <memory>
#include <limits>
#include <cmath>

#include "bitmap.h"
#include "mandelbrot.h"
#include "zoom_list.h"
#include "rgb.h"
#include "fractal_creator.h"

int main()
{
	FractalCreator fc(2560, 1440);

	fc.addZoom(Zoom{ 295, 202, 0.1 });
	fc.addZoom(Zoom{ 312, 304, 0.1 });

	fc.addRange(0.3, RGB{ 255, 0, 0 });
	fc.addRange(0.5, RGB{ 255, 255, 0 });
	fc.addRange(1.0, RGB{ 255, 255, 255 });

	fc.generate("test.bmp");

	std::cout << "Finished" << std::endl;
	return 0;
}
