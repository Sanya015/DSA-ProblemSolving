class Solution {
public:

// RECURSIVE: T.C.=O(N)+O(2^N) S.C.=O(N)
    bool solve(vector<int>& nums, int index, int target){
        if(target==0) return true;
        if(index==0) return (target==nums[0]);
        bool ntake=solve(nums, index-1, target);
        bool take=false;
        if(nums[index]<=target) take=solve(nums, index-1, target-nums[index]);
        return take|ntake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        return solve(nums, n-1, sum/2);
    }
};

// MEMOIZATION: T.C.=O(N)+O(NK) S.C.=O(NK)+O(N)
    bool solve(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if(target==0) return true;
        if(index==0) return (target==nums[0]);
        if(dp[index][target]!=-1) return dp[index][target];
        bool ntake=solve(nums, index-1, target, dp);
        bool take=false;
        if(nums[index]<=target) take=solve(nums, index-1, target-nums[index], dp);
        return dp[index][target]=take|ntake;
    }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        vector<vector<int>> dp(n, vector<int>(sum/2+1, -1));
        return solve(nums, n-1, sum/2, dp);
    }
};

// TABULATION: T.C.=O(N)+O(NK) S.C.=O(NK)
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<vector<bool>> dp(n, vector<bool>(target+1, 0));
        for(int i=0; i<n; i++){
            dp[i][0]=true;
        }
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool ntake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j) take=dp[i-1][j-nums[i]];
                dp[i][j]=take|ntake;
            }
        }
        return dp[n-1][target];
    }
};


// SPACE OPTIMIZATION: T.C.=O(N)+O(NK) S.C.=O(K)
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<int> pre(target+1, 0), cur(target+1, 0);
        for(int i=0; i<n; i++){
            pre[0]=true;
        }
        if(nums[0]<=target) pre[nums[0]]=true;
        for(int i=1; i<n; i++){
            for(int j=1; j<=target; j++){
                bool ntake=pre[j];
                bool take=false;
                if(nums[i]<=j) take=pre[j-nums[i]];
                cur[j]=take|ntake;
            }
            pre=cur;
        }
        return pre[target];
    }
};
