#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int* twoSum(int* nums, int numsSize, int target);
int main(){
	int nums[5] = {1, 2, 3, 4, 5};
	int start, end
	int *p;
	start = clock();
	p = twoSum(nums, 16204, 16021);
	end = clock();
	printf("”√ ±:%d", end - start);
	getchar();
	return 0;
}
/**
* Note: The returned array must be malloced, assume caller calls free().
*/
int* twoSum(int* nums, int numsSize, int target) {
	int * p = (int *)malloc(sizeof(int) * 2), i, j;

	for(i = 0; i < numsSize; i ++) {
		for(j = i + 1; j < numsSize; j ++) {
			if(nums[i] + nums[j] == target){
				*p = i + 1;
				*(p + 1) = j + 1;
				break;
			}
		}
	}
	return p;
}