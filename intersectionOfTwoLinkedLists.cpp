/*

        //Brute Force
        TC - N*M
        SC - 1

Keep any one of the list to check its node present in the other list. means pick each element of one list
and search whether this node is present in second list or node. if while traversing first node we reach at null
means there is no intersection bw two lists so return null

code:
node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

*/

//--------------------------------------------------------------------------------------------------

/*

        //Better approch
        TC - N+M
        SC - N

Using hashing ,
store one list in the hashmap and iterate over other list to search if any node is already stored in
the hashmap

node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

}

*/

/*

                //Optimal approach
                TC - 2(N+M)
                SC - 1

difference of length:
We will reduce the search length. This can be done by searching the length of the shorter linked list. 


Code :
int getDifference(node* head1,node* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
 int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;


}

*/

/*

    TC - 2(N+M)
    SC - 1

Code :

Take two dummy nodes for each list. Point each to the head of the lists.
Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue 
iterating until they collide.

Code:

node* intersectionPresent(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}

*/