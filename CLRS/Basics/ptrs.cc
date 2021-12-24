#include <iostream>
#include <memory>

using namespace std;

int main() { auto p{make_unique<int>(38)}; }