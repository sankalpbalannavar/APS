//Author: Sankalp Balannavar
//Date: 10-2-23
//APS problem 1: Longest Common Subsequence using dp2
//Example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

#include<stdio.h>
#include<string.h>

void main()
{
    char str1[100]="abcda",str2[100]="bdabac";
    int i,j,max,lcs[100][100];

    for(i=0;i<strlen(str1);i++)
    {
        lcs[i][0]=0; //Setting rows to 0
    }

    for(i=0;i<strlen(str2);i++)
    {
        lcs[0][i]=0; //setting columns to 0

    }

    for(i=1;i<=strlen(str1);i++)
    {
        for(j=1;j<=strlen(str2);j++)
        {
            if(str1[i-1]==str2[j-1]) //checking if the charecters from both strings match. -1 because lcs array has first element 0,ie index=1 but str1 and str2 start from 0 index.
            {
                lcs[i][j]=lcs[i-1][j-1]+1; //upper left diagonal element + 1
            }
            else
            {
                if(lcs[i-1][j]>=lcs[i][j-1])
                    max=lcs[i-1][j];
                else
                    max=lcs[i][j-1];

                lcs[i][j]=max; //checking top and left element, setting to which is larger.
            }

        }
    }

    for(i=0;i<=strlen(str1);i++)
    {
        for(j=0;j<=strlen(str2);j++)
        {
            printf("%d\t",lcs[i][j]);
        }
        printf("\n");
    }

}