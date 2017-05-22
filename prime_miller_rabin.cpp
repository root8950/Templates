uint64_t mul_mod(uint64_t a, uint64_t b, uint64_t m) {
	long double x;
	uint64_t c;
	int64_t r;
	if (a >= m) a %= m;
	if (b >= m) b %= m;
	x = a;
	c = x * b / m;
	r = (int64_t)(a * b - c * m) % (int64_t)m;
	return r < 0 ? r + m : r;
}

size_t fast_expo(size_t a, size_t n, size_t mod) {
	size_t power = a;
	size_t result = 1;
	while (n) {
		if (n & 1) {
			result = mul_mod(result, power, mod);
		}
		power = mul_mod(power, power, mod);
		n = (n >> 1);
	}
	return result;
}
 
bool check(size_t n, size_t s, size_t d, size_t a) {
	size_t x = fast_expo(a, d, n);
	size_t y;
	while (s) {
		y = mul_mod(x, x, n);
		if (y == 1 && x != 1 && x != n-1) return false;
		x = y;
		--s;
	}
	if (y != 1) return false;
	return true;
}
 
bool is_prime(size_t n) {
	if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3)) return false;
	if (n <= 3)return true;
	size_t d = (n >> 1);
	size_t s = 1;
	while (!(d & 1)) {
		d = (d >> 1);
		++s;
	}
	if (n < 1373653) return check(n,s,d,2) && check(n,s,d,3);
	if (n < 9080191) return check(n,s,d,31) && check(n,s,d,73);
	if (n < 4759123141) return check(n,s,d,2) && check(n,s,d,7) && check(n,s,d,61);
	if (n < 1122004669633) return check(n,s,d,2) && check(n,s,d,13) && check(n,s,d,23) && check(n,s,d,1662803);
	if (n < 2152302898747) return check(n,s,d,2) && check(n,s,d,3) && check(n,s,d,5) && check(n,s,d,7) && check(n,s,d,11);
	if (n < 3474749660383) return check(n,s,d,2) && check(n,s,d,3) && check(n,s,d,5) && check(n,s,d,7) && check(n,s,d,11) && check(n,s,d,13);
	return check(n,s,d,2) && check(n,s,d,3) && check(n,s,d,5) && check(n,s,d,7) && check(n,s,d,11) && check(n,s,d,13) && check(n,s,d,17);
}
