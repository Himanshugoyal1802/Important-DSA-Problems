/*

You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. 
The task is to delete the node. Pointer/ reference to head node is not given. 
Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail 
node in the linked list.

        //TC - 1
        SC - 1

void deleteNode(ListNode* node) {
        if(node->next == NULL){
            delete node;
            return;
        }
        swap(node->val , node->next->val);
        ListNode * temp = node->next;
        node->next = node->next->next;
        delete temp;
        return;
    }

*/