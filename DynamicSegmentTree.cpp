////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct node {
	int sm;
	node *left, *right;
	node() {
		sm = 0;
		left = NULL;
		right = NULL;
	}
};

int query(node *idx, int st, int ed, int l, int r) {
	if (idx == NULL || st > ed || st > r || ed < l) return 0;//Out of range        <--------------- dont forget it
	if (st >= l && ed <= r) {
		return (idx -> sm) % MOD;
	}
	int mid = ((st*1LL + ed) >> 1);
	if (idx -> left == NULL && idx -> right == NULL) return 0;
	else if (idx -> left == NULL) return query(idx -> right, mid + 1, ed, l, r);
	else if (idx -> right == NULL) return query(idx -> left, st, mid, l, r);
	return (query(idx -> left, st, mid, l, r) + query(idx -> right, mid + 1, ed, l, r)) % MOD;
}

void update(node *idx, int st, int ed, int pos, int val) {
	if (st == ed) {
		(idx -> sm) = (idx -> sm + val) % MOD;//update node
	}
	else {
		int mid = ((st*1LL + ed) >> 1);
		if (idx -> left == NULL) idx -> left = new node();
		if (idx -> right == NULL) idx -> right = new node();
		if (pos <= mid) {
			update(idx -> left, st, mid, pos, val);
		}
		else {
			update(idx -> right, mid + 1, ed, pos, val);
		}
		idx -> sm = ((idx -> left) -> sm + (idx -> right) -> sm) % MOD;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
