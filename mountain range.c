/*
 * C program to find the longest increasing subsequence in a mountain range
 * Author: Sankalp Balannavar
 * SRN: 01FE21BCS414
 */

#include <stdio.h>

#define MAX_SIZE 100

// Function to find the longest increasing subsequence in a mountain range
void findLongestIncreasingSubsequence(int arr[], int size) {
    int left[size], right[size], i, j, maxLength = 0, maxIndex = 0;
    // calculate the length of the longest increasing subsequence from left to right
    for (i = 0; i < size; i++) {
        left[i] = 1;
        for (j = 0; j < i; j++) {
            if (arr[j] < arr[i] && left[j] + 1 > left[i]) {
                left[i] = left[j] + 1;
            }
        }
    }
    // calculate the length of the longest increasing subsequence from right to left
    for (i = size - 1; i >= 0; i--) {
        right[i] = 1;
        for (j = size - 1; j > i; j--) {
            if (arr[j] < arr[i] && right[j] + 1 > right[i]) {
                right[i] = right[j] + 1;
            }
        }
        // calculate the length of the longest mountain range ending at index i
        if (left[i] > 1 && right[i] > 1 && left[i] + right[i] - 1 > maxLength) {
            maxLength = left[i] + right[i] - 1;
            maxIndex = i;
        }
    }
    // print the longest increasing subsequence in the mountain range
    printf("The longest increasing subsequence in the mountain range is:\n");
    for (i = maxIndex - left[maxIndex] + 1; i < maxIndex; i++) {
        printf("%d ", arr[i]);
    }
    printf("%d ", arr[maxIndex]);
    for (i = maxIndex + 1; i <= maxIndex + right[maxIndex] - 1; i++) {
        printf("%d ", arr[i]);
    }
}

// Main function
int main() {
    int arr[MAX_SIZE] = { 1, 3, 5, 4, 2 }; // input array
    int size = 5; // size of the array
    findLongestIncreasingSubsequence(arr, size);
    return 0;
}