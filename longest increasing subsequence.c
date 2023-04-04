/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Longest Increasing Subsequence
*/

int lengthOfLIS(int* nums, int numsSize){
    if(numsSize == 0) {
        return 0;
    }
    int* dp = (int*)malloc(numsSize*sizeof(int));
    dp[0] = 1;
    int max_ans = 1;
    for(int i=1; i<numsSize; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(nums[i] > nums[j]) {
                dp[i] = fmax(dp[i], dp[j]+1);
            }
        }
        max_ans = fmax(max_ans, dp[i]);
    }
    return max_ans;
}