#define MXVL (1e5 + 5)
#define TYPE int

vector<TYPE> BIT(MXVL);

TYPE query(int idx) {
	TYPE sum = 0;
	while (idx > 0) {
		sum = sum + BIT[idx];
		idx = idx - (idx & -idx);
	}
	return sum;
}

void update(int idx, TYPE val) {
	while(idx <= MXVL){
		BIT[idx] = BIT[idx] + val;
		idx = idx + (idx & -idx);
	}
}

TYPE rangeQuery(int l, int r) {
	if( l > r ) return 0;
	return (query(r) - query(l-1));
}

void rangeUpdate(int l, int r, TYPE val) {
	update(l, val);
	update(r+1, -val);
}
