#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <vector>
#include "Point.hpp"

namespace tellez
{
  struct Polygon
  {
    std::vector< Point > points;
  };
}

#endif
