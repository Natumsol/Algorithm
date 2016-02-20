/**
*C语言版本的插入排序测试
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * insert_sort(int* data, int num);
int * shell_sort(int * data, int num);
int main(){
    FILE * file;
    int data_size = 100000;// 测试数据的大小
    int *data = (int*) malloc(sizeof(int) * data_size),temp, i;
    time_t start, end;
    file = fopen("src.txt", "r");
    if(file) {
        for(i = 0; i < data_size && !feof(file); i ++) {
            fscanf(file, "%d", &temp);
            data[i] = temp;
        }// 读取文件中的数据到内存
        start = clock();
        shell_sort(data, data_size);
        end = clock();
        printf("C语言版shell_sort: %dms", end - start);
    } else {
        printf("open file src.txt error!");
    }
    getchar();
    return 0;
}

int * insert_sort(int* data, int num){
	int i,j, temp;
	for(i = 0; i < num; i ++){
		temp = data[i];
		for(j = i; j > 0 && data[j - 1] > temp; j --){
			data[j] = data[j - 1];
		}
		data[j] = temp;
	}
	return data;
}
int * shell_sort(int * data, int num){
	int i, j, increment, temp;
	for(increment = num / 2; increment > 0 ; increment = increment / 2){
		for(i = increment; i < num; i ++){
			temp = data[i];
			for(j = i; j >= increment; j -= increment){
				if(temp < data[j - increment])
					data[j] = data[j - increment];
				else
					break;
			}

			data[j] = temp;
		}
	}
	return data;
}
