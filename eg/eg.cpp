#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

#include "benchmark.hpp"
#include <unistd.h>

void foo() {
  usleep(30000);
}
void foo2() {
  usleep(35000);
}

int main() {
  benchmark::timethis(100, foo);
  benchmark::cmpthese(100, "foo1", foo, "fooo2", foo2);
  return 0;
}
