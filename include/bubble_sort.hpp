#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

#include <vector>
#include <ranges>

template<typename T>
inline void bubble_sort(std::vector<T>& vec) noexcept
{
  bool swapped {true};
  while(swapped)
  {
    swapped = false;
    for(auto i : std::views::iota(std::size_t {0}, vec.size() - 1))
      if(vec[i] > vec[i + 1])
      {
        std::swap(vec[i], vec[i + 1]);
        swapped = true;
      }
  }
}

#endif // BUBBLE_SORT_HPP