#pragma once
#include <string>
#include "Shape.h"


class ShapeFactory
{
public:
	ShapeFactory();
	Shape* getShape(std::string shapeType);
};