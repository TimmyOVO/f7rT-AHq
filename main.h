#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FlexibleIntArray {
    size_t numbers_size;
    int numbers[];
};

int FactorSum(int i);
int* ChickenAndRabbitInSingleCage(int head,int foot);
struct FlexibleIntArray* AllPerfectNumberInRange(int upperBound,int lowerBound);

struct FlexibleIntArray* newFlexibleIntArray(int size, const int *data){
    struct FlexibleIntArray *perfectNumbers = malloc(sizeof(struct FlexibleIntArray) + sizeof(int) * size);
    perfectNumbers->numbers_size = size;
    for (size_t i = 0; i < size; ++i) {
        perfectNumbers->numbers[i] = data[i];
    }
    return perfectNumbers;
}

struct FlexibleIntArray* add(struct FlexibleIntArray* structFlexibleIntArray,int element){
    size_t new_size = structFlexibleIntArray->numbers_size+1;
    int *new_array = (int*)malloc(sizeof(int)*new_size);
    for (int i = 0; i < structFlexibleIntArray->numbers_size; ++i) {
        new_array[i] = structFlexibleIntArray->numbers[i];
    }
    new_array[structFlexibleIntArray->numbers_size] = element;
    free(structFlexibleIntArray);
    return newFlexibleIntArray(new_size,new_array);
}

void printFlexibleIntArray(struct FlexibleIntArray* structFlexibleIntArray){
    printf("size: %zu\n",structFlexibleIntArray->numbers_size);
    for (int i = 0; i < structFlexibleIntArray->numbers_size; ++i) {
        printf("data: %d\n",structFlexibleIntArray->numbers[i]);
    }
}
