//
//  node.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__node__
#define __RedBlackTree__node__

#include <iostream>
#include <assert.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <assert.h>

#include "utility.h"

namespace Structures {
    
    class Tree;

    // _________________
    /**
     *  Node Definition
     */
    class Node {
        int m_i; // TODO: rename to m_nValue;
        
    public:
        Node();                     // init with one child
        Node( int _num_children );  // init with number of children
        virtual ~Node();
        
        virtual bool insertChild( Node* child ) = 0;
        
        void setValue( int i );
        int  getValue() const;
        
        void setKey( int i );
        int  getKey() const;
        
        Node*  get( int _id );
        Node*& set( int _id );
        void   set( int _id, Node* );
        
        int    getChildCount() const { return (int)m_children.size(); }
        
        Node* getParent() const { return m_pParent; }
        void  setParent( Node* pParent ) { m_pParent = pParent; }
        
        std::vector<Node*> m_children;
        Node* m_pParent;
    };
    
    
    // ____________________________
    class BinaryNode : public Node {
    public:
        BinaryNode();                       // inits Node with 2 children
        BinaryNode(int key, int value);
        BinaryNode(int key);                // with empty value
        
        /* Node Child Direction - Indecies into Children vec */
        typedef enum {
            None  = -1,
            Left  = 0,
            Right = 1,
        } Direction;
        
        BinaryNode* get_node_safe( Direction dir );
        BinaryNode* left();
        BinaryNode* right();
        
        void setLeft( BinaryNode* node );
        void setRight( BinaryNode* node );
        
        /* @param child 
            (1) Inserted as the left child of this node if and only if the child's
            value is less than this's value AND if the m_left child pointer is 
            NULL. 
            if (1) failed to insert then attempt to insert as right child under
            the same conditions, but applied to the right child.
         */
        virtual bool insertChild(Node* child); /// Override
    };
    
} // namespace Structures

#endif /* defined(__RedBlackTree__node__) */
