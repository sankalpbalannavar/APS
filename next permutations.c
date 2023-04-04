/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Next Permutation
*/

#include <stdio.h>
#include <stdlib.h>

void nextPermutation(int* nums, int numsSize) {
    int i, j, k;
    for (i = numsSize - 2; i >= 0; i--) {
        if (nums[i] < nums[i+1]) {
            break;
        }
    }
    if (i < 0) {
        for (j = 0, k = numsSize - 1; j < k; j++, k--) {
            int temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
        }
    } else {
        for (j = numsSize - 1; j > i; j--) {
            if (nums[j] > nums[i]) {
                break;
            }
        }
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        for (j = i + 1, k = numsSize - 1; j < k; j++, k--) {
            temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
        }
    }
}

int main() {
    int nums[] = {1, 2, 3};
    int numsSize = 3;
    nextPermutation(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}