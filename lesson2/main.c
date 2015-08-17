#include <stdio.h>;
#include "maxSubsequenceSum.h"
#include "binary_search.h"
#include "gcd.h"
/************************************************************************/
/* �������                                                                     */
/************************************************************************/
int main() {
	//testMaxSubSequenceSum();
	//testBinarySearch();
	printf("%d", Pow(2, 2));
	getchar();
	return 0;
}

int testMaxSubSequenceSum(){
	int array[30000], i, temp;
	clock_t  t_start, t_end;
	srand((unsigned)time(NULL));//�õ�ǰʱ�䣬�������� 
	for (i = 0; i < 30000; i ++) {
		temp = rand()%1000;
		if (temp % 2) temp = -temp;
		array[i] = temp;
	}
	/*t_start = clock() ;
	temp = maxSubsequenceSum1(array, 3000);
	t_end = clock() ;
	printf("�������Ϊ:%d, ִ��ʱ��Ϊ:%d ms\n",temp, t_end - t_start);

	t_start = clock() ;
	temp = maxSubsequenceSum2(array, 3000);
	t_end = clock() ;
	printf("�������Ϊ:%d, ִ��ʱ��Ϊ:%d ms\n",temp, t_end - t_start);*/

	t_start = clock() ;
	temp = maxSubsequenceSum3(array, 30000);
	t_end = clock() ;
	printf("�������Ϊ:%d, ִ��ʱ��Ϊ:%d ms\n",temp, t_end - t_start);

	t_start = clock() ;
	temp    = maxSubsequenceSum4(array, 30000);
	t_end   = clock() ;
	printf("�������Ϊ:%d, ִ��ʱ��Ϊ:%d ms\n",temp, t_end - t_start);

	getchar();
	return 0;
}

int testBinarySearch(){
	ElementType A[1000];
	int i = 0, N = 512;
	for(i; i < 1000; i ++) {
		A[i] = i;
	}
	printf("�� %d ������A�е�λ����: %d", N, binarySearch(A, N, 1000));
	return 0;
}