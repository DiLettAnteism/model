target: LP.out
	./LP.out > answer.txt

LP.out: LP.cpp fraction.cpp handler.cpp input.cpp
	g++ LP.cpp fraction.cpp handler.cpp input.cpp -o LP.out

test: test.out
	./test.out

test.out: test.cpp fraction.cpp
	g++ test.cpp fraction.cpp -o test.out

.PHONY: clean
clean:
	rm *.out