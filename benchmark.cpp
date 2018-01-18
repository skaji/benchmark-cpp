#include "benchmark.hpp"

#include <time.h>
#include <sys/time.h>
#include <iostream>

using namespace std;

namespace {

unsigned long point() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t.tv_sec * 1000*1000 + t.tv_usec;
}

}

namespace benchmark {

void timethis(int count, void (*func)()) {
  (void)count;
  (void)func;
  cout << point() << "\n";
}


}
