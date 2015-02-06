//
//  redblacknode.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 2/3/15.
//  Copyright (c) 2015 Oriah Ulrich. All rights reserved.
//

#include "redblacknode.h"

namespace Structures
{
    RedBlackNode::RedBlackNode() : BinaryNode::BinaryNode()
    {
        m_color = Black;
    }
    
    RedBlackNode::RedBlackNode( Color color ) : RedBlackNode()
    {
        m_color = color;
    }
    
    RedBlackNode::~RedBlackNode()
    {
    }
} // namespace Structures