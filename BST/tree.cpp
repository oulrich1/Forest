//
//  tree.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include "tree.h"

namespace {
    std::string Int2String(int i)
    {
        std::stringstream ss;
        ss << i;
        return ss.str();
    }
}

namespace Structures {
    
    Tree::Tree()
    {
        m_root = NULL;
        m_size = 0;
    }
    Tree::~Tree()
    {
        if ( m_root )
        {
            delete m_root;
            m_root = NULL;
        }
        m_size = 0;
    }
    
    std::string Tree::toJSON()
    {
        std::string json;
        
        if (!m_root) {
            return json;
        }
        
        return toJSON(m_root);
    }
    
    std::string Tree::toJSON(Node* root)
    {
        std::string json = "";
        
        if (!root) {
            return "";
        }
        
        std::string L = toJSON(root->getLeft());
        std::string N = Int2String(root->getValue());
        std::string R = toJSON(root->getRight());
        
        json += "{";
        json += L;
        if ( !L.empty() && !N.empty() )
        {
            json += ",";
        }
        json += N;
        if ( !N.empty() && !R.empty() )
        {
            json += ",";
        }
        json += R;
        json += "}";
        
        return json;
    }
    
    void Tree::clear()
    {
        if(m_root)
        {
            delete m_root;
            m_root = NULL;
            m_size = 0;
        }
    }
    int Tree::size()
    {
        return m_size;
    }
}

