//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/839d6ba2c2e4c669ba9d9d9f32ad20118937284e/1

// Count the Substrings

// Given a string S. 
// The task is to count the number of substrings 
// which contains equal number of lowercase and uppercase letters. 

class Solution
{
    public:
    int countSubstring(string s)
    {
        map<int,int>m;
        int c=0,result=0;
        for(int i=0;i<s.size();i++){
            if(s[i]>='A' && s[i]<='Z')
                c++;
            else
                c--;
            if(c==0)
                result++;
            if(m.find(c)!=m.end())
                result+=m[c];
            m[c]++;
        }
        return result;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends