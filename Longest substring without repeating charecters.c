/* 
   Author: Sankalp Balannavar
   SRN: 01FE21BCS414
   Title: Longest Substring Without Repeating Characters
*/

int lengthOfLongestSubstring(char * s){
    int n = strlen(s);
    if(n==0) return 0;
    int freq[256];
    memset(freq, -1, sizeof(freq));
    int start = 0, end = 0, len = 1;
    freq[s[0]] = 0;
    while(end<n-1) {
        end++;
        if(freq[s[end]] >= start) {
            start = freq[s[end]] + 1;
        }
        freq[s[end]] = end;
        len = fmax(len, end - start + 1);
    }
    return len;
}