/*
 * C program to count the number of bits set in an integer
 * Author: Sankalp Balannavar
 * SRN: 01FE21BCS414
 */
#include <stdio.h>

int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int num = 123; // example number
    int numSetBits = countSetBits(num);
    printf("The number of bits set in %d is %d\n", num, numSetBits);
    return 0;
}
