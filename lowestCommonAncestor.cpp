/*

        TC - N
        SC - N
    
approach:
finding root to node path of both the nodes and then find the last matching ancestor from beginning

for eg: two nodes are 4 & 7 and there root to node paths are
4 : 1->2->4
7 : 1->2->5->7

so from start last matching node is 2 so the lowest common ancestor is 2

*/


//-------------------------------------------------------------------------------------------------

/*

        TC - N
        SC - 1

Code:
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
	if(root == NULL || root == p || root == q){
		return root;
	}
	Node * left = lowestCommonAncestor(root->left ,p,q);
	Node * right = lowestCommonAncestor(root->right,p,q);

	if(left == NULL)return right;
	else if(right == NULL)return left;
	return root;
}


*/