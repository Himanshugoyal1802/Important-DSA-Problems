/*

        //Brute Force
        TC - nlogn
        SC - n

approach:

Use hashmap to make frequency map and then make pair of frequency and their respective no and add them
into a vector and then sort the vector and return last k top elements


*/


/*

        //optimal approach
        TC - nlogk
        SC - n

use hashmap and use minheap

vector<int> topKFrequent(vector<int>& arr, int k) {
    unordered_map<int,int> map;
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> minheap;

    for(auto i : arr){
        map[i]++;
    }

    for(auto a : map){
        pair<int,int> p;
        p.first = a.second;
        p.second = a.first;
        minheap.push(p);
        if(minheap.size() > k){
            minheap.pop();
        }
    }

    vector<int> rslt;
    while(minheap.size()>0){
        rslt.push_back(minheap.top().second);
        minheap.pop();
    }
    return rslt;
}

*/