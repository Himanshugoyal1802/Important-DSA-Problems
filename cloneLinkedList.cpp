/*

        //Brute Force 
        TC - N
        SC - N

Use hashmap to store nodes

Code:

Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        Node * temp = head;
        while(temp != NULL){
            Node * copy = new Node(temp->val);
            m[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }

*/

/*

                //Optimal Approach
                TC - N
                SC - 1

Code:

void copyList(Node * head){
        Node * temp = head, *n = head->next;
        while(temp){
            Node * copy = new Node(temp->val);
            temp->next = copy;
            copy->next = n;
            temp = n;
            if(n!=NULL) n = n->next;
        }
    }
    
    void handleRandom(Node * head){
        Node * temp = head;
        while(temp){
            if(temp->random)
            temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    
    Node * detach( Node * head){
        Node * dummy = new Node(-1);
        Node * tail = dummy, *temp = head;
        while(temp){
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
        
    Node* copyRandomList(Node* head) {
       if(head == NULL)return head;
        copyList(head);
        handleRandom(head);
        return detach(head);
    }


*/