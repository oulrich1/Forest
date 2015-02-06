//
//  binarytree.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__binarytree__
#define __RedBlackTree__binarytree__

#include "tree.h"
#include "node.h"

namespace Structures {
    /**
     *  Binary Tree
     */
    class BinaryTree : public Tree {
    protected:
        bool  insertRoot( int value );
        bool  insertChild( Node* parent, int value );
        Node* binaryWalk( Node* node, int value );
        
        bool  remove( Node* node, Node* parent );
        Node* getAndRemoveReplacementNode( Node* node );
        
        typedef Tree baseclass;
        
    public:
        BinaryTree() { baseclass::Tree(); }
        virtual ~BinaryTree() { baseclass::~Tree(); }
        bool  insert( int value );
        Node* find( int value );
        bool  remove( int value );
    };
}

#endif /* defined(__RedBlackTree__binarytree__) */
