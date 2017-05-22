//Computing Euler Totient function

int ETF(int n) {
	int num = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			num = num - (num / i);
		}
		while (n % i == 0) {
			n = n / i;
		}
	}
	if (n > 1) {// if n is prime
		num = num - (num / n);
	}
	return num;
}
