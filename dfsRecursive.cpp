void dfs(int u, vvi &nxt, vector<bool> &visited) {
	visited[u] = 1;
	int sz = nxt[u].size();
	for (int i = 0; i < sz; i++) {
		if(visited[nxt[u][i]] == 0){
			dfs(nxt[u][i], nxt, visited);
		}
	}
}
