// Spiral order traversal of a binary tree
// Given a binary tree, print its nodes level by level in spiral order, i.e., all nodes present at level 1 should be printed first from left to right, followed by nodes of level 2 from right to left, followed by nodes of level 3 from left to right and so on… In other words, odd levels should be printed from left to right, and even levels should be printed from right to left or vice versa.

void spiralOrder(Node* root){
    if(root == NULL) return;
    deque<Node*> dq;
    dq.push_front(root);
    bool flag = true;
    while(!dq.empty()){
        int n = dq.size();
        if(flag){
            while(n--){
                Node* curr = dq.front();
                dq.pop_front();
                cout<<curr->val << " ";
                dq.push_back(curr->left);
                dq.push_back(curr->right);
            }
        }
        else{
            while(n--){
                Node* curr = dq.back();
                dq.pop_back();
                cout<<curr->val<<" ";
                if(curr->right != NULL) dq.push_front(curr->right);
                if(curr->left != NULL) dq.push_front(curr->left);
            }
        }
        flag = !flag;
        cout<<endl;
    }
}


// Time Complexity : O(n)
// Space Complexity : O(n)


