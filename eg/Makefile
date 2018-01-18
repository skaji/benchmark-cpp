eg: eg.o
	$(CXX) -o $@ $< -L$(PWD)/.. -lbenchmark -Wl,-rpath,$(PWD)/..

%.o: %.cpp
	$(CXX) -I.. -fPIC -Wall -Wextra -Werror -g -c -o $@ $<
