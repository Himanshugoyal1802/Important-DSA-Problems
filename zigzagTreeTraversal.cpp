/*

        TC - N
        SC - N

Code:
vector <int> zigZagTraversal(Node* root)
{
    // Code here
        vector<int> ans;
    queue<Node* > q;
    q.push(root);
    bool ltr = true;
    
    if(root == NULL)
        return ans;
    
    while(!q.empty()){
        int size = q.size();
        vector<int> res(size);
        
        for(int i = 0; i<size; i++){
            
            Node* front = q.front();
            q.pop();
            
            int index = ltr ? i : size - i - 1;
            res[index] = front->data;
            
            if(front->left)
                q.push(front->left);
            
            if(front->right)
                q.push(front->right);           
        }
        ltr = !ltr;
        for(auto i : res){
            ans.push_back(i);
        }
    }
        return ans;
}

*/