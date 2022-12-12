/*

        Brute Force
        TC - n1 + n2
        SC - n1 + n2

make an external linked list and append nodes in sorted way

*/

/*

        //Better Approach
        TC - n1+n2
        SC - 1

he idea to do it without extra space is to play around with the next pointers of nodes in the two input 
lists and arrange them in a fashion such that all nodes are linked in increasing order of values.

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        
        ListNode * ans, *tail;
        if(list1->val < list2->val){
            ans = list1;
            tail = list1;
            list1 = list1->next;
        }
        else{
            ans = list2;
            tail = list2;
            list2 = list2->next;
        }
        while(list1 != NULL && list2 != NULL){
            if(list1->val < list2->val){
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        
        if(list1 == NULL)tail->next = list2;
        else tail->next = list1;
        return ans;
        
    }
*/