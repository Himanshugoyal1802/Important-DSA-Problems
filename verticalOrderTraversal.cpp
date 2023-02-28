/*
        //Medium level question(No sorted order asked in question)
        TC - N
        SC - N

Code:

vector<int> verticalOrder(Node *root)
{
    //Your code here
    map<int,vector<int>> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        
        Node * node = it.first;
        int level = it.second;
        
        m[level].push_back(node->data);
        
        if(node->left){
            q.push({node->left , level-1});
        }
        if(node->right){
            q.push({node->right, level+1});
        }
    }
    
    vector<int>ans;
    for(auto i : m){
        vector<int>temp = i.second;
        ans.insert(ans.end(),temp.begin(),temp.end());
    }
    return ans;
}

*/


//--------------------------------------------------------------------------------------------------

/*

        //Hard level questions (sorted order asked in question for same level nodes)
        TC - N
        SC - N

Code:

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int,int>>> todo;
    todo.push({root,{0,0}});
    
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        
        TreeNode * node = p.first;
        int x = p.second.first;
        int y = p.second.second;
        
        nodes[x][y].insert(node->val);
        
        if(node->left){
            todo.push({node->left , {x-1,y+1}});
        }
        if(node->right){
            todo.push({node->right, {x+1,y+1}});
        }
    }
    
    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int>col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

*/