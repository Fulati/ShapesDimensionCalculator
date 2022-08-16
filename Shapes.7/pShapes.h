//C++ Libraries
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#ifndef pShapes_h
#define pShapes_h

//PI
const double PI = 3.141593;


//Shape Struct
struct Shape {
  virtual void output(ostream&) const = 0; // Pure Virtual Function
  virtual ~Shape() { }
};

//Insertion
ostream& operator<<(ostream&, const Shape* const);

//SQUARE CLASS
class Square : public Shape {
protected:
  const double side;

public:
  Square(const vector<string>& tokens)
    : side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0) {}
  Square& operator=(const Square&);
  void output(ostream&) const;
};

namespace comsc {
  //RECTANGLE CLASS
  class Rectangle : public Shape {
  protected:
    const double length;
    const double width;

  public:
    Rectangle(const vector<string>& tokens)
      : length(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0),
      width(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0) {}
    Rectangle& operator=(const Rectangle&);
    void output(ostream&) const;
  };
}

//CIRCLE CLASS
class Circle : public Shape {
protected:
  const double radius;

public:
  Circle(const vector<string>& tokens)
    : radius(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0) {}
  Circle& operator=(const Circle&);
  void output(ostream&) const;
};

//TRIANGLE CLASS
class Triangle : public Shape {
protected:
  const double side;

public:
  Triangle(const vector<string>& tokens)
    : side(tokens.size() >= 2 ? atof(tokens[1].c_str()) : 0) {}
  Triangle& operator=(const Triangle&);
  void output(ostream&) const;
};

//CUBE CLASS
class Cube : public Square {
public:
  Cube(const vector<string>& tokens)
    : Square(tokens) {}
  Cube& operator=(const Cube&);
  void output(ostream&) const;
};

//BOX CLASS
class Box : public comsc::Rectangle {
  const double height;

public:
  Box(const vector<string>& tokens)
    : Rectangle(tokens),
    height(tokens.size() >= 4 ? atof(tokens[3].c_str()) : 0) {}
  Box& operator=(const Box&);
  void output(ostream&) const;
};

//CYLINDER CLASS
class Cylinder : public Circle {
  const double height;

public:
  Cylinder(const vector<string>& tokens)
    : Circle(tokens),
    height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0) {}
  Cylinder& operator=(const Cylinder&);
  void output(ostream&) const;
};

//PRISM CLASS
class Prism : public Triangle {
  const double height;

public:
  Prism(const vector<string>& tokens)
    : Triangle(tokens),
    height(tokens.size() >= 3 ? atof(tokens[2].c_str()) : 0) {}
  Prism& operator=(const Prism&);
  void output(ostream&) const;
};



#endif
