/*

            //Brute Force approch
            TC - N
            SC - N

traverse over all the nodes in given linked list and storing the nodes in hashmap.
check each node whether it is stored previously in the hashmap or not.

Code:
bool cycleDetect(node* head) {
    unordered_set<node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}

*/

/*

        //Optimal Approach
        TC - N
        SC - 1

Using two pointers fast and slow:

Code:
bool cycleDetect(node* head) {
    if(head == NULL) return false;
    node* fast = head;
    node* slow = head;
        
    while(fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}


*/

/*
        //AND to return the node where cycle starts

Code :
ListNode* getStartingNodeOfLoop(ListNode* list){
	if (list->next == NULL) {
		return NULL;
	}
	ListNode *slowPtr = list->next, *fastPtr = list->next->next;
	while (fastPtr != NULL && fastPtr->next != NULL) {
		if(slowPtr == fastPtr) {
			slowPtr = list;
			break;
		}
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next->next;
	}
	if (fastPtr == NULL || fastPtr->next == NULL) {
		return NULL;
	}
	while (slowPtr != fastPtr) {
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	return slowPtr;
}


*/