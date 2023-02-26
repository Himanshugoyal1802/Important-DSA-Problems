/*

        TC - N
        SC - N

Code:

vector<int> leftView(Node* root) {
	vector<int>ans;
   if(root == NULL)return ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int size = q.size();
       for(int i=0;i<size;i++){
           Node * top = q.front();
           q.pop();
           
           if(i == 0){
               ans.push_back(top->data);
           }
           if(top->left){
               q.push(top->left);
           }
           if(top->right){
               q.push(top->right);
           }
       }
   }
   return ans;
}

*/