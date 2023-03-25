/*

        //Naive implementation
        TC - n^2
        SC - 1

in this implementation we will calculate the path sum between each two nodes and maintain the maximum
path sum

*/

/*

        //Optimal implementation
        TC - n
        SC - 1

In this implementation, at every node , which is the longest path ,is what we return, and use 
maxi variable to store the maximum path sum. (somewhat based on finding height of a tree)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi;
    }
    
    int helper(TreeNode * root, int &maxi){
        if(root == NULL)return 0;
        int leftsum = max(0,helper(root->left,maxi));
        int rightsum = max(0,helper(root->right,maxi));
        
        maxi = max(maxi , root->val+leftsum+rightsum);
        return root->val + max(leftsum , rightsum);
    }
};
*/