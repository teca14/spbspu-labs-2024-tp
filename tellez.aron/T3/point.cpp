k#include "point.hpp"
#include <cmath>
#include <ostream>
#include <delimiterI.hpp>

std::istream& tellez::operator>>(std::istream& in, Point& rhs)
{
  std::istream::sentry sentry(in);
  if (!sentry)
  {
    return in;
  }

  Point tmp{ 0, 0 };
  using del = StrictCaseCharDelimiterI;
  in >> del{ '(' } >> tmp.x >> del{ ';' } >> tmp.y >> del{ ')' };
  if (in)
  {
    rhs = tmp;
  }

  return in;
}

std::ostream& tellez::operator<<(std::ostream& out, const Point& rhs)
{
  std::ostream::sentry sentry(out);
  if (!sentry)
  {
    return out;
  }
  out << '(' << rhs.x << ';' << rhs.y << ')';
  return out;
}

bool tellez::operator==(const Point& lhs, const Point& rhs)
{
  return lhs.x == rhs.x && lhs.y == rhs.y;
}

double tellez::AreaAccumulator::operator()(double val, const Point& p2, const Point& p3)
{
  val += 0.5 * std::abs((p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y));
  p1 = p2;
  return val;
}
