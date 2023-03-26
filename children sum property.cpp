/*

        TC - N
        SC - 1

code:

void changeTree(BinaryTreeNode < int > * root) {
    if(!root) {
        return;
    }
    int childrenSum=0;
    childrenSum+=(root->left?root->left->data:0);
    childrenSum+=(root->right?root->right->data:0);
    if(childrenSum>root->data) {
        root->data=childrenSum;
    }
    else {
        if(root->left) {
            root->left->data = root->data;
        }
        if(root->right) {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);
    int total=0;
    total+=(root->left?root->left->data:0);
    total+=(root->right?root->right->data:0);
    if(root->left || root->right) {
        root->data = total;
    }
}  

*/