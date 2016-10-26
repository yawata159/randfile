default: rand_file

rand_file: rand_file.c
	gcc -o rand_file rand_file.c

run: rand_file
	./rand_file

clean: 
	-rm *~
	-rm out.txt
