// 725. Split Linked List in Parts
// Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.
// The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.
// The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.
// Return an array of the k parts.


vector<ListNode*> splitParts(ListNode *head, int k){
    ListNode *curr = head;
    int len = 0;
    while(curr != NULL){
        len++;
        curr = curr->next;
    }
    int baseSize = len/k;
    int extra = len%k;
    vector<ListNode*> res;
    curr = head;
    for(int i=0; i<k; i++){
        ListNode *end = curr;
        if(extra > 0){
            int c = baseSize;
            while(c--){
                end = end->next;
            }
            ListNode* temp = end->next;
            end->next = NULL;
            res.push_back(curr);
            extra--;
            curr = temp;
        }
        else{
            if(baseSize == 0) res.push_back(NULL);
            else{
                int c = baseSize-1;
                while(c--){
                    end = end->next;
                }
                ListNode* temp = end->next;
                end->next = NULL;
                res.push_back(curr);
                extra--;
                curr = temp;
            }
        }
    }
    return res;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


