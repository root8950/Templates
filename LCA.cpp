//////////////////////////////////////////////////////////////////Lowest Common Ancestor////////////////////////////////////////////////////////////////////////////
// 0-based
#define MXNODES 1025
vi p(MXNODES);
vvi ancestor(MXNODES, vi(log2(MXNODES) + 1) );
vi level(MXNODES);

void initialiseLevel(int n, vvi &nxt) {
	for (int i = 0; i < n; i++) {
		p[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		int sz = nxt[i].size();
		for (int j = 0; j < sz; j++) {
			p[nxt[i][j]] = i;
		}
	}
	//finding the root
	int rt;
	for (int i = 0; i < n; i++) {
		if (p[i] == -1){
			rt = i;
			break;
		}
	}

	//intialising level
	for (int i = 0; i < n; i++) {
		level[i] = -1;
	}
	
	//bfs
	queue<int> q;
	q.push(rt);
	level[rt] = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		int sz = nxt[u].size();
		for (int i = 0; i < sz; i++) {
			int v = nxt[u][i];
			if (level[v] == -1) {
				level[v] = level[u] + 1;
				q.push(v);
			}
		}
	}
}

void preProcessLCA(int n, vvi &nxt) {
	initialiseLevel(n, nxt);
	//initialising ancestor
	for (int i = 0; i < n; i++) {
		for (int j = 0; (1 << j) < n; j++) {
			ancestor[i][j] = -1;
		}
	}
	//initialising the first ancestor ie parent
	for (int i = 0; i < n; i++) {
		ancestor[i][0] = p[i];
	}
	//initialising ancestors at 2^j
	for (int j = 1; (1 << j ) < n; j++) {
		for (int i = 0; i < n; i++) {
			if (ancestor[i][j-1] != -1) {
				ancestor[i][j] = ancestor[ ancestor[i][j-1] ][j-1]; 
			}
		}
	}
}

int query(int n, int x, int y) {
	//if x and y not at same level
	if (level[x] < level[y]) {// if x is at higher level than y
		swap(x,y);
	}

	// lg = [log2[level[x]]
	int lg = 1;
	for (lg = 1; (1 << lg) <= level[x]; lg++);
	lg--;

	// find ancestor of x at level of y
	for (int i = lg; i >= 0; i--) {
		if ((level[x] - (1 << i)) >= level[y]) {
			x = ancestor[x][i];
		}
	}

	if (x == y) return x;

	for (int i = lg; i >= 0; i--) {
		if (ancestor[x][i] != -1 && ancestor[x][i] != ancestor[y][i]){
			x = ancestor[x][i];
			y = ancestor[y][i];
		}
	}
	return p[x];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
