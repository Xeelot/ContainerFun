#pragma once
#include "JContainer.h"

template <class T>
class JQueue : virtual public JContainer<T>
{
public:
   virtual void addItem(const T& item);
   virtual T getItem();
   virtual void printItems();

   bool empty() const;   // Is container empty?
   size_t size() const;  // What is the size of all elements?

private:
   // Implementation of the Queue is entirely internal
   struct node {
      T data;     // Value of the item
      node *next; // Pointer to next item in Queue
      node() :data(), next(nullptr) {}
      node(T const& value, node* nextItem) :data(value), next(nextItem) {}
      node(T&& value, node* nextItem) :data(value), next(nextItem) {}
   };

   size_t elements = 0;  // Number of items in Queue
   node* head = nullptr; // Head pointer for popping
   node* tail = nullptr; // Tail pointer for pushing
};


template <class T>
bool JQueue<T>::empty() const
{
   return elements == 0;
}


template <class T>
size_t JQueue<T>::size() const
{
   return elements;
}


template <class T>
void JQueue<T>::addItem(const T& item)
{
   // Create a new item/node
   node* newItem = new node(item, nullptr);
   // Check for first element
   if (!elements)
   {
      head = newItem;
   }
   // Otherwise point last element to new
   else
   {
      tail->next = newItem;
   }
   // Make the new item the new tail/last item
   tail = newItem;
   ++elements;
}


template <class T>
T JQueue<T>::getItem()
{
   T itemTemp(0);
   node* nodeTemp;
   // Check for an empty queue
   if (elements)
   {
      // Retrieve value to return
      itemTemp = head->data;
      // Set item to next or null
      nodeTemp = head;
      head = head->next;
      // Cleanup the popped node
      delete nodeTemp;
      --elements;
   }
   return itemTemp;
}


template <class T>
void JQueue<T>::printItems()
{
   if (!elements)
   {
      std::cout << "Queue: empty" << std::endl;
   }
   else
   {
      std::cout << "Queue: ";
      node* printItem = head;
      while (printItem != nullptr)
      {
         std::cout << printItem->data << " ";
         printItem = printItem->next;
      }
      std::cout << std::endl;
   }
}