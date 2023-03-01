/*

        TC - N^2
        SC - 1

Code:

int depth (TreeNode *root) {
    if (root == NULL) return 0;
    return max (depth(root -> left), depth (root -> right)) + 1;
}

bool isBalanced (TreeNode *root) {
    if (root == NULL) return true;
    
    int left=depth(root->left);
    int right=depth(root->right);
    
    return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}


*/

//----------------------------------------------------------------------------------------------------

/*

        TC - N
        SC - 1

Code:
  
int dfs(Node * root){
    if(root == NULL)return 0;

    int lh = dfs(root->left);
    int rh = dfs(root->right);

    if(lh == -1 || rh == -1)return -1;
    if(abs(lh-rh)>1)return -1;

    return 1 + max(lh,rh);
}

bool isBinaryTreeBalanced(Node* root) {
    // add your logic here
	return dfs(root)!=-1;
}

*/