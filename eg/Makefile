eg: eg.o
	$(CXX) -o $@ $< -L.. -lbenchmark -Wl,-rpath,$(PWD)/..

%.o: %.cpp
	$(CXX) -I.. -fPIC -Wall -Wextra -Werror -g -c -o $@ $<
