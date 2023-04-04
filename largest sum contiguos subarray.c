Title: Largest Sum Contiguous Subarray
Author: Sankalp Balannavar
SRN: 01FE21BCS414

#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int maxSubarraySum(int arr[], int n) {
    int dp[n];
    int ans = arr[0];

    dp[0] = arr[0];
    for(int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Largest Sum Contiguous Subarray is %d\n", maxSubarraySum(arr, n));
    return 0;
}