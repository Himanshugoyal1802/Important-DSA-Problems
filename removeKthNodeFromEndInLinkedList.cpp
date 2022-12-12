/*

        Brute Force Approach
        TC - 2N
        SC - 1

first find the size of ll by travering 
then length - nth given node is the target node to be deleted from the front

so again traverse over the array and maintain a count. whenever the (count == tar) remove the curr node

ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)return NULL;
        int len = 0;
        ListNode * temp = head;
        while(temp!=NULL){
            len++;
            temp = temp->next;
        }

        int tar = len-n;
        if(tar == 0)return head->next;
        int count = 0;
        temp = head;
        ListNode * prev =NULL;
        while(temp!=NULL){
            if(count == tar){
                ListNode * a = temp;
                prev->next = temp->next;
                delete a;
                break;
            }
            prev = temp;
            temp = temp->next;
            count++;
        }
        return head;
    }

*/

/*

        //Better approach
        TC - N
        SC - 1

use to pointers slow and fast pointer first place the fast pointer at the nth node from the front and
then move fast and slow pointers by one step till the fast pointer reaches to the end of ll.
and then remove the slow->next node; and return head of the linked list

ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * slow = dummy, *fast = dummy;
        for(int i=0;i<n;i++){
            fast = fast->next;
        }
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return dummy->next;
    }

*/