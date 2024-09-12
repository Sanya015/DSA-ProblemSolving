class Solution {
public:

// T.C.=O(N x 32) S.C.=O(1)
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int ind=0; ind<32; ind++){
            int cnt=0;
            for(int i=0; i<nums.size(); i++){
                if(nums[i]>>ind & 1) cnt++;  // OR if(nums[i] & (1<<ind) )
            }
            if(cnt%3==1) ans=ans | (1<<ind); 
        }
        return ans;
    }
};

// Better than prev: not bit manipulation
// T.C.=O(N LogN) +N/3 S.C.=O(1)
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i+=3){
            if(nums[i]!=nums[i-1]) return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};

// OPTIMAL
// T.C.=O(N) S.C.=O(1)
    int singleNumber(vector<int>& nums) {
        int one=0;
        int two=0;
        for(int i=0; i<nums.size(); i++){
            one=(one^nums[i] & ~two);
            two=(two^nums[i] & ~one);
        }
        return one;
    }
};


