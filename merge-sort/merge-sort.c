/**
*C语言版本的插入排序测试
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void merge_sort(int * data, int num); 
void m_sort(int * data, int * datatemp, int left, int right);
void merge(int * data, int * dataTemp, int left, int leftEnd, int rightEnd);
void print(int * data, int num);
int * insert_sort(int* data, int num);
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
        merge_sort(data, data_size);
        end = clock();
        printf("C语言版merge_sort: %dms", end - start);
    } else {
        printf("open file src.txt error!");
    }
    getchar();
    return 0;
}


void merge_sort(int * data, int num){
    int * dataTemp = (int *) malloc(sizeof(int) * num);
    if(dataTemp != NULL) {
        m_sort(data, dataTemp, 0, num - 1);
    } else {
        printf("No Space For dataTemp!");
    }
}

void m_sort(int * data, int * dataTemp, int left, int right) {
    int center;
    if(left < right) {
        center = (left + right) / 2;
        m_sort(data, dataTemp, left, center);
        m_sort(data, dataTemp, center + 1, right);
        merge(data, dataTemp, left, center + 1, right);
    }
}

void merge(int * data, int *dataTemp, int leftPos, int rightPos, int rightEnd){
    int leftEnd = rightPos - 1,
        tempPos = leftPos, 
        i,
        total = (rightEnd - leftPos + 1);
        
    while(leftPos <= leftEnd && rightPos <= rightEnd) {
        if(data[leftPos] < data[rightPos]) {
            dataTemp[tempPos ++] = data[leftPos ++];
        } else {
            dataTemp[tempPos ++] = data[rightPos ++];
        }
    }
    
    while(leftPos <= leftEnd) {
        dataTemp[tempPos ++] = data[leftPos ++];
    }
    
    while(rightPos <= rightEnd) {
         dataTemp[tempPos ++] = data[rightPos ++];
    }
    
    for(i = 0; i < total; i ++, rightEnd --) {
        data[rightEnd] = dataTemp[rightEnd];
    }
}

void print(int * data, int num){
    int i;
    for(i = 0; i < num; i ++) {
        printf("%d ", data[i]);
    }
    printf("\n");
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