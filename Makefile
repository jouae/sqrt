fixed_point: fixed_point.c
	gcc -o fixed_point fixed_point.c -lm

clean:
	rm fixed_point