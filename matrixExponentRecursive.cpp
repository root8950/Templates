//MATRIX EXPONENTIATION
#define TYPE int
#define MAT vector< vector<TYPE> >

MAT matrixExponent(MAT & mat,int d,ll power,ll mod){
	MAT res=mat;
	if(power==1){
		return res;
	}

	res=matrixExponent(mat,d,power/2,mod);
		
	//squaring matrix res
	MAT sqrmtrx(d,vector<TYPE> (d,0) );
	for(int i=0;i<d;i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<d;k++){
				sqrmtrx[i][j]+=( (res[i][k]%mod) * 1LL * (res[k][j]%mod) )%mod;
			}
		}
	}
	res=sqrmtrx;
	
	if(power%2==1){
		//multiplying res and mat
		MAT mulmtrx(d,vector<TYPE> (d,0) );
		for(int i=0;i<d;i++){
			for(int j=0;j<d;j++){
				for(int k=0;k<d;k++){
					mulmtrx[i][j]+=( (res[i][k]%mod) * 1LL * (mat[k][j]%mod) )%mod;
				}
			}
		}
		res=mulmtrx;
	}
	return res;
}
