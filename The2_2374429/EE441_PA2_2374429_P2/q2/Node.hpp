#include<iostream>
using namespace std;


template <class T>
class Node
{
 public :
    T data;
    // Xor of next node and previous node
    Node<T>* xnode;
};

