#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using std::cout;
using std::cerr;
using std::endl;
using std::ostream;

#include <memory>
using std::unique_ptr;

#include <utility>
using std::pair;

// TODO your code for the TreeNode class goes here:

template<typename T>
class TreeNode
{
    public:
    T data;
    unique_ptr <TreeNode> leftChild;
    unique_ptr <TreeNode> rightChild;
    TreeNode<T> * parent;

    TreeNode(T datat):data(datat)
    {
        parent = nullptr;
    }

    void setLeftChild(TreeNode* child)
    {
        leftChild.reset(child);
        child->parent = this;
    }

    void setRightChild(TreeNode* child)
    {
        rightChild.reset(child);
        child->parent = this;
    }


     ostream & write (ostream & tree) const
    {
        if(leftChild != nullptr)
        {
            leftChild->write(tree);
        }

        tree<<" "<<data<<" ";

        if(rightChild != nullptr)
        {
            rightChild->write(tree);
        }

        return tree;
    }

    int maxDepth(TreeNode *tem)
    {
        if(!tem)
        {
            return 0;
        }

        int temleft = maxDepth(tem -> leftChild.get());
        int temright = maxDepth(tem -> rightChild.get());

        return 1 + std::max(temleft,temright);
    }

};

template<typename T>
class TreeNodeIterator
{

    private:
    TreeNode<T> * tem;

    public:
    TreeNodeIterator(TreeNode<T>* temm)
    :tem(temm){}

    T & operator*(){
        return tem -> data;
    }

    bool operator == (const TreeNodeIterator & temm)const{
        return (tem == temm.tem);
    }


    bool operator != (const TreeNodeIterator & temm)const{
        return (tem != temm.tem);
    }

    void operator++()
    {
        if(tem != nullptr)
        {
            if(tem -> rightChild != nullptr)
            {
                tem = tem -> rightChild.get();
            }

            else 
            {
                while(tem -> parent != nullptr && tem->data > tem->parent->data)
                {
                    tem = tem -> parent;
                }

                tem = tem -> parent;
            }

    }
  }



};

// do not edit below this line

#endif
