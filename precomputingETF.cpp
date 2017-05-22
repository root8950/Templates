//1.) A little Slower (not linear)

#define sz 1000001
vector<int> pr;
vector<bool> primes(sz, 1);

void sieve() {
	primes[0] = primes[1] = 0;
	for (int i = 2; i * i <= sz; i++) {
		if (primes[i] == 1) {
			for (int j = i + i; j < sz; j += i) {
				primes[j] = 0;
			}
		}
	}
	for (int i = 0; i < sz; i++) {
		if (primes[i] == 1) {
			pr.pb(i);
		}
	}
}

vector<int> _ETF(sz, -1);
inline void euler_sieve() {
	//sieve();
	for (int i = 1; i < sz; i++) {
		_ETF[i] = i;
	}
	for (int i = 1; i < sz; i++) {
		if (primes[i] == 1) {
			for (int j = i; j < sz; j += i) {
				_ETF[j] -= _ETF[j] / i;
			}
		}
	}
}

//2.) Fast (Linear)

#define sz (1e7 + 1)
vi pr;
vi phi(sz);

void pre_phi() {
	phi[1] = 1;
	vi lp(sz,0);
	for (int i = 2; i < sz; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			phi[i] = i - 1;
			pr.pb(i);
		}
		else {
			if (lp[i / lp[i]] == lp[i]) {
				phi[i] = phi[i / lp[i]] * lp[i];
			}
			else {
				phi[i] = phi[i / lp[i]] * (lp[i] - 1);
			}
		}
		int lim = pr.size();
		for (int j = 0; j < lim && pr[j] <= lp[i] && i * pr[j] < sz; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}
