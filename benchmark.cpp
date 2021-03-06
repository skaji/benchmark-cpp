#include "benchmark.hpp"

#include <time.h>
#include <sys/time.h>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <sstream>

using namespace std;

namespace {

double point() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return static_cast<double>(t.tv_sec) + static_cast<double>(t.tv_usec) / 1000000;
}

double run(unsigned long count, void (*func)()) {
  double start = point();
  for (unsigned long i = 0; i < count; ++i) {
    func();
  }
  double end = point();
  return end - start;
}

}

namespace benchmark {

void timethis(unsigned long count, void (*func)()) {
  double took = run(count, func);
  printf("%.2f count/s (= %.3f msec/count)\n", count / took, took / count * 1000);
}

void cmpthese(unsigned long count,
              const char* name1, void (*func1)(),
              const char* name2, void (*func2)()) {
  double took1 = run(count, func1);
  double took2 = run(count, func2);

  size_t max = strlen(name1) > strlen(name2) ? strlen(name1) : strlen(name2);
  stringstream ss;
  ss << "%" << max << "s " << "%12.2f count/s (= %.3f msec/count) (ratio: %5ld%)\n";
  string format = ss.str();
  printf(format.c_str(),
         name1,
         count / took1,
         took1 / count * 1000,
         static_cast<unsigned long>(took2 / took1 * 100));
  printf(format.c_str(),
         name2,
         count / took2,
         took2 / count * 1000,
         static_cast<unsigned long>(took1 / took2 * 100));
}

}
