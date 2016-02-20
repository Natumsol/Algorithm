/**
*一些常用函数集合
**/
#include <stdio.h>
void save(char * name, int * data, int num) {
    FILE *file = fopen(name, "w+");
    int i;
    if(file){
        for(i = 0; i < num; i ++) {
            fprintf(file, "%d\n", data[i]);
        }
        fclose(file);
    } else {
        printf("open file %c fail!", name);
    }
}