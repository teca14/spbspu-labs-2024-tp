#include "polygon.hpp"
#include <ostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <functional>
#include "point.hpp"
#include "predicates.hpp"
std::istream& tellez::operator>>(std::istream& in, Polygon& rhs)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }
  std::size_t n{};
  in >> n;
  if (n < 3)
  {
    in.setstate(std::ios::failbit);
    return in;
  }
  std::vector< Point > points;
  points.reserve(n);
  for (std::size_t i = 0; (i < n) && in; ++i)
  {
    Point p{ 0, 0 };
    if (in.peek() == '\n')
    {
      in.setstate(std::ios::failbit);
    }
    if (in >> p)
    {
      points.push_back(p);
    }
  }
  if ((in.peek() != '\n' && !in.eof()) || points.size() != n)
  {
    in.setstate(std::ios::failbit);
  }
  else
  {
    rhs.points = std::move(points);
  }
  return in;
}
std::ostream& tellez::operator<<(std::ostream& out, const Polygon& rhs)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  out << rhs.points.size() << " ";
  std::copy(rhs.points.cbegin(), rhs.points.cend(), std::ostream_iterator< Point >{ out, " " });
  return out;
}
bool tellez::operator==(const Polygon& lhs, const Polygon& rhs)
{
  if (lhs.points.size() != rhs.points.size())
  {
    return false;
  }
  return std::equal(lhs.points.cbegin(), lhs.points.cend(), rhs.points.cbegin());
}
double tellez::get_area(const Polygon& rhs)
{
  using namespace std::placeholders;
  auto acc_area = std::bind(AccumulatePolygonArea{ rhs.points[1] }, _1, _2, rhs.points[0]);
  return std::accumulate(rhs.points.cbegin(), rhs.points.cend(), 0.0, acc_area);
}

int tellez::min_x(const Polygon& rhs)
{
  return std::min_element(rhs.points.cbegin(), rhs.points.cend(), compare_points_x)->x;
}
int tellez::min_y(const Polygon& rhs)
{
  return std::min_element(rhs.points.cbegin(), rhs.points.cend(), compare_points_y)->y;
}
int tellez::max_x(const Polygon& rhs)
{
  return std::max_element(rhs.points.cbegin(), rhs.points.cend(), compare_points_x)->x;
}
int tellez::max_y(const Polygon& rhs)
{
  return std::max_element(rhs.points.cbegin(), rhs.points.cend(), compare_points_y)->y;
}
