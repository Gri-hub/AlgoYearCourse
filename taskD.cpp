#include <iostream>
#include <vector>

class MaxHeap {
 public:
  MaxHeap() : data_(kCapacity), size_(0) {}

  size_t ExtractMax();

  void DeleteMax();

  size_t GetMax() const;

  size_t Insert(size_t value);

 private:
  void Resize(size_t new_capacity);

  void SiftUp(size_t index);

  void SiftDown(size_t index);

  static constexpr size_t kCapacity = 8;
  std::vector<size_t> data_;
  size_t size_;
};
size_t MaxHeap::ExtractMax() {
  std::swap(data_[0], data_[size_ - 1]);
  --size_;
  SiftDown(0);
  return data_[size_];
}
void MaxHeap::DeleteMax() {
  std::swap(data_[0], data_[size_ - 1]);
  --size_;
  SiftDown(0);
}
size_t MaxHeap::GetMax() const { return data_[0]; }
size_t MaxHeap::Insert(size_t value) {
  if (size_ == data_.size()) {
    Resize(2 * size_);
  }
  data_[size_++] = value;
  SiftUp(size_ - 1);
  return 0;
}
void MaxHeap::Resize(size_t new_capacity) { data_.resize(new_capacity); }
void MaxHeap::SiftUp(size_t index) {
  if (index > 0) {
    size_t parent = (index - 1) / 2;
    if (data_[index] > data_[parent]) {
      std::swap(data_[index], data_[parent]);
      SiftUp(parent);
    }
  }
}
void MaxHeap::SiftDown(size_t index) {
  size_t max_index = index;
  size_t left_child = 2 * index + 1;
  size_t right_child = 2 * index + 2;
  if (left_child < size_ && data_[max_index] < data_[left_child]) {
    max_index = left_child;
  }
  if (right_child < size_ && data_[max_index] < data_[right_child]) {
    max_index = right_child;
  }
  if (index != max_index) {
    std::swap(data_[max_index], data_[index]);
    SiftDown(max_index);
  }
}

void BuildHeap(MaxHeap& heap, size_t& answer) {
  const size_t kMaxNumber = 1 << 30;
  size_t sequence_size;
  size_t first_element;
  size_t x, y;
  std::cin >> sequence_size >> answer;
  std::cin >> first_element;
  std::cin >> x >> y;
  size_t next_element;
  size_t biggest_heap_element;
  for (size_t i = 0; i < sequence_size; ++i) {
    next_element = (x * first_element + y) % kMaxNumber;
    first_element = next_element;
    if (i < answer) {
      heap.Insert(next_element);
    } else {
      biggest_heap_element = heap.GetMax();
      if (next_element < biggest_heap_element) {
        heap.DeleteMax();
        heap.Insert(next_element);
      }
    }
  }
}

void Output(MaxHeap heap, size_t heap_size) {
  size_t* answer_array = new size_t[heap_size];
  for (int i = heap_size - 1; i >= 0; --i) {
    answer_array[i] = heap.ExtractMax();
  }
  for (size_t i = 0; i < heap_size; ++i) {
    std::cout << answer_array[i] << ' ';
  }
  delete[] answer_array;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);

  MaxHeap heap;
  size_t answer;
  BuildHeap(heap, answer);

  Output(heap, answer);
  return 0;
}
