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

void insert(Node*& c, int num);
void print(Node* c, int h);
void fromFile();
void fromClient();

void reColor(Node*& c);
void checkCases(Node*& c);
void rightRedU(Node*& c);
void leftRedU(Node*& c);

Node* rightRotate(Node* n);
Node* leftRotate (Node* n);
//need global vriable
Node* root = nullptr;



int main()
{

  //loop for initial creation of tree
  while(true)
  {
    int cmd;
    cout << "select input, Enter 1 for File or 2 for Manual";
    cin >> cmd;
    if(cmd == 1)
    {
      cout << "selected: F" << endl;
      break;
    }
    else if(cmd == 2)
    {
      cout << "selected: M" << endl;
      break;
    }
    else
    {
      cout << "error in cmd" << endl;
    }
  }
  print(root,0);
  while(true)
  {
    int rsp;
    cout << "1 to insert, 2 to print, 3 to quit";
    cin >> rsp;
    if(rsp == 1)
    {//insert
      int num;
      cout << "Enter a number to insert" << endl;
      cin>> num;
      cin.get();
      insert(root, num);
      cout << "insert function called" << endl;

    }
    else if(rsp == 2)
    {//print
      print(root, 0);
    }
    else if(rsp ==3)
    {//quit
      break;
    }
    else
    {
      cout << "Invalid command";
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
  int inp;
  cout << "Enter numbers one by one, entering 0 will exit the loop." << endl;
  int loopCount = 0;
  while(inp != 0 || loopCount < 50)
  {
    cin >> inp;
    insert(root, inp);
    cout << endl;
    loopCount++;
  }
}

void insert(Node*& c, int num)
{
  //first check if curr is null
  if (c == NULL) 
  {
    c = new Node(num, NULL, NULL, NULL, false);
    root = c;
    return;
  }
  //check that the addition is >= curr
  if (num >= c->data) 
  {
    if (c->right == NULL) 
    {
      c->right = new Node(num, NULL, NULL, c, true);
      checkCases(c->right);
      return;
    }
    else 
    {
      insert(c->right, num);
    }
  }
  //check less than curr
  else 
  {
    if (c->left == NULL) 
    {
      c->left = new Node(num, NULL, NULL, c, true);
      checkCases(c->left);
      return;
    }
    else 
    {
      insert(c->left, num);
    }
  }
}
void print(Node* c, int h)
{

}
void reColor(Node*& c)
{

}
void checkCases(Node*& c)
{

}
void rightRedU(Node*& c)
{

}
void leftRedU(Node*& c)
{

}

Node* rightRotate(Node* n)
{

}
Node* leftRotate (Node* n)
{

}