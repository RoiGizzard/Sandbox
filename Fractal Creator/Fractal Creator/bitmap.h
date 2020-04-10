#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

class Bitmap 
{
public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(std::string filename);

private:
	int m_width{0};
	int m_height{0};
	std::unique_ptr<uint8_t[]> m_pixels{nullptr};
};

#endif // BITMAP_H 
