/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Coin Change
*/

int coinChange(int* coins, int coinsSize, int amount){
    int* dp = (int*)malloc((amount+1)*sizeof(int));
    for(int i=0; i<=amount; i++) {
        dp[i] = amount+1;
    }
    dp[0] = 0;
    for(int i=0; i<=amount; i++) {
        for(int j=0; j<coinsSize; j++) {
            if(coins[j] <= i) {
                dp[i] = fmin(dp[i], 1+dp[i-coins[j]]);
            }
        }
    }
    if(dp[amount] > amount) {
        return -1;
    }
    return dp[amount];
}