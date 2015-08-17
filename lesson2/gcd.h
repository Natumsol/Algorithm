/************************************************************************/
/* 计算最大公约数                                                       */
/************************************************************************/
typedef int boolean;
#define false 0;
#define true 1;
unsigned int gcd(unsigned int M, unsigned int N){
	unsigned int rem;
	while(N > 0){
		rem = M % N;
		M = N;
		N = rem;
	}
	return M;
}

boolean isEven(unsigned int N) {
	if(N % 2)
		return false;
	return true;
}
long int Pow(long int X, unsigned int N) {
	if(N == 0)
		return 1;
	if(N == 1)
		return X;
	if(isEven(N))
		return Pow(X * X, N / 2);
		//return Pow(Pow(X, 2), N / 2); // 会陷入死循环,因为显示调用了Pow(X, 2)这句话,N 永远为2.
		//return Pow(Pow(X, N / 2), 2);//同样会陷入死循环
	else
		return Pow(X * X, N / 2) * X;
}