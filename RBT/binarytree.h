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
        bool  insertRoot( Node* newNode );
        Node* binaryWalk( Node* node, int key );
        
        bool  remove( Node* node, Node* parent );
        Node* getAndRemoveReplacementNode( Node* node );
        
    protected:
        typedef Tree baseclass;
        
    public:
        BinaryTree();
        virtual ~BinaryTree();
        
        virtual bool  insert( Node* newNode );
        virtual Node* find( int key );
        virtual bool  remove( int key );
    };
}

#endif /* defined(__RedBlackTree__binarytree__) */
