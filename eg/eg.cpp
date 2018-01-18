#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#include "benchmark.hpp"

void foo() {
}

int main() {
  benchmark::timethis(10, foo);

  return 0;
}
