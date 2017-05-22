//Fibonacci numbers mod N with matrix multiplication ( original matrix { {1,1} , {1,0} } )
//compatible in both C and C++

ll ** fib_mod(ll **mat, ll power, ll mod) {
	ll **res = mat;
	if (power == 1) {
		return res;
	}

	res = fib_mod(mat, power / 2, mod);
		
	//squaring matrix res
	ll a, b, c, d;
	a = res[0][0]; b = res[0][1]; c = res[1][0]; d = res[1][1];
	res[0][0] = (mul_mod(a, a, mod) + mul_mod(b, c, mod)) % mod;
	res[0][1] = (mul_mod(a, b, mod) + mul_mod(b, d, mod)) % mod;
	res[1][0] = (mul_mod(a, c, mod) + mul_mod(d, c, mod)) % mod;
	res[1][1] = (mul_mod(b, c, mod) + mul_mod(d, d, mod)) % mod;
	
	if (power % 2 == 1) {
		//multiplying res and mat
		a = res[0][0]; b = res[0][1]; c = res[1][0]; d = res[1][1];
		res[0][0] = (a + b) % mod;
		res[0][1] = a % mod;
		res[1][0] = (c + d) % mod;
		res[1][1] = c % mod;
	}
	return res;
}
