// 92. Reverse Linked List II
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.


ListNode* reverseBetween(ListNode* head){
    ListNode* dummy = new ListNode(0);
    dummy->next - head;
    ListNode* prev = dummy;
    for(int i=0; i<left-1; i++){
        prev = prev->next;
    }
    ListNode* curr = prev->next;
    for(int i=0; i<right-left; i++){
        ListNode* next = curr->next;
        curr->next = next->next;
        next->next = prev->next;
        prev->next = next;
    }
    return dummy->next;
}

// Time Complexity : O(n)
// Space Complexity : O(1)
