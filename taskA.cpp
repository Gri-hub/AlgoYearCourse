#include <iostream>

bool BinarySearch(const int* begin, const int* end, int target) {
  size_t left_boundary = 0;
  size_t right_boundary = end - begin;
  while (right_boundary - left_boundary > 1) {
    size_t middle = (right_boundary + left_boundary) / 2;
    if (target >= *(begin + middle)) {
      left_boundary = middle;
    } else {
      right_boundary = middle;
    }
  }
  return (*(begin + left_boundary) == target);
}

void Read(size_t array_length, int array[]) {
  std::cin >> array_length;
  for (size_t i = 0; i < array_length; i++) {
    std::cin >> array[i];
  }
}

void Output(bool answer) {
  if (answer) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}

void ManageRequests(int array[]) {
  int number_of_calls;
  std::cin >> number_of_calls;
  for (int i = 0; i < number_of_calls; i++) {
    int begin, end, target;
    std::cin >> begin >> end >> target;
    Output(BinarySearch(array + begin, array + end, target));
  }
}

int main() {
  const int kMaxInt = 1e5 + 1;
  int* array = new int[kMaxInt];
  size_t array_length = 0;

  Read(array_length, array);
  ManageRequests(array);

  delete[] array;
  return 0;
}

