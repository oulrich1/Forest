//
//  binarytree.cpp
//  RedBlackTree
//
//  Created by Oriah Ulrich on 11/16/14.
//  Copyright (c) 2014 Oriah Ulrich. All rights reserved.
//

#include "binarytree.h"


namespace Structures {
    
    BinaryTree::BinaryTree() : Tree::Tree() { }
    BinaryTree::~BinaryTree() { baseclass::~Tree(); }

    bool BinaryTree::insert( Node* newNode )
    {
        if ( !newNode )
            return false;
        
        if ( !m_root )
        {
            return insertRoot( newNode );
        }
        
        bool bFoundDuplicate = false;
        Node* node = m_root;
        Node* parent = NULL;
        
        /* Go through the binary tree until we reach NULL */
        while( node != NULL )
        {
            if ( newNode->getKey() == node->getKey() )
            {
                bFoundDuplicate = true;
                break;
            }
            
            parent = node;
            node = binaryWalk( node, newNode->getKey() );
        }
        
        if ( bFoundDuplicate )
        {
            delete newNode;
            return false;
        }
        
        // this is the node we are inserting into
        assert( parent );
        
        parent->insertChild( newNode );
        m_size += 1;
        
        return true;
    }
    
    bool BinaryTree::insertRoot( Node* newNode )
    {
        m_root = newNode;
        m_root->setParent( NULL );
        m_size = 1;
        
        return true;
    }
   
    Node* BinaryTree::find( int key )
    {
        bool found = false;
        Node* curNode = m_root;
        
        /* find the node */
        while (curNode != NULL && !found)
        {
            if ( key == curNode->getKey() )
            {
                found = true;
            }
            else
            {
                curNode = binaryWalk( curNode, key );
            }
        }
        
        if ( found )
        {
            return curNode;
        }
    
        return NULL;
    }
    
    bool BinaryTree::remove( int key )
    {
        Node* nodeToRemove = find( key );
        
        if ( !nodeToRemove )
        {
            return false; // not in tree
        }
        
        /* remove node from tree and return status */
        return remove( nodeToRemove, nodeToRemove->getParent() );
    }
    
    bool BinaryTree::remove( Node* node, Node* parent )
    {
        if (!node)
        {
            return false;
        }
        
        // this node will replace the node that is able to be removed
        Node* newNode = getAndRemoveReplacementNode( node );
        
        Node* nodeLeftSub = node->get( BinaryNode::Left );
        Node* nodeRightSub = node->get( BinaryNode::Right );
        
        /* If the recplacement node is the node-to-remove's child..
         then there is no corresponding subtree.. ignore that subtree */
        if ( newNode == nodeRightSub )
        {
            nodeRightSub = NULL;
        }
        else if ( newNode == nodeLeftSub )
        {
            nodeLeftSub = NULL;
        }
        
        /* a balancing act */
        if ( newNode == NULL )
        {
            assert(nodeRightSub == NULL);
            
            /* simply remove the node and replace parent
             left or right with old node->left */
            
            if (node == m_root)
            {
                assert(parent == NULL);
                m_root = nodeLeftSub;
                if ( nodeLeftSub )
                {
                    nodeLeftSub->setParent( NULL );
                }
            }
            else
            {
                if ( nodeLeftSub )
                {
                    nodeLeftSub->setParent( parent );
                }
                
                if (parent->get( BinaryNode::Left ) == node)
                {
                    parent->set( BinaryNode::Left ) = nodeLeftSub;
                }
                else if (parent->get( BinaryNode::Right ) == node)
                {
                    parent->set( BinaryNode::Right ) = nodeLeftSub;
                }
            }
        }
        else
        {
            if (nodeLeftSub)
            {
                nodeLeftSub->setParent( newNode );
            }
            newNode->set( BinaryNode::Left ) = nodeLeftSub;
            
            if (node == m_root) {
                assert(parent == NULL);
                m_root = newNode; // and the right subtree is the new node's tree
            }
            else // update the new nodes right subtree to the node-to-remove's right
            {
                if ( nodeRightSub )
                {
                    nodeRightSub->setParent( newNode );
                }
                
                if ( newNode->get( BinaryNode::Right ) == NULL )
                {
                    assert( newNode != nodeRightSub );
                    newNode->set( BinaryNode::Right ) = nodeRightSub;
                }
                
                
                // attach the newNode as the parent's child. parent
                // being the parent of that node to delete
                newNode->setParent( parent );
                if (parent->get( BinaryNode::Left ) == node)
                {
                    parent->set( BinaryNode::Left ) = newNode;
                }
                else if (parent->get( BinaryNode::Right ) == node)
                {
                    parent->set( BinaryNode::Right ) = newNode;
                }
            }
            
        }
        
        node->set( BinaryNode::Left ) = NULL;
        node->set( BinaryNode::Right ) = NULL;
        node->setParent( NULL );
        delete node;
        
        m_size -= 1;
        
        return true;
    }
    
    
    /** ___________________________________________________________
     *  Removes AND Returns the node with the next value in order
     *  after the given @param "node". IF the given node has value 
     *  of 19 and the next numbered node is 27 it will get 27, 
     *  regardless of where 27 is in the tree. It snips it out and
     *  returns that node.
     *
     *  @param node starting node position in the tree from which a 
     *              search for the node with the next highest key 
     *              value is snipped and returned node with
     *
     *  @return - Node that is snipped out from the tree, which has
     *            the next highest key value from and excluding "node"
     */
    Node* BinaryTree::getAndRemoveReplacementNode( Node* node )
    {
        if ( !node )
        {
            return NULL;
        }
         
        // step right (from node)
        Node* parent = node;
        Node* newNode = node->get( BinaryNode::Right );
        
        if ( !newNode )
        {
            return NULL;
        }
        
        /* now step left until reached next highest keyvalue, essentially */
        while( newNode->get( BinaryNode::Left ) )
        {
            parent = newNode;
            newNode = newNode->get( BinaryNode::Left );
        }
        
        // temporary check in progress of updating the tree to support parents
        assert( newNode->getParent() &&
                newNode->getParent() == parent );
        
        
        // since its the left most of the subtree to the right of node
        assert( newNode->get( BinaryNode::Left ) == NULL );
        
        // as long as the new node's parent is not the node to delete.. then do:
        if ( newNode->getParent() != node )
        {
            // since we traversed left most of the node's right subtree
            assert( parent->get( BinaryNode::Left ) == newNode );
            
            // snip child branch and give the parent the child
            newNode->getParent()->set( BinaryNode::Left )
                       = newNode->get( BinaryNode::Right );
            
            /* isolate the new node but dont "delete" it*/
            newNode->set( BinaryNode::Right ) = NULL;
            newNode->setParent( NULL );
        }
        
        return newNode;
    }
    

    
    Node* BinaryTree::binaryWalk( Node* node, int key )
    {
        if ( !node )
        {
            return NULL;
        }
        
        if ( key < node->getKey() )
        {
            node = node->get( BinaryNode::Left );
        }
        else if ( key > node->getKey() )
        {
            node = node->get( BinaryNode::Right );
        }
        
        return node;
    }
    
} // namespace Structures


