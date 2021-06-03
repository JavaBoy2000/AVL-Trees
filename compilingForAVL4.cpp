#include <iostream>
// #include "avl_tree.h"
#include "avl_tree_4.h"
// Hello this is an update to the file

int main() {
    std::cout << "Hello walls" << std::endl;

    // AVLTree<int> left_right_rotation_tree;
    // left_right_rotation_tree.insert(15);
    // left_right_rotation_tree.insert(10);
    // left_right_rotation_tree.insert(5);
    // left_right_rotation_tree.insert(7);
    // left_right_rotation_tree.insert(8); // illustrate in tree
    /*
    std::cout << "left_right_rotation_tree.root->balance_factor: " << left_right_rotation_tree.root->balance_factor << std::endl;
    std::cout << "left_right_rotation_tree.root->left->balance_factor: " << left_right_rotation_tree.root->left->balance_factor << std::endl;
    std::cout << "left_right_rotation_tree.root->left->right->balance_factor: " << left_right_rotation_tree.root->left->right->balance_factor << std::endl;
    */
    // std::cout << "left_right_rotation_tree.root->left->right->right->balance_factor: " << left_right_rotation_tree.root->left->right->right->balance_factor << std::endl;
    // left_right_rotation_tree.inorder(left_right_rotation_tree.root);
    // left_right_rotation_tree.left_right_rotation(left_right_rotation_tree.root);
    // std::cout << std::endl;
    // left_right_rotation_tree.inorder(left_right_rotation_tree.root);
    // std::cout << std::endl;
    // well let's print out the tree here too and see how it looks
    // std::cout << "left_right_rotation_tree.root->data: " << left_right_rotation_tree.root->data << std::endl;
    // std::cout << "left_right_rotation_tree.root->right->data: " << left_right_rotation_tree.root->right->data << std::endl;
    // std::cout << "left_right_rotation_tree.root->left->data: " << left_right_rotation_tree.root->left->data << std::endl;
    // std::cout << "left_right_rotation_tree.root->left->left->data: " << left_right_rotation_tree.root->left->left->data << std::endl;
    // std::cout << "left_right_rotation_tree.root->left->right->data: " << left_right_rotation_tree.root->left->right->data << std::endl;

    // std::cout << "left_right_rotation_tree.root->left->data: " << left_right_rotation_tree.root->left->data << std::endl;
    // std::cout << "left_right_rotation_tree.root->right->data: " << left_right_rotation_tree.root->right->data << std::endl;
    // std::cout << "left_right_rotation_tree.root->left->right->data: " << left_right_rotation_tree.root->left->right->data << std::endl;
    // Alright well that works but let's do a little larger case because I don't like this resetting the root solution we have

   /*
        10                 7
       /                  / \
      /                  5   10
     5          =>           
      \                This is the kind of tree that we
       7               want after a left right rotation.
   */

    // We need some bigger cases for the left right rotation in trees

    /*
    AVLTree<int> left_right_rotation_tree_2;
    left_right_rotation_tree_2.insert(41);
    left_right_rotation_tree_2.insert(20);
    left_right_rotation_tree_2.insert(65);
    left_right_rotation_tree_2.insert(50);
    left_right_rotation_tree_2.insert(26);
    left_right_rotation_tree_2.insert(11);
    left_right_rotation_tree_2.insert(23);
    left_right_rotation_tree_2.insert(29);
    left_right_rotation_tree_2.insert(55);
    */
    // do all the checks
    /*
    std::cout << "left_right_rotation_tree_2.root->left->data: " << left_right_rotation_tree_2.root->left->data << std::endl;
    std::cout << "left_right_rotation_tree_2.root->left->left->data: " << left_right_rotation_tree_2.root->left->left->data << std::endl;
    std::cout << "left_right_rotation_tree_2.root->left->right->data: " << left_right_rotation_tree_2.root->left->right->data << std::endl;
    std::cout << "left_right_rotation_tree_2.root->left->right->right->data: " << left_right_rotation_tree_2.root->left->right->right->data << std::endl;
    std::cout << "left_right_rotation_tree_2.root->left->right->left->data: " << left_right_rotation_tree_2.root->left->right->left->data << std::endl;
    */

    // std::cout << left_right_rotation_tree_2.root->right->left->left->balance_factor << std::endl;

    // left_right_rotation_tree_2.longestPath(left_right_rotation_tree_2.root->left); // do not try to print this out
    /*
    vector<int> output = left_right_rotation_tree_2.longestPath(left_right_rotation_tree_2.root->left);
    int n = output.size();
    std::cout << "n: " << n << std::endl;
    std::cout << left_right_rotation_tree_2.longest_path_value(left_right_rotation_tree_2.longestPath(left_right_rotation_tree_2.root)) << std::endl;
    // So this thing works apparently which is good but longestPath is built into vector.
    */


    /*

                41
               /  \
              /    \
             /      \
            /        \
           /          \
          20          65
         /  \        /
        /    \      /
       11    26    50
            /  \    \
           23  29   55

           65 will need a left right rotation, we got it!!

        1. 55 trades spots with 50. 
        2. 55 trades spots with 65.
    */

   

    /*
    AVLTree<int> right_rotation;

    right_rotation.insert(10);
    right_rotation.insert(5);
    right_rotation.insert(2);
    std::cout << "right_rotation.root->balance_factor: " << right_rotation.root->balance_factor << std::endl;
    std::cout << "right_rotation.root->left->balance_factor: " << right_rotation.root->left->balance_factor << std::endl;
    std::cout << "right_rotation.root->left->left->balance_factor: " << right_rotation.root->left->left->balance_factor << std::endl;
    */

    /*
            10
            /
           /            5
          5      =>    / \
         /            2  10
        2
    */

    /*
    AVLTree<int> right_rotation_tree_2;

    right_rotation_tree_2.insert(41);
    right_rotation_tree_2.insert(25);
    right_rotation_tree_2.insert(69);
    right_rotation_tree_2.insert(13);
    right_rotation_tree_2.insert(55);
    right_rotation_tree_2.insert(45);

    std::cout << "inorder: ";
    right_rotation_tree_2.inorder(right_rotation_tree_2.root);
    std::cout << std::endl;
    std::cout << "preorder: ";
    right_rotation_tree_2.preorder(right_rotation_tree_2.root);
    std::cout << std::endl;
    std::cout << "postorder: ";
    right_rotation_tree_2.postorder(right_rotation_tree_2.root);
    std::cout << std::endl;
    */

    /* 
    
                41                      41
               /  \                    /  \
              /    \                  /    \
             25    69       =>       25    55
            /      /                /     /  \
           13     55               13    45  69
                 /
                45
            
        1. C is 69, B is 55, A is 45
        2. 69 (C) goes to the right of 55 (B)
        3. 41->right becomes 55 (B)

    */
    
    
    /*
    AVLTree<int> left_rotation_tree;

    left_rotation_tree.insert(10);
    left_rotation_tree.insert(15);
    left_rotation_tree.insert(20);
    std::cout << "left_rotation_tree.root->balance_factor: " << left_rotation_tree.root->balance_factor << std::endl;
    std::cout << "left_rotation_tree.root->right->balance_factor: " << left_rotation_tree.root->right->balance_factor << std::endl;
    std::cout << "left_rotation_tree.root->right->right->balance_factor: " << left_rotation_tree.root->right->right->balance_factor << std::endl;
    left_rotation_tree.left_rotation(left_rotation_tree.root);
    std::cout << "left_rotation_tree.root->data: " << left_rotation_tree.root->data << std::endl;
    left_rotation_tree.inorder(left_rotation_tree.root);
    */
    
    

    /*
        10
          \                   15
           \        =>       /  \
           15               10  20
             \
             20              10 becomes left
                             child of 15.
    */

    /*
    AVLTree<int> left_rotation_tree_2;

    left_rotation_tree_2.insert(41);
    left_rotation_tree_2.insert(64);
    left_rotation_tree_2.insert(25);
    left_rotation_tree_2.insert(37);
    left_rotation_tree_2.insert(71);
    left_rotation_tree_2.insert(39);

    std::cout << "left_rotation_tree_2.root: " << left_rotation_tree_2.root->data << std::endl;
    std::cout << "left_rotation_tree_2.root->left: " << left_rotation_tree_2.root->left->data << std::endl;
    std::cout << "left_rotation_tree_2.root->left->left: " << left_rotation_tree_2.root->left->left->data << std::endl;
    std::cout << "left_rotation_tree_2.root->left->right: " << left_rotation_tree_2.root->left->right->data << std::endl;
    */


    /*
            41                          41
           /  \                        /  \
          /    \                      /    \
         25    64          =>        37    64 
          \      \                  /  \     \
          37     71                25  39    71
            \
            39

        1. 25 is A, 37 is B, 39 is C
        2. 25 (A) goes to the left of 37 (B)
        3. 41->left becomes 37 (B)

    */
    



/*
    AVLTree<int> right_left_rotation;
    // left_right_rotation.insert(15);
    right_left_rotation.insert(10);
    right_left_rotation.insert(15);
    right_left_rotation.insert(13);
    std::cout << "right_left_rotation.root->balance_factor: " << right_left_rotation.root->balance_factor << std::endl;
    std::cout << "right_left_rotation.root->left->balance_factor: " << right_left_rotation.root->left->balance_factor << std::endl;
    std::cout << "right_left_rotation.root->left->right->balance_factor: " << right_left_rotation.root->left->right->balance_factor << std::endl;
*/

    /*
        10
          \               13
           \      =>     /  \
           15           10   15
           /
          13

        I need a larger case for a right left rotation cause I don't wanna deal with three nodes rn
        cause I gotta fix it later.
    */

   /*
    AVLTree<int> right_left_rotation_2;
    right_left_rotation_2.insert(41);
    right_left_rotation_2.insert(20);
    right_left_rotation_2.insert(65);
    right_left_rotation_2.insert(70);
    right_left_rotation_2.insert(67);
    right_left_rotation_2.insert(11);
    right_left_rotation_2.insert(26);
    right_left_rotation_2.insert(23);
    right_left_rotation_2.insert(29);

    std::cout << "right: " << right_left_rotation_2.root->right->data << std::endl; // 65
    std::cout << "right->right: " << right_left_rotation_2.root->right->right->data << std::endl; // 70
    std::cout << "right->left: " << right_left_rotation_2.root->right->left->data << std::endl; // 67

    // std::cout << "longest path of " <<  right_left_rotation_2.root->right->data << ": " << right_left_rotation_2.longest_path_value(right_left_rotation_2.longestPath(right_left_rotation_2.root->right)) << std::endl;
    // std::cout << "longest path of " <<  right_left_rotation_2.root->right->right->data << ": " << right_left_rotation_2.longest_path_value(right_left_rotation_2.longestPath(right_left_rotation_2.root->right->right)) << std::endl;
    // std::cout << "longest path of " <<  right_left_rotation_2.root->right->right->left->data << ": " << right_left_rotation_2.longest_path_value(right_left_rotation_2.longestPath(right_left_rotation_2.root->right->right->left)) << std::endl;

    std::cout << "balance factor of " << right_left_rotation_2.root->right->data << ": " << right_left_rotation_2.root->right->balance_factor << std::endl;

    std::cout << "inorder: ";
    right_left_rotation_2.inorder(right_left_rotation_2.root);
    std::cout << std::endl;
    std::cout << "preorder: ";
    right_left_rotation_2.preorder(right_left_rotation_2.root);
    std::cout << std::endl;
    std::cout << "postorder: ";
    right_left_rotation_2.postorder(right_left_rotation_2.root);
    std::cout << std::endl;
    */


    /*
                41
               /  \
              /    \
             /      \
            /        \
           /          \
          20          65
         /  \           \
        /    \           \
       11    26          70
            /  \         /
           23  29       67

           65 will need a right left rotation, we got it!!

        1. 70 trades spots with 65. 
        2. 67 goes to the left of 70.

        1. 67 trades with 65.
        2. 
    */

    /*
    AVLTree<int> random_tree;
    random_tree.insert(15);
    random_tree.insert(20);
    random_tree.insert(5);
    random_tree.insert(6);
    random_tree.insert(19);
    random_tree.insert(35);
    random_tree.insert(12);
    random_tree.insert(17);
    // no clue what this tree looks like, let's see if it screams at me
    random_tree.insert(18);
    random_tree.insert(50);
    random_tree.insert(65);
    */
    // random_tree.count_nodes(random_tree.root, 0);
    /*
    std::cout << std::endl;
    int count = random_tree.counter(random_tree.root);
    std::cout << "count: " << count << std::endl;

    int count_of_20 = random_tree.counter(random_tree.root->right);
    std::cout << "count_of_20: " << count_of_20 << std::endl; // 4
    // if greater than 3 then don't rotate

    std::cout << "random_tree.root->left->count_of_nodes: " << random_tree.root->left->count_of_nodes << std::endl;
    */

    /*
    std::cout << "inorder: ";
    random_tree.inorder(random_tree.root);
    std::cout << std::endl;
    std::cout << "preorder: ";
    random_tree.preorder(random_tree.root);
    std::cout << std::endl;
    std::cout << "postorder: ";
    random_tree.postorder(random_tree.root);
    std::cout << std::endl;
    */

    /*
                15                                  15                                      15
               /  \                                /  \                                    /  \
              /    \       Insert 18              /    \         After rotation           /    \           Insert 50
             6     20         =>                 6     20             =>                 6     20              =>
            / \   /  \                          / \   /  \                              / \   /  \
           5  12 19  35                        5  12 19  35                            5  12 18  35
                /                                   /                                       /  \
               17                                  17                                      17  19
                                                    \
                                                    18                              I want to print this
                                                                                       tree out below
                                        This needs a left right rotation
                                
    */

    // I need to print out this entire tree
    /*
    std::cout << "random_tree.root->data: " << random_tree.root->data << std::endl; // 15

    std::cout << "random_tree.root->left->data: " << random_tree.root->left->data << std::endl; // 6
    std::cout << "random_tree.root->left->left->data: " << random_tree.root->left->left->data << std::endl; // 5
    std::cout << "random_tree.root->left->right->data: " << random_tree.root->left->right->data << std::endl; // 12
    // That's the entire left subtree above

    std::cout << "random_tree.root->right->data: " << random_tree.root->right->data << std::endl; // 20
    std::cout << "random_tree.root->right->left->data: " << random_tree.root->right->left->data << std::endl; // 18
    std::cout << "random_tree.root->right->left->left->data: " << random_tree.root->right->left->left->data << std::endl; // 17
    std::cout << "random_tree.root->right->left->right->data: " << random_tree.root->right->left->right->data << std::endl; // 19
    std::cout << "random_tree.root->right->right->data: " << random_tree.root->right->right->data << std::endl; // 50
    // That's the entire right subtree above. This is all correct. New insertions will be below

    std::cout << "random_tree.root->right->right->right->data: " << random_tree.root->right->right->right->data << std::endl; // 65
    std::cout << "random_tree.root->right->right->right->data: " << random_tree.root->right->right->left->data << std::endl; // 35
    */
    // All good with the new insert


    /*
    std::cout << "random_tree.root->right->left->data: " << random_tree.root->right->left->data << std::endl;
    std::cout << "random_tree.root->right->left->count_of_nodes: " << random_tree.root->right->left->count_of_nodes << std::endl;
    std::cout << "random_tree.root->right->left->balance_factor: " << random_tree.root->right->left->balance_factor << std::endl;
    */
    // std::cout << "random_tree.root->right->left->left->right->data: " << random_tree.root->right->left->left->right->data << std::endl;

    /*
    AVLTree<int> left_rotation_prev_node_cases;

    left_rotation_prev_node_cases.insert(42);
    left_rotation_prev_node_cases.insert(25);
    left_rotation_prev_node_cases.insert(67);
    left_rotation_prev_node_cases.insert(65);
    left_rotation_prev_node_cases.insert(37);
    left_rotation_prev_node_cases.insert(77);
    left_rotation_prev_node_cases.insert(39);
    left_rotation_prev_node_cases.insert(71);
    left_rotation_prev_node_cases.insert(69);   
    */

    /*
                42                                                      42
               /  \                                                    /  \
              /    \                                                  /    \
             25    67                                                37    67
              \      \       After left rotate on 25                /  \     \
               37    77                =>                          25  39    77
                \    /                                                       /
                39  71                                                      71
                    /                                                       /
                   69                                                      69

        1. left rotation with prev node on the right in the left subtree
        2. left rotation with prev node on the left in the right subtree

        // This tree case is used to test the different left rotates we've programmed
        // but we run into an error where 67 triggers a right left rotate which is no
        // good. I don't know why that gets triggered because the height of the right
        // subtree of 67 is 3 but I don't think I have a conditional for the right
        // subtree only the left.
    */

    // std::cout << left_rotation_prev_node_cases.root->right->data << std::endl;
    // std::cout << "longest path of 67: " << left_rotation_prev_node_cases.longest_path_value(left_rotation_prev_node_cases.longestPath(left_rotation_prev_node_cases.root->right)) << std::endl;
    // it's actually not an error what happens is the rotate happens before node 69 is inserted so what
    // we need to do is insert a node to the left of 67 and that should work and trigger the other left rotate.

    // Update we fixed it but now it triggers the right rotate which probably means we set up the wrong case in the tree
    // we have to just kind of fix that but also I'm concerned that there is only one case for the left and right rotate
    // and that there aren't two like I thought

    // I run into an error here where it does a right left rotate for node 67 which is weird
    // and I don't really know why it does that. I do now, it's because we haven't inserted node 69 yet.

    // I think you can trigger the prev on left of node_pointer by having a tree like this

    /*
        node
          \
          node
            \
            node
              \
              node
    */

    /*
    AVLTree<int> left_rotate_prev_on_left;

    left_rotate_prev_on_left.insert(42);
    left_rotate_prev_on_left.insert(23);
    left_rotate_prev_on_left.insert(61);
    left_rotate_prev_on_left.insert(17);
    left_rotate_prev_on_left.insert(29);
    left_rotate_prev_on_left.insert(51);
    left_rotate_prev_on_left.insert(73);
    left_rotate_prev_on_left.insert(79);
    left_rotate_prev_on_left.insert(81);
    */
    
    /*
            42                                                     42
           /  \                                                   /  \
          /    \                                                 /    \
         /      \               After rotation                  /      \
        23      61                   =>                        23      61
       /  \    /  \                                           /  \    /  \
      17  29  51  73                                         17  29  51  79
                    \                                                   /  \
                    79                                                 73  81
                      \                                                     
                      81                                    

      This should trigger the left rotation 
      on the previous node when it's too the 
      left of node_pointer
    */

    // Yes it triggers it and it works now we should work on the root cases
    // that don't really work out for us

    /*
    AVLTree<int> root_case_left_rotate;

    root_case_left_rotate.insert(15);
    root_case_left_rotate.insert(25);
    root_case_left_rotate.insert(30);

    std::cout << root_case_left_rotate.root->data << std::endl;
    std::cout << root_case_left_rotate.root->right->data << std::endl;
    std::cout << root_case_left_rotate.root->left->data << std::endl;
    */

    /*
        15                                    25
          \       After left rotate          /  \
          25            =>                  15  30
            \
            30

        // Initialize a temp_node with data equal to root node's data

        0. root->left = temp_node;

                    15
                   /  \
                  15  25
                        \
                        30

        1. root->data = root->right->data; // 15 becomes 25, make sure to save 15 though

                    25
                   /  \
                  15  25
                        \
                        30

                // Now we need to move the 30 to the lower 25 and get rid of the lower 30
                
        2. root->right = root->right->right; // lower 25 becomes node 30, I think this might give an error.
            // We could try setting the data of lower 25 to 30 and then setting the lower 30 to nullptr. Might work IDK

            2.1 root->right->data = root->right->right->data; // lower 25 becomes 30
            2.2 root->right->right = nullptr; // might give error, worth a try

                    25
                   /  \
                  15  30

    */

    // I think I figured it out. Mess with the data!!

    /*
    AVLTree<int> root_case_right_rotate;

    root_case_right_rotate.insert(15);
    root_case_right_rotate.insert(10);
    root_case_right_rotate.insert(3);

    // root_case_right_rotate

    std::cout << root_case_right_rotate.root->data << std::endl;
    std::cout << root_case_right_rotate.root->right->data << std::endl;
    std::cout << root_case_right_rotate.root->left->data << std::endl;
    */


    /*
        15                                    10
        /          After right rotate        /  \
       10                  =>               3   15
       /
      3

        // We need to be more thorough about this
    */

    AVLTree<int> root_case_left_right_rotate;

    root_case_left_right_rotate.insert(25);
    root_case_left_right_rotate.insert(17);
    root_case_left_right_rotate.insert(19);

    std::cout << root_case_left_right_rotate.root->data << std::endl;
    std::cout << root_case_left_right_rotate.root->right->data << std::endl;
    std::cout << root_case_left_right_rotate.root->left->data << std::endl;
    // very good 
    // root_case_left_right_rotate.inorder(root_case_left_right_rotate.root); // very good this works

    /*
            25
           /
          17
           \
           19

        Should be a fun case.

        1. Make a temp_node with data 17
        2. root->left->left = temp_node; 17->left = 17

                25 
               /
              17
             /  \
            17  19

        3. root->left->data = root->left->right->data;

                25 
               /
              19
             /  \
            17  19

        4. root->left->right->data = root->data;

                19 
               /
              19
             /  \
            17  25

        5. root = root->left;

              19
             /  \
            17  25

        // Should be good

    */

    AVLTree<int> root_case_right_left_rotate;

    root_case_right_left_rotate.insert(25);
    root_case_right_left_rotate.insert(29);
    root_case_right_left_rotate.insert(27);

    std::cout << root_case_right_left_rotate.root->data << std::endl;
    std::cout << root_case_right_left_rotate.root->right->data << std::endl;
    std::cout << root_case_left_right_rotate.root->left->data << std::endl;







} // end main