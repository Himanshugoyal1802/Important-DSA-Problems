/*

        //REcursive
        TC - N
        SC - 1

Code:

void helper(Node * root, vector<int>&ans){
        if(root == NULL){
            return;
        }
        
        helper(root->left,ans);
        helper(root->right,ans);
        ans.push_back(root->data);
    }
vector<int> getPostorderTraversal(Node* root) {
    // add your logic here
	vector<int>ans;
        helper(root,ans);
        return ans;
}

*/

//-----------------------------------------------------------------------------------------------


/*

        Iterative
        TC- N
        SC - 2N

Code:
vector<int> postOrder(Node* root) {
    // code here
    vector<int>ans;
    stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty()){
        root = s1.top();
        s1.pop();
        
        s2.push(root);
        if(root->left){
            s1.push(root->left);
        }
        if(root->right){
            s1.push(root->right);
        }
    }
    
    while(!s2.empty()){
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;
}

*/