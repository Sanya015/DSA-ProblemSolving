// Recursive:  T.C.=O(2^n)
class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 1;
        if(n==1) return 1;
        int one=climbStairs(n-1);
        int two=climbStairs(n-2);
        return (one+two);
    }
};

// Memoization: T.C=O(n) S.C= O(n)+O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        if(n==0) return 1;
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int one=climbStairs(n-1);
        int two=climbStairs(n-2);
        return dp[n]=(one+two);
    }
};

// Tabulation: T.C=O(n) S.C.=O(n)
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            if(dp[i]==-1) {
                dp[i]=dp[i-1]+dp[i-2];
            }
        }
        return dp[n];
    }
};

// Reduces Space Complexity:  T.C.=O(n) S.C.=O(1)
class Solution {
public:
    int climbStairs(int n) {
        int prev=1;
        int prev1=1;
        int curr;
        for(int i=2; i<=n; i++){
            curr=prev+prev1;
            prev1=prev;
            prev=curr;
            
        }
        return prev;
    }
};
