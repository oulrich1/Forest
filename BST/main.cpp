//
//  main.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/15/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include "binarytree.h"

// --- MAIN
int main(int argc, const char * argv[]) {
    
    using namespace Structures;
    
    BinaryTree tree;
    tree.insert(20);
    tree.insert(7);
    tree.insert(10);
    tree.insert(60);
    tree.insert(12);
    tree.insert(5);
    
    Node* node;
    node = tree.find(7);
    
    std::cout << tree.toJSON() << std::endl;
    tree.remove(7);
    std::cout << tree.toJSON() << std::endl;
    tree.remove(20);
    std::cout << tree.toJSON() << std::endl;
    tree.remove(60);
    std::cout << tree.toJSON() << std::endl;
    tree.remove(12);
    std::cout << tree.toJSON() << std::endl;
    tree.remove(5);
    std::cout << tree.toJSON() << std::endl;
    tree.remove(10);
    std::cout << tree.toJSON() << std::endl;
    
    tree.insert(42);
    std::cout << tree.toJSON() << std::endl;
    
    node = tree.find(42);
    if ( node )
    {
        std::cout << node->getValue() << " was found." << std::endl;
    }
    tree.insert(42);
    tree.insert(42);
    tree.insert(42);
    std::cout << "Size: " << tree.size() << std::endl;
    tree.insert(20);
    tree.insert(2);
    tree.insert(-1);
    tree.insert(0);
    std::cout << "Size: " << tree.size() << std::endl;
    tree.clear();
    std::cout << "Size: " << tree.size() << std::endl;
    
    
    return 0;
}
