#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
	int array[1000], i, temp;
	clock_t  t_start, t_end;
	srand((unsigned)time(NULL));//用当前时间，设置种子 
	for (i = 0; i < 1000; i ++) {
		temp = rand()%100;
		if (temp % 2) temp = -temp;
		array[i] = temp;
	}
	t_start = time((time_t*)NULL) ;
	temp = maxSubsequenceSum1(array, 1000);
	t_end = time((time_t*)NULL) ;
	printf("最大序列为:%d, 执行时间为:%d ms\n",temp, t_end - t_start);

    t_start = time((time_t*)NULL) ;
	temp = maxSubsequenceSum2(array, 1000);
	t_end = time((time_t*)NULL) ;
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
