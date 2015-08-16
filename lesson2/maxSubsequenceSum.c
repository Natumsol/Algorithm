#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int array[30000], i, temp;
	clock_t  t_start, t_end;
	srand((unsigned)time(NULL));//用当前时间，设置种子 
	for (i = 0; i < 30000; i ++) {
		temp = rand()%1000;
		if (temp % 2) temp = -temp;
		array[i] = temp;
	}
	/*t_start = clock() ;
	temp = maxSubsequenceSum1(array, 3000);
	t_end = clock() ;
	printf("最大序列为:%d, 执行时间为:%d ms\n",temp, t_end - t_start);

	t_start = clock() ;
	temp = maxSubsequenceSum2(array, 3000);
	t_end = clock() ;
	printf("最大序列为:%d, 执行时间为:%d ms\n",temp, t_end - t_start);

	t_start = clock() ;
	temp = maxSubsequenceSum3(array, 300000);
	t_end = clock() ;
	printf("最大序列为:%d, 执行时间为:%d ms\n",temp, t_end - t_start);*/

	t_start = clock() ;
	temp = maxSubsequenceSum4(array, 30000);
	t_end = clock() ;
	printf("最大序列为:%d, 执行时间为:%d ms\n",temp, t_end - t_start);

	getchar();
	return 0;
}

int maxSubsequenceSum1(int A[], int N) {
	int ThisSum, MaxSum, i, j, k;
	MaxSum = 0;
	for (i = 0; i < N; i ++) {
		for (j = i; j < N; j ++) {
			ThisSum = 0;
			for (k = i; k <= j; k ++) {
				ThisSum += A[k];
			}
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int maxSubsequenceSum2(int A[], int N) {
	int ThisSum, MaxSum, i, j;
	MaxSum = 0;
	for (i = 0; i < N; i ++) {
		ThisSum = 0;
		for (j = i; j < N; j ++) {
			ThisSum += A[j];
			if (ThisSum > MaxSum)
				MaxSum = ThisSum;
		}
	}
	return MaxSum;
}

int maxSubSum(int A[], int left, int right){
	int MaxLeftSum, MaxRightSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int LeftBorderSum, RightBorerSum;
	int Center, i;
	if(left == right){
		if(A[left]  > 0)
			return A[left];
		else
			return 0;
	}
	Center = (left + right) / 2;
	MaxLeftSum = maxSubSum(A, left, Center);
	MaxRightSum = maxSubSum(A, Center + 1, right);

	MaxLeftBorderSum = 0;LeftBorderSum = 0;
	for (i = Center; i >= left; i --){
		LeftBorderSum += A[i];
		if(LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}
	MaxRightBorderSum = 0; RightBorerSum = 0;
	for (i = Center + 1; i <= right; i ++){
		RightBorerSum += A[i];
		if(RightBorerSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorerSum;
	}

	return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}
int maxSubsequenceSum3(int A[], int N) {
	return maxSubSum(A, 0, N -1);
}

int Max3(int a, int b, int c){
	int temp = a > b ? a :b;
	return temp > c ? temp : c;
}

int maxSubsequenceSum4(int A[], int N){
	int thisMax = 0, maxSum = 0, i;
	for(i = 0; i < N; i ++) {
		thisMax += A[i];
		if(thisMax > maxSum)
			maxSum = thisMax;
		else if(thisMax < 0)
			thisMax = 0;
	}
	return maxSum;
}