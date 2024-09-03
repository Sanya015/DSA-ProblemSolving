// Preorder
// T.C.=O(N) S.C.=O(N)
class Solution {
public:
    void pre(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        pre(root->left, ans);
        pre(root->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        pre(root, ans);
        return ans;
    }
};

// Inorder
// T.C.=O(N) S.C.=O(N)
class Solution {
public:

    void in(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        in(root->left, ans);
        ans.push_back(root->val);
        in(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        in(root, ans);
        return ans;
    }
};

 // Postorder
// T.C.=O(N) S.C.=O(N)

class Solution {
public:

    void post(TreeNode* root, vector<int>& ans){
        if(root==NULL) return;
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }
};


 // Levelorder
 // T.C.=O(N) S.C.=O(N)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(root==NULL) return ans;
        q.push(root);
        
        while(!q.empty()){
            int size=q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

            }
            ans.push_back(temp);

        }
        return ans;

    }
};
