#ifndef SHELL_SORT_SEQUENCES_HPP
#define SHELL_SORT_SEQUENCES_HPP

#include <cstddef>
#include <vector>
#include <ranges>
#include <functional>

using ShellSortSequenceGen = std::function<std::vector<std::size_t>(std::size_t const)>;

inline std::vector<std::size_t> simple_sequence(std::size_t const vec_size) noexcept
{
  std::vector<std::size_t> return_val;
  for(std::size_t k {1}; k < vec_size; k *= 2)
    return_val.push_back(k);
  return return_val;
}

inline std::vector<std::size_t> complex_sequence(std::size_t const vec_size) noexcept
{
  std::vector<std::size_t> return_val;
  for(auto j : std::views::iota(std::size_t{1}, vec_size))
  {
    auto const k {(std::size_t{1} << j) - 1};
    if(k >= vec_size)
      return return_val;
    return_val.push_back(k);
  }
  //Only to supress warnings
  return return_val;
}

inline std::vector<std::size_t> complex_sequence2(std::size_t const vec_size) noexcept
{
  std::vector<std::size_t> return_val {1};
  for(auto j : std::views::iota(std::size_t{1}, vec_size))
  {
    auto const k {(std::size_t{1} << j) + 1};
    if(k >= vec_size)
      return return_val;
    return_val.push_back(k);
  }
  //Only to supress warnings
  return return_val;
}

inline std::vector<std::size_t> complex_sequence3(std::size_t const vec_size) noexcept {
  std::vector<std::size_t> return_val;
  std::size_t k {3};
  while(true)
  {
    std::size_t const val {(k - 1) / 2};
    if(val >= vec_size)
      break;
    return_val.push_back(val);
    k *= 3;
  }
  return return_val;
}

#endif // SHELL_SORT_SEQUENCES_HPP