/*

        TC - N
        SC - 1

Code :

//code for reversing the rest nodes also if they are less than k value
void reversePart(struct node* s, struct node * e){
        struct node * p = NULL, *c = s, *n = s->next;
        while(p!=e){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        // Complete this method
        if(head == NULL || head->next == NULL || k == 1)return head;
        struct node * dummy = new node(-1);
        dummy->next = head;
        struct node * beforeStrt = dummy, *e = head;
        int i = 0;
        while(e != NULL){
            i++;
            if(i%k == 0 || e->next==NULL){
                struct node * s = beforeStrt->next, *temp = e->next;
                reversePart(s,e);
                beforeStrt->next = e;
                s->next = temp;
                beforeStrt = s;
                e = temp;
            }
            else{
                e = e->next;
            }
        }
        return dummy->next;
    }

*/

/*

//Code for reversing only those grps who are in size of k(almost same code just remove this condition(e->next == NULL))

Code:
void reverse(ListNode* s, ListNode * e){
        ListNode * p = NULL, *c = s, *n = s->next;
        while(p!=e){
            c->next = p;
            p = c;
            c = n;
            if(n != NULL) n = n->next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k == 1)return head;
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * beforeStrt = dummy, *e = head;
        int i = 0;
        while(e != NULL){
            i++;
            if(i%k == 0){
                ListNode * s = beforeStrt->next, *temp = e->next;
                reverse(s,e);
                beforeStrt->next = e;
                s->next = temp;
                beforeStrt = s;
                e = temp;
            }
            else{
                e = e->next;
            }
        }
        return dummy->next;
    }


*/