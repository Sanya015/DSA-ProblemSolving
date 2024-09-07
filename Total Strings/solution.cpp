// T.C.=O(N) where n is the length of the input for the combination function S.C.=O(1)
// We take combinations ki b can be 0 to kya possibilities hain plus b=1 ke liye kya. 
long long comb(int n, int r){
    if(r==n) return 1;
    long long ans=1;
    for(int i=1; i<=r; i++){
        ans*=n-i+1;
        ans/=i;
    }
    return ans;
}
long long countStrings(int n)
{
    long long ans=0;
    ans+=(comb(n, 1)*comb(n-1, 0))+(comb(n, 1)*comb(n-1, 1))+(comb(n, 1)*comb(n-1, 2));
    ans+=(comb(n, 0)*comb(n, 0))+(comb(n, 0)*comb(n, 1))+(comb(n, 0)*comb(n, 2));
    return ans;
}

// T.C.=O(1) S.C.=O(1)
// Approach: n!/repeated ka factorial . So case all a, 1 b, 1 c, 2 c, 1b 1c, 1b 2c. So added all.
long long int countStr(long long int n){
    return (1+n+n+(n*(n-1))/2+(n*(n-1))+((n-2)*(n-1)*n)/2);

}

// DP Solution T.C.=O(6N) S.C.=O(6N)
int f(int ind, int n, int b, int c, vector<vector<vector<int>>> &dp) {
    if(ind==n) return 1;
    if(dp[ind][b][c] != -1) return dp[ind][b][c];
    int ans=0;
    if(ind < n) ans+=f(ind+1, n, b, c, dp);
    if(b>0 && ind<n) ans+=f(ind+1, n, b-1, c, dp);
    if(c>0 && ind<n) ans+=f(ind+1, n, b, c-1, dp);
    return dp[ind][b][c] = ans;
}
int countStrings(int n) {
    int b=1, c=2;
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, -1)));
    return f(0, n, b, c, dp);
}
