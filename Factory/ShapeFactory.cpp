#include <string>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "ShapeFactory.h"


ShapeFactory::ShapeFactory()
{
}


Shape* ShapeFactory::getShape(std::string shapeType)
{
	if (shapeType == "Circle")
	{
		return new Circle();
	}
	else if (shapeType == "Rectangle")
	{
		return new Rectangle();
	}
	else if (shapeType == "Square")
	{
		return new Square();
	}
}