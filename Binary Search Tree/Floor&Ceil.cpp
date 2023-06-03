// Find Floor and Ceil in a Binary Search Tree
// Given a BST, find the floor and ceil of a given key in it. If the given key lies in the BST, then both floor and ceil are equal to that key; otherwise, the ceil is equal to the next greater key (if any) in the BST, and the floor is equal to the previous greater key (if any) in the BST.

Node *floor = NULL, *ceil = NULL;
void floorAndCeil(Node *root, int key){
    while(root != NULL){
        if(root->val == key){
            floor = ceil = root;
            break;
        }
        else if(key > root->val){
            floor = root;
            root = root->right;
        }
        else if(key < root->val){
            ceil = root;
            root = root->left;
        }
    }
}

// Time complexity : O(n)
// Space Complexity : O(h)


