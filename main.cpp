#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

/*
Ghazi Abbas
shs data structures - galbraith

red black tree insertion (part 1)

--using numbers.txt

Sources:
https://www.geeksforgeeks.org/insertion-in-red-black-tree/
https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/
https://youtu.be/tJ7niBAhDQI
https://www.programiz.com/dsa/red-black-tree
https://youtu.be/jNyTK_2CLPU
+
Professor Fant's video lectures
*/

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
    color = false; //from https://www.geeksforgeeks.org/insertion-in-red-black-tree/
  }

  ~Node(){}//nothing to deallocate 

};


void fromFile();
void fromClient();

int main()
{

  boolean initRun = true;
  while(initRun)
  {
    int cmd;
    cout << "select input, Enter 1 for File or 2 for Manual";
    cin >> cmd;
    if(cmd == 1)
    {
      cout << "selected: F" << endl;
      initRun = false;
    }
    else if(cmd == 2)
    {
      cout << "selected: M" << endl;
      initRun = false;
    }
    else
    {
      cout << "error in cmd" << endl;
    }
  }

  while(true)
  {
    int rsp;
    cout << "1 to insert, 2 to print, 3 to quit";
    cin >> rsp;
    if(rsp == 1)
    {//insert

    }
    else if(rsp == 2)
    {//print

    }
    else if(rsp ==3)
    {//quit
      break;
    }
    else
    {

    }

  }
  
}


void fromFile()
{
  ifstream numbers("numbers.txt");
  srand(time(NULL));

  int n;
  
  while(!numbers.eof())
  {
    numbers >> n;
    insert(root, n);
  }
}

void fromClient()
{
  
}
