#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
  
  // T.C.=O(N) S.C.=O(1)
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        int sum=0;
        int i=0, j;
        int i1, i2;
        
        for(int k=0; k<n; k++){
            sum+=arr[k];
            if(sum==s) {
                return {i+1, k+1};
                
            }
            while(i<k && sum>s) {
                sum-=arr[i];
                i++;
            }
            if(sum==s) {
                return {i+1, k+1};
            }
        }
        return {-1};
    }
};
