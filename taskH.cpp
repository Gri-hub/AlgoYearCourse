#include <cmath>
#include <iomanip>
#include <iostream>

double FindAverageSound(int left_boundary, int right_boundary,
                        const double array[], size_t array_size) {
  double average_sound = array[right_boundary + 1] / array[left_boundary];
  double number_of_multipliers =
      (double)right_boundary - (double)left_boundary + (double)1;
  return std::pow(average_sound, (double)array_size / (number_of_multipliers));
}

void Read(size_t arr_size, double arr1[], double arr2[]) {
  arr2[0] = 1;
  for (size_t i = 0; i < arr_size; i++) {
    std::cin >> arr1[i];
    arr1[i] = std::pow(arr1[i], 1 / (double)arr_size);
    arr2[i + 1] = arr1[i] * arr2[i];
  }
}

void Out(double arr[], size_t arr_size) {
  size_t requests;
  std::cin >> requests;
  int left_boundary;
  int right_boundary;
  for (size_t i = 0; i < requests; i++) {
    std::cin >> left_boundary >> right_boundary;
    std::cout << FindAverageSound(left_boundary, right_boundary, arr, arr_size);
    std::cout << "\n";
  }
}

int main() {
  std::cin >> std::setprecision(2);

  size_t number_of_creatures;
  std::cin >> number_of_creatures;
  double* creature_sound = new double[number_of_creatures];
  double* array_of_products = new double[number_of_creatures + 1];
  Read(number_of_creatures, creature_sound, array_of_products);

  std::cout << std::fixed;
  const int kPrecision = 6;
  std::cout << std::setprecision(kPrecision);
  Out(array_of_products, number_of_creatures);

  delete[] creature_sound;
  delete[] array_of_products;
  return 0;
}