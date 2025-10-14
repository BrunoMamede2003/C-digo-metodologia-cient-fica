#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include <vector>
#include <ranges>

template<typename T>
inline void insertion_sort(std::vector<T>& vec) noexcept
{
  for(auto i : std::views::iota(std::size_t{1}, vec.size()))
    for(auto j {i}; j > 0 and vec[j] < vec[j - 1]; j -= 1)
      std::swap(vec[j], vec[j - 1]);
}

#endif // INSERTION_SORT_HPP