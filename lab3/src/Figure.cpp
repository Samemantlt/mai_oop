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

double Figure::get_size() const {
  std::vector<Point> points = get_points();

  if (points.size() < 3) {
    return 0.0; // Return 0 if the polygon has less than 3 points
  }

  double area = 0.0;
  for (size_t i = 0; i < points.size(); ++i) {
    const Point &p1 = points[i];
    const Point &p2 = points[(i + 1) % points.size()];
    area += (p1.get_x() * p2.get_y()) - (p2.get_x() * p1.get_y());
  }

  return std::fabs(0.5 * area);
}

Point Figure::get_center() const {
  Point result;
  int count = 0;

  for (auto point : get_points()) {
    count++;
    result += point;
  }

  return Point(result.get_x() / count, result.get_y() / count);
}

Figure::operator double() const {
  return get_size();
}

bool Figure::operator==(const Figure &other) const {
  return get_points() == other.get_points();
}
