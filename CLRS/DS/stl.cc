#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>

void print(auto &&r) {
  std::ranges::for_each(r, [](auto &&i) { std::cout << i << ' '; });
}
int main() {
  auto v = std::vector<int>(6);
  std::iota(v.begin(), v.end(), 0);
  print(v); // Prints: "0 1 2 3 4 5 "
}