#define FAST I/O :p

a.) //fast cin/cout

ios_base::sync_with_stdio(false);
cin.tie(NULL);

b.) //(input) using getchar_unlocked

#define gc getchar_unlocked
int rd_int() {
	char c = gc();
	while (c < '0' || c > '9') {
		c = gc();
	}
	int num = 0;
	while (c >= '0' && c <= '9') {
		num = 10 * num + c - 48;
		c = gc();
	}
	return num;
}

c.) //(intput) for negative numbers also

#define gc getchar_unlocked
int rd_int() {
	int num = 0;
	char c = gc();
	bool flag = 0;
	while (!((c >= '0' & c <= '9') || c == '-'))
		c = gc();
	if (c == '-') {
		flag = 1;
		c = gc();
	}
	while (c >= '0' && c <= '9') {
		num = (num << 1) + (num << 3) + c - '0';
		c = gc();
	}
	if (flag)
		return -num;
	return num;
}

d.) //(output)

#define pc putchar_unlocked
void wr_int(int num) {
	if (num < 0) {
		pc('-');
		num = -num;
	}
	char snum[20];
	int i = 0;
	do {
		snum[i++] = num % 10 + 48;
		num /= 10;
	} while(num);
	i--;
	while (i >= 0) {
		pc(snum[i--]);
	}
	//pc('\n');
}
