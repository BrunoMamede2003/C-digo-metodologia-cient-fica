#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <ranges>

template<typename T>
void selection_sort(std::vector<T>& vec) noexcept
{
  for(auto start : std::views::iota(std::size_t{0}, vec.size() - 1))
  {
    auto min_index {start};
    for(auto index : std::views::iota(start + 1, vec.size()))
      if(vec[index] < vec[min_index])
        min_index = index;
    std::swap(vec[start], vec[min_index]);
  }   
}

#endif // SELECTION_SORT_HPP