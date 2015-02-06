//
//  structure.h
//  RedBlackTree
//
//  Created by Oriah Ulrich on 2/2/15.
//  Copyright (c) 2015 Oriah Ulrich. All rights reserved.
//

#ifndef __RedBlackTree__structure__
#define __RedBlackTree__structure__

#include <stdio.h>
#include "node.h"

namespace Structures
{
    
    /**
     Data Structure
     */
    class DataStructure {
    protected:
        int m_size;
        
    public:
        virtual void clear() = 0;
        virtual int  size()  = 0;
        
        virtual bool  insert( Node* newNode ) = 0;
        virtual Node* find( int key )   = 0;
        virtual bool  remove( int key ) = 0;
        
        virtual std::string toJSON() = 0;
    };
    
    /**
     *  A chainable data structure
     *  Syntax: Chainable<BinaryTree> tree; tree.insert(42).insert(5).delete(42);
     */
    template <typename T>
    class Chainable : public T
    {
    protected:
        typedef T baseclass;
        
    public:
        virtual Chainable<T>& Insert( int value );
        virtual Chainable<T>& Find( int value );
        virtual Chainable<T>& Remove( int value );
    };
    
    /**
     *  An alternative to the above. Instead of templates, this implements a wrapper
     */
    class ChainableWrapper
    {
    public:
        ChainableWrapper( DataStructure* ds ) { m_ds = ds; m_last_found_node = 0; }
        
        virtual ChainableWrapper& insert( Node* node );
        virtual ChainableWrapper& find( int value );
        virtual ChainableWrapper& remove( int value );
        
        Node* getFound() const { return m_last_found_node; }
      
    private:
        DataStructure* m_ds;
        Node* m_last_found_node;
    };
}

#endif /* defined(__RedBlackTree__structure__) */
