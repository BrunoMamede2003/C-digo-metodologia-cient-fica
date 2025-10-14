#ifndef SHELL_SORT_HPP
#define SHELL_SORT_HPP

#include <vector>
#include <ranges>
#include <shell_sort_sequences.hpp>

template<typename T>
inline void shell_sort(
  std::vector<T>& vec,
  ShellSortSequenceGen sequence_generator) noexcept
{
  auto intervals {sequence_generator(vec.size())};
  for(auto k : std::ranges::views::reverse(intervals))
    for(auto i : std::views::iota(k, vec.size()))
    {
      auto temp = vec[i];
      auto j = i;
      while(j >= k and vec[j - k] > temp)
      {
        vec[j] = vec[j - k];
        j -= k;
      }
      vec[j] = temp;
    }
}

#endif // SHELL_SORT_HPP