//Factorial of a large number (n here)

#define MAX 200

vi calFact(int n) {
	vi arr(MAX, 0);
	arr[MAX-1] = 1;
	for (int j = n; j > 0; j--, n--) {
		int carry = 0;
		for (int i = MAX - 1; i >= 0; i--){
			int temp = (arr[i] * n) + carry;
			arr[i] = temp % 10;
			carry = temp / 10;
		}
	}
	return arr;
}
