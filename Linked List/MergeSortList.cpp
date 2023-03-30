148. Sort List
Given the head of a linked list, return the list after sorting it in ascending order.

ListNode* findMid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* merge(ListNode* l1, ListNode* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->val > l2->val) swap(l1, l2);
    ListNode* res = l1;
    ListNode* temp = res;
    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}

ListNode* mergeSort(ListNode* head){
    if(head == NULL || head->next == NULL) return head;
    ListNode* mid = findMid(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL;
    left = mergeSort(left);
    right = mergeSort(right);
    ListNode* res = merge(left, right);
    return res;
}

// Time Complexity : O(nlogn)
// Space Complexity : O(logn)

