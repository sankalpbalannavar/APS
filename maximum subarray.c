/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Maximum Subarray
*/

int maxSubArray(int* nums, int numsSize){
    int max_sum = nums[0];
    int curr_sum = nums[0];
    for(int i=1; i<numsSize; i++) {
        curr_sum = fmax(nums[i], curr_sum+nums[i]);
        max_sum = fmax(max_sum, curr_sum);
    }
    return max_sum;
}