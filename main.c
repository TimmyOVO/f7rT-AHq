#include "main.h"

int main() {
    int item;
    printf("菜单:\n");
    printf("1.鸡兔同笼问题\n");
    printf("2.求范围内完美数问题\n");
    printf(">");
    scanf("%d",&item);
    if(item == 1){
        int head,foot;
        printf("请输入头的数量: \n");
        printf(">");
        scanf("%d",&head);
        printf("请输入脚的数量: \n");
        printf(">");
        scanf("%d",&foot);
        if (head <=0 || foot <= 0){
            printf("输入数量错误，请检查输入!");
            return 0x02;
        }
        int* rr = ChickenAndRabbitInSingleCage(head,foot);
        if (rr != NULL){
            printf("鸡的数量: %d,兔子的数量: %d \n",*rr,*(rr+1));
            free(rr);
            rr = NULL;
        } else{
            printf("无法求出结果，结果不存在！");
            return 0x03;
        }
    }
    if (item == 2){
        int upperBound,lowerBound;
        printf("请输入所求完美数的范围上限: \n");
        printf(">");
        scanf("%d",&upperBound);
        printf("请输入所求完美数的范围下限: \n");
        printf(">");
        scanf("%d",&lowerBound);
        if (lowerBound <1 || upperBound>1000){
            printf("输入的范围有误，请检查输入！");
            return 0x04;
        }
        if (lowerBound >= upperBound){
            printf("输入的范围不包含符合要求的任何值，请检查输入！");
            return 0x05;
        }

        struct FlexibleIntArray* allPerfectNumbers = AllPerfectNumberInRange(upperBound,lowerBound);
        if (allPerfectNumbers->numbers_size == 0 ){
            printf("无法找到任何在此范围内的完美数!");
        } else {
            for (int i = 0; i < allPerfectNumbers->numbers_size; ++i) {
                printf("%d\n",allPerfectNumbers->numbers[i]);
            }
        }
    }
    return 0;
}

int* ChickenAndRabbitInSingleCage(int head,int foot){
    for (int i = 0; i < head; ++i) {
        int footSum = i*4 + ((head-i)*2);
        if (footSum== foot) {
            int* r = malloc(2*sizeof(int));
            *r = head-i;
            *(r+1) = i;
            return r;
        }
    }
    return NULL;
}

struct FlexibleIntArray* AllPerfectNumberInRange(int upperBound,int lowerBound){
    int size = 0;
    int data[1] = {};
    struct FlexibleIntArray* result = newFlexibleIntArray(size,data);
    for (int j = lowerBound; j < upperBound; ++j) {
        int sum = 0;
        for (int k = 1; k < j; ++k) {
            if (j % k == 0){
                sum += k;
            }
        }
        if (sum == j){
            result = add(result,j);
        }
    }
    return result;
}

int FactorSum(int i) {
    int sum = 0;
    for (int k = 1; k < i; ++k) {
        if (i % k == 0){
            sum += k;
        }
    }
    return sum;
}