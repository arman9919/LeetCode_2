class Solution {
public:
    int level(TreeNode* root){// it finds the no. of levels/height of the tree
        if(root == NULL) return 0;
        return 1 + max(level(root->left) , level(root->right));
    }

    void nLevel(TreeNode* root , vector<vector<int>> &ans){
        // responsible for calling the fn so that values can be inserted in the Arrays 
        int n = level(root);
        for(int i=1 ; i<=n ; i++){
            vector<int> v;
            traversal(root , 1 , i, v);
            ans.push_back(v);
        }  
    }

    void traversal(TreeNode* root , int current , int level , vector<int> &v){
        if(root==NULL) return;
        if(current == level){
            v.push_back(root->val);
            return;
        }
        traversal(root->left , current+1 , level , v);
        traversal(root->right , current+1 , level , v);
    }

    vector<vector<int>> levelOrder(TreeNode* root) { // main fun
        vector<vector<int>> ans;
        nLevel(root , ans);
        return ans;
    }
};