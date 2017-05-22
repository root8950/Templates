//a.) Without mod

ll com(ll n, ll r) {
	if (r == 0) {
		return 1;
	}
	if (r > n-r ) {
		r = n - r;
	}
	ll ans = 1;
	for (int i = 0; i < r; i++) {
		ans = (ans * (n - i)) / (i + 1);
	}
	return ans;
}

//b.) With mod

/*
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
*/

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

ll exponent(ll a, ll b, ll c) {
	ll x = 1, y = a;
	while (b > 0) {
		if (b & 1) {
			x = (x * y) % c;
		}
		y = (y * y) % c;
		b = (b >> 1);
	}
	return x % c;
}

ll inverse_mod(ll n, ll c) {
	return  exponent(n, c - 2, c);
}


ll com(ll n, ll r, ll c) {
	ll Cnr = 1, Cn = 1, Cr = 1;
	ll num = 1;
	for (int i = 2; i <= n; i++) {
		num = mul_mod(num, i, c);
		if (i == (n - r)) Cnr=num;
		else if (i == n) Cn=num;
		else if (i == r) Cr=num;
	}
	return (Cn * ((inverse_mod(Cr, c) * inverse_mod(Cnr, c)) % c)) % c;
}

ll Lucas(ll n, ll r, ll c) {
	if (r == 0) return 1;
	int ni = n % c;
	int ri = r % c;
	if (ri > ni) return 0;
	return ( ( ( Lucas(n / c, r / c, c) ) % c ) * ( com(ni, ri, c) ) % c );
}
