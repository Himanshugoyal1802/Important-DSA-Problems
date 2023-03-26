/*

        TC - 2N
        SC - N

class Solution {
public:
    
    TreeNode * helper(TreeNode * root){
        if(root == NULL){
            return root;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        
        TreeNode * left = helper(root->left);
        TreeNode * right = helper(root->right);
        
        if(root->left == NULL){
            return root;
        }
        
        TreeNode * temp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode * t = root->right;
        while(t->right != NULL){
            t = t->right;
        }
        t->right = temp;
        return root;
    }
    
    void flatten(TreeNode* root) {
        if(root == NULL)return;

        root = helper(root);
    
    }
};

*/

//----------------------------------------------------------------

/*

        TC - N
        SC - N


class Solution
{
    public:
    
    Node * prev = NULL;
    
    void flatten(Node *root)
    {
        //code here
        if(root == NULL){
            return;
        }
        flatten(root->right);
        flatten(root->left);
    
        root->right = prev;
        root->left = NULL;
        prev = root;
        
    }
};


*/

//----------------------------------------------------------------

/*

        TC - N
        SC - 1

Code:

void flatten(Node* root) {
    // add your logic here
	if(root == NULL)return ;
    
    Node * curr = root;
    while(curr){
        if(curr->left){
            Node * prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;

            curr->left = NULL;
        }
        curr= curr->right;
    }
}

*/