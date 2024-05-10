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
+
https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
for testing
*/

class Node //node class
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

//fucntion prototpes, c is current h is height
void insert(Node*& c, int num);
void print(Node* c, int h);
void fromFile();
void fromClient();

//deletion
void search(Node* c, int n);
Node* void remove(Node* c, int n);

void reColor(Node*& c);
void checkCases(Node*& c);
void rightRedU(Node*& c);
void leftRedU(Node*& c);


//need global vriable for be;ow
Node* root = nullptr;

Node* rightRotate(Node* n)
{

  Node* lNode = n->left;
  n->left = lNode->right;
  if (lNode->right != NULL) 
  {
    //child right not null
    lNode->right->parent = n;
  }
  lNode->right = n;
  lNode->parent = n->parent;
  //node rotates t root
  if (n->parent == NULL) 
  {
    root = lNode;
  }
  else if (n == n->parent->left) 
  {
    //node be left child
    n->parent->left = lNode;
  }
  else 
  {
    //node be right child
    n->parent->right = lNode;
  }
  n->parent = lNode;
  return lNode;
}
Node* leftRotate (Node* n)
{//identical ^
  Node* rNode = n->right;
  n->right = rNode->left;
  if (rNode->left != NULL) 
  {
    rNode->left->parent = n;
  }
  rNode->left = n;
  rNode->parent = n->parent;
  if (n->parent == NULL) 
  { 
    root = rNode;
  }
  else if (n == n->parent->left) 
  { 
    n->parent->left = rNode;
  }
  else 
  {
    n->parent->right = rNode;
  }
  n->parent = rNode;
  return rNode;

}



//driver code
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
      fromFile();
      break;
    }
    else if(cmd == 2)
    {
      cout << "selected: M" << endl;
      fromClient();
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
    cout << "1 to insert, 2 to print, 3 to search, 4 to delete, 5 to quit";
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
    {//search
      
    }
    else if(rsp == 4)
      {//delete

    }
    else if(rsp == 5)
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
  int c=0;
  while(c <51 && !numbers.eof())
  {
    numbers >> n;
    insert(root, n);
    c++;
  }
}

void fromClient()
{
  int inp;
  cout << "Enter numbers one by one, entering 0 will exit the loop." << endl;
  
  //it was inserting 0 before checking if it would satisfy the loop condition i think


  int loopCount = 0;
  while(true)
  {
    
    cin >> inp;
    if(inp != 0)
    {  
      insert(root, inp);
      cout << endl;
      loopCount++;
    }
    else
    {
      break;
    }
  }
  /*
    cout << "";
    int c =0;
    while(true)
    {
      cin>>inp;
      if(inp !=0)
      {
        cout << "\n";
        insert(root, inp);
        c++;
      }
    }

*/
  
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
  if (c == nullptr) 
  {
    return;
  }
  print(c->right, h + 1);// Recursively print right subtree while incrementing h
  for (int i = 0; i < h; i++) 
  {
    cout << "\t"; //visualizer
  }
  if(c->color)
  {
    cout << c->data << "r" << endl; //printing data/color
  }
  else//else color is fale (black
  {
    cout << c->data << "b" << endl;
  }
  print(c->left, h + 1);
}
void reColor(Node*& c)
{//check if the value of "c" color is red, change to black. else opposite.
  if (c->color) 
  {
    c->color = false;
  }
  else 
  {
    c->color = true;
  }
}
void checkCases(Node*& c)
{//recursively check balance maintain rbt properties after inserting c new npde
  if (c == NULL || c->parent == NULL || c->parent->parent == NULL) 
  {//if c, c's parent, and c's grandparent dont exist
    return;
  }
  Node* grandparent = c->parent->parent; //ease of access
  if (grandparent->right == c->parent) 
  {//right parent
    Node* uncle = grandparent->left;
    if ((uncle != NULL) && (uncle->color == true)) 
    {//red uncle
      rightRedU(c);
      checkCases(grandparent);
    }
    else if (((uncle == NULL) || (uncle->color == false)) && c->parent->color == true) 
    {//black uncle case
      if (c->parent->left == c) 
      {
        Node * temp = rightRotate(c->parent);
        checkCases(temp->right);
      }
      else
      {
        reColor(c->parent);
        reColor(grandparent);
        Node* temp = leftRotate(c->parent->parent);
        checkCases(grandparent);
      }
    }
    if (root->color == true) 
    {
      reColor(root);
    }
    return;
  }
  else 
  {//left parent
    Node* uncle = grandparent->right;
    if ((uncle != NULL) && (uncle->color == true)) 
    {//uncle is red
      leftRedU(c);
      checkCases(grandparent);
    }
    else if (((uncle == NULL) || (uncle->color == false)) && c->parent->color == true) 
    {//black uncle cases
      if (c->parent->right == c) 
      {//c , paremnt right
        Node * temp = leftRotate(c->parent);
        checkCases(temp->left);
      }
      else
      {//c is left, parent is left
        reColor(c->parent);
        reColor(grandparent);
        Node * temp = rightRotate(grandparent);
        checkCases(temp);
      }
    }
    if (root->color == true) 
    {//maintain root
      reColor(root);
    }
    return;
  }
}
void rightRedU(Node*& c)
{
  reColor(c->parent);
  reColor(c->parent->parent);
  reColor(c->parent->parent->left);

}
void leftRedU(Node*& c)
{
  reColor(c->parent);
  reColor(c->parent->parent);
  reColor(c->parent->parent->right);
}

void search(Node* c, int n)
{

}

Node* void remove(Node* c, int n)
{
  if(c==nullptr)
  {
      return c;
  }
  if(n> c->data)
  {
    c->right = remove(c->right, n);
    return c;
  }
  if(n < c->data)
  {
    c->left = remove(c->left, n);
    return c;
  }
  else
  {
    if()
    {

    }
  }
}
