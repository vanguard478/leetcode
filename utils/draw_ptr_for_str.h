
#if !defined(DRAW_PTR)
#define DRAW_PTR

#include<iostream>
#include<string>
void draw_pointers(const std::string &str, int left_idx, int right_idx) {
  std::string left_pointer = "L";
  std::string right_pointer = "R";

  // Print array elements
  for (int i = 0; i < str.size(); ++i) {
    std::cout << str[i] << ' ';
  }
  std::cout << '\n';

  // Draw pointers below the array
  for (int i = 0; i < str.size(); ++i) {
    if (i == left_idx && i == right_idx) {
      std::cout << 'B'; // Both pointers at the same position
    } else if (i == left_idx) {
      std::cout << left_pointer;
    } else if (i == right_idx) {
      std::cout << right_pointer;
    } else {
      std::cout << ' ';
    }
    std::cout << ' ';
  }
  std::cout << '\n';
}

#endif // DRAW_PTR

