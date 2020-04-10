#ifndef RGB_H
#define RGB_H

struct RGB
{
	double r;
	double g;
	double b;

	friend RGB operator-(const RGB& first, const RGB& second)
	{
		return RGB{ first.r - second.r, first.g - second.g, first.b - second.r };
	}
};

#endif // RGB_H
