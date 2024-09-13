class Solution {
public:
// T.C.=O(2N) S..C.=O(1)
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long xorr=0;
        for(int i=0; i<n; i++){
            xorr=xorr^nums[i];
        }
        int right=(xorr&(xorr-1))^xorr;
        int b1=0, b2=0;
        for(int i=0; i<n; i++){
            if(nums[i]&right) b1=b1^nums[i];
            else b2=b2^nums[i];
        }
        return {b1, b2};

    }
};
