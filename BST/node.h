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

namespace Structures {
    
    class Tree;

    /**
     *  Node Definition
     */
    class Node {
        int m_i;
        
    public:
        Node();
        virtual ~Node();
        
        typedef int NodeType;
        
        bool insertChild(Node* child);
        
        int getValue() const;
        void setValue(int i);
        
        Node* getLeft() { return m_left; }
        Node* getRight() { return m_right; }
        
        Node* m_left;
        Node* m_right;
    };
    
} // namespace Structures

#endif /* defined(__RedBlackTree__node__) */
