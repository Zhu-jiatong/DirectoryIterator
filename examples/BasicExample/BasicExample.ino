#include "src/DirectoryIterator.h"
#include <SD.h>

void setup()
{
	try
	{
		Serial.begin(115200);
		if (!SD.begin())
			throw std::runtime_error("Cannot mount SD");

		Serial.println("Range for loop test:");
		for (auto &file : DirectoryIterator(SD.open("/Legacy")))
			Serial.println(file.path());

		Serial.println("Iterator loop test:");
		DirectoryIterator it(SD.open("/Legacy"));
		for (auto i = it.begin(); i != it.end(); ++i)
			Serial.println(i->path());
	}
	catch (const std::exception &e)
	{
		Serial.println(e.what());
	}
}

void loop() {}