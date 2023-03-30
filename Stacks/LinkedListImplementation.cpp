// Linked List Implementation of Stack


struct MyStack(){
    Node* head;
    int size;
    MyStack(){
        head = NULL;
        size = 0;
    }
    void push(int x){
        Node *temp = new Node(x);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop(){
        if(head == NULL) return INT_MAX;
        int res = head->data;
        Node *temp = head;
        head = head->next;
        delete(temp);
        size--;
        return res;
    }
    int size(){
        return size;
    }
    bool isEmpty(){
        return head == NULL;
    }
    int peek(){
        if(head == NULL) return INT_MAX;
        return head->data;
    }
};
