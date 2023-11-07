all: 
	g++ -std=c++11 src/*/*.cpp tests/*/*.cpp -o bin/test
	rm -rf *.o

clean:
	rm -rf *.o bin/test

run: 
	./bin/test