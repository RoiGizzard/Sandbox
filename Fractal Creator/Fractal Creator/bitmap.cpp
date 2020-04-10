#include <fstream>

#include "bitmap.h"
#include "bitmap_info_header.h"
#include "bitmap_file_header.h"

Bitmap::Bitmap(int width, int height) 
	: m_width(width)
	, m_height(height)
	, m_pixels(new uint8_t[width * height * 3]{}) 
{}

bool Bitmap::write(std::string filename) {

	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);

	if (!file) 
	{
		return false;
	}

	file.write((char *) &fileHeader, sizeof(fileHeader));
	file.write((char *) &infoHeader, sizeof(infoHeader));
	file.write((char *) m_pixels.get(), m_width * m_height * 3);

	file.close();

	if (!file) 
	{
		return false;
	}

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) 
{
	uint8_t *pixel = m_pixels.get();

	pixel += (y * 3) * m_width + (x * 3);

	pixel[0] = blue;
	pixel[1] = green;
	pixel[2] = red;
}
