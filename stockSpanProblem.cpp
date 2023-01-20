/*

        TC - N
        SC - N


Code:
#include <bits/stdc++.h> 
vector<int> findSpans(vector<int> &price) {
    vector<int>rslt;
    stack<pair<int,int>> st;
    for(int i=0;i<price.size();i++){
        int res = 1;
        while(!st.empty() && (st.top().first <= price[i])){
            res += st.top().second;
            st.pop();
        }
        st.push({price[i] , res});
        rslt.push_back(res);
    }
    return rslt;
}

*/