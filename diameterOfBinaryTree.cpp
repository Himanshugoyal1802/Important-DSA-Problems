/*

        TC - N
        SC - 1

Code:
int diameterOfBinaryTree(TreeNode* root) {
    int d=0;
    rec(root, d);
    return d;
}

int rec(TreeNode* root, int &d) {
    if(root == NULL) return 0;
    int ld = rec(root->left, d);
    int rd = rec(root->right, d);
    d=max(d,ld+rd);
    return max(ld,rd)+1;
}

*/