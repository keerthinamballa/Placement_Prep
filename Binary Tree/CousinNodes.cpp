// Determine whether the given binary tree nodes are cousins of each other
// Given a binary tree, determine if two given nodes are cousins of each other or not. 

// Two nodes of a binary tree are cousins of each other only if they have different parents, but they are at the same level.

struct nodeInfo{
    Node* node;
    int level;
    Node* parent;
};

void getInfo(Node* root, Node* parent, int level, nodeInfo &x, nodeInfo &y){
    if(root == NULL) return;
    getInfo(root->left, root, level+1, x, y);
    if(root == x.node){
        x.level = level;
        x.parent = parent;
    }

    if(root == y.node){
        y.level = level;
        y.parent = parent;
    }
    getInfo(root->right, root, level+1, x, y);
}

bool checksCousins(Node* root, Node* n1, Node* n2){
    if(root == NULL) return false;
    int level = 1;
    Node* parent = NULL;
    nodeInfo x = {node1, level, parent};
    nodeInfo y = {node2, level, parent};
    getInfo(root, NULL, 1, x, y);
    return x.level == y.level && x.parent != y.parent;
}

// Time Complexity : O(n)
// Space Complexity : O(h)

