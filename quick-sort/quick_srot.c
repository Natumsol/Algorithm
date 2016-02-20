#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../common.h"
#define CUTOFF 3
void swap(int*, int*);//交换程序
int media3(int*, int, int); // 寻找pivot
void quick_sort(int*, int, int); // 快排主程序
int * insert_sort(int*, int); // 插入排序
void print(int*, int);
void save(char*, int*, int); // 存储到文件
int main(){
    FILE * file;
    int data_size = 100000;// 测试数据的大小
    int *data = (int*) malloc(sizeof(int) * data_size),temp, i;
    time_t start, end;
    file = fopen("../src.txt", "r");
    if(file) {
        for(i = 0; i < data_size && !feof(file); i ++) {
            fscanf(file, "%d", &temp);
            data[i] = temp;
        }// 读取文件中的数据到内存
        start = clock();
        quick_sort(data, 0, data_size - 1);
        end = clock();
        printf("C语言版quick_sort: %dms\n", end - start);
        save("sorted.txt", data, data_size);
    } else {
        printf("open file src.txt error!");
    }
    getchar();
    return 0;
}

void print(int *data, int num){
    int i;
    for(i = 0; i < num; i ++){
        printf("%d ", data[i]);
    }
    printf("\n");
}

void swap(int* p, int* q) {
    int temp;
    temp = *q;
    *q = *p;
    *p = temp;
}

int media3(int *data, int left, int right){
    int center = (left + right) / 2;
    
    if(data[left] > data[center]) {
        swap(&data[left], &data[center]);
    } 
    if(data[left] > data[right]) {
        swap(&data[left], &data[right]);
    }
    if(data[center] > data[right]) {
        swap(&data[center], &data[right]);
    } // 将data[left], data[center], data[right]从小到大排好序
    
    swap(&data[center], &data[right - 1]); // 将pivot放到倒数第二个位置
    
    return data[right - 1];
    
}

void quick_sort(int* data, int left, int right){
    int pivot, i = left, j = right - 1;
    if(left + CUTOFF <= right) { // 如果所剩元素小于三个， 那么这不能利用快速排序了，因为Pivot的选取至少需要三个元素
        pivot = media3(data, left, right);
        while(1){
            while(data[++ i] < pivot) {}
            while(data[-- j] > pivot) {}
            if(i < j) {
                swap(&data[i], &data[j]);
            } else {
                break;
            }
        }
        swap(&data[i], &data[right - 1]);
        quick_sort(data, left, i - 1);
        quick_sort(data, i + 1, right);
    } else {
        insert_sort(data + left, right - left + 1 );// 对于小雨3个的元素，直接利用插入排序
    }
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