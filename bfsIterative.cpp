void bfs (int start, int n, vvi &nxt) {
	vector<bool> visited(n + 1, 0);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while( !q.empty() ){
		int u = q.front();
		q.pop();
		int sz = nxt[u].size();
		for (int i = 0; i < sz; i++) {
			int v = nxt[u][i];
			if(visited[v] == 0) {
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}
