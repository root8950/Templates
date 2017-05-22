//////////////////////////////////////////////////////////////////////MAX FLOW - PUSH REALBEL///////////////////////////////////////////////////////////////////////

// Adjacency list implementation of FIFO push relabel maximum flow
// with the gap relabeling heuristic.  This implementation is
// significantly faster than straight Ford-Fulkerson.  It solves
// random problems with 10000 vertices and 1000000 edges in a few
// seconds, though it is possible to construct test cases that
// achieve the worst-case.
//
// Running time:
//     O(|V|^3)
//
// INPUT: 
//     - graph, constructed using AddEdge()
//     - source
//     - sink
//
// OUTPUT:
//     - maximum flow value
//     - To obtain the actual flow values, look at all edges with
//       capacity > 0 (zero capacity edges are residual edges).


class Edge {
	public:
	int from, to, cap, flow, index;
	//constructor
	Edge(int init_from, int init_to, int init_cap, int init_flow, int init_index) {
		tie(this->from, this->to, this->cap, this->flow, this->index) = mt(init_from, init_to, init_cap, init_flow, init_index);
	}
};

class PushRelabel {
	public:
	int N;
	vector< vector<Edge> > G;
	vll excess;
	vi dist, count;
	vector<bool> active;
	queue<int> Q;
	
	PushRelabel(int n) {
		(this->N) = n;
		(this->G).resize(N);
		(this->excess).resize(N);
		(this->dist).resize(N);
		(this->active).resize(N);
		(this->count).resize(N + N);
	}

	void AddEdge(int from, int to, int cap) {
		G[from].pb(Edge(from, to, cap, 0, G[to].size()));
		if (from == to) {
			G[from].back().index++;
		}
		G[to].pb(Edge(to, from, 0, 0, G[from].size() - 1));
	}

	void Enqueue(int v) {
		if (!active[v] && excess[v] > 0) {
			active[v] = true;
			Q.push(v);
		}
	}

	void Push(Edge &e) {
		int amt = (int)(min(excess[e.from], (ll)(e.cap - e.flow)));
		if ((dist[e.from] <= dist[e.to]) || (amt == 0)) return;
		e.flow += amt;
		G[e.to][e.index].flow -= amt;
		excess[e.to] += amt;
		excess[e.from] -= amt;
		Enqueue(e.to);
	}

	void Gap(int k) {
		for (int v = 0; v < N; v++) {
			if (dist[v] < k) {
				continue;
			}
			count[dist[v]]--;
			dist[v] = max(dist[v], N + 1);
			count[dist[v]]++;
			Enqueue(v);
		}
	}
	
	void Relabel(int v) {
		count[dist[v]]--;
		dist[v] = N + N;
		int sz = G[v].size();
		for (int i = 0; i < sz; i++) {
			if (G[v][i].cap - G[v][i].flow > 0) {
				dist[v] = min(dist[v], dist[G[v][i].to] + 1);
			}
		}
		count[dist[v]]++;
		Enqueue(v);
	}
	
	void Discharge(int v) {
		int sz = G[v].size();
		for (int i = 0; excess[v] > 0 && i < sz; i++) {
			Push(G[v][i]);
		}
		if (excess[v] > 0) {
			if (count[dist[v]] == 1){
				Gap(dist[v]);
			}
			else{
				Relabel(v);
			}
		}
	}
	
	ll GetMaxFlow(int s, int t) {
		count[0] = N - 1;
		count[N] = 1;
		dist[s] = N;
		active[s] = active[t] = true;
		int sz = G[s].size();
		for (int i = 0; i < sz; i++) {
			excess[s] += G[s][i].cap;
			Push(G[s][i]);
		}
		
		while (!Q.empty()) {
			int v = Q.front();
			Q.pop();
			active[v] = false;
			Discharge(v);
		}
		
		ll totflow = 0;
		sz = G[s].size();
		for (int i = 0; i < sz; i++) {
			totflow += G[s][i].flow;
		}
		return totflow;
  	}
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
