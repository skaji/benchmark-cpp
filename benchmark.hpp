#ifndef BENCHMARK_HPP_
#define BENCHMARK_HPP_

namespace benchmark {

void timethis(unsigned long count, void (*func)());
void cmpthese(unsigned long count,
              const char* name1, void (*func1)(),
              const char* name2, void (*func2)());

};

#endif
