int n;

void initialiseDSU(vector< pii > &dsu) {
	for (int i = 0; i < n; i++){
		dsu = {i, 0};
	}
}

int _find(int x, vector< pii > &dsu) {//ft stores parent, sd stores rank
	if(dsu[x].ft != x){
		dsu[x].ft = _find(dsu[x].ft, dsu);
	}
	return dsu[x].ft;
}
 
void _union(int x, int y, vector< pii > &dsu) {//initially each node is parent of itself and rank is 0.
	int a = _find(x, dsu);
	int b = _find(y, dsu);
	if (a == b)
		return;
	if (dsu[a].sd < dsu[b].sd)
		dsu[a].ft = b;
	else if (dsu[a].sd > dsu[b].sd)
		dsu[b].ft = a;
	else {
		dsu[a].ft = b;
		dsu[b].sd++;
	}
}
