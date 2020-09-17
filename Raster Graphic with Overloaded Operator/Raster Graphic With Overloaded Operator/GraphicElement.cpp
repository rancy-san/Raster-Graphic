#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Image.h"
#include "GraphicElement.h"

/******************
Function name: operator+
Purpose: Add together the GraphicElements
Function In parameters: the GraphicElement&
Function Out parameters: a copy of the GraphicElement
Version: 1.00
******************/
GraphicElement GraphicElement::operator+(GraphicElement& GE) {
	vector<Image> newImg;
	vector<Image>::iterator i = Images.begin();
	int j = 0;

	while (i != Images.end()) {
		newImg.push_back(Image(Images.at(j++)));
		i++;
	}

	i = GE.Images.begin();
	j = 0;

	while (i != GE.Images.end()) {
		newImg.push_back(Image(GE.Images.at(j++)));
		i++;
	}

	GraphicElement newGE(fileName + "_" + GE.fileName, newImg);
	return newGE;
}

/******************
Function name: operator<<
Purpose: Append messages to the ostream by iterating through the list of GraphicElement
Function In parameters: ostream for appending strings and arguments to one 'cout'
						GraphicElement, to directly get data from the original GraphicElement
Function Out parameters: ostream
Version: 1.00
******************/
ostream& operator<<(ostream& o, GraphicElement& GE) {
	int j = 0;
	vector<Image>::iterator i = GE.Images.begin();

	o << "\tfileName = " << GE.fileName << endl;
	
	while (i != GE.Images.end()) {
		o << "\tImage #" << j++ << ":" << *i << endl;
		i++;
	}

	return o;
}