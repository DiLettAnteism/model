test.out: test.cpp fraction.cpp
	g++ test.cpp fraction.cpp -o test.out
	./test.out

.PHONY: clean
clean:
	rm *.out