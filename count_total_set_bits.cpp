//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// https://practice.geeksforgeeks.org/problems/count-total-set-bits-1587115620/1

// Count total set bits in an array
// You are given a number N. 
// Find the total count of set bits 
// for all numbers from 1 to N(both inclusive).

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if(n<=1)
         return n;
        int x = log2(n);
        
        return (pow(2,x-1)*x)+(n-pow(2,x)+1)+countSetBits(n-pow(2,x));
        
        // int temp,count=0;
        // for(int i=1;i<=n;i++){
            // temp=i;
            // while(temp){
            //     temp&=(temp-1);
            //     count++;
            // }
            
            // count+=__builtin_popcount(i);
            
            // temp=i;
            // while(temp){
            //     count+=temp&1;
            //     temp>>=1;
            // }
        // }
        // return count;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}

// } Driver Code Ends