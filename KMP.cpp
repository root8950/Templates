//length of failure function is m+1;
void failure_func(string &pat, vi &F) {
	int m = pat.length();
	for (int i = 2; i <= m; i++) {
		int j = F[i-1];
		while(1) {
			if (pat[j] == pat[i-1]) {
				F[i] = j + 1;
				break;
			}
			if (j == 0) {
				F[i] = 0;
				break;
			}
			j = F[j];
		}
	}
}

int KMP(string &str, string &pat, vi &F, vi &pos){
	int n = str.length();
	int m = pat.length();
	failure_func(pat, F);
	int i = 0;
	int j = 0;
	int ans = 0;
	while(1) {
		if (j == n) {
			break;
		}
		if (str[j] == pat[i]) {
			i++;
			j++;
			if (i == m) {
				pos.pb(j - i);
				i = F[i];
				ans++;
			}
		}
		else if (i > 0) {
			i = F[i];
		}
		else j++;
	}
	return ans;
}
