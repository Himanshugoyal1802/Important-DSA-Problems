/*

        TC - n
        SC - n


-> use two queues q1 & q2
-> first add element in q2
-> then add all elements from q1 to q2
-> make q2 = q1 && q1 = q2
->q1 is our main queue


#include <bits/stdc++.h> 
class Stack {
	// Define the data members.
    queue<int>q1,q2;
   public:
    Stack() {
        // Implement the Constructor.
    }


    int getSize() {
        // Implement the getSize() function.
        return q1.size();
        
    }

    bool isEmpty() {
        // Implement the isEmpty() function.
        return q1.size() == 0;
    }

    void push(int ele) {
        // Implement the push() function.
        q2.push(ele);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop() {
        // Implement the pop() function.
        if(q1.size()!=0){
            int val = q1.front();
            q1.pop();
            return val;
        }
        return -1;
    }

    int top() {
        // Implement the top() function.
        if(q1.size() != 0){
            return q1.front();
        }
        return -1;
    }
};
*/