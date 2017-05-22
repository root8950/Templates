////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class node {
	public:
	bool mark;
	map<char, int> nxt;
	node() {
		mark = 0;
	}
};

int idx = 0;
#define sz (1e5 + 5)
vector< node > trie(sz);

void addWord(string &str) {
	int l = str.length();
	int cur = 0;
	for (int i = 0; i < l; i++) {
		if (trie[cur].nxt[str[i]] == 0) {
			node tmp;
			trie.pb(tmp);
			idx++;
			trie[cur].nxt[str[i]] = idx;
			cur = idx;
		}
		else {
			cur = trie[cur].nxt[str[i]];
		}
	}
}

void buildSuffixTree(string &str) {
	string suff = "";
	node tmp;
	trie.pb(tmp);
	int l = str.length();
	for (int i = l - 1; i >= 0; i--) {
		suff = str[i] + suff;
		addWord(suff);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
