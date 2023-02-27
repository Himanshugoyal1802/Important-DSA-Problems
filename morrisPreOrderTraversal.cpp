/*

        TC- N
        SC - 1

Code:

 vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode * cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            ans.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode * prev = cur->left;
            while(prev->right != NULL && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                ans.push_back(cur->val);
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return ans;
}

*/