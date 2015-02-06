//
//  node.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include "node.h"


namespace Structures {
    
    Node::Node()
    {
        m_left = NULL;
        m_right = NULL;
    }
    Node::~Node()
    {
        if (m_left) {
            delete m_left;
        }
        if (m_right) {
            delete m_right;
        }
    }
    
    bool Node::insertChild(Node* child)
    {
        if (child->getValue() < this->getValue()) {
            if (!m_left) {
                m_left = child;
            }
        } else {
            if (!m_right) {
                m_right = child;
            }
        }
        // TODO: handle other cases when left is NOT NULL
        // probably requires implementing rotations and stuff
        return true;
    }
    
    int Node::getValue() const
    {
        return m_i;
    }
    
    void Node::setValue(int i)
    {
        m_i = i;
    }
    
} // namespace Structure