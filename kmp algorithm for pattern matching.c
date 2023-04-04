#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* computeLPS(char* pat) {
    int len = strlen(pat);
    int *lps = (int *)malloc(len*sizeof(int));
    int i = 1, j = 0;
    lps[0] = 0;
    while (i < len) {
        if (pat[i] == pat[j]) {
            j++;
            lps[i] = j;
            i++;
        }
        else {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

void KMP(char* pat, char* txt) {
    int lenPat = strlen(pat);
    int lenTxt = strlen(txt);
    int *lps = computeLPS(pat);
    int i = 0, j = 0;
    while (i < lenTxt) {
        if (pat[j] == txt[i]) {
            i++;
            j++;
        }
        if (j == lenPat) {
            printf("Pattern found at index %d\n", i-j);
            j = lps[j-1];
        }
        else if (i < lenTxt && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j-1];
            }
            else {
                i++;
            }
        }
    }
