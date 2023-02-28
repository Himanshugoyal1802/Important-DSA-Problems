/*

        TC - N
        SC - 1

Code:

bool helper(TreeNode<int> *root, int x, vector<int>&ans){
	if(root == NULL)return false;

	ans.push_back(root->data);
	if(root->data == x)return true;

	if(helper(root->left,x,ans) || helper(root->right,x,ans)){
		return true;
	}
	ans.pop_back();
	return false;
	
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>ans;
	if(root == NULL)return ans;
	helper(root,x,ans);
	return ans;
}



*/


///--------------------------------------------------------------------------------------------
