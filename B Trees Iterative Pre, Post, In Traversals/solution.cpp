// Preorder USING STACK
// T.C.=O(N) S.C.=O(N)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            ans.push_back(node->val);
            s.pop();
            if(node->right!=NULL) s.push(node->right);
            if(node->left!=NULL) s.push(node->left);
        }
        return ans;
    }
};

 // INORDER USING STACK
 // T.C.=O(N) S.C.=O(N)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        while(true){
            if(root!=NULL){
                s.push(root);
                root=root->left;
            }
            else{
                if(s.empty()) break;
                root=s.top();
                s.pop();
                ans.push_back(root->val);
                root=root->right;
            }

        }
        return ans;
    }
};

 // POSTORDER USING 2 STACKS
 // T.C.=O(N) S.C.=O(2N)
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* node=s1.top();
            s1.pop();
            s2.push(node);
            if(node->left!=NULL) s1.push(node->left);
            if(node->right!=NULL) s1.push(node->right);

        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};
