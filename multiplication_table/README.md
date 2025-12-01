Multiplication Table
====================
- [C++14之std::index_sequence和std::make_index_sequence_c++ sequence-CSDN博客](https://blog.csdn.net/haokan123456789/article/details/136632869)
- [C++雾中风景16:std::make_index_sequence, 来试一试新的黑魔法吧](https://www.cnblogs.com/happenlee/p/14219925.html)
  ```
  template <size_t ...N>
  static constexpr auto square_nums(size_t index, std::index_sequence<N...>) {
      constexpr auto nums = std::array{N * N ...};
      return nums[index];
  }

  template <size_t N>
  constexpr static auto const_nums(size_t index) {
      return square_nums(index, std::make_index_sequence<N>{});
  }

  int main() {
      static_assert(const_nums<101>(100) == 100 * 100); 
  }
  ```
