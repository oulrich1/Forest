//
//  redblacknode.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 2/3/15.
//  Copyright (c) 2015 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__redblacknode__
#define __RedBlackTree__redblacknode__

#include <stdio.h>
#include <vector>

#include "node.h"

namespace Structures
{
    class RedBlackNode : public BinaryNode {
    public:
        RedBlackNode();
        RedBlackNode(int key, int value) : BinaryNode( key, value ) {}
        RedBlackNode(int key) : BinaryNode( key ) {}
        virtual ~RedBlackNode();
        
        /* Node Type/Color */
        typedef enum {
            Red,
            Black
        } Type;
        typedef Type Color;
        
    protected:
        Color         m_color; // node type
        
    public:
        RedBlackNode( Color );
        
        Color getColor() const      { return m_color; }
        void  setColor( Color color ) { m_color = color; }
        
        inline bool is( RedBlackNode::Color color ) const
        {
            return (m_color == color);
        }
        inline bool isRed() const
        {
            return is( RedBlackNode::Red );
        }
        inline bool isBlack() const
        {
            return is( RedBlackNode::Black );
        }
        
    };
    
    
    // comparison helpers for the redblack node
} // namespace Structures

#endif /* defined(__RedBlackTree__redblacknode__) */
