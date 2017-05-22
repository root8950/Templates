//////////////////////////////////////////////////////////////////////////SEGMENT TREE//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////Range Query, Range Update///////////////////////////////////////////////////////////////////////

class node {
	public:
	//variables
	node() {//initialise
	}
};

#define SEGTREEsize (4e5 + 5)
vector<node> tree(SEGTREEsize);
vector<int> lazy(SEGTREEsize);

node merge(node a, node b) {
	node tmp;
	//merging logic
	return tmp;
}

void lazy_prop(int idx, int st, int ed) {
	if (lazy[idx] == ) {//if marked
		tree[idx] = ;//update node
		if (st != ed) {//if not tree node, mark children lazy
			lazy[lft] = ;
			lazy[rgt] = ;
		}
		lazy[idx] = 0;//unmark lazy
	}
}

void build(vi &vec, int idx, int st, int ed) {
	if (st == ed) {
		tree[idx] = vec[st];//initialise node
	}
	else {
		int mid = ((st + ed) >> 1);
		build(vec, cllft);
		build(vec, clrgt);
		tree[idx] = merge(tree[lft], tree[rgt]);
	}
}

node query(int idx, int st, int ed, int l, int r) {
	node tmp;
	if (st > ed || st > r || ed < l) return tmp;//Out of range        <--------------- dont forget it
	lazy_prop(idx, st, ed);
	if (st >= l && ed <= r) {
		return tree[idx];
	}
	int mid = ((st + ed) >> 1);
	return merge(query(cllft, l, r), query(clrgt, l, r));
}

void update(int idx, int st, int ed, int l,int r, int new_val) {
	lazy_prop(idx, st, ed);
	if (st > ed || st > r || ed < l) return;//Out of range
	if (st >= l && ed <= r) {
		tree[idx] = ;//update node
		if (st != ed) {//mark children lazy
			lazy[lft] = ;
			lazy[rgt] = ;
		}
	}
	else {
		int mid = ((st + ed) >> 1);
		update(cllft, l, r, new_val);
		update(clrgt, l, r, new_val);
		tree[idx] = merge(tree[lft], tree[rgt]);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
