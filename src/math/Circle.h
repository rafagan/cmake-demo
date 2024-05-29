#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
public:
    explicit Circle(double r);
    [[nodiscard]] double getArea() const;
    [[nodiscard]] double getPerimeter() const;
private:
    double radius;
};

#endif // CIRCLE_H