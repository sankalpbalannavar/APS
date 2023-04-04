#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* longestCommonSubstring(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int maxLen = 0, maxIndex = 0;
    int **lcs = (int **)malloc((len1+1)*sizeof(int *));
    for (int i = 0; i <= len1; i++) {
        lcs[i] = (int *)malloc((len2+1)*sizeof(int));
        for (int j = 0; j <= len2; j++) {
            if (i == 0 || j == 0) {
                lcs[i][j] = 0;
            }
            else if (str1[i-1] == str2[j-1]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
                if (lcs[i][j] > maxLen) {
                    maxLen = lcs[i][j];
                    maxIndex = i;
                }
            }
            else {
                lcs[i][j] = 0;
            }
        }
    }
    if (maxLen == 0) {
        char* empty = malloc(sizeof(char));
        empty[0] = '\0';
        return empty;
    }
    char* lcsStr = malloc((maxLen+1)*sizeof(char));
    strncpy(lcsStr, str1+(maxIndex-maxLen), maxLen);
    lcsStr[maxLen] = '\0';
    return lcsStr;
}

int main() {
    char* str1 = "ABCDGH";
    char* str2 = "ACDGHR";
    char* lcs = longestCommonSubstring(str1, str2);
    printf("Longest Common Substring: %s\n", lcs);
    free(lcs);
    return 0;
}
