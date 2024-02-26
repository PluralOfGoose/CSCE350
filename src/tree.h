#ifndef TREE_H
#define TREE_H
#include <unordered_set>
using namespace std;



template<typename T>
struct BST_Node {
T val;
BST_Node* left;
BST_Node* right;

BST_Node(T v) : val(v),left(NULL),right(NULL)
{}

void insert(T v) {
    if(v>val){
        if (right==NULL) right = new BST_Node<T>(v);
        else right->insert(v);
    }
    else{
        if (left==NULL) left = new BST_Node<T>(v);
        else left->insert(v);
    }
}

};


template<typename T>
void delete_tree(BST_Node<T>* root){
    if (root==NULL) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

//your work starts here
template<typename T>
int num_nodes(BST_Node<T>* root){
    if (root == NULL){
        return 0;
    }
    
    else {
        int left_root = num_nodes(root->left);
        int right_root = num_nodes(root->right);

        return right_root + left_root + 1;
    }
    
}

// template<typename T>
// bool has_duplicate_val(BST_Node<T>* root){
//     std::unordered_set<T> visited_values;
//     if (root = NULL) return; 
//     has_duplicate_val(root->left);
//     visited_values.push(root->val);
//     has_duplicate_val(root->right);
    
//     for (i=0; i < visited_values.size(); i++){
//         if (visited_values.find())
//     }
//     return true;
// }

template<typename T>
bool has_duplicate_val(BST_Node<T>* root) {
    std::unordered_set<T> visited_values;
    return dup_val_helper(root, visited_values);
}

template<typename T>
bool dup_val_helper(BST_Node<T>* root, std::unordered_set<T>& visited_values) {
    if (root == nullptr) {
        return false;  // No duplicates in an empty tree
    }

    if (!visited_values.insert(root->val).second) {
        return true;  // Duplicate found
    }

    // Check left and right subtrees for duplicates
    return dup_val_helper(root->left, visited_values) ||
           dup_val_helper(root->right, visited_values);
}

template<typename T>
bool trees_identical(BST_Node<T>* a, BST_Node<T>* b) {
    if (a == nullptr && b == nullptr) {
        return true;
    }

    if (a == nullptr || b == nullptr) {
        return false;
    }

    return (a->val == b->val) &&
           trees_identical(a->left, b->left) &&
           trees_identical(a->right, b->right);
}


#endif //TREE_H
