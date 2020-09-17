/******************
File name: GraphicElement
Purpose: Constructor and Desctructor for GraphicElement
******************/

#include "GraphicElement.h"
/******************
Function name: ~GraphicElement()
Purpose: Free dynamic memory
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
GraphicElement::~GraphicElement() {
	delete this->fileName;
	delete this->pNext;
}
/******************
Function name: ~GraphicElement()
Purpose: Initialize GraphicElement
Function In parameters: None
Function Out parameters: None
Version: 1.00
******************/
GraphicElement::GraphicElement() {
	fileName = nullptr;
	pNext = nullptr;
}