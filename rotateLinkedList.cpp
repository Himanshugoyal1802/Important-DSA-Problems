/*

        //Brute Force 
        TC - k*N
        SC - 1

We have to move the last element to first for each k.
For each k, find the last element from the list. Move it to the first.

Code:

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL) return head;
    for(int i=0;i<k;i++) {
        node* temp = head;
        while(temp->next->next != NULL) temp = temp->next;
        node* end = temp->next;
        temp->next = NULL;
        end->next = head;
        head = end;
    }
    return head;
}

*/

/*

        //Optimal Approach
        TC - N
        SC - 1

node* rotateRight(node* head,int k) {
    if(head == NULL||head->next == NULL||k == 0) return head;
    //calculating length
    node* temp = head;
    int length = 1;
    while(temp->next != NULL) {
        ++length;
        temp = temp->next;
    }
    //link last node to first node
    temp->next = head;
    k = k%length; //when k is more than length of list
    int end = length-k; //to get end of the list
    while(end--) temp = temp->next;
    //breaking last node link and pointing to NULL
    head = temp->next;
    temp->next = NULL;
        
    return head;
}


*/