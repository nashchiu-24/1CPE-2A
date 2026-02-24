#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int value) : data(value), left(nullptr), right(nullptr) {}
};
node* insert(node* root, int key){
    if (!root) {
        return new node(key);
    }
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

void displayconnections(node* node) {
    if (!node) return;
    if (node->left) {
        cout << node->data << " -> " << node->left->data << " (left)" << endl;
        displayconnections(node->left);
    }
    if (node->right) {
        cout << node->data << " -> " << node->right->data << " (right)" << endl;
        displayconnections(node->right);
    }
}

node* search(node* root, int key) {
    if (!root || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

int main() {
  node *root = nullptr;
  int keys [] = {40,30,25,35,50,45,60};
  for (int key : keys) {
    root = insert(root, key);
  }
  cout << "Connections in the binary search tree:" << endl;
  displayconnections(root);
  
  int searchkey = 46;
  node* result = search(root, searchkey);
  if (result) {
    cout << "found node with value: " << result->data << endl;
  } else {
    cout << "Node with value " << searchkey << " not found." << endl;
  }
  return 0;
}