vi squareNum(int n) {	
	vi arr(MAX, 0);
	arr[MAX - 1] = 1;
	for (int j = n; j > 0; j--) {
		int carry = 0;
		int temp;
		for (int i = MAX - 1; i >= 0; i--) {
			temp = ((arr[i] >> 1) + carry);
			arr[i] = temp % 10;
			carry = temp / 10;
		}
	}
	/*prinitng here
	int idx = 0;
	while (arr[idx] == 0) idx++;
	for (int i = idx; i < MAX; i++) cout << arr[i];
	cout << "\n";*/
	return arr;
}
