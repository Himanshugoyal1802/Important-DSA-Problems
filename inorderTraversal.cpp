/*

        Recursive
        TC - N
        SC - 1

Code:

void helper(TreeNode * root,vector<int> &ans){
        if(root == NULL){
            return;
        }
        helper(root->left,ans);
        ans.push_back(root->data);
        
        helper(root->right,ans);
    }

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
        helper(root,ans);
        return ans;
}


*/

//----------------------------------------------------------------------------------------------

/*

        //Iterative
        TC - N
        SC - N

Code:
vector<int> inOrder(Node* root)
{
    vector<int>ans;
    stack<Node*>st;
    while(true){
        if(root != NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty()){
                break;
            }
            root = st.top();
            st.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}

*/