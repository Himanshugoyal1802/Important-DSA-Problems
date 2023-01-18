/*

        TC - N*N
        SC - N

recursive approach

Code:
#include <bits/stdc++.h> 

void insert_correct_pos(int x, stack<int> &st){
    if(st.size() == 0 || st.top() < x){
        st.push(x);
        return;
    }
    else{
        int a = st.top();
        st.pop();
        insert_correct_pos(x,st);
        st.push(a);
    }
}

void sortStack(stack<int> &st)
{
	if(st.size() > 0){
        int x = st.top();
        st.pop();
        sortStack(st);
        insert_correct_pos(x,st);
    }
}

*/