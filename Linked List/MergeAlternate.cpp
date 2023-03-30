// Construct a linked list by merging alternate nodes of two given lists
// Given two linked lists, merge their nodes to make one list, taking nodes alternately between the two lists. If either list runs out, all the nodes should be taken from the other list.


ListNode* mergeAlternate(ListNode* l1, ListNode* l2){
    ListNode* res = l1;
    while(l1 != NULL && l2 != NULL){
        ListNode* n1 = l1->next, *n2 = l2->next;
        l1->next = l2;
        l2->next = n1;
        l1 = n1;
        l2 = n2;
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


