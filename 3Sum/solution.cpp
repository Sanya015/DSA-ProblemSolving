class Solution {
public:
// BRUTE: T.C.=O(N^3*LOG OF NO. OF TRIPLETS DUE TO SET) S.C.=2O(NO. OF TRIPLETS)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        
        set<vector<int>> s;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int> temp;
                        temp={nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};

// BETTER: T.C.=O(N^2*Log of size of set) S.C.=O(N)+2O(NO. OF UNIQUE TRIPLETS)
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>> store;
        for(int i=0; i<n; i++){
            set<int> s;
            for(int j=i+1; j<n; j++){
                int find=-1*(nums[i]+nums[j]);
                if(s.find(find)!=s.end()){
                    vector<int> temp={nums[i], nums[j], find};
                    sort(temp.begin(), temp.end());
                    store.insert(temp);
                }
                s.insert(nums[j]);
            }
        } 
        vector<vector<int>> ans(store.begin(), store.end());
        return ans;      
    }
};


//OPTIMAL: T.C.=O(NLOGN)+O(N^2) S.C.=O(N)
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-1; i++){
            int j=i+1, k=n-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    while(j<k && nums[j]==nums[j+1]) j++;
                    while(j<k && nums[k]==nums[k-1]) k--;
                    j++; k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};
