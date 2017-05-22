int lis(vi &vec) {
	int n = vec.size();
	set<int> s;
	set<int>::iterator it;
	for (int i = 0; i < n; i++) {
		if (s.insert(vec[i]).sd) {
			it = s.find(vec[i]);
			it++;
			if (it != s.end()) {
				s.erase(it);
			}
		}
	}
	return s.size();
}
