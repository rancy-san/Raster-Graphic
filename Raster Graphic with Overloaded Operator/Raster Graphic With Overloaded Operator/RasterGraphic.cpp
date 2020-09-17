#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <vector>
#include <forward_list>

using namespace std;

#include "Image.h"
#include "GraphicElement.h"
#include "RasterGraphic.h"

/******************
Function name: InsertGraphicElement
Purpose: InsertGraphicElement using a forward_list
		 Insert at the 'end' of the list if the length of the list is less than 2.
		 Otherwise insert at an index.
		 Iterate the GraphicElement using an iterator until the position is attained.
		 Insert.
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
void RasterGraphic::InsertGraphicElement() {

	char* fileName;
	string tempFileName;
	int numOfImages;
	int x;
	int y;
	int duration;
	char *imgName;
	string tempImgName;
	int pos;
	int listLength = distance(GraphicElements.begin(), GraphicElements.end());

	vector<Image> img;
	forward_list<GraphicElement>::iterator i;

	cout << "Insert a GraphicElement in the RasterGraphic" << endl;
	cout << "Please enter the GraphicElement filename: ";
	cin >> tempFileName;
	cout << endl;
	fileName = new char[tempFileName.length() + 1];
	strcpy(fileName, tempFileName.c_str());

	cout << "Entering the GraphicElement Images (the sets of dimensions and durations)" << endl;
	cout << "Please enter the number of Images: ";
	cin >> numOfImages;
	cout << endl;

	for (int i = 0; i < numOfImages; i++) {
		cout << "Please enter pixel x for Image #" << i << " pixel_x: ";
		cin >> x;
		cout << endl;
		cout << "Please enter pixel y for Image #" << i << " pixel_y: ";
		cin >> y;
		cout << endl;
		cout << "Please enter the duration sec for this Image: ";
		cin >> duration;
		cout << endl;
		cout << "Please enter the name for this Image: ";
		cin >> tempImgName;
		imgName = new char[tempImgName.length() + 1];
		strcpy(imgName, tempImgName.c_str());

		img.push_back(Image(x, y, duration, imgName));
	}
	
	if (GraphicElements.empty()) {
		cout << "This is the first GraphicElement in the list" << endl;
		GraphicElements.push_front(GraphicElement(tempFileName, img));
	} else if (listLength > 1) {
		cout << "There are " << listLength << " GraphicElement(s) in the list" << endl;
		cout << "Please specify the position, between 0 and " << (listLength - 1) << "  to insert after: ";
		cin >> pos;
		cout << endl;
		i = GraphicElements.begin();
		while (pos--) {
			i++;
		}
		GraphicElements.insert_after(i, GraphicElement(tempFileName, img));
	}
	else {
		GraphicElements.push_front(GraphicElement(tempFileName, img));
		GraphicElements.reverse();
	}

	delete[] fileName;
	delete[] imgName;
	return;
}

/******************
Function name: DeleteGraphicElement
Purpose: Delete first graphic element using pop_front()
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
void RasterGraphic::DeleteGraphicElement() {
	if (GraphicElements.empty())
		cout << "Empty GraphicElement." << endl;
	else
		GraphicElements.pop_front();
}

/******************
Function name: operator[]
Purpose: return length of list using an iterator
Function In parameters: unsigned int n
Function Out parameters: pointer to iterator
Version: 1.00
******************/
GraphicElement& RasterGraphic::operator[](unsigned int n) {
	forward_list<GraphicElement>::iterator i = GraphicElements.begin();
	int j = 0;

	while (i != GraphicElements.end()) {
		if (n == j++)
			break;
		i++;
	}

	return *i;
}

/******************
Function name: operator+=
Purpose: Add images to the front of the GraphicElement
Function In parameters: GraphicElement& GE
Function Out parameters: None
Version: 1.00
******************/
void RasterGraphic::operator+=(GraphicElement& GE) {
	GraphicElement GraphicElement(GE);
	GraphicElements.push_front(GraphicElement);
	cout << endl;
}

/******************
Function name: operator<<
Purpose: Display the RasterGraphic name, and append messages to the ostream
Function In parameters: ostream, RasterGraphic
Function Out parameters: ostream
Version: 1.00
******************/
ostream& operator<<(ostream& o, RasterGraphic& RG) {
	if (RG.GraphicElements.empty())
		cout << "Empty GraphicElements" << endl;
	else {
		forward_list<GraphicElement>::iterator i;
		int j = 0;
		i = RG.GraphicElements.begin();
		cout << "RasterGraphic " << RG.name << endl;
		cout << "Run the RasterGraphic" << endl;

		while (i != RG.GraphicElements.end()) {
			o << "Image #" << j++ << ": " << endl << *i;
			i++;
		}
	}
	return o;
}