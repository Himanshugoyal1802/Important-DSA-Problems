#include <bits/stdc++.h>
using namespace std;

class StackMemory{
    int * data;
    int capacity;
    int nextIndex;

    public:

    StackMemory(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
    }

    bool is_empty(){
        return nextIndex == 0;
    }

    int size(){
        return nextIndex;
    }

    void push(int value){
        // if(nextIndex == capacity){       //here size of array is statically created so it is fix
        //     cout<<"Stack is Full!"<<endl;
        //     return;
        // }

        if(nextIndex == capacity){          //here we double the size of array when the nextIndez value becomes equal to capacity 
            int * newData = new int[2*capacity];    //.... or say i created the dynamic array
            for(int  i=0;i<2*capacity; i++){
                newData[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newData;
        }
        data[nextIndex] = value;
        nextIndex++;
    }

    int pop(){
        if(nextIndex == 0){
            cout<<"Stack is Empty!"<<endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top(){
        if(is_empty()){
            cout<<"Stack is Empty!"<<endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

};

int main(){
    StackMemory s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout<<s.top()<<endl;

    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;

    cout<<s.size()<<endl;

    cout<<s.is_empty()<<endl;

}