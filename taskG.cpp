#include <iostream>

template <typename T>
size_t Partition(T* array, size_t left, size_t right) {
  int pivot = array[(left + right) / 2];
  size_t i = left;
  size_t j = right;
  do {
    while (array[i] < pivot) {
      ++i;
    }
    while (array[j] > pivot) {
      --j;
    }
    if (i >= j) {
      return j;
    }
    std::swap(array[i], array[j]);
    ++i;
    --j;
  } while (true);
}

template <typename T>
void Qsort(T* array, size_t left, size_t right) {
  if (left >= right) {
    return;
  }
  size_t p = Partition(array, left, right);
  Qsort(array, left, p);
  Qsort(array, p + 1, right);
}

template <typename T>
void Qsort(T* array, size_t size) {
  Qsort(array, 0, size - 1);
}

int main() {
  size_t array_size;
  std::cin >> array_size;
  int* array = new int[array_size];
  for (size_t i = 0; i < array_size; ++i) {
    std::cin >> array[i];
  }

  Qsort(array, array_size);
  for (size_t i = 0; i < array_size; ++i) {
    std::cout << array[i] << " ";
  }
  delete[] array;
  return 0;
}
