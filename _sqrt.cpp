//1.) sqrt function

double _sqrt(double n) {
	double x = n;
	double y = 1;
	while (x - y > 0.00000001) {
		x = ((x + y) / 2);
		y = n / x;
	}
	return x;
}
