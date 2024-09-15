class Solution {
public:
// RECURSIVE
// T.C.=O(N) 
// S.C.=O(N) - worst case when tree is skewed (worst case), O(logN) for balanced tree (best case)
    void dfs(TreeNode* node, int& sum, int val){
        if(node==nullptr){
            return;
        }
        val=(val*10)+node->val;
        if (node->left == nullptr && node->right == nullptr) {
            sum += val;
            return;
        }

        dfs(node->left, sum, val);
        dfs(node->right, sum, val);
    }

    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        int sum=0;
        dfs(root, sum, 0);
        return sum;
    }
};

// USING STACK (same logic)
// Same TC and SC as above
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root==nullptr) return 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root,0});
        int sum=0;
        while(!s.empty()){
            auto [node, value]=s.top();
            s.pop();
            value=(value*10)+node->val;
            if(node->left==nullptr && node->right==nullptr){
                sum+=value;
            }
            if(node->left) s.push({node->left, value});
            if(node->right) s.push({node->right, value});

        }
        return sum;
    }
};
