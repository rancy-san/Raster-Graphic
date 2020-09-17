#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Image.h"
#include "SystemMemoryImage.h"
#include "GPUMemoryImage.h"
#include "GraphicElement.h"

/******************
Constructor name: GraphicElement
Purpose: Add together the GraphicElements
Function In parameters: the GraphicElement&
Function Out parameters: a copy of the GraphicElement
Version: 1.00
******************/
GraphicElement::GraphicElement(const GraphicElement& GE) {
	fileName = GE.fileName;
	vector<Image*>::const_iterator i = GE.Images.begin();
	vector<Image*>::const_iterator range = GE.Images.end();

	for (; i < range; i++) {
		if (SystemMemoryImage *SMI = dynamic_cast<SystemMemoryImage*>(*i))
			Images.push_back(new SystemMemoryImage(*SMI));
		else if (GPUMemoryImage *GMI = dynamic_cast<GPUMemoryImage*>(*i)) {
			//cout << "Images.push_back(new GPUMemoryImage(*GMI));";
			Images.push_back(new GPUMemoryImage(*GMI));
		}
	}
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
	vector<Image *>::iterator i = GE.Images.begin();
	vector<Image *>::iterator range = GE.Images.end();

	o << "\tfileName = " << GE.fileName << endl;
	
	while (i != range) {
		o << "\tImage # " << j++ << ":" << **i << endl;
		i++;
	}

	return o;
}