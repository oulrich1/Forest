//
//  redblacktree.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 2/2/15.
//  Copyright (c) 2015 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__redblacktree__
#define __RedBlackTree__redblacktree__

#include <stdio.h>
#include "binarytree.h"
#include "redblacknode.h"

namespace Structures {
    
    bool rb_rotate( Node* node, BinaryNode::Direction dir );

    /** _______________
        Red Black Tree:
     */
    class RedBlackTree : public BinaryTree {
    protected:
        typedef BinaryTree baseclass;
        RedBlackNode* m_nil;
        
        bool post_insert_fix_tree( RedBlackNode* node );
        bool post_remove_fix_tree( RedBlackNode* node );
        bool fix( RedBlackNode* parent, RedBlackNode* uncle,
                  RedBlackNode* node, BinaryNode::Direction dir );
        
    public:
        RedBlackTree();
        virtual ~RedBlackTree();
        
        virtual bool rotate( BinaryNode* n, BinaryNode::Direction dir );
        virtual bool rotate_left( BinaryNode* x );
        virtual bool rotate_right( BinaryNode* y );
        
    public:
        virtual bool  insert( Node* newNode );
        virtual Node* find( int key );
        virtual bool  remove( int key );
    };
    
} // namespace Structures

#endif /* defined(__RedBlackTree__redblacktree__) */
