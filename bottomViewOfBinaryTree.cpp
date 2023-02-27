/*

        Tc - nlogn
        SC - n

Code:
vector <int> bottomView(Node *root) {
    // Your Code Here
    vector<int> ans;
    map<int,int> m;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        Node * node = it.first;
        int level = it.second;
        m[level] = node->data;
        
        if(node->left){
            q.push({node->left,level-1});
        }
        if(node->right){
            q.push({node->right,level+1});
        }
    }
    
    for(auto i : m){
        ans.push_back(i.second);
    }
    
    return ans;
}


*/