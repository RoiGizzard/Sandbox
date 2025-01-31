#ifndef BITMAP_FILE_HEADER_H
#define BITMAP_FILE_HEADER_H

#include <cstdint>

#pragma pack(2)

struct BitmapFileHeader 
{
	char header[2] { 'B', 'M' };
	int32_t fileSize;
	int32_t reserved { 0 };
	int32_t dataOffset;
};

#endif // BITMAP_FILE_HEADER_H
