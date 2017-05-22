//Computing (a*b)mod n efficiently where overflow can occur
//a.) expoiting long double ( O(1) )

//reference -> http://en.wikipedia.org/wiki/Modular_arithmetic

#define TU U64
#define TI I64
#define U64 uint64_t
#define I64 int64_t

TU mul_mod(TU a, TU b, TU m) {
	long double x;
	TU c;
	TI r;
	if (a >= m) a %= m;
	if (b >= m) b %= m;
	x = a;
	c = x * b / m;
	r = (TI)(a * b - c * m) % (TI)m;
	return r < 0 ? r + m : r;
}



//b.) ( O(log(min(a,b)) )

ll mul_mod(ll a, ll b, ll c) {
	ll x = 0, y = a % c;
	while (b > 0) {
		if (b & 1) {
			x = (x + y) % c;
		}
		y = (y << 1) % c;
		b = (b >> 1);
	}
	return x % c;
}
