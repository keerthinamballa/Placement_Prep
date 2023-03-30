// Insert in a Sorted List
// Given a linked list sorted in ascending order and an integer called data, insert data in the linked list such that the list remains sorted.

Node *insertSorted(Node *head, int data){
    Node *node = new Node(data);
    if(head == NULL) return node;
    if(head->val > data){
        node->next = head;
        return node;
    }
    Node *curr = head;
    while(curr->next != NULL && curr->next->val < data){
        curr = curr->next;
    }
    node->next = curr->next;
    curr->next = node;
    return head;
}

// Time Complexity : O(n)
// Space Complexity : O(1)


