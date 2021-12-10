#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

#include <utility>
#include <initializer_list>

// Do not add any #include statements here.  If you have a convincing need for adding a different `#include` please post in the forum on KEATS.

// TODO your code goes here:
template<typename T>
class LinkedList{
    private:
    Node<T> *head;
    Node<T> *tail;
    int count;

    public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    LinkedList(std::initializer_list<T> ls)
    {
        auto itr = ls.begin();
        Node<T> *p = new Node<T>(*itr);
        head = p;
        itr++;
        Node<T> *tem = head;

        for(;itr != ls.end(); itr++)
        {
            p = new Node<T> (*itr);

            if(head->next == nullptr)
            {
                head->next = p;
                p->previous = head;
            }

            else
            {
                tem = tem->next;
                tem->next = p;
                p->previous = tem;
                tail = p;
            }
        }
    }


    void push_front(const T input)
    {
        Node<T> *p = new Node<T>(input);

        if(head == nullptr)
        {
            head = p;
            tail = head;
            count = count + 1;
        }

        else
        {
            head->previous = p;
            p->next = head;
            head = p;
            count = count + 1;
        }
    }

    T & front()
    {
        if(count == 1)
        {
            return tail->data;
        }
        return head->data;
    }

    void push_back(const T input)
    {
        Node<T> *p = new Node<T>(input);

        if(head == nullptr)
        {
            head = p;
            tail = head;
            count = count + 1;
        }

        else
        {
            tail->next = p;
            p->previous = tail;
            tail = p;
            count = count + 1;
        }
    }

    T & back()
    {
        if(count == 1)
        {
            return(head->data);
        }

        return tail->data;
    }

    int size()
    {
        return count;
    }

    NodeIterator<T> begin() const
    {
        return NodeIterator<T> (head);
    }

    NodeIterator<T> end() const
    {
        return NodeIterator<T> (tail->next);
    }

    ~LinkedList()
    {
        Node<T> *tem = head;
        Node<T> *p;

        while(tem != nullptr && tem->next!= nullptr)
        {
            p = tem;
            tem = tem->next;
            delete p;
            p = nullptr;
        }
    }

    void reverse()
    {
        Node<T> *tem = tail;
        Node<T> *temhead = head;
        Node<T> *temtail = tail;
        Node<T> *temnext;
        Node<T> *temprevious;
        int a = 0;

        while(a < count)
        {
            temnext = tem->next;
            temprevious = tem->previous;
            tem->next = temprevious;
            tem->previous = temnext;
            tem = temprevious;
            a++;
        }

        head = temtail;
        tail = temhead;

    }

    NodeIterator<T> insert(NodeIterator<T> itr, const T tem)
    {
        Node<T> *temm = new Node<T>(tem);

        if(itr == begin())
        {
            push_front(tem);
        }

        else
        {
        itr.getnode()->previous->next = temm;
        temm->previous = itr.getnode()->previous;
        itr.getnode()->previous = temm;
        temm->next = itr.getnode();
        }

        return NodeIterator<T>(temm);
        
    }

    NodeIterator<T> erase(NodeIterator<T> itr)
    {
        NodeIterator<T> tem = NodeIterator<T>(itr.getnode()->next);

        if(itr.getnode() == head)
        {
            Node <T> *temm = head;

            if(head->next != nullptr)
            {
                 head = head->next;
                 delete temm;
                 head->previous = nullptr;
            }

            else
            {
                delete temm;
            }
        }

        else if(itr.getnode() == tail)
        {
            Node <T> *temm = tail;

            if(tail->previous != nullptr)
            {
                 tail = tail->previous;
                 delete temm;
                 tail->next = nullptr;
            }

            else
            {
                delete temm;
            }
        }

        else
        {
            itr.getnode()->previous->next = itr.getnode()->next;
            itr.getnode()->next->previous = itr.getnode()->previous;
            delete itr.getnode();
        } 

        return NodeIterator<T>(tem.getnode());
        
    }



};



// do not edit below this line

#endif