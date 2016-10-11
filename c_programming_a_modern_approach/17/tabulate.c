/**
 * Tabulates values of trigonometric functions
 */
#include <math.h>
#include <stdio.h>

void tabulate (double (*f)double, double first, double last, double incr);

int main () {
	double final, increament, initial;
	printf("Enter initial value: ");
	scanf("%lf", &initial);

	printf("Enter final value:");
	scanf("%lf", &final);

	printf("Enter increament:");
	scanf("%lf", &increament);

	printf("\n     x     cos(x)\n   -------    -------\n");
	tabulate(cos, initial, final, increament);
	
	printf("\n     x     sin(x)\n   -------    -------\n");
	tabulate(sin, initial, final, increament);
	
	printf("\n     x     tan(x)\n   -------    -------\n");
	tabulate(tan, initial, final, increament);

	return 0;
}

void tabulate (double (*f)(double), double first, double last, double incr) {
	double x;
	int i, num_intervals;
	num_intervals = cell((last - first) / incr);
	for (i = 0; i <= num_intervals; i++) {
		x = first + i * incr;
		printf("%10.5f %10.5f\n", x, (*f)[x]);
	}
}