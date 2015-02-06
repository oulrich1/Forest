//
//  node.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include "node.h"


namespace Structures {
    
    Node::Node() : Node(1) { }
    
    Node::Node( int _num_children )
    {
        m_children.resize( _num_children );
        
        for (int idx = 0; idx < m_children.size(); ++idx)
        {
            m_children[idx] = NULL;
        }
        
        m_pParent = NULL;
    }
    Node::~Node()
    {
        for (int idx = 0; idx < m_children.size(); ++idx)
        {
            if ( m_children[idx] )
            {
                delete m_children[idx];
                m_children[idx] = NULL;
            }
        }
        
        m_pParent = NULL;
    }
    
    void Node::setValue(int i)
    {
        setKey( i );
    }
    
    int Node::getValue() const
    {
        return getKey();
    }
    
    void Node::setKey( int i )
    {
        m_i = i;
    }
    
    int Node::getKey() const
    {
        return m_i;
    }
    
    Node* Node::get( int _id )
    {
        assert(Utility::is_within<int>(_id, 0, (int)m_children.size()));
        
        return m_children[_id];
    }
    
    Node*& Node::set( int _id )
    {
        assert(Utility::is_within<int>(_id, 0, (int)m_children.size()));
        
        return m_children[_id];
    }
    
    void Node::set( int _id, Node* node )
    {
        assert(Utility::is_within<int>(_id, 0, (int)m_children.size()));
        
        m_children[_id] = node;
    }
    
    
    // -------------------------------
    
    BinaryNode::BinaryNode() : Node::Node( 2 ) { }
    
    BinaryNode::BinaryNode(int key, int value) : BinaryNode()
    {
        Node::setValue( value );
        Node::setKey( key );
    }
    
    BinaryNode::BinaryNode(int key) : BinaryNode(key, key) { }
    
    
    // @param dir - either Left or Right
    // performs an assertion that the left or right is a BinaryNode for sure
    BinaryNode* BinaryNode::get_node_safe( Direction dir )
    {
        return dynamic_cast<BinaryNode*>( get( dir ) );
    }
    
    // get the left binary child node
    BinaryNode* BinaryNode::left()
    {
        return get_node_safe( Left );
    }
    
    // get the right binary child node
    BinaryNode* BinaryNode::right()
    {
        return get_node_safe( Right );
    }
    
    void BinaryNode::setLeft( BinaryNode* node )
    {
        set( Left, node );
    }
    void BinaryNode::setRight( BinaryNode* node )
    {
        set( Right, node );
    }
    
    bool BinaryNode::insertChild( Node* child )
    {
        child->setParent( this );
        
        if ( child->getKey() < this->getKey() )
        {
            if ( !m_children[Left] )
            {
                m_children[Left] = child;
            }
        }
        else
        {
            if ( !m_children[Right] )
            {
                m_children[Right] = child;
            }
        }
        
        return true;
    }
    
} // namespace Structure