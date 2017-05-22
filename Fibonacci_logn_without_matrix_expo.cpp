// #define ll long long
// const int MOD = (1e9) + 7 ;

map<ll, ll> F;

ll calFib(ll n) {
	//n -> 0 1 2 3 4....
	//F -> 1 1 2 3 5....
	F[0] = F[1] = 1;
	if (F.count(n)) return F[n];
	ll k = n / 2;
	if (n % 2 == 0) {
		return F[n] = ((calFib(k) * calFib(k)) % MOD + (calFib(k - 1) * calFib(k - 1)) % MOD) % MOD;
	} else {
		return F[n] = ((calFib(k) * calFib(k + 1)) % MOD + (calFib(k - 1) * calFib(k)) % MOD) % MOD;
	}
}