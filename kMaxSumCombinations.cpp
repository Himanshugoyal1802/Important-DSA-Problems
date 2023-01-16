/*

        TC - n^2
        SC - n^2

approach:
generate all possible combinations by running two for loops and insert them in a priority queue.
And then pop top k elements.

Code:



*/

//-------------------------------------------------------------------------------------------------

/*

        TC - nlogn 
        SC - n

Code:

vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());
    
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({a[n-1]+b[n-1],{n-1,n-1}});
    
    set<pair<int,int>> set;
    set.insert({n-1,n-1});
    
    vector<int> rslt;
    while(k>0){
        pair<int,pair<int,int>> top = pq.top();
        pq.pop();
        
        int sum = top.first;
        int x = top.second.first;
        int y = top.second.second;
        
        rslt.push_back(sum);
        
        if(set.find({x-1,y}) == set.end()){
            pq.push({ a[x-1]+b[y] , {x-1,y} });
            set.insert({x-1,y});
        }
        
        if(set.find({x,y-1}) == set.end()){
            pq.push({ a[x]+b[y-1], {x,y-1}});
            set.insert({x,y-1});
        }
        
        k--;
    }
    
    return rslt;
}

*/