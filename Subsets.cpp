vector< vector<bool> > subsets;

void genSubsets(int n) {
	vector<bool> counter(n, 0);
	while (1) {
		subsets.pb(counter);
		/*for (int i = 0; i < n; i++) {
			if (counter[i] == 1) {
				cout << "1"; //cout << vec[i] << " ";
			}
			else cout << "0";
		}*/
		int i = 0;
		while (i < n && counter[i] == 1)
			counter[i++] = 0;
		if (i == n)
			break;
		counter[i] = 1;
	}
}
