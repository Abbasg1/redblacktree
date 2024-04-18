#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class Node
{
public:
  int data;

  Node* right;
  Node* left;
  Node* parent;

  bool color; //true is red black is false
  //constructor called
  Node(int data, Node* right, Node* left, Node* parent, bool color)
  {
    this->data = data;
    this->right = right;
    this->left = left;
    this->parent = parent;
    this->color = color;
  }

  //default
  Node()
  {
    data = 0;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
    color = false;
  }

  ~Node(){}//nothing to deallocate 

};



int main()
{


}
