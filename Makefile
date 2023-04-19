main: src/main.c
	cc -g -Ilib -Llib/tinycc -ltcc src/main.c -o build/main

other_main: src/other_main.c
	cc -g -Ilib -Llib/tinycc -ltcc src/other_main.c -o build/other_main

run: main
	./build/main

inception: other_main
	./build/other_main

clean:
	rm -rf build/*