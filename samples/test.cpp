#include <iostream>

#include "oled.h"
#include "bitmap.h"
#include "graphics.h"

#define OLED_ADDR	0x3C

int main(int argc, char **argv)
{
	Bitmap buffer = Bitmap(50, 50);
	buffer.setPixel(34, 34);
	Oled_128x64 oled("/dev/i2c-1", OLED_ADDR);
	oled.setPixel(34, 34);

	oled.displayUpdate();

	std::cout << "H: " << oled.height() << std::endl;
	std::cout << "W: " << oled.width() << std::endl;

	std::cout << (oled.isPixelSet(34, 34) ? "ja" : "nein") << std::endl;
	std::cout << (buffer.isPixelSet(34, 34) ? "ja" : "nein") << std::endl;

	oled.displayUpdate();
	getchar();
	drawCircle(Pixel(32, 32), 30, PixelStyle::Set, oled);
	drawCircle(Pixel(96, 32), 15, PixelStyle::Set, oled);
	oled.displayUpdate();

	getchar();
	oled.clear();
	oled.displayUpdate();

	std::string file	= "/var/tmp/src/libSSD1306/Pi-Debug/samples/bitSplash.bitmap";
	std::string file3	= "/var/tmp/src/libSSD1306/Pi-Debug/samples/bitSplash2.bitmap";

	Bitmap b(128, 64);
	b.load(file);
	b.save(file3, Bitmap::Format::Bit);
	oled.setBuffer(b, 0, 0);
	oled.displayUpdate();
	getchar();



	std::string file2 = "/var/tmp/src/libSSD1306/Pi-Debug/samples/byteSplash.bitmap";
	std::string file4 = "/var/tmp/src/libSSD1306/Pi-Debug/samples/byteSplash2.bitmap";

	Bitmap b2(10, 10);
	b2.load(file2);
	b2.save(file4, Bitmap::Format::Byte);
	oled.setBuffer(b2, 0, 0);

	drawCircle(Pixel(32, 32), 30, PixelStyle::Toggle, oled);
	drawCircle(Pixel(96, 32), 15, PixelStyle::Toggle, oled);
	
	
	oled.displayInverse();


	oled.displayUpdate();

	getchar();
	return 0;
}