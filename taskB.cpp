#include <iostream>

int main() {
  const int kMaxInt = 1e9 + 1;
  int min = kMaxInt;
  int min_position = 0;

  int array_size;
  std::cin >> array_size;
  int* array = new int[array_size];
  for (int i = 0; i < array_size; i++) {
    std::cin >> array[i];
    if (min > array[i]) {
      min = array[i];
      min_position = i;
    }
  }
  delete[] array;
  std::cout << min_position;
  return 0;
}
