/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Longest Palindromic Substring
*/

char * longestPalindrome(char * s){
    int n = strlen(s);
    if(n==0) return "";
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    int start = 0, end = 0, len = 1;
    for(int i=0; i<n; i++) {
        dp[i][i] = true;
    }
    for(int i=0; i<n-1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = true;
            start = i;
            end = i+1;
            len = 2;
        }
    }
    for(int l=3; l<=n; l++) {
        for(int i=0; i<n-l+1; i++) {
            int j = i + l - 1;
            if(s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                start = i;
                end = j;
                len = l;
            }
        }
    }
    char* result = (char*) malloc((len+1) * sizeof(char));
    strncpy(result, s+start, len);
    result[len] = '\0';
    return result;
}