// space optimized solution rather than dp
// similar to max sum of non adj elements, just that here we passed to arrays one without 1st element and other without last element
//S.C.=O(N) T.C.=O(N)

#include <bits/stdc++.h>

long long int solve(vector<int>& val){
    long long int prev=val[0];
    long long int prev2;
    long long int curr;
    long long int inc, ninc;
    for(int i=1; i<val.size(); i++){
        inc=val[i];
        if(i>1) inc+=prev2;
        ninc=prev;
        curr=max(inc, ninc);
        prev2=prev;
        prev=curr;
    }
    return prev;

}

long long int houseRobber(vector<int>& valueInHouse)
{
    vector<int> temp1;
    vector<int> temp2;
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    for(int i=0; i<n; i++){
        if(i!=0) temp1.push_back(valueInHouse[i]);
        if(i!=n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(solve(temp1), solve(temp2));
}
