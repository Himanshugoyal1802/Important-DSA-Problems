/*

        //Approach
        TC - 2^n + 2^n log(2^n)
        SC - 2^n

Code: 

#include <bits/stdc++.h> 

void helper(vector<int>&num , int i, vector<int>&rslt,int sum){
    if(i == num.size()){
        rslt.push_back(sum);
        return;
    }
    helper(num,i+1,rslt,sum+num[i]);
    helper(num,i+1,rslt,sum);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    int idx = 0;
    vector<int>rslt;
    helper(num,idx,rslt,0);
    
    sort(rslt.begin(),rslt.end());
    
    return rslt;
}

*/