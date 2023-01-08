/*

        //Brute Force
        TC - 2^n * klog(x)
        SC - 2^n * k to store every subset of avg length k

klog(x) is due to inserting every subset in a set.(while putting a data structure into another 
                                                    data structure it takes time, not a constant 
                                                    value so we take an avg length of each subset
                                                    to k)

At every index, we make a decision whether to pick or not pick the element at that index. 
This will help us in generating all possible combinations but does not take care of the duplicates. 
Hence we will use a set to store all the combinations that will discard the duplicates.

*/


/*

    //Optimal approach
    TC - 2^n
    SC - 2^n * k


Code: 

#include <bits/stdc++.h> 

void uniqueSubsetsHelper(int ind, vector<int> &arr, int n, vector<vector<int>> &ans, vector<int> &v){
    ans.push_back(v);
    for(int i = ind; i < n; i++){
        if(i != ind && arr[i] == arr[i-1])continue;
        v.push_back(arr[i]);
        uniqueSubsetsHelper(i+1, arr, n, ans, v);
        v.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    int ind = 0;
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    vector<int> v;
    uniqueSubsetsHelper(ind, arr, n, ans, v);
    return ans;
}

*/
