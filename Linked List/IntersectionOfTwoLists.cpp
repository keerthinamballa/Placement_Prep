// 160. Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.


ListNode* intersectionNode(ListNode* l1, ListNode* l2){
    if(l1 == NULL || l2 == NULL) return NULL;
    ListNode* a = l1;
    ListNode* b = l2;
    while(a != b){
        a = (a == NULL) ? l2 : a->next;
        b = (b == NULL) ? l1 : b->next;
    }
    return a;
}

// Time Complexity : O(2m)
// Space Complexity : O(1)
