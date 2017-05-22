		
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> vec[i];
			compressed[i] = sorted[i] = vec[i];
		}
		sort(sorted + 1, sorted + n + 1);
		
		for (int i = 1; i <= n; i++) {
			compressed[i] = lower_bound(sorted + 1, sorted + n + 1, vec[i]) - sorted;
		}