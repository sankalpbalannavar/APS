/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Edit Distance
*/

int minDistance(char * word1, char * word2){
    int m = strlen(word1), n = strlen(word2);
    int** dp = (int**)malloc((m+1)*sizeof(int*));
    for(int i=0; i<=m; i++) {
        dp[i] = (int*)malloc((n+1)*sizeof(int));
    }
    for(int i=0; i<=m; i++) {
        dp[i][0] = i;
    }
    for(int j=0; j<=n; j++) {
        dp[0][j] = j;
    }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(word1[i-1] == word2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = fmin(fmin(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
            }
        }
    }
    return dp[m][n];
}