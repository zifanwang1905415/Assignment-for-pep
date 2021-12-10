#ifndef TREE_H
#define TREE_H

#include "treenode.h"

// TODO your code goes here:
template<typename T>
class BinarySearchTree
{
    private:
    unique_ptr <TreeNode <T> > root;

    public:
    BinarySearchTree(){}

    BinarySearchTree(const BinarySearchTree & tem)
    {
        root.reset((tem.root).get());
    }

    void operator = (const BinarySearchTree & tem)
    {
        root.reset((tem.root).get());
    }

    ostream & write (ostream & treeroot) const
    {
        root->write(treeroot);
        return treeroot;
    }

    TreeNode<T> * insert(const T & tem)
    {  
        TreeNode<T> *temm = root.get();
        TreeNode<T> *neww = new TreeNode<T>(tem);

        if(!temm)
        {
            root.reset(neww);
            return neww;
        }

        while(temm)
        {
            if(temm->data < tem)
            {
                if(!temm->rightChild)
                {
                    temm->setRightChild(neww);
                    return neww;
                }

                else
                {
                    temm = temm->rightChild.get();
                }
            }

            else
            {
                if(!temm->leftChild)
                {
                    temm->setLeftChild(neww);
                    return neww;
                }

                else
                {
                    temm = temm->leftChild.get();
                }
            }
        }

        return neww;
    }

    TreeNode<T> * find(const T tem)
    {
        TreeNode<T> *temm = root.get();

        while(temm)
        {
            if(temm->data < tem)
            {
                temm = temm -> rightChild.get();
            }

            else if(tem < temm->data)
            {
                temm = temm->leftChild.get();
            }

            else
            {
                return temm;
            }
        }

        return nullptr;
    }

    TreeNodeIterator<T> begin() const
    {
        TreeNode<T> *tem = root.get();

        if(tem == nullptr || tem ->leftChild == nullptr)
        {
            return TreeNodeIterator<T>(tem);
        }

        else
        {
            while(tem ->leftChild != nullptr)
            {
                tem = tem->leftChild.get();
            }
        }

        return TreeNodeIterator<T>(tem);


    }

    TreeNodeIterator<T> end() const
    {
        return nullptr;
    }

    int maxDepth()
    {
        TreeNode<T> *tem = root.get();
        return root->maxDepth(tem);
    }
};



// do not edit below this line

#endif
