/*

        Recursive
        TC - N
        SC - 1
    
Code:
void helper(TreeNode * root, vector<int>&ans){
    if(root == NULL)return;
    
    ans.push_back(root->val);
    helper(root->left,ans);
    helper(root->right,ans);
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int>ans;
    helper(root,ans);
    return ans;
}

*/

//-------------------------------------------------------------------------------------------------

/*

        //Iterative
        TC - N
        SC - N

Code:
vector<int> preOrder(Node* root)
{
    //code here
    vector<int>ans;
    stack<Node*> s;
    while(true){
        while(root != NULL){
            ans.push_back(root->data);
            s.push(root);
            root = root->left;
        }
        if(s.empty())break;
        
        Node * front = s.top();
        s.pop();
        root = front->right;
    }
    return ans;
}



*/