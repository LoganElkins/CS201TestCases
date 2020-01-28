CC=g++
CFLAGS=-I.

test: tests/main.o tests/CDA.o
	@echo "Testing Project..."
	@g++ src/CDA.cpp -c -o src/CDA.o
	@g++ tests/CDA.cpp -c  -o tests/CDA.o
	@$(CC) src/CDA.o tests/main.o tests/CDA.o -o run_tests
	@./run_tests

clean:
	rm -f src/*.o tests/*.o run_tests 
