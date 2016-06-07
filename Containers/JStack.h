#pragma once
#include "JContainer.h"

template <class T>
class JStack : public JContainer<T>
{
public:
   virtual void addItem(const T& item);
   virtual T getItem();
   virtual void printItems();

   bool empty() const;   // Is container empty?
   size_t size() const;  // What is the size of all elements?

private:
   // The entire Stack is implemented internally
   struct node {
      T data;     // Value of the item
      node *next; // Pointer to next item in Queue
      node() :data(), next(nullptr) {}
      node(T const& value, node* nextItem) :data(value), next(nextItem) {}
      node(T&& value, node* nextItem) :data(value), next(nextItem) {}
   };

   node *top;       // Top of the stack
   size_t elements; // Number of items in the stack
};


template <class T>
bool JStack<T>::empty() const
{
   return elements == 0;
}


template <class T>
size_t JStack<T>::size() const
{
   return elements;
}


template <class T>
void JStack<T>::addItem(const T& item)
{
   // Create a new top node, and point the next to the previous top
   top = new node(item, top);
   ++elements;
}


template <class T>
T JStack<T>::getItem()
{
   T itemTemp(0);
   node* nodeTemp;
   // Check to make sure top is not null
   if (elements)
   {
      // Retrieve value to return
      itemTemp = top->data;
      // Set item to next or null
      nodeTemp = top;
      top = top->next;
      // Cleanup the popped node
      delete nodeTemp;
      --elements;
   }
   return itemTemp;
}


template <class T>
void JStack<T>::printItems()
{
   if (!elements)
   {
      std::cout << "Stack: empty" << std::endl;
   }
   else
   {
      std::cout << "Stack: ";
      node* printItem = top;
      while (printItem != nullptr)
      {
         std::cout << printItem->data << " ";
         printItem = printItem->next;
      }
      std::cout << std::endl;
   }
}