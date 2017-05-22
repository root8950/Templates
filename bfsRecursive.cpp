void bfs(int u, vvi &nxt, vector<bool> &visited, queue<int> &q){
	int sz = nxt[u].size();
	for (int i = 0; i < sz; i++) {
		if (visited[nxt[u][i]] == 0) {
			q.push(nxt[u][i]);
		}
	}

	if ( !q.empty() ) {
		int v = q.front();
		q.pop();
		bfs(v, nxt, visited, q);
	}
}
