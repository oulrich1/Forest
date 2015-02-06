//
//  tree.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__tree__
#define __RedBlackTree__tree__

#include "node.h"

namespace Structures {
    
    /**
     Data Structure
     */
    class DataStructure {
    protected:
        int m_size;
        
    public:
        virtual std::string toJSON() = 0;
        virtual void clear() = 0;
        virtual int size() = 0;
    };
    
    /**
     *  Tree Definition
     */
    class Tree : public DataStructure {
    protected:
        Node* m_root;
        
        virtual std::string toJSON(Node* root); // LNR (inorder)
        
    public:
        Tree();
        virtual ~Tree();
        virtual void clear();
        virtual int  size();
        
        virtual std::string toJSON();
    };
    
}

#endif /* defined(__RedBlackTree__tree__) */
