/*

        //Naive approch
        TC - 2N
        SC - 1

first find the size of linked list and then traverse to size/2 part again and return middle

ListNode* middleNode(ListNode* head) {
    	int n = 0;
    	ListNode* temp = head;
    	while(temp) {
        	n++;
        		temp = temp->next;
    	}
   	 
    	temp = head;
   	 
    	for(int i = 0; i < n / 2; i++) {
        		temp = temp->next;
    	}
   	 
    	return temp;
	}

*/

/*

            //Better Approach
            TC - N
            SC - 1

            Tortoise-Hare Approach

ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

*/