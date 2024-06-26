#include "Keys.hpp"
#include "Delimeter.hpp"
#include "ScopeGuard.hpp"

std::istream & reznikova::operator>>(std::istream & is, reznikova::ULLOCT && value)
{
  std::istream::sentry sentry(is);
  if (!sentry)
  {
    return is;
  }
  using del = Delimiter;
  is >> del{'0'};
  return is >> std::oct >> value.num;
}

std::istream & reznikova::operator>>(std::istream & is, reznikova::CMPLSP && value)
{
  std::istream::sentry sentry(is);
  if (!sentry)
  {
    return is;
  }
  using del = Delimiter;
  double real;
  double imag;
  is >> del{'#'} >> del{'c'} >> del{'('} >> real >> imag >> del{')'};
  value.num.real(real);
  value.num.imag(imag);
  return is;
}

std::istream & reznikova::operator>>(std::istream & is, reznikova::STR && value)
{
  std::istream::sentry sentry(is);
  if (!sentry)
  {
    return is;
  }
  return std::getline(is >> Delimiter{ '"' }, value.num, '"');
}
