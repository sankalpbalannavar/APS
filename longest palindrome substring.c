#include <stdio.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    if (n < 2) {
        return s;
    }
    int maxLen = 1, start = 0;
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        if (i < n - 1 && s[i] == s[i + 1]) {
            dp[i][i + 1] = 1;
            maxLen = 2;
            start = i;
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                maxLen = len;
                start = i;
            }
        }
    }
    s[start + maxLen] = '\0';
    return s + start;
}

int main() {
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    char* result = longestPalindrome(s);
    printf("Longest Palindromic Substring: %s\n", result);
    return 0;
}