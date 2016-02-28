#include <stdio.h>
#include <stdlib.h>

typedef int bool;

#define true 1
#define false 0

int compare(const void* a, const void* b){
    return *(int *)a - *(int *)b;
}
bool containsDuplicate(int* nums, int numsSize) {
    if(numsSize < 2)
        return false;
    qsort(nums, numsSize, sizeof(nums[0]), compare);

    for(int i = 0; i < numsSize; ++i)
        printf("%d ", nums[i]);
    printf("\n");

    for(int i = 0; i < numsSize-1; ++i){
        if(nums[i] == nums[i+1])
            return true;
    }
    return false;
}

int main()
{
    int a[] = {3,3};
    if(containsDuplicate(a, 2))
        printf("hl\n");
    else
        printf("err\n");
}
