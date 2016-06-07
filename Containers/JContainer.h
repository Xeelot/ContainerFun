#pragma once
#include <string>

template <class T>
class JContainer
{
public:
   virtual void addItem(const T& item) = 0;
   virtual T getItem() = 0;
   virtual void printItems() = 0;
};

