all: 
	g++ -std=c++11 src/*/*.cpp tests/functional/*.cpp -o bin/functional_tests -Lbin/ -lmyvensim
	g++ -std=c++11 src/*/*.cpp tests/unit/*.cpp -o bin/unit_tests -Lbin/ -lmyvensim
	rm -rf *.o

dll:
	g++ -std=c++11 -c src/*/*.cpp
	ar rvs bin/libmyvensim.a *.o
	rm -rf *.o

clean:
	rm -rf *.o bin/test

run: 
	./bin/test