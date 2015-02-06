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
#include "structure.h"

namespace Structures {
    
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
        virtual void clear(); // final
        virtual int  size();  // final
        
        virtual Node* getRoot() const { return m_root; }
        
        virtual std::string toJSON();
    };
    
}

#endif /* defined(__RedBlackTree__tree__) */
