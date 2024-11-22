// my recursive solution approach
// RECURSIVE T.C.=O(2^N) S.C.=O(N)
class Solution {
public:

    int solve(vector<int>& nums, int target, int index){
        if(index<0){
            if(target==0) return 1;
            return 0;
        }
        int add=solve(nums, target-nums[index], index-1);
        int sub=solve(nums, target+nums[index], index-1);
        return add+sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(nums, target, n-1);
    }
};

// striver says problem is same as partition a set into 2 subsets with min diff.
// the space optimized version  T.C.=O(N*K)+O(N) S.C.=O(K)
class Solution {
public:
int countPartitions(int n, int d, vector<int> &arr)
{
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    if((sum-d)<0 || (sum-d)%2) return 0;
    int k=(sum-d)/2;
	vector<int> prev(k+1, 0);
	prev[0]=1;
	if(arr[0]<=k) prev[arr[0]]=1;
	if(arr[0]==0) prev[0]=2;
	for(int i=1; i<n; i++){
		vector<int> curr(k+1, 0);
		for(int j=0; j<k+1; j++){
			int inc=0;
			if(arr[i]<=j) inc=prev[j-arr[i]];
			int ninc=prev[j];
			curr[j]=(inc+ninc);
		}
		prev=curr;
	}
	return prev[k];
}

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n, target, nums);
    }
};
