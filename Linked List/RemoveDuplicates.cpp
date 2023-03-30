// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.


ListNode* removeDuplicates(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* curr = head;
    while(curr != NULL && curr->next != NULL){
        if(curr->val == curr->next->val){
            curr->next = curr->next->next;
        }
        else curr = curr->next;
    }
    return head;
}

// Time Complexity : O(n)
// Space Complexity : O(1)

