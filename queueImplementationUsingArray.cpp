#include<iostream>
using namespace std;

class Queue{
    int *data;
    int capacity,size,firstIndex,nextIndex;

    public:
    Queue(int val){
        data = new int[val];
        size = 0;
        capacity = val;
        firstIndex = -1;
        nextIndex = 0;
    }

    int getSize(){
        return size;
    }
    bool isEmpty(){
        return size == 0;
    }

    void enqueue(int ele){
        if(size == capacity){
            cout<<"Queue OverFlow"<<endl;
            return;
        }
        data[nextIndex] = ele;
        nextIndex = (nextIndex+1)%capacity;
        size++;
        if(firstIndex == -1){
            firstIndex = 0;
        }
    }

    int dequeue(){
        if(size == 0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int ans = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }
    int front(){
        if(size == 0){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return data[firstIndex];
    }
};

int main(){
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;
    cout<<q.dequeue()<<endl;

    cout<<q.getSize()<<endl;
    cout<<q.isEmpty()<<endl;
}