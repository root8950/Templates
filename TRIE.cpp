class node {
	public:
	int nxt[2];
	vi pos;
	node() {
		nxt[0] = nxt[1] = -1;
	}
};

#define BITS 20
#define MAXVAL 1e5
vector<node> trie(MAXVAL*BITS);
