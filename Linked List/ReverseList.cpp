// Reverse Linked List
// Given the head of a singly linked list, reverse the list, and return the reversed list.

ListNode* reverseList(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* curr = head;
    ListNode* prev = NULL;
    while(curr != NULL){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->next;
    }
    return prev;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


