//
//  main.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/15/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include <math.h>
#include "binarytree.h"
#include "redblacktree.h"


void test_binary_tree()
{
    using namespace Structures;
    
    std::cout << "Testing Binary Search Tree" << std::endl;
    
    BinaryTree tree;
    tree.insert( new BinaryNode(11) );
    tree.insert( new BinaryNode(7) );
    tree.insert( new BinaryNode(20) );
    tree.insert( new BinaryNode(60) );
    tree.insert( new BinaryNode(12) );
    tree.insert( new BinaryNode(5) );
    
    Node* node;
    node = tree.find( 5 );
    
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (7) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (20) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (60) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (7) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (10) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (5) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (12) );
    std::cout << tree.toJSON() << std::endl;
    tree.remove( (11) );
    std::cout << tree.toJSON() << std::endl;
   
    std::cout << "Done." << std::endl << std::endl;
}

void test_chainable_template()
{
    using namespace Structures;
    std::cout << "Testing Chainable Template Builders for DataStructure Insertion" << std::endl;
    
//    Chainable<BinaryTree> tree;
//    tree.Insert(42);
    
//    std::cout << tree.toJSON() << std::endl;
    std::cout << "Not Working.." << std::endl << std::endl;
}

void test_chainable_wrapper()
{
    using namespace Structures;
    std::cout << "Testing Chainable Wrapper Builders for DataStructure Insertion" << std::endl;
    
//    BinaryTree _tree;
//    ChainableWrapper tree( &_tree );
//    tree.insert(14).insert(42).insert(52)
//        .insert(23).insert(14).insert(5)
//        .insert(43)
//        .remove(5).remove(42);
    
//    std::cout << _tree.toJSON() << std::endl;
    std::cout << "Done." << std::endl << std::endl;
}


// if this is confusing then just delete it.. just a "simple" test
Structures::Node* create_mini_tree( int nLeft, int nRight )
{
    using namespace Structures;
    Node* root = new RedBlackNode();
    
    int height = 0;     // height of the subtree
    int nNodeCount = 0; // number of nodes to insert in current subtree side
    int nSides = 2;     // sides of the tree (left and right)
    int dir = 0;        // determines the direction left or right
    while ( nSides != 0 )
    {
         /**
         *  Determine which sub tree to insert into.. Left or Right subtree
         */
        if ( nSides == 2 )
        {
            nNodeCount = nLeft;
            dir = RedBlackNode::Left;
        }
        else if ( nSides == 1 )
        {
            nNodeCount = nRight;
            dir = RedBlackNode::Right;
        }
        
        /**
         *  Now if there are nodes to insert then Start inserting them
         */
        if ( nNodeCount )
        {
            /* figure out the height of the subtree and 
             init the left or right subtree root node */
            double power = log2(nNodeCount);
            height = (int) (floor( power ) + 1);
            
            /* Since there is at least one node to insert
             and the rest of the algorithm depends on 
             having at least one node in the sub tree 
             inserted.. then lets insert it here 
             (either the root's left or right node) */
            root->set(dir) = new RedBlackNode();
            root->get(dir)->setParent(root);
            
            /* Start pushing the rest of the nodes breath-first
             into the left subtree. (OR the right subtree if thats
             the side we are on..) This loop goes through the height
             of the tree */
            std::vector<Node*> vec;
            vec.push_back( root->get(dir) );
            for (int h = 1; h < height; ++h)
            {
                // generate left and right children for each of the
                // nodes in this "layer" at the given height.
                std::vector<Node*> vec2;
                for (int i = 0; i < pow(2.0, h); ++i)
                {
                    if ( (i % 2) == 0 )
                    {
                        dir = RedBlackNode::Left;
                    }
                    else
                    {
                        dir = RedBlackNode::Right;
                    }
                    
                    // create new node and set it's parent
                    Node* node = vec[(i / 2)];
                    node->set(dir) = new RedBlackNode();
                    node->get(dir)->setParent(node);
                    vec2.push_back(node->get(dir));
                }
                
                // get rid of the nodes we went through already
                // and then update the vec with the cache of child
                // nodes that each become new roots to their own mini trees
                vec.clear();
                vec.insert(vec.begin(), vec2.begin(), vec2.end());
            }
        }
        
        nSides -= 1; // sides as in left or right sub tree from master root
    }
   
    return root;
}


void test_rb_rotate() {
    using namespace Structures;
    
    /* Create mock tree with no data */
    Node* root = new RedBlackNode();
    
    root->set(BinaryNode::Left) = create_mini_tree( 8, 16 );
    root->set(BinaryNode::Right) = create_mini_tree( 2, 4 );
    assert( root );
    
    /* Test the rotations */
    const int nExpected = 1;
    int nSuccess = 0;
    
//    if ( rb_rotate(root->get(BinaryNode::Left), BinaryNode::Right) )
//    {
//        nSuccess += 1;
//    }
    
    assert( nSuccess == nExpected );
}


void test_red_black_tree()
{
    using namespace Structures;
    
    std::cout << "Testing Red Black Tree" << std::endl;
    RedBlackTree tree;
    tree.insert( new RedBlackNode(42) );
    tree.insert( new RedBlackNode(42) );
    tree.insert( new RedBlackNode(7) );
    tree.insert( new RedBlackNode(11) );
    std::cout << tree.toJSON() << std::endl;
    
    tree.remove(11);
    tree.insert( new RedBlackNode(11) );
    tree.remove(43);
    tree.insert( new RedBlackNode(5) );
    tree.remove(42);
    std::cout << tree.toJSON() << std::endl;
    
    tree.insert( new RedBlackNode(12) );
    tree.insert( new RedBlackNode(13) );
    tree.insert( new RedBlackNode(1) );
    tree.insert( new RedBlackNode(14) );
    tree.insert( new RedBlackNode(12) );
    tree.insert( new RedBlackNode(6) );
    tree.insert( new RedBlackNode(22) );
    tree.insert( new RedBlackNode(21) );
    std::cout << tree.toJSON() << std::endl;
    
    Node* node;
    node = tree.find(42);   // no
    assert( !node );
    
    node = tree.find(12);   // yes
    assert( node );
    
    node = tree.find(1);    // yes
    assert( node );
    
    node = tree.find(0);    // no
    assert( !node );
    
    node = tree.find(7);    // yes
    assert( node );
    
    assert( tree.remove(7) );  // yes
    std::cout << tree.toJSON() << std::endl;
    assert( tree.remove(1) );  // yes
    std::cout << tree.toJSON() << std::endl;
    assert( !tree.remove(42) ); // no
    assert( !tree.remove(0) );  // no
    
    std::cout << tree.toJSON() << std::endl << "\n";
    
    tree.clear();
    tree.insert( new RedBlackNode(5) );
    tree.insert( new RedBlackNode(10) );
    tree.insert( new RedBlackNode(7) );
    tree.insert( new RedBlackNode(6) );
    tree.insert( new RedBlackNode(8) );
    tree.insert( new RedBlackNode(4) );
    tree.insert( new RedBlackNode(3) );
    tree.insert( new RedBlackNode(9) );
    
    std::cout << tree.toJSON() << std::endl;
    tree.rotate( (RedBlackNode*)tree.getRoot(), RedBlackNode::Direction::Left );
    tree.rotate( (RedBlackNode*)tree.getRoot(), RedBlackNode::Direction::Right );
    std::cout << tree.toJSON() << std::endl;
    
    std::cout << "Done." << std::endl << std::endl;
}


// ________________________________________

int main(int argc, const char * argv[])
{
    test_binary_tree();
    // test_chainable_template(); 
    test_chainable_wrapper();
//    test_rb_rotate();
    test_red_black_tree();
    
    return 0;
}
