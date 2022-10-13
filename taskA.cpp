#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
  long left_boundary = 0;
  long right_boundary = end - begin;
  while (right_boundary - left_boundary > 1) {
    long middle = (right_boundary + left_boundary) / 2;
    if (target >= *(begin + middle)) {
      left_boundary = middle;
    } else {
      right_boundary = middle;
    }
  }
  return (*(begin + left_boundary) == target);
}

int main() {
  int array_length;
  std::cin >> array_length;
  int* array = new int[array_length];
  for (int i = 0; i < array_length; i++) {
    std::cin >> array[i];
  }

  int number_of_calls;
  std::cin >> number_of_calls;
  for (int i = 0; i < number_of_calls; i++) {
    int begin, end, target;
    std::cin >> begin >> end >> target;
    if (BinarySearch(array + begin, array + end, target)) {
      std::cout << "YES" << std::endl;
    } else {
      std::cout << "NO" << std::endl;
    }
  }
  delete[] array;
  return 0;
}

