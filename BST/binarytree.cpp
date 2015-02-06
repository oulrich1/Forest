//
//  binarytree.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include "binarytree.h"



namespace Structures {

    bool BinaryTree::insert(int value)
    {
        if ( !m_root )
        {
            return insertRoot(value);
        }
        
        Node* parent = NULL;
        Node* iter = m_root;
        
        /* Go through the binary tree until we reach NULL */
        while( iter != NULL )
        {
            if ( value == iter->getValue() )
                break;
            
            parent = iter; // save the parent ptr
            
            iter = binaryWalk( iter, value );
        }
        
        if ( iter != NULL ) { // then we found a node with the same value
            return false;
        }
        
        return insertChild(parent, value);
    }
    
    bool BinaryTree::insertRoot(int value)
    {
        m_root = new Node();
        m_root->setValue(value);
        m_size = 1;
        
        return true;
    }
    
    bool BinaryTree::insertChild(Node* parent, int value)
    {
        if ( !parent || parent->getValue() == value )
        {
            return false;
        }
        
        Node* newChild = new Node();
        newChild->setValue(value);
        parent->insertChild( newChild );
        m_size += 1;
        
        return true;
    }
   
    Node* BinaryTree::find( int value )
    {
        bool found = false;
        Node* iter = m_root;
        
        /* find the node */
        while (iter && !found)
        {
            if ( value == iter->getValue() )
            {
                found = true;
            }
            else
            {
                iter = binaryWalk( iter, value );
            }
        }
        
        return iter;
    }
    
    bool BinaryTree::remove( int value )
    {
        bool found = false;
        
        Node* parent = NULL;
        Node* iter = m_root;
        
        /* find the node and parent */
        while (iter && !found)
        {
            if ( value == iter->getValue() )
            {
                found = true;
            }
            else
            {
                parent = iter;
                iter = binaryWalk( iter, value );
            }
        }
        
        if (!found)
        {
            return false; // not in tree
        }
        
        /* remove node from tree and return status */
        return remove(iter, parent);
    }
    
    bool BinaryTree::remove( Node* node, Node* parent )
    {
        if (!node)
        {
            return false;
        }
        
        Node* newNode = getAndRemoveReplacementNode( node );
        
        Node* nodeLeftSub = node->getLeft();
        Node* nodeRightSub = node->getRight();
        
        /* a balancing act */
        if ( newNode == NULL )
        {
            assert(nodeRightSub == NULL);
            
            /* simply remove the node and replace parent
             left or right with old node->left */
            
            if (node == m_root) {
                assert(parent == NULL);
                m_root = nodeLeftSub;
            } else if (parent->getLeft() == node) {
                parent->m_left = nodeLeftSub;
            } else if (parent->getRight() == node) {
                parent->m_right = nodeLeftSub;
            }
        }
        else
        {
            newNode->m_left = nodeLeftSub;
            
            if (node == m_root) {
                assert(parent == NULL);
                m_root = newNode; // and the right subtree is the new node's tree
            }
            else // update the new nodes right subtree to the node to remove's right
            {
                if ( newNode->m_right == NULL ) {
                    newNode->m_right = nodeRightSub;
                } else {
                    assert(newNode == nodeRightSub);
                }
                
                if (parent->getLeft() == node) {
                    parent->m_left = newNode;
                } else if (parent->getRight() == node) {
                    parent->m_right = newNode;
                }
            }
            
        }
        
        node->m_left = NULL;
        node->m_right = NULL;
        delete node;
        
        m_size -= 1;
        
        return true;
    }
    
    
    /* this will remove and return the node with the next value in
     order FROM the given @param node.. so if the given node has value
     of 19 and 20 is the next numbered node, it will get 20.. */
    Node* BinaryTree::getAndRemoveReplacementNode( Node* node )
    {
        if (!node)
        {
            return NULL;
        }
        
        Node* parent = node;
        Node* newNode = node->getRight();
        
        if (!newNode)
        {
            return NULL;
        }
        
        while( newNode->getLeft() )
        {
            parent = newNode;
            newNode = newNode->getLeft();
        }
        
        assert(newNode != NULL);
        assert(newNode->m_left == NULL);
        assert(parent != NULL);
        
        if (parent != node)
        {
            parent->m_left = newNode->getRight();
            
            /* isolate the new node */
            newNode->m_right = NULL;
        }
        
        return newNode;
    }
    

    
    Node* BinaryTree::binaryWalk( Node* node, int value )
    {
        if ( !node )
            return NULL;
        
        if ( value < node->getValue() ) {
            node = node->getLeft();
        } else if ( value > node->getValue() ) {
            node = node->getRight();
        }
        return node;
    }
    
} // namespace Structures


