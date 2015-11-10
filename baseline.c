#include <stdint.h>
#include <time.h>
#include <stdio.h>

double compute_pi(size_t dt)
{
	double pi = 0.0;
	double delta = 1.0 / dt;
	for(size_t i = 0; i<dt; i++){
		double x = (double)i / dt;
		pi += delta / (1.0 + x*x);
	}
	return pi * 4.0;
}

int main(void)
{
	clock_t start_time, end_time;
	double pi;
	start_time = clock();		
	pi = compute_pi(128000000);
	end_time = clock();
	printf("%f\nTime : %f\n", pi, (double)(end_time-start_time)/CLOCKS_PER_SEC);
	return 0;
}