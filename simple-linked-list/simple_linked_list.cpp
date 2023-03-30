#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list 
{

size_t List::size() const 
{
    return current_size;
}

void List::inner_push( Element** list, const int entry)
{
    Element* pElem = new Element(entry);

    if(*list == nullptr)
    {
        // is the first element to be added
        *list = pElem;
        (*list)->next = nullptr; 
    }
    else
    {
        Element* p = *list;
        
        for( ; p->next != nullptr ; p = p->next );
        p->next = pElem; 
    }

    current_size++;
}


void List::push(const int entry) 
{
    inner_push( &head, entry );
}

int List::pop() 
{
    int ret = 0;
    if( head )
    {
        Element *p = head;
        Element *p_prev = nullptr;
        for( ; p->next != nullptr ; p = p->next )
        {
            p_prev = p;
        }

        ret = p->data;
        delete p;

        if(p_prev != nullptr)
        {
            p_prev->next = nullptr;
        }

        current_size--;
    }

    return ret;
}

void List::reverse() 
{
    Element* reverse_list = nullptr;
    int list_size = size();

    while( list_size-- )
    {
        inner_push( &reverse_list, pop() );
    }

    head = reverse_list;
}

List::~List() 
{
    while(size())
    {
        pop();
    }
}

}  // namespace simple_linked_list
