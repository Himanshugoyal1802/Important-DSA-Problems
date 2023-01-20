/*

        TC - 1
        SC - 2N

approach:
we will use a stack of pair<int,int> where first value is current ele and second value is min value till max

space complexity is 2N bcz we are using a stack of pair<int,int>

Code:

class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            st.push({val,val});
        }
        else{
            if(val < st.top().second){
                st.push({val,val});
            }
            else{
                st.push({val,st.top().second});
            }
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

*/

//--------------------------------------------------------------------------------------------------

/*

            //Optimal approach
            TC - 1
            SC - N

we will keep a min variable

Code:

class MinStack {
public:
   stack<long long> st;
    long long mini;
    MinStack() {
       mini = INT_MIN; 
    }
    
    void push(int val) {
        long long num = val;
        if(st.empty()){
            mini = num;
            st.push(num);
        }
        else{
            if(num < mini){
                st.push(2 * num* 1LL - mini);
               mini = num;                   
            }
            else{
                st.push(num);
            }
        }
    }
    
    void pop() {
        if(st.empty())return ;
            long long el = st.top();
            st.pop();
            if(el < mini){
                mini = 2 * mini - el;
            }
    }
    
    int top() {
       if(st.empty()){
                return -1;
            }
            long long el = st.top();
            if(el < mini){
                return mini;
            }
            return el;
    }
    
    int getMin() {
        return mini;
    }
};


*/