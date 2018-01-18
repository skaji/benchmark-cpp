all: libbenchmark.so
	cd eg && $(MAKE)

libbenchmark.so: benchmark.o
	$(CXX) -shared -o $@ $<

%.o: %.cpp %.hpp
	$(CXX) -fPIC -Wall -Wextra -Werror -g -c -o $@ $<
