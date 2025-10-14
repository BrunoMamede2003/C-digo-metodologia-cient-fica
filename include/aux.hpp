#ifndef AUX_HPP
#define AUX_HPP

#include <bubble_sort.hpp>
#include <insertion_sort.hpp>
#include <selection_sort.hpp>
#include <shell_sort_sequences.hpp>
#include <shell_sort.hpp>
#include <vector>
#include <random>
#include <algorithm>
#include <functional>
#include <chrono>
#include <iostream>

inline std::vector<int> generate_random(std::size_t const size) noexcept
{
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> dist(1, 1'000'000);
  std::vector<int> ret (size);
  std::ranges::generate(ret, [&](){return dist(gen);});
  return ret;
}

inline double test_time(
  std::function<void(std::vector<int>&)> sort_function,
  std::size_t const test_size)
{
  auto test_vec {generate_random(test_size)};
  auto begin {std::chrono::high_resolution_clock::now()};
  sort_function(test_vec);
  auto end {std::chrono::high_resolution_clock::now()};
  std::chrono::duration<double> diff {end - begin};
  return diff.count();
}

inline double test_time(
  std::function<void(std::vector<int>&, ShellSortSequenceGen)> sort_function,
  std::size_t const test_size,
  ShellSortSequenceGen sequence_generator)
{
  auto test_vec {generate_random(test_size)};
  auto begin {std::chrono::high_resolution_clock::now()};
  sort_function(test_vec, sequence_generator);
  auto end {std::chrono::high_resolution_clock::now()};
  std::chrono::duration<double> diff {end - begin};
  return diff.count();
}

inline void test_all(std::size_t const test_size) noexcept
{
  std::cout << "Starting tests with size = " << test_size << '\n'
    << "Bubble sort time:\t" << test_time(bubble_sort<int>, test_size) << '\n'
    << "Insertion sort time:\t" << test_time(insertion_sort<int>, test_size) << '\n'
    << "Selection sort time:\t" << test_time(selection_sort<int>, test_size) << '\n'
    << "Shell sort time (simple seq):\t" << test_time(shell_sort<int>, test_size, simple_sequence) << '\n'
    << "Shell sort time (complex seq1):\t" << test_time(shell_sort<int>, test_size, complex_sequence) << '\n'
    << "Shell sort time (complex seq2):\t" << test_time(shell_sort<int>, test_size, complex_sequence2) << '\n'
    << "Shell sort time (complex seq3):\t" << test_time(shell_sort<int>, test_size, complex_sequence3) << '\n';
}

inline void test_only_shell(std::size_t const test_size) noexcept
{
  std::cout << "Starting test with shell sort only and size = " << test_size << '\n'
    << "simple sequence:\t" << test_time(shell_sort<int>, test_size, simple_sequence) << '\n'
    << "complex sequence 1:\t" << test_time(shell_sort<int>, test_size, complex_sequence) << '\n'
    << "complex sequence 2:\t" << test_time(shell_sort<int>, test_size, complex_sequence2) << '\n'
    << "complex sequence 3:\t" << test_time(shell_sort<int>, test_size, complex_sequence3) << '\n';
}

#endif // AUX_HPP