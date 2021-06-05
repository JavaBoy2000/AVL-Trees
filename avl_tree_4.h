#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <bits/stdc++.h>
// #include <stdlib.h>     /* abs, lmao c++ got a six pack */ // I don't need this cause I need the negative to
// tell which kind of rotation I need to do in the tree

using std::cout;
using std::endl;
using std::cerr;
using std::ofstream;
using namespace std;
// AVLTree()

// .h files are used for class and struct declarations and definitions
// If I'm not using templating then you should define your functions in a cpp
// file and declare your functions in a header file but since you ARE templating
// then you SHOULD do both implementation and declaration in the same place in the
// header file because of templating.

// AVLTree itself is a class. I can make the class with an array
// or linked list components. Pointers are probably going to be much easier
// cause arrays have weird formulas. Pointers are the way to go when initializing
// the class for the BST.

// f2 on a variable, you can replace other instances of that variable
// select and ctrl slash will comment all out.
// alt shift f will auto format your code and it won't break anything, on Kyle's honour

// arrows are pointers and dot operator is for non-pointers

// struct is public by default
template <typename Comparable> // type parameter
struct node
{
    Comparable data;         // public member, data must be an int or some other type besides a pointer
    node<Comparable> *left;  // public member
    node<Comparable> *right; // public member
                             // Could possibly add rule of three here, talk to Ritchey.
    Comparable balance_factor; // public member, acts as the same type as data
    Comparable has_left; // public member, says whether or not the node has a left child
    Comparable has_right; // public member, says wehther or not the node has a right child
    Comparable level; // public member, gets the level of each node
    Comparable count_of_nodes; // public member, count of nodes in both the left and right subtree

    // node<>T* parent; // used to traverse back up tree. Public member
    // might not even need to use the parent node if I implement
    // post order traversal to delete all the nodes in the destructor.
    // node(); // constructor, I wouldn't need this because I would
    // actually need a constructor for the BST class to construct an
    // empty tree.

}; // end node


// class is private by default
template <typename T2> // can have same template names when templating elsewhere if that makes sense
class AVLTree
{
private:
    void helper_for_destructor(node<T2> *curr_node)
    { 

        if (curr_node == nullptr)
            return;
        if (curr_node->left != nullptr)
        {
            // std::cout << "You're in the left conditional in the helper function for the destructor" << std::endl;
            helper_for_destructor(curr_node->left);
        } // end if
        if (curr_node->right != nullptr)
        {
            helper_for_destructor(curr_node->right);
        } // end if
        delete curr_node;
        // std::cout << "You're in the helper function for the destructor, in the back" << std::endl;
    } // end helper_for_destructor

    node<T2> *copy(node<T2> *node_pointer) // pointer to current node
    {
        node<T2> *temp_root = new node<T2>(node_pointer->data); // preorder traversal
        if (node_pointer->left != nullptr)
            temp_root->left = copy(node_pointer->left); // left->copy...
        // node_pointer->left will access the left subtree
        if (node_pointer->right != nullptr)
            temp_root->right = copy(node_pointer->right); // right->copy...
        // node_pointer->right will access the right subtree
        return temp_root;
    } // end copy
    // Reason we made copy() is cause we are setting temp_root to root.

    bool search(const node<T2> *curr_node, const T2 &value) const
    {
        if (curr_node == nullptr) // 1st conditional, checks to see if bst is empty
        {                      
            std::cout << "Not Found... " << value << std::endl;
            return false;
        }                             // end if
        if (curr_node->data == value) // 2nd conditional, finds the value
        {
            std::cout << "Found... " << value << std::endl;
            return true;
        }                            // end if
        if (value < curr_node->data) // 3rd conditional, sees if value is less than current node value
        {
            return search(curr_node->left, value); // I need a node pointer
        }                                          // end if
        if (value > curr_node->data)               // 4th conditional
        {
            return search(curr_node->right, value);
        } // end if
        return false;
    } // end search

public:
    node<T2> *root; // public data member, why is it private if it is in public?
    // root is pointer to the top of the tree.
    node<T2> *pub_prev; // this is for prev_node

    // declare and define the constructor.
    AVLTree()
    {
        root = nullptr;
        // see if you need to set the left and right pointers of the root equal to nullptr
    } // end AVLTree()

    ~AVLTree()
    {
        // Implement post order traversal and for every node
        // use the delete operator to destruct the BST.
        // code for this exists, I have it.
        // this destructor only gets called twice
        helper_for_destructor(root);
        // node<T2>*, look at this later.
        // std::cout << "You're in the actual destructor!! SUPER END" << std::endl;

    } // end Destructor

    AVLTree(const AVLTree &bst)
    { // bst has all data
        root = copy(bst.root);
    } // end copy constructor

    AVLTree &operator=(const AVLTree &bst)
    { // copy assignment operator (CAO)
        // Very similar to copy constructor
        // copy of yourself into yourself does nothing, ideally.
        // wrap functionality of the CAO into an if statement.
        if (&bst != this) // aren't these two data types different?
        {                 // other tree is not equal this tree
            // && is pointer and "this" is a pointer type.
            // this is a pointer and it operates on A when A = B, for example
            helper_for_destructor(root); // this takes care of memory leaks, kills everything
            root = copy(bst.root);       // copy constructor, it exists. I don't really know why

        }             // end if
        return *this; // dereferenced pointer is reference

        // I want more explanation on this, specifically the root=copy thing also "this"

    } // end copy assignment operator

    // End of Rule of Three

    bool contains(const T2 &to_be_found) const
    {
        // Recursion saves us a headache here, it does. But it also gives us one when we code
        std::cout << "Searching... " << to_be_found << std::endl;
        return search(root, to_be_found);
    } // end contains

    void insert(const T2 &to_be_inserted) { // to_be_inserted is a pass by constant reference
    // just gets the value it dereferences a pointer which gives the value. "Automatically dereferenced pointer" Oh

        // Use a while loop that checks for a nullptr
        // and once you hit a nullptr insert.
        // You will traverse with conditionals but it's basically like
        // the search function. We should've just done recursion with a helper function

        /*
            How this insert works is basically we compare the value we want to insert to values in the
            tree and along the way we determine whether or not it is to the left or right of its parent
            node and then we create a new node and insert it into the tree depending on whether or not
            it's to the left or the right.
        */ 

        node<T2> *curr_node = root;
        node<T2> *prev_node;
        bool is_left = false;
        bool is_right = false;
        std::cout << "Inserting... " << to_be_inserted << std::endl;
        if (curr_node == nullptr) { // check if curr_node is equal to nullptr, checks for emptiness
            node<T2> *node_to_be_inserted = new node<T2>;
            node_to_be_inserted->data = to_be_inserted; 
            node_to_be_inserted->left = nullptr;
            node_to_be_inserted->right = nullptr;
            root = node_to_be_inserted; // the root tree has been created
            return;
        } // end if
        while (curr_node != nullptr) {
            prev_node = curr_node;
            if (to_be_inserted > curr_node->data) {                             
                curr_node = curr_node->right;
                is_right = true;
                is_left = false;
            } // end if
            else if (to_be_inserted < curr_node->data) { // second case, this is left insert
                curr_node = curr_node->left;
                is_right = false;
                is_left = true;
            } // end else if
            else {
                throw std::invalid_argument("Error: Duplicate found"); 
            } // end else
        } // end while
        node<T2> *node_to_be_inserted = new node<T2>;
        node_to_be_inserted->data = to_be_inserted;
        node_to_be_inserted->left = nullptr;
        node_to_be_inserted->right = nullptr;
        if (is_left) {
            prev_node->left = node_to_be_inserted;
        } // end if
        else {
            prev_node->right = node_to_be_inserted;
        } // end else
        // node_pointer->balance_factor = longest_path_value(longestPath(node_pointer->left)) - longest_path_value(longestPath(node_pointer->right));

        correct_balance_factor_setter_with_recursion(root);
        recursive_out_of_balance_checker(root); 
        count_setter(root);
    } // end insert

    int counter(node<T2>*node_pointer) {
        int count =  1;
        if (node_pointer ==NULL) {
            return 0;
        } // end if
        else {
            count += counter(node_pointer->left);
            count += counter(node_pointer->right);
            return count;
        } // end else
    } // end counter

    void count_setter(node<T2>*node_pointer) {
        if (node_pointer == NULL) {
            return;
        } // end if
        node_pointer->count_of_nodes = counter(node_pointer);
        // std::cout << "counter(" << node_pointer->data << "): " << counter(node_pointer) << std::endl;
        count_setter(node_pointer->left);
        count_setter(node_pointer->right);
    } // end count_setter

    vector<int> longestPath(node<T2>*node_pointer) {
 
        // If node_pointer is null means there
        // is no binary tree so
        // return a empty vector
        if (node_pointer == NULL) {
            vector<int> temp = {};
            return temp;
        }
    
        // Recursive call on node_pointer->right
        vector<int> rightvect = longestPath(node_pointer->right);
    
        // Recursive call on node_pointer->left
        vector<int> leftvect = longestPath(node_pointer->left);
    
        // Compare the size of the two vectors
        // and insert current node accordingly
        if (leftvect.size() > rightvect.size()) {
            leftvect.push_back(node_pointer->data);
        } // end if
            else {
                rightvect.push_back(node_pointer->data);
            } // end else
    
        // Return the appropriate vector
        return (leftvect.size() > rightvect.size()
                    ? leftvect
                    : rightvect); // what even is this
        } // end longestPath

    int longest_path_value(vector<int> output) {
        int n = output.size();
        return n - 1;
    } // end longest_path_value

    void correct_balance_factor_setter_with_recursion(node<T2>*node_pointer) {
        if(node_pointer == NULL) {
            return;
        } // end if
        node_pointer->balance_factor = longest_path_value(longestPath(node_pointer->left)) - longest_path_value(longestPath(node_pointer->right));
        // std::cout << "balance factor of " << node_pointer->data << ": " << node_pointer->balance_factor << std::endl;
        correct_balance_factor_setter_with_recursion(node_pointer->left);
        correct_balance_factor_setter_with_recursion(node_pointer->right);
    } // end correct_balance_factor_setter_with_recursion

    void recursive_out_of_balance_checker(node<T2>*node_pointer) {
        // We need to check to see that a node is out of balance whenever it's inserted
        if (node_pointer == NULL) {
            return;
        } // end if

        if ((node_pointer->balance_factor == 2) && (node_pointer->left->right != nullptr) && (longest_path_value(longestPath(node_pointer)) == 2)) {
            if (node_pointer == root) {
                    std::cout << "root_case_left_right_rotation in conditional" << std::endl; // it works that's cool
                    root_case_left_right_rotation();
                } // end if
                    else if (prev_node_getter(root, node_pointer->data)->left->data == node_pointer->data) {
                        std::cout << node_pointer->data << " needs a left right rotation with prev on right side of node_pointer" << std::endl;
                        left_right_rotation_prev_on_right(node_pointer);
                    } // end else if
                    else if (prev_node_getter(root, node_pointer->data)->right->data == node_pointer->data)  {
                        std::cout << node_pointer->data << " needs a left right rotation with prev on left side of node_pointer" << std::endl;
                        left_right_rotation_prev_on_left(node_pointer);
                    } // end else if
            return;
        } // end if
            else if ((node_pointer->balance_factor == 2) && (node_pointer->left->left != nullptr) && (longest_path_value(longestPath(node_pointer)) == 2)) {
                    // Get the longest path of node_pointer and check to see if it is 2.
                if (node_pointer == root) {
                    std::cout << "root_case_right_rotation in conditional" << std::endl; // it works that's cool
                    root_case_right_rotation();
                } // end if
                    else if (prev_node_getter(root, node_pointer->data)->left->data == node_pointer->data) {
                        std::cout << node_pointer->data << " needs a right rotation with prev on right side of node_pointer" << std::endl;
                        right_rotation_prev_on_right(node_pointer);
                    } // end else if
                    else if (prev_node_getter(root, node_pointer->data)->right->data == node_pointer->data)  {
                        std::cout << node_pointer->data << " needs a right rotation with prev on left side of node_pointer" << std::endl;
                        right_rotation_prev_on_left(node_pointer);
                    } // end else if
                return;
            } // end if
            else if ((node_pointer->balance_factor == -2) && (node_pointer->right->left != nullptr)  && (longest_path_value(longestPath(node_pointer)) == 2)) {
                // this is right left
                if (node_pointer == root) {
                    std::cout << "root_case_right_left_rotation in conditional" << std::endl; // it works that's cool
                    root_case_right_left_rotation();
                } // end if
                    else if (prev_node_getter(root, node_pointer->data)->left->data == node_pointer->data) {
                        std::cout << node_pointer->data << " needs a right left rotation with prev on right side of node_pointer" << std::endl;
                        right_left_rotation_prev_on_right(node_pointer);
                    } // end else if
                    else if (prev_node_getter(root, node_pointer->data)->right->data == node_pointer->data)  {
                        std::cout << node_pointer->data << " needs a left right rotation with prev on left side of node_pointer" << std::endl;
                        right_left_rotation_prev_on_left(node_pointer);
                    } // end else if
                return;
            } // end else if
            else if ((node_pointer->balance_factor == -2) && (node_pointer->right->right != nullptr) && (longest_path_value(longestPath(node_pointer)) == 2)) {
                if (node_pointer == root) {
                    std::cout << "root_case_left_rotation in conditional" << std::endl; // it works that's cool
                    root_case_left_rotation();
                } // end if
                    else if (prev_node_getter(root, node_pointer->data)->left->data == node_pointer->data) {
                        std::cout << node_pointer->data << " needs a left rotation with prev on right side of node_pointer" << std::endl;
                        left_rotation_prev_on_right(node_pointer);
                    } // end else if
                    else if (prev_node_getter(root, node_pointer->data)->right->data == node_pointer->data)  {
                        std::cout << node_pointer->data << " needs a left rotation with prev on left side of node_pointer" << std::endl;
                        left_rotation_prev_on_left(node_pointer);
                    } // end else if
            } // end else if
            return;
        recursive_out_of_balance_checker(node_pointer->left);
        recursive_out_of_balance_checker(node_pointer->right);
        // return false;
    } // end is_out_of_balance

    void left_right_rotation_prev_on_right(node<T2>*node_pointer) {
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->left->data; // is 17
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->left->left = temp_node; // 17 becomes left of higher 17
        node_pointer->left->data = node_pointer->left->right->data; // higher 17 becomes 18
        node_pointer->left->right->data = node_pointer->data; // lower 18 becomes 19
        node_pointer = node_pointer->left; // I don't think this works
        prev_node_getter(root, prev_node_getter(root, node_pointer->data)->data)->left = node_pointer; // basically a parent node
    } // end left_right_rotation

    void left_right_rotation_prev_on_left(node<T2>*node_pointer) {
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->left->data; // is 17
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->left->left = temp_node; // 17 becomes left of higher 17
        node_pointer->left->data = node_pointer->left->right->data; // higher 17 becomes 18
        node_pointer->left->right->data = node_pointer->data; // lower 18 becomes 19
        node_pointer = node_pointer->left; // I don't think this works
        prev_node_getter(root, prev_node_getter(root, node_pointer->data)->data)->right = node_pointer; // basically a parent node
    } // end left_right_rotation_prev_on_left

    void right_left_rotation_prev_on_left(node<T2>*node_pointer) {
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->right->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->right->right = temp_node;
        node_pointer->right->data = node_pointer->right->left->data; // higher 5 becomes 7
        node_pointer->right->left->data = node_pointer->data; // lower 7 becomes 10
        node_pointer = node_pointer->right; // higher 10 becomes 7
        prev_node_getter(root, prev_node_getter(root, node_pointer->data)->data)->right = node_pointer; // basically a parent node
    } // end right_left_rotation

    void right_left_rotation_prev_on_right(node<T2>*node_pointer) {
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->right->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->right->right = temp_node;
        node_pointer->right->data = node_pointer->right->left->data; // higher 5 becomes 7
        node_pointer->right->left->data = node_pointer->data; // lower 7 becomes 10
        node_pointer = node_pointer->right; // higher 10 becomes 7
        prev_node_getter(root, prev_node_getter(root, node_pointer->data)->data)->left = node_pointer; // basically a parent node
    } // end right_left_rotation

    void left_rotation_prev_on_left(node<T2>*node_pointer) { // prev on left means it's left of node_pointer
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->right->left = temp_node; // A goes to the left of B.
        std::cout << "node_pointer->data: " << node_pointer->data << std::endl;
        prev_node_getter(root, node_pointer->data)->right = node_pointer->right; // come back here
    } // end left_rotation_prev_on_left

    void left_rotation_prev_on_right(node<T2>*node_pointer) { 
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->right->left = temp_node; // A goes to the left of B.
        std::cout << "node_pointer->data: " << node_pointer->data << std::endl;
        prev_node_getter(root, node_pointer->data)->left = node_pointer->right;
    } // end left_rotation_prev_on_right

    void right_rotation_prev_on_left(node<T2>*node_pointer) {
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->left->right = temp_node;
        prev_node_getter(root, node_pointer->data)->right = node_pointer->left;
    } // end right_rotation

    void right_rotation_prev_on_right(node<T2>*node_pointer) {
        node<T2> *temp_node = new node<T2>;
        temp_node->data = node_pointer->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        node_pointer->left->right = temp_node;
        prev_node_getter(root, node_pointer->data)->left = node_pointer->left;
    } // end right_rotation

    void root_case_left_rotation() {
        // what would node_pointer be? The root node? Sure then we would need no argument
        node<T2> *temp_node = new node<T2>;
        temp_node->data = root->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        root->left = temp_node; // root->left = 15
        root->data = root->right->data; // 15 is now 25
        root->right->data = root->right->right->data; // 25 is now 30
        root->right->right = nullptr; // lower 30 is now gone
        // I hope this works lmao
    } // end root_case_left_rotation

    void root_case_right_rotation() {
        // what would node_pointer be? The root node? Sure then we would need no argument
        node<T2> *temp_node = new node<T2>;
        temp_node->data = root->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        root->right = temp_node; // root->right = 15
        root->data = root->left->data; // 15 is now 10
        root->left->data = root->left->left->data; // 10 is now 3
        root->left->left = nullptr; // lower 3 is now gone
        // I hope this works lmao, it should
    } // end root_case_left_rotation

    void root_case_left_right_rotation() {
        // These will be a little harder to figure out
        // 1. Make a temp node for root->left
        node<T2> *temp_node = new node<T2>;
        temp_node->data = root->left->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        // 2. Initalize left node to root->left
        root->left->left = temp_node;
        // 3.
        root->left->data = root->left->right->data;
        // 4.
        root->left->right->data = root->data;
        // 5.
        root = root->left;

    } // end root_case_left_right_rotation

    void root_case_right_left_rotation() {
        // These will be a little harder to figure out
        // 1. Make a temp node for root->left
        node<T2> *temp_node = new node<T2>;
        temp_node->data = root->right->data;
        temp_node->left = nullptr;
        temp_node->right = nullptr;
        // 2. Initalize left node to root->left
        root->right->right = temp_node;
        // 3.
        root->right->data = root->right->left->data;
        // root->left->data = root->left->right->data; code from left right
        // 4.
        root->right->left->data = root->data;
        // 5.
        root = root->right;

    } // end root_case_left_right_rotation

    node<T2> *prev_node_getter(node<T2> *nody, const T2 &to_be_removed) { // we might need to use this for rotations in place of a parent node
        std::cout << "We want to find the previous node of " << to_be_removed << std::endl;
        node<T2> *prev_node = pub_prev;
        while (nody != nullptr) {
            if (to_be_removed > nody->data) {
                prev_node = nody;
                nody = nody->right;
            } // end if
                else if (to_be_removed < nody->data) {
                    prev_node = nody;
                    nody = nody->left;
                } // end else if
                else if (to_be_removed == nody->data) {
                    break;
                } // end else if
                    else {
                        throw std::invalid_argument("Error: Duplicate found");
                    } // end else
        } // end while
        std::cout << "prev_node->data: " << prev_node->data << std::endl;
        return prev_node;
    } // end prev_node_getter

    int findMax(int a, int b) {
        if (a > b) {
            return a;
        } // end if
            else if (b > a) {
                return b;
            } // end else if
        return 0;
    } // end findMax

    int find_height(node<T2>*node_pointer) {
        // fucking recursion
        if(node_pointer == NULL) {
            return 0;
        } // end if
        return findMax(find_height(node_pointer->left), find_height(node_pointer->right)) + 1;
    } // end find_height

    bool is_leaf(node<T2> *node_pointer) { // takes in an entire node 
        if ((node_pointer->left == nullptr) && (node_pointer->right == nullptr)) {
            return true;
        } // end if
        else {
            return false;
        } // end else
    } // end is_leaf

    bool is_internal_node(node<T2> *node_pointer) {
        if ((node_pointer->left != nullptr) || (node_pointer->right != nullptr)) {
            return true;
        } // end if
        else {
            return false;
        } // end else
    } // end is_internal_node

    void inorder(node<T2>*node_pointer) {
        if (node_pointer != NULL) { // recursive definition
            inorder(node_pointer->left);
            std::cout << node_pointer->data << " ";
            inorder(node_pointer->right);
        } // end if
    } // end inorder

    void postorder(node<T2>*node_pointer) {
        if (node_pointer == NULL) {
            return;
        } // end if
        postorder(node_pointer->left); // recur on left subtree
        postorder(node_pointer->right); // recur on right subtree
        std::cout << node_pointer->data << " ";
    } // end postorder

    void preorder(node<T2>*node_pointer) {
        if (node_pointer == NULL) {
            return;
        } // end if
        cout << node_pointer->data << " ";
        preorder(node_pointer->left);
        preorder(node_pointer->right);
    } // end preorder

    void doing_stuff_in_LS (node<T2> *curr_node, node<T2> *prev_node) {
        if (is_leaf(curr_node->left)) { 
                std::cout << "Case 1" << std::endl;
                curr_node->data = curr_node->left->data;
                curr_node->left = nullptr;
                delete curr_node->left;
            } // end if
                else if (curr_node->left->right == nullptr) { 
                    std::cout << "Case 2" << std::endl;
                    curr_node->data = curr_node->left->data;
                    curr_node->left = curr_node->left->left;
                } // end else if
                else if (curr_node->left->left == nullptr) {
                    if (is_leaf(find_max_node(curr_node->left))) {
                        std::cout << "Case 3" << std::endl;
                        std::cout << "find_max_node(curr_node->left)->data)->data: " << find_max_node(curr_node->left)->data << std::endl;
                        prev_node = prev_node_getter(root, find_max_node(curr_node->left)->data);
                        curr_node->data = find_max_node(curr_node->left)->data;
                        prev_node->right = nullptr;
                        delete prev_node->right;
                    } // end if
                        else if (is_internal_node(find_max_node(curr_node->left))) {
                            std::cout << "Case 4" << std::endl;
                            prev_node = prev_node_getter(root, find_max_node(curr_node->left)->data);
                            curr_node->data = find_max_node(curr_node->left)->data;
                            prev_node->right = prev_node->right->left;
                        } // end else if
                } // end else if
    } // end doing_stuff_in_LS

    void doing_stuff_in_RS (node<T2> *curr_node, node<T2> *prev_node) {
        // right subtree does exist and the left subtree does not
                std::cout << "You're in the left subtree existence INTERNAL_NODE conditional!!" << std::endl;
                // There are truly six cases. Try four bitch. Try eight... maybe more
                if (is_leaf(curr_node->right)) { 
                    std::cout << "Case 5" << std::endl;
                    curr_node->data = curr_node->right->data;
                    curr_node->right = nullptr;
                    delete curr_node->right;
                } // end if
                    else if (curr_node->right->left == nullptr) {
                        std::cout << "Case 6" << std::endl;
                        curr_node->data = curr_node->right->data;
                        curr_node->right = curr_node->right->right; // moves
                } // end else if
                else if (curr_node->right->right == nullptr) { // no right subtree of RSR (Right Subtree Root)
                    if (is_leaf(find_min_node(curr_node->right))) {
                        std::cout << "Case 7" << std::endl;
                        std::cout << "find_min_node(curr_node->right)->data)->data: " << find_min_node(curr_node->right)->data << std::endl;
                        prev_node = prev_node_getter(root, find_min_node(curr_node->right)->data);
                        curr_node->data = find_min_node(curr_node->right)->data;
                        prev_node->left = nullptr;
                        delete prev_node->left;
                    } // end if
                        else if (is_internal_node(find_min_node(curr_node->right))) {
                            std::cout << "Case 8" << std::endl;
                            prev_node = prev_node_getter(root, find_min_node(curr_node->right)->data);
                            curr_node->data = find_min_node(curr_node->right)->data;
                            prev_node->left = prev_node->left->right;
                        } // end else if
                } // end else if

    } // end doing_stuff_in_RS



}; // end class

#endif