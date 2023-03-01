/*

        TC - N
        SC - 1

Code:

bool areIdenticalTrees(Node* root1, Node* root2) {
	if(root1 == NULL && root2 == NULL)return true;
    if(root1 == NULL || root2 == NULL)return false;

    if(root1->data != root2->data)return false;

    return areIdenticalTrees(root1->left,root2->left) & areIdenticalTrees(root1->right, root2->right);
}

*/