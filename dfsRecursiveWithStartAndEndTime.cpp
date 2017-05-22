#define MXNODES (1e5 + 5)
int _time = 0;
vector<bool> visited(MXNODES);
vi st(MXNODES), ed(MXNODES), parent(MXNODES);
vi dfstree(MXNODES+MXNODES);

void dfs(int u, int v, vvi &nxt) {
	parent[u] = v;
	dfstree[_time] = u;
	st[u] = _time++;
	visited[u] = 1;
	int sz = nxt[u].size();
	for (int i = 0; i < sz; i++) {
		if (visited[nxt[u][i]] == 0) {
			dfs(nxt[u][i], u, nxt);
		}
	}
	dfstree[_time] = u;
	ed[u] = _time++;
}
