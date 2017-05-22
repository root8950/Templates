//gcd
int n;
#define sz (5e5)
vvi ST(sz, vi(20));
vi vec(sz);

void preprocess() {
	for (int i = 0; i < n; i++) {
		ST[i][0] = vec[i];
	}
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			ST[i][j] = __gcd(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
		}
	}
}

int query(int start, int end) {
	int diff = end - start;
	diff = 31 - __builtin_clz(diff + 1);
	return __gcd(ST[start][diff], ST[end - (1 << diff) + 1][diff]);
}
