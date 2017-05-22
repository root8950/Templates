void dfs(int start, int n, vvi &nxt) {
	vector<bool> visited(n+1, 0);
	stack<int> stck;
	stck.push(start);
	while ( !stck.empty() ) {
		int u = stck.top();
		stck.pop();
		if (visited[u] == 0) {
			visited[u] = 1;
			int sz = nxt[u].size();
			for (int i = 0; i < sz; i++) {
				stck.push(nxt[u][i]);
			}
		}
	}
}
