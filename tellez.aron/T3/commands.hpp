#ifndef COMMAND_HPP
#define COMMAND_HPP
#include <vector>
#include <map>
#include <functional>
#include "polygon.hpp"

namespace tellez
{
  namespace cmd
  {
    using poly_vec_t = std::vector< Polygon >;

    using area_args_t = std::map< std::string, std::function< double(double, const Polygon&) > >;
    void area(const area_args_t& cmds, const poly_vec_t& vec, std::istream& in, std::ostream& out);
    using Predicate = std::function< bool(const Polygon&) >;
    double acc_area_if(double val, const Polygon& rhs, Predicate pred);
    double acc_area_mean(double val, const Polygon& rhs, std::size_t size);

    using max_args_t = std::map< std::string, std::function< void(const std::vector< Polygon >&, std::ostream&) > >;
    void max(const max_args_t& args, const poly_vec_t& vec, std::istream& in, std::ostream& out);
    void max_area(const poly_vec_t& vec, std::ostream& out);
    void max_vertexes(const poly_vec_t& vec, std::ostream& out);

    using min_args_t = std::map< std::string, std::function< void(const std::vector< Polygon >&, std::ostream&) > >;
    void min(const max_args_t& args, const poly_vec_t& vec, std::istream& in, std::ostream& out);
    void min_area(const poly_vec_t& vec, std::ostream& out);
    void min_vertexes(const poly_vec_t& vec, std::ostream& out);

    using count_args_t = std::map< std::string, std::function< bool(const Polygon&) > >;
    void count(const count_args_t& args, const poly_vec_t& vec, std::istream& in, std::ostream& out);
  }
}

#endif
