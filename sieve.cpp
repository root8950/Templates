//SIEVE
//1.) NloglogN
#define sz (1e6 + 1)
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

//2.) Linear
#define sz (1e7 + 1)
vector<int> pr;
vector<int> lp(sz,0);

void sieve() {
	for (int i = 2; i < sz; i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			pr.pb(i);
		}
		int lim = pr.size();
		for (int j = 0; j < lim && pr[j] <= lp[i] && i * pr[j] < sz; j++) {
			lp[i * pr[j]] = pr[j];
		}
	}
}
