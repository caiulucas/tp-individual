all: 
	g++ -std=c++11 src/*/*.cpp tests/functional/*.cpp -o bin/functional_tests
	g++ -std=c++11 src/*/*.cpp tests/unit/*.cpp -o bin/unit_tests
	rm -rf *.o

clean:
	rm -rf *.o bin/test

run: 
	./bin/test