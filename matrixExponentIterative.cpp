//MATRIX EXPONENTIATION
#define TYPE int
#define MAT vector< vector<TYPE> >

MAT exponent(MAT &a, int d, ll b, ll mod) {
	MAT x(d, vector<TYPE> (d, 0) );
	MAT y(d, vector<TYPE> (d) );
	for (int i = 0; i < d; i++) {
		x[i][i] = 1;
	}
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			y[i][j] = a[i][j];
		}
	}
	while (b > 0) {
		if (b & 1) {
			//multiplying x and y
			MAT mulmtrx(d, vector<TYPE> (d, 0) );
			for (int i = 0; i < d; i++) {
				for (int j = 0; j < d; j++) {
					for (int k = 0; k < d; k++) {
						mulmtrx[i][j] += (x[i][k] * 1LL * y[k][j]) % mod;
					}
				}
			}
			x = mulmtrx;
		}
		//squaring matrix y
		MAT sqrmtrx(d, vector<TYPE> (d, 0) );
		for (int i = 0; i < d; i++) {
			for (int j = 0; j < d; j++) {
				for (int k = 0; k < d; k++) {
					sqrmtrx[i][j] += (y[i][k] * 1LL * y[k][j]) % mod;
				}
			}
		}
		y = sqrmtrx;
		b = (b >> 1);
	}
	return x;
}
