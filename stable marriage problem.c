/*
 * C program to solve the Stable Marriage problem using the Gale-Shapley algorithm
 * Author: Sankalp Balannavar
 * SRN: 01FE21BCS414
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

// Function to find index of the first unengaged person in an array of booleans
int findUnengaged(bool engaged[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (!engaged[i]) {
            return i;
        }
    }
    return -1; // everyone is engaged
}

// Function to check if a man prefers one woman over another
bool prefers(int man, int woman, int rank[MAX_SIZE][MAX_SIZE], int womanPartner[MAX_SIZE], int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (rank[man][i] == woman) {
            return true;
        }
        if (rank[man][i] == womanPartner[man]) {
            return false;
        }
    }
    return false; // should never happen
}

// Function to solve the Stable Marriage problem using the Gale-Shapley algorithm
void solveStableMarriage(int menPref[MAX_SIZE][MAX_SIZE], int womenPref[MAX_SIZE][MAX_SIZE], int size) {
    bool engaged[MAX_SIZE] = { false }; // initially no one is engaged
    int womanPartner[MAX_SIZE] = { -1 }; // initially all women are single
    int i, j;
    while ((i = findUnengaged(engaged, size)) != -1) { // while there is an unengaged man
        for (j = 0; j < size && !engaged[i]; j++) { // for each woman
            int woman = menPref[i][j];
            if (womanPartner[woman] == -1) { // woman is single
                womanPartner[woman] = i;
                engaged[i] = true;
            } else if (prefers(i, woman, womenPref, womanPartner, size)) { // woman prefers new man
                engaged[womanPartner[woman]] = false;
                womanPartner[woman] = i;
                engaged[i] = true;
            }
        }
    }
    // print the stable marriages
    printf("Stable marriages are:\n");
    for (i = 0; i < size; i++) {
        printf("Woman %d is married to Man %d\n", i, womanPartner[i]);
    }
}

// Main function
int main() {
    int menPref[MAX_SIZE][MAX_SIZE] = {
        { 0, 1, 2, 3 }, // preferences of men for women
        { 1, 0, 3, 2 },
        { 1, 2, 3, 0 },
        { 0, 2, 1, 3 }
    };
    int womenPref[MAX_SIZE][MAX_SIZE] = {
        { 2, 3, 0, 1 }, // preferences of women for men
        { 0, 1, 2, 3 },
        { 3, 2, 1, 0 },
        { 1, 0, 3, 2 }
    };
    int size = 4; // number of men/women
    solveStableMarriage(menPref, womenPref, size);
    return 0;