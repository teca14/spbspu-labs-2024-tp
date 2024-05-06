#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <istream>
#include <vector>
#include "point.hpp"
namespace tellez
{
  struct Polygon
  {
    std::vector< Point > points;
  };
  std::istream& operator>>(std::istream& in, Polygon& rhs);
  std::ostream& operator<<(std::ostream& out, const Polygon& rhs);
  double get_area(const Polygon& rhs);
}

#endif
