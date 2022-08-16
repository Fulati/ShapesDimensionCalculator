#include "pch.h"
#include "pShapes.h"

//C++ Libraries
#include <iostream>
#include <vector>
#include <string>
using namespace std;

//C Libraries
#include <cmath>

//function prototypes
ostream& roundingTwo(ostream&);
ostream& roundingOff(ostream&);

//rounding to 2 percision Manipulator
ostream& roundingTwo(ostream& out)
{
  out.setf(ios::fixed);
  out.precision(2);
  return out;
}

//rounding off percision Manipulator
ostream& roundingOff(ostream& out)
{
  out.unsetf(ios::fixed);
  out.precision(6);
  return out;
}

//Insertion function
ostream& operator<<(ostream& out, const Shape* const s)
{
  s->output(out);
  return out;
}

//Assignment Operators
Square& Square::operator=(const Square& copyThis) {
  Square& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

comsc::Rectangle& comsc::Rectangle::operator=(const Rectangle& copyThis) {
  Rectangle& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
  }
  return host;
}

Circle& Circle::operator=(const Circle& copyThis) {
  Circle& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.radius) = copyThis.radius;
  }
  return host;
}

Triangle& Triangle::operator=(const Triangle& copyThis) {
  Triangle& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

Cube& Cube::operator=(const Cube& copyThis) {
  Cube& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
  }
  return host;
}

Box& Box::operator=(const Box& copyThis) {
  Box& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.length) = copyThis.length;
    const_cast<double&>(host.width) = copyThis.width;
    const_cast<double&>(host.height) = copyThis.height;

  }
  return host;
}

Cylinder& Cylinder::operator=(const Cylinder& copyThis) {
  Cylinder& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.radius) = copyThis.radius;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

Prism& Prism::operator=(const Prism& copyThis) {
  Prism& host = *this;
  if (this != &copyThis) {
    const_cast<double&>(host.side) = copyThis.side;
    const_cast<double&>(host.height) = copyThis.height;
  }
  return host;
}

//Square output Function
void Square::output(ostream& out) const {

  out << "SQUARE side=" << side;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " area=" << side * side << " perimeter=" << 4 * side << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Rectangle output Function
void comsc::Rectangle::output(ostream& out) const {

  out << "RECTANGLE length=" << length << " width=" << width;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " area=" << length * width << " perimeter=" << 2 * (length + width) << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Circle output Function
void Circle::output(ostream& out) const {

  out << "CIRCLE radius=" << radius;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " area=" << PI * radius * radius << " perimeter=" << 2 * PI * radius << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Triangle output Function
void Triangle::output(ostream& out) const {

  out << "TRIANGLE side=" << side;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " area=" << (sqrt(3.0) / 4) * side * side << " perimeter=" << 3 * side << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Cube output Function
void Cube::output(ostream& out) const {

  out << "CUBE side=" << side;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " surface area=" << 6 * side * side << " volume=" << side * side * side << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Box output Function
void Box::output(ostream& out) const {

  out << "BOX length=" << length << " width=" << width << " height=" << height;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " surface area=" << (2 * length * width) + (2 * width * height) + (2 * length * height) << " volume=" << length * width * height << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Cylinder output Function
void Cylinder::output(ostream& out) const {

  out << "CYLINDER radius=" << radius << " height=" << height;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " surface area=" << (2 * PI * radius * radius) + (2 * PI * radius * height) << " volume=" << PI * radius * radius * height << endl;

  //Turn Off Rounding
  out << roundingOff;
}

//Prism output Function
void Prism::output(ostream& out) const {

  out << "PRISM side=" << side << " height=" << height;

  //Round the digits to 2 decimals
  out << roundingTwo;

  out << " surface area=" << ((sqrt(3) * side * side) / 2) + (3 * side * height) << " volume=" << (sqrt(3) / 4) * side * side * height << endl;

  //Turn Off Rounding
  out << roundingOff;
}
