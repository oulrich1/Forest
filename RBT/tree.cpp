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

namespace Structures
{
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
    
    std::string Tree::toJSON( Node* root )
    {
        std::string json = "";
        
        if ( !root )
        {
            return "";
        }
        
        const int numChildren = root->getChildCount();
        std::string value = "";
        
        json += "[ ";
        
        // get the values from the left subtree
        for ( int idx = 0; idx < numChildren/2; ++idx )
        {
            value = toJSON( root->get( idx ) );
            if ( !value.empty() )
            {
                value += ", ";
                json += value;
            }
        }
        
        // get the value from this node
        value = Int2String( root->getValue() );
        json += value;
        
        // get the values from the right subtree
        for ( int idx = (numChildren/2); idx < numChildren; ++idx )
        {
            value = toJSON( root->get( idx ) );
            if ( !value.empty() )
            {
                value = ", " + value;  // append comma
                json += value; // append value to the stringified data
            }
        }
        
        json += " ]";
        
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

