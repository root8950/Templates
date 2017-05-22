int N;

class cmp {
	public:
	bool operator() (const pii &a, const pii &b) {
		return a.sd > b.sd;
	}
};

// nxt stores pair of node and weight
void dijkstra(int source, vi &dis, vv(pii) &nxt) {
	for (int i = 0; i <= N; i++) {
		dis[i] = inf;
	}
	dis[source] = 0;
	priority_queue< pii, v(pii), cmp> pq;
	pq.push( {source, 0} );
	while ( !pq.empty() ) {
		pii top = pq.top();
		pq.pop();
		int u = top.ft;
		if (top.sd <= dis[u]) {
			int sz = nxt[u].size();
			for (int i = 0; i < sz; i++) {
				pii node = nxt[u][i];
				int v = node.ft;
				int w = dis[u] + node.sd;
				if (w < dis[v]) {
					dis[v] = w;
					pq.push( {v, w} );
				}
			}
		}
	}
}
