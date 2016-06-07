// Containers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "JQueue.h"
#include "JStack.h"
#include "JHashMap.h"

#include <unordered_map>

void printStdMap(std::unordered_map<std::string, int> map)
{
   std::cout << "UnOMap: ";
   for (auto& i : map)
   {
      std::cout << "(" << i.first << "," << i.second << ") ";
   }
   std::cout << std::endl;
}


int main()
{
   const int QUEUE_STUFF = 0;
   const int STACK_STUFF = 0;
   const int HASHMAP_STUFF = 1;

   // Play with the queue
   if (QUEUE_STUFF)
   {
      JContainer<int>* q;
      q = new JQueue<int>();
      q->printItems();
      q->addItem(3);
      q->printItems();
      q->addItem(9);
      q->printItems();
      q->addItem(15);
      q->printItems();
      q->getItem();
      q->printItems();
      q->addItem(1);
      q->printItems();
      q->getItem();
      q->printItems();
      q->getItem();
      q->printItems();
      q->getItem();
      q->printItems();
      q->getItem();
      q->printItems();
      std::cout << std::endl << std::endl;
   }

   // Play with the Stack
   if (STACK_STUFF)
   {
      JContainer<int>* s;
      s = new JStack<int>();
      s->printItems();
      s->addItem(3);
      s->printItems();
      s->addItem(9);
      s->printItems();
      s->addItem(15);
      s->printItems();
      s->getItem();
      s->printItems();
      s->addItem(1);
      s->printItems();
      s->getItem();
      s->printItems();
      s->getItem();
      s->printItems();
      s->getItem();
      s->printItems();
      s->getItem();
      s->printItems();
      std::cout << std::endl << std::endl;
   }

   // Play with the HashMap
   if (HASHMAP_STUFF)
   {
      // STD implementation
      std::unordered_map<std::string, int> h1;
      printStdMap(h1);
      std::unordered_map<std::string, int>::const_iterator iter1 = h1.find("IP1");
      std::unordered_map<std::string, int>::const_iterator iter2 = h1.find("IP2");
      // Neither were found, set the first to be unique (1) and second a duplicate (2)
      if (iter1 == h1.end() && iter2 == h1.end())
      {
         h1.insert(std::make_pair<std::string, int>("IP1", 1));
         h1.insert(std::make_pair<std::string, int>("IP2", 2));
      }
      // First was not found, but second was, insert as a duplicate (2)
      else if (iter1 == h1.end() && iter2 != h1.end())
      {
         h1.insert(std::make_pair<std::string, int>("IP1", 2));
      }
      // First was found, but second was not, insert second as duplicate (2)
      else if (iter1 != h1.end() && iter2 == h1.end())
      {
         h1.insert(std::make_pair<std::string, int>("IP2", 2));
      }
      printStdMap(h1);
      h1.insert(std::make_pair<std::string, int>("IP4", 1));
      printStdMap(h1);
      h1.insert(std::make_pair<std::string, int>("cheese", 4));
      printStdMap(h1);
      h1.insert(std::make_pair<std::string, int>("bacon", 8));
      printStdMap(h1);
      h1.insert(std::make_pair<std::string, int>("crumbs", 3));
      printStdMap(h1);
      h1.insert(std::make_pair<std::string, int>("eggs", 2));
      printStdMap(h1);
      h1.erase("eggs");
      printStdMap(h1);
      h1.erase("eggs");
      printStdMap(h1);
      h1.erase(h1.find("cheese"), h1.end());
      printStdMap(h1);

      std::cout << std::endl << std::endl;
      // J Implementation
      JHashMap<int, int> h2;
      h2.printItems();
      h2.addItem(6);
      h2.addItem(6, 12);
      h2.printItems();
      h2.addItem(14, 28);
      h2.printItems();
      h2.addItem(6, 13);
      h2.printItems();
      h2.getItem();
      std::cout << "Get 6: " << h2.getItem(6) << std::endl;
      std::cout << "Get 7: " << h2.getItem(7) << std::endl;
      std::cout << "Get 14: " << h2.getItem(14) << std::endl;
   }


    return 0;
}

