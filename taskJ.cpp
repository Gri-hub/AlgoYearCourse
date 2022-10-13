#include <iostream>
#include <vector>

class MinHeap {
 public:
  MinHeap() : data_(kCapacity), size_(0) {}

  std::pair<int, int> ExtractMin() {
    std::swap(data_[0], data_[size_ - 1]);
    --size_;
    SiftDown(0);
    return data_[size_];
  }
  int Insert(std::pair<int, int> value) {
    if ((long unsigned int)size_ == data_.size()) {
      Resize(2 * size_);
    }
    data_[size_++] = value;
    SiftUp(size_ - 1);
    return 0;
  }
  bool Empty() { return size_ == 0; }

 private:
  void Resize(int new_capacity) { data_.resize(new_capacity); }
  void SiftUp(int index) {
    if (index > 0) {
      int parent = (index - 1) / 2;
      if (data_[index] < data_[parent]) {
        std::swap(data_[index], data_[parent]);
        SiftUp(parent);
      }
    }
  }
  void SiftDown(int index) {
    int min_index = index;
    int left_child = 2 * index + 1;
    int right_child = 2 * index + 2;
    if (left_child < size_ && data_[min_index] > data_[left_child]) {
      min_index = left_child;
    }
    if (right_child < size_ && data_[min_index] > data_[right_child]) {
      min_index = right_child;
    }
    if (index != min_index) {
      std::swap(data_[min_index], data_[index]);
      SiftDown(min_index);
    }
  }
  static constexpr int kCapacity = 8;
  std::vector<std::pair<int, int>> data_;
  int size_;
};

std::vector<int> MergeArrays(const std::vector<std::vector<int>> kArrays,
                             int size) {
  MinHeap heap;
  int index = 0;
  std::vector<int> indexes(kArrays.size(), 0);
  for (auto& array : kArrays) {
    heap.Insert({array[0], index});
    ++index;
  }
  std::vector<int> result;
  result.reserve(size);
  while (!heap.Empty()) {
    std::pair<int, int> temporary_pair = heap.ExtractMin();
    int value = temporary_pair.first;
    int array_index = temporary_pair.second;
    result.emplace_back(value);
    ++indexes[array_index];
    if (indexes[array_index] < (int)kArrays[array_index].size()) {
      heap.Insert({kArrays[array_index][indexes[array_index]], array_index});
    }
  }
  return result;
}

int main() {
  int number_of_arrays;
  std::cin >> number_of_arrays;
  std::vector<std::vector<int>> arrays(number_of_arrays);
  int array_length;
  int number;
  int size = 0;
  for (int i = 0; i < number_of_arrays; ++i) {
    std::cin >> array_length;
    size += array_length;
    for (int j = 0; j < array_length; ++j) {
      std::cin >> number;
      arrays[i].push_back(number);
    }
  }
  std::vector<int> answer(size);
  answer = MergeArrays(arrays, size);
  for (int i = 0; i < size; ++i) {
    std::cout << answer[i] << ' ';
  }

  return 0;
}
