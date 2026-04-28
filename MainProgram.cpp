// ============================================================

// Lab: More Details about Classes

// Course: Object-Oriented Programming (C++)

// Level: 2nd Year Engineering

// Duration: 60 minutes

// ============================================================

#include <iostream>

#include <string>

#include <cmath>

// ============================================================

// CLASS DEFINITIONS

// ============================================================

class Rectangle; // forward declaration

class Point {

private:

    double x;

    double y;

public:

    // TODO 1: Constructor with member initializer list

    Point(double x, double y) : x(x), y(y) {}

    // TODO 2: const getter for x

    double getX() const {

        return x;

    }

    // TODO 3: const getter for y

    double getY() const {

        return y;

    }

    // TODO 4: const display()

    void display() const {

        std::cout << "(" << x << ", " << y << ")";

    }

    // TODO 5: declare Rectangle as friend class

    friend class Rectangle;

};

class Rectangle {

private:

    Point topLeft;

    Point bottomRight;

public:

    // TODO 6: constructor with member initializer list

    Rectangle(double x1, double y1, double x2, double y2)

        : topLeft(x1, y1), bottomRight(x2, y2) {}

    // TODO 7: const getWidth()

    double getWidth() const {

        return std::abs(bottomRight.x - topLeft.x);

    }

    // TODO 8: const getHeight()

    double getHeight() const {

        return std::abs(topLeft.y - bottomRight.y);

    }

    // TODO 9: const getArea()

    double getArea() const {

        return getWidth() * getHeight();

    }

    // TODO 10: const display()

    void display() const {

        std::cout << "Rectangle: ";

        topLeft.display();

        std::cout << " -> ";

        bottomRight.display();

        std::cout << std::endl;

        std::cout << "Width: " << getWidth() << std::endl;

        std::cout << "Height: " << getHeight() << std::endl;

        std::cout << "Area: " << getArea() << std::endl;

    }

    // TODO 11: declare isSameSize as friend function

    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);

};

// TODO 12: implement isSameSize

bool isSameSize(const Rectangle& r1, const Rectangle& r2) {

    return (r1.getWidth() == r2.getWidth()) &&

           (r1.getHeight() == r2.getHeight());

}

class ConstDemo {

private:

    int value;

public:

    // TODO 13: constructor with member initializer list

    ConstDemo(int v) : value(v) {}

    // TODO 14: const getValue()

    int getValue() const {

        return value;

    }

    // TODO 15: NON-const doubleValue()

    void doubleValue() {

        value *= 2;

    }

    // TODO 16: const constGetDouble()

    int constGetDouble() const {

        return value * 2;

    }

};

// ============================================================

// MAIN

// ============================================================

int main() {

    // TODO 17-21: demo code

    Point p1(3, 4);

    std::cout << "Point: ";

    p1.display();

    std::cout << std::endl << std::endl;

    Rectangle r1(0, 0, 4, 3);

    Rectangle r2(1, 1, 4, 4);

    std::cout << "Rectangle 1:" << std::endl;

    r1.display();

    std::cout << std::endl;

    std::cout << "Rectangle 2:" << std::endl;

    r2.display();

    std::cout << std::endl;

    if (isSameSize(r1, r2)) {

        std::cout << "Rectangles have the same size." << std::endl;

    } else {

        std::cout << "Rectangles do NOT have the same size." << std::endl;

    }

    std::cout << std::endl;

    ConstDemo demo(10);

    std::cout << "Initial value: " << demo.getValue() << std::endl;

    std::cout << "Const double value: " << demo.constGetDouble() << std::endl;

    demo.doubleValue();

    std::cout << "After doubleValue(): " << demo.getValue() << std::endl;

    return 0;

}
 
