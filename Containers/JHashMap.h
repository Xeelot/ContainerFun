#pragma once
#include "JContainer.h"
#include <vector>

const int HASHMAP_SIZE = 50;

template <class S, class T>
class JHashMap : public JContainer<T>
{
public:
   JHashMap<S, T>();
   void addItem(S key, T item);
   T getItem(const S& key);
   virtual void addItem(const T& item);
   virtual T getItem();
   virtual void printItems();

private:
   // Would like to implement as vector...
   std::pair<S, T> table[HASHMAP_SIZE];
};


template <class S, class T>
JHashMap<S, T>::JHashMap()
{
   // Initialize the table
   for (int i = 0; i < HASHMAP_SIZE; ++i)
   {
      // limited to int until upgraded to vectors or some other container
      table[i] = std::make_pair<S, T>(0, 0);
   }
}


template <class S, class T>
void JHashMap<S, T>::addItem(S key, T item)
{
   // Determine the hash value to add at (currently limited to int, need to get smarter with vectors)
   int hash = (key % HASHMAP_SIZE);
   // Search for the next spot to add the pair
   while ((std::get<0>(table[hash]) != 0) || (std::get<0>(table[hash]) == key))
   {
      hash = (hash + 1) % HASHMAP_SIZE;
   }
   // Insert the new pair
   table[hash] = std::pair<S, T>(key, item);
}


template <class S, class T>
void JHashMap<S, T>::addItem(const T& item)
{
   std::cout << "HashMap: Must use a key! Try again." << std::endl;
}


template <class S, class T>
T JHashMap<S, T>::getItem(const S& key)
{
   // Create the same hash value
   int hash = (key % HASHMAP_SIZE);
   // Loop over the table to find an empty entry or the key value
   while ((std::get<0>(table[hash]) != 0) && (std::get<0>(table[hash]) != key))
   {
      hash = (hash + 1) % HASHMAP_SIZE;
   }
   // Return the key value
   if (std::get<0>(table[hash]) == 0)
   {
      return -1;
   }
   return std::get<1>(table[hash]);
}


template <class S, class T>
T JHashMap<S, T>::getItem()
{
   std::cout << "HashMap: Must use a key! Try again." << std::endl;
   return 1;
}


template <class S, class T>
void JHashMap<S, T>::printItems()
{
   std::cout << "HashMap: ";
   for (int i = 0; i < HASHMAP_SIZE; ++i)
   {
      std::cout << "(" << std::get<0>(table[i]) << "," << std::get<1>(table[i]) << ") ";
   }
   std::cout << std::endl;
}