/*

        //Optimal approach
        TC - N
        SC - N

 vector <int> maxOfMin(int arr[], int n)
{
    
    vector<int> rslt(n,0);
    vector<int> left(n,0);
    vector<int> right(n,n-1);
    stack<int>st;
    
    //finding prev smaller index 
    
    for(int i=0;i<n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = 0;
        }
        else{
            left[i] = st.top()+1;
        }
        st.push(i);   
    }
    
    while(!st.empty()) st.pop();
    
    //finding next smaller index
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()]>=arr[i])
                st.pop();
            if(st.empty())
            {
                right[i]=n-1;
            }
            else
            {
                right[i]=st.top()-1;
                
            }
                st.push(i);
        }
        
        //filling rslt array
        for(int i=0;i<n;i++){
        rslt[right[i] - left[i]] = max(rslt[right[i] - left[i]],arr[i]);
        }
        for(int i=n-2;i>=0;i--){
            rslt[i] = max(rslt[i] , rslt[i+1]);
        }
        return rslt;
}

*/