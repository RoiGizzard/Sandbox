#ifndef MANDELBROT_H
#define MANDELBROT_H

class Mandelbrot
{
public:
	static int getIterations(double x, double y);

	static const int MAX_ITERATIONS = 10000;
};

#endif // MANDELBROT_H
