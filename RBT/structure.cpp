//
//  structure.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 2/2/15.
//  Copyright (c) 2015 Oriah Ulrich. All rights reserved.
//

#include "structure.h"


namespace Structures
{
    
    //
    template <typename T>
    Chainable<T>& Chainable<T>::Insert( int value )
    {
        baseclass::insert( value );
        return *this;
    }
    
    template <typename T>
    Chainable<T>& Chainable<T>::Find( int value )
    {
        baseclass::find( value );
        return *this;
    }
    
    template <typename T>
    Chainable<T>& Chainable<T>::Remove( int value )
    {
        baseclass::remove( value );
        return *this;
    }
    
    
    /**
     *  Chainable Wrapper: Returns a reference to the same object 
     *  as in a builder object..
     *
     *  @param value - The integer to insert
     *
     *  @return a reference to "this" chianable wrapper
     */
    ChainableWrapper& ChainableWrapper::insert( Node* node )
    {
        if ( m_ds )
        {
            m_ds->insert( node );
        }
        
        return *this;
    }
    ChainableWrapper& ChainableWrapper::find( int value )
    {
        if ( m_ds )
        {
            m_last_found_node = m_ds->find( value );
        }
        
        return *this;
    }
    ChainableWrapper& ChainableWrapper::remove( int value )
    {
        if ( m_ds )
        {
            m_ds->remove( value );
        }
        
        return *this;
    }
}
