#include "Figure.h"

#include <cmath>

std::ostream &operator<<(std::ostream &output, const Figure &figure) {
  figure.print(output);
  return output;
}

std::istream &operator>>(std::istream &input, Figure &figure) {
  figure.read(input);
  return input;
}

double Figure::getSize() const {
  std::vector<Point> points = getPoints();

  if (points.size() < 3) {
    return 0.0; // Return 0 if the polygon has less than 3 points
  }

  double area = 0.0;
  for (size_t i = 0; i < points.size(); ++i) {
    const Point &p1 = points[i];
    const Point &p2 = points[(i + 1) % points.size()];
    area += (p1.getX() * p2.getY()) - (p2.getX() * p1.getY());
  }

  return std::fabs(0.5 * area);
}

Point Figure::getCenter() const {
  Point result;
  int count = 0;

  for (auto point : getPoints()) {
    count++;
    result += point;
  }

  return Point(result.getX() / count, result.getY() / count);
}

Figure::operator double() const {
  return getSize();
}

bool Figure::operator==(const Figure &other) const {
  return getPoints() == other.getPoints();
}
