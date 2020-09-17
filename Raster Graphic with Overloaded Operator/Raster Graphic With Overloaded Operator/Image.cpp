#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

#include "Image.h"

/******************
Constructor name: Image
Purpose: Constructor initializes the coordinates, duration, and name of the image
Function In parameters: int, int, int for coordinates and duration of the images,
						char* name to pass in a series of characters
Function Out parameters: None
Version: 1.00
******************/
Image::Image(int x, int y, int duration, char* name) {
	this->pixel_x = x;
	this->pixel_y = y;
	this->duration = duration;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

/******************
Constructor name: Image
Purpose: Constructor passing in an image's already defined coordinate, duration,
		and name
Function In parameters: Image& to directly get the Image's attributes
Function Out parameters: None
Version: 1.00
******************/
Image::Image(const Image& image) {
	this->pixel_x = image.pixel_x;
	this->pixel_y = image.pixel_y;
	this->duration = image.duration;
	this->name = new char[strlen(image.name) + 1];
	strcpy_s(this->name, (strlen(image.name) + 1), image.name);
}

/******************
Function name: operator<<
Purpose: Append strings and arguments to the ostream so that it may be fully displayed later
Function In parameters: ostream, Image
Function Out parameters: None
Version: 1.00
******************/
ostream& operator<<(ostream& o, Image& image) {
	int duration = image.duration;

	o << "\tname = " << image.name << "; ";
	o << "pixel_x = " << image.pixel_x << "; ";
	o << "pixel_y = " << image.pixel_y << "; ";
	o << "duration = " << duration << ";" << endl;

	o << "\tCounting the seconds for this Image: ";
	for (int i = 1; i <= duration; i++) {
		o << i << ", ";
	}

	o << endl;

	return o;
}

/******************
Function name: Image
Purpose: Destructor for the allocation of the name
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
Image::~Image() {
	delete[] name;
}