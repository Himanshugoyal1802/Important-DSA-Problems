/*

        //Iterative Approach
        TC - N
        SC - 1

ListNode* reverseList(ListNode* head) {
        if(head == NULL)return head;
        ListNode* curr = head, *nex = head->next, *prev = NULL;
        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = nex;
            if(nex != NULL)nex = nex->next;
        }
        return prev;
    }

*/

/*

        //Recursive Approach
        TC - N
        SC - N (recursive Stack)

ListNode* reverseList(ListNode* head) {
       if(head == NULL)return head;
        if(head->next == NULL)return head;
        ListNode * reverseHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return reverseHead;
    }

*/