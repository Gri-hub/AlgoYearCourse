#include <iostream>
#include <limits>

void ReadAndManageRequest(size_t& min_position) {
  int min = std::numeric_limits<int>::max();;
  size_t array_size;
  std::cin >> array_size;
  int* array = new int[array_size];
  for (size_t i = 0; i < array_size; i++) {
    std::cin >> array[i];
    if (min > array[i]) {
      min = array[i];
      min_position = i;
    }
  }
  delete[] array;
}

void Output(size_t min_position) { std::cout << min_position; }

int main() {
  size_t min_position = 0;
  ReadAndManageRequest(min_position);
  Output(min_position);
  return 0;
}