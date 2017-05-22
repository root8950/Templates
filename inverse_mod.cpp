//Modular multiplicative inverse

ll exponent(ll a, ll b, ll c) {
	ll x = 1 , y = a;
	while (b > 0) {
		if (b & 1) {
			x = (x * y) % c;
		}
		y = (y * y) % c;
		b = (b >> 1);
	}
	return x % c;
}

ll inverse_mod(ll n, ll c){
	return  exponent(n, c - 2, c);
}
