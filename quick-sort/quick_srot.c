#include <stdio.h>
void swap(int*, int*);//交换程序
int media3(int*, int, int); // 寻找pivot
void quick_sort(int*, int, int); // 快排主程序
void print(int*, int);
int main(){
    int test[11] = {10, 9, 8,7,6,5,4,3,2,1,0};
    print(test, 11);
    quick_sort(test, 0, 10);
    print(test, 11);
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
    if(left < right) {
        pivot = media3(data, left, right);
        while(1){
            while(data[++ i] < pivot) {}
            while(data[-- j] > pivot) {}
            if(i < j) {
                swap(&data[i], &data[j]);
            } else {
                break;
            }
            swap(&data[i], &data[right - 1]);
            quick_sort(data, left, i - 1);
            quick_sort(data, i + 1, right);
        }
    }
}