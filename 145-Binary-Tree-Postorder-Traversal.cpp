// Method-1 : RECURSIVE
// class Solution {
// public:

//     void postOrder(TreeNode* root , vector<int> &ans){
//         if(root == NULL) return;
//         postOrder(root->left , ans);
//         postOrder(root->right , ans);
//         ans.push_back(root->val);

//     }
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         postOrder(root , ans);
//         return ans;      
//     }
// };

// Method -2  Iterative 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        if(root!=NULL)st.push(root);
        while( st.size()>0 ){
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->left!=NULL) st.push(temp->left);
            if(temp->right!=NULL) st.push(temp->right);
        }
        reverse(ans.begin() , ans.end());
        return ans;         
    }
};

