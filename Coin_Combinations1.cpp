#include<bits/stdc++.h>
using namespace std;
#define ll long long

// Coin Combination 1 

ll coinCombination(ll k,vector<ll>c){
    ll dp[k+1];
    dp[0]=1;
    for(ll i=1;i<=k;i++){
        dp[i]=0;
        for(ll j=0j<a.size();j++){
            if((i-c[j])>=0){
                dp[i]+=dp[i-c[j]];
            }
        }
    }
    return dp[sum]%1e9+7;
}

int main(){
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<coinCombination(n,k,a);
    return 0;
}