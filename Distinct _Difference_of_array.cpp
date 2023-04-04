//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/c670bf260ea9dce6c5910dedc165aa403f6e951d/1
// Distinct Difference

// Given an array A[] of length N. For each index i (1<=i<=N), 
// find the diffference between the number of distinct element
// in it's left and right side in the array.

class Solution {
  public:
    // vector<int> getDistinctDifference(int n, vector<int> &ar) {
    //     unordered_map<int,int>left,right;
    //     unordered_set<int>a,b;
    //     for(int i=0;i<n;i++){
    //         left[i]=a.size();
    //         right[n-i-1]=b.size();
    //         a.insert(ar[i]);
    //         b.insert(ar[n-i-1]);
    //     }
    //     for(int i=0;i<n;i++){
    //         ar[i]=left[i]-right[i];
    //     }
    //     return ar;
    // }
    
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        vector<int> m1(N);
        unordered_set<int> s1;
        for(int i=0; i<N; i++){
            m1[i] = s1.size();
            s1.insert(A[i]);
        }
        s1.clear();
        for(int i=N-1; i>=0; i--){
            m1[i] = m1[i]-s1.size();
            s1.insert(A[i]);
        }
        return m1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends