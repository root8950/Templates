//////////////////////////////////////////////////////////////////////////SEGMENT TREE//////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////Range Query, Point Update///////////////////////////////////////////////////////////////////////

class node {
	public:
	//variables
	node() {//initialise
	}
};

#define SEGTREEsize (4e5 + 4)
vector<node> tree(SEGTREEsize);

node merge(node a, node b) {
	node tmp;
	//merging logic
	return tmp;
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
	if (st >= l && ed <= r) {
		return tree[idx];
	}
	int mid = ((st + ed) >> 1);
	return merge(query(cllft, l, r) , query(clrgt, l, r));
}

void update(int idx, int st, int ed, int pos, int new_val) {
	if (st == ed) {
		tree[idx] = ;//update node
	}
	else {
		int mid = ((st + ed) >> 1);
		if (pos <= mid) {
			update(cllft, pos, new_val);
		}
		else {
			update(clrgt, pos, new_val);
		}
		tree[idx] = merge(tree[lft], tree[rgt]);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
