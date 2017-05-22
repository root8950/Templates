// O(nlog^2n)

bool cmp(const pair< pii,int > &a, const pair< pii,int > &b) {
	if (a.ft.ft == b.ft.ft) {
		return a.ft.sd < b.ft.sd;
	}
	return a.ft.ft < b.ft.ft;
}

int suffix_arr(string &str, vi &suff_arr, vvi &P) {//O(nlog^2n)
	int l = str.length();
	for (int i = 0; i < l; i++) {
		P[0][i] = str[i] - 'A';
	}
	int stp = 1;
	vector< pair< pii,int > > tuple(l, { {0,0}, 0 } );
	for (int cnt = 1; (cnt >> 1) < l; stp++, cnt <<= 1) {//O(logn)
		for (int i = 0; i < l; i++) {//O(n)
			tuple[i].ft.ft = P[stp - 1][i];
			tuple[i].ft.sd = (i + cnt < l) ? P[stp - 1][i + cnt] : -1;
			tuple[i].sd = i;
		}
		sort(all(tuple), cmp);//O(n(logn))
		for (int i = 0; i < l; i++) {
			P[stp][tuple[i].sd] = ( (i > 0 && tuple[i].ft.ft == tuple[i-1].ft.ft && tuple[i].ft.sd == tuple[i-1].ft.sd) ? P[stp][tuple[i-1].sd] : i );
		}
	}
	for (int i = 0; i < l; i++) {
		suff_arr[P[stp - 1][i]] = i;
	}
	return stp;//cout << stp << "\n";
}

int lcp(int x, int y, int stp, int l, vvi &P) {//O(logn)
	int ans = 0;
	if (x == y) {
		return l - x;
	}
	for (int k = stp - 1; k >=0; k--) {
		if (x < l && y < l) {
			if (P[k][x] == P[k][y]) {
				x += 1 << k;
				y += 1 << k;
				ans += 1 << k;
			}
		}
		else break;
	}
	return ans;
}
