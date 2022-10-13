#include <cmath>
#include <iomanip>
#include <iostream>

double FindAverageSound(int left_boundary, int right_boundary,
                        const double array[], int array_size) {
  double average_sound = array[right_boundary + 1] / array[left_boundary];
  double number_of_multipliers =
      (double)right_boundary - (double)left_boundary + (double)1;
  return std::pow(average_sound, (double)array_size / (number_of_multipliers));
}

int main() {
  int number_of_creatures;
  std::cin >> std::setprecision(2);
  std::cin >> number_of_creatures;
  double* creature_sound = new double[number_of_creatures];
  double* array_of_products = new double[number_of_creatures + 1];
  array_of_products[0] = 1;
  for (int i = 0; i < number_of_creatures; i++) {
    std::cin >> creature_sound[i];
    creature_sound[i] =
        std::pow(creature_sound[i], 1 / (double)number_of_creatures);
    array_of_products[i + 1] = creature_sound[i] * array_of_products[i];
  }
  int number_of_requests;
  std::cin >> number_of_requests;
  int left_boundary;
  int right_boundary;
  std::cout << std::fixed;
  const int kPrecision = 6;
  std::cout << std::setprecision(kPrecision);
  for (int i = 0; i < number_of_requests; i++) {
    std::cin >> left_boundary >> right_boundary;
    std::cout << FindAverageSound(left_boundary, right_boundary,
                                  array_of_products, number_of_creatures);
    std::cout << "\n";
  }
  delete[] creature_sound;
  delete[] array_of_products;
  return 0;
}
