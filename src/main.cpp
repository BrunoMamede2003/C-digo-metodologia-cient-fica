#include <aux.hpp>
#include <cstdlib>
#include <iostream>
#include <bubble_sort.hpp>
#include <insertion_sort.hpp>
#include <selection_sort.hpp>
#include <shell_sort_sequences.hpp>
#include <shell_sort.hpp>

int main(void)
{
  test_all(1'000);
  test_all(10'000);
  test_all(100'000);
  test_only_shell(1'000'000);
  test_only_shell(10'000'000);
  test_only_shell(100'000'000);
  std::cout << "\nTests finished\n";
  return EXIT_SUCCESS;
}