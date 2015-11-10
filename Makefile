main: 
	gcc -std=c99 -o baseline baseline.c
	gcc -mavx2 -std=c99 -o SIMD SIMD.c

default: SIMD baseline

SIMD: SIMD.c
	gcc $(CFLAGS) $< -o $@
	
baseline:baseline.c
	gcc $(CFLAGS) $< -o $@
	
clean:
	rm SIMD baseline