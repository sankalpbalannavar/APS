//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// https://practice.geeksforgeeks.org/problems/anagram-1587115620/1
// https://leetcode.com/problems/valid-anagram/description/

// 2 string Anagram
//Function is to check whether two strings are anagram of each other or not.
class Solution
{
    public:
    bool isAnagram(string a, string b){
        if(a.size()!=b.size())
            return false;
        map<char,int>m1,m2;
        for(int i=0;i<a.size();i++)
            m1[a[i]]++;
        for(int i=0;i<b.size();i++)
            m2[b[i]]++;
        for(auto it=m1.begin();it!=m1.end();it++){
            if(m2.find(it->first)!=m2.end()){
                if(m2[it->first]!=(it->second))
                    return false;
            }
            else
                return false;
        }
        return true;
        
        
        // // sorting approach
        
        // sort(a.begin(),a.end());
        // sort(b.begin(),b.end());
    
        // if(a==b)
            // return true;
        // else
            // return false;
            
            
        // // hashing or easy map approach
        
        // vector<int>v(26,0);
    
        // for(int i=0;i<a.size();i++)
        // {
        //     v[a[i]-'a']++;
        // }
        
        // for(int i=0;i<b.size();i++)
        // {
        //     v[b[i]-'a']--;
        // }
        
        // for(int i=0;i<26;i++)
        // {
        //     if(v[i]!=0)
        //     return false;
        // }
        
        // return true;
        
    }
    


};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends