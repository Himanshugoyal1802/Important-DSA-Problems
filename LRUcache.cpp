/*

        TC - 1 for get and set
        SC - 1

approach:
we will use a doubly linked list and hashmap to have a record of the key and their address

Code:

#include<bits/stdc++.h>
class LRUCache
{
public:
    map<int,int> m;
    map<int, list<int> :: iterator> address;
    list<int> l;
    int siz=0;
    int capacity;    
    
    LRUCache(int cap)
    {
        capacity = cap;
        siz=0;
    }

    int get(int key)
    {
        if(m.find(key) == m.end()){
            return -1;
        }
        l.erase(address[key]);
        address.erase(key);
        
        l.push_front(key);
        address[key] = l.begin();
        return m[key];
        
    }

    void put(int key, int value)
    {
        // Write your code here
        
        if(m.find(key) != m.end()){
            l.erase(address[key]);
            address.erase(key);
            m.erase(key);
            siz--;
        }
        
        if(siz == capacity){
            int k = l.back();
            l.pop_back();
            address.erase(k);
            m.erase(k);
            siz--;
        }
        
        siz++;
        l.push_front(key);
        address[key] = l.begin();
        m[key] = value;
    }
};

*/