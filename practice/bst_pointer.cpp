#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#define FC(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
using namespace std;
/*template <class T>
struct BSTNode {
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;
    BSTNode(T data) {
      this->data = data;
      this->left = this->right = NULL;
    }
};
template <class T>
struct BinarySearchTree {
  BSTNode<T>* root;
  BSTNode<T>** search(T data) {
    BSTNode<T>** node = &root;
    while (*node != NULL) {
        if (data <= (*node)->data)
            node = &(*node)->left;
        else if ((*node)->data < data)
            node = &(*node)->right;
        else
            break;
    }
    return node;
  }
  void infix(BSTNode<T> *node) {
    if(node == NULL) return;
    infix(node->left);
    cout << "(" << node->data << ")";
    infix(node->right);
  }  
  void insert(T data) {
    BSTNode<T>** node = search(data);
    if (*node == NULL) {
        *node = new BSTNode<T>(data);
    }
  }  
  void proba() {
    string s;
    for(int x; ; ) {
      cin >> x >> s;
      if(x < 0) insert(s[0]);
      BSTNode<char> **wh;
      wh = search(s[0]);
      if(*wh == NULL) cout << "0" << endl;
      else cout << *wh; 
      infix(root);
    }  
  } 
};
BinarySearchTree<char> tr;*/
struct Node {
  char key;
  Node *left;
  Node *right;
  Node(char c) {
    key = c;
    left = right = NULL;
  }  
};  
struct tree {
  Node *root;
  void infix(Node *node) {
    if(node == NULL) return ;
    infix(node->left);
    cout << "(" << node->key << ")";
    infix(node->right);
  }  
  bool search(Node *node, char c) {
    if(node == NULL) return false;
    if(node->key == c) return true;
    if(c <= node->key) return search(node->left, c);
    return search(node->right, c);
  }  
  void insert(Node *&node, char c) {
     if (node == NULL)
       node = new Node(c);
     else if (c <= node->key)
       insert(node->left, c);
     else
       insert(node->right, c);
  }
  void proba() {
    string s;
    for(int x; ; ) {
      cin >> x >> s;
      if(x < 0) insert(root, s[0]);
      else cout << "->" << search(root, s[0]) << endl;
      infix(root);
    }  
  } 
  tree() {
    root = NULL;
  }  
} t;
struct elem {
  int words;
  int pref;
  elem *next[26];
  elem() {
    words = pref = 0;
    for(int i = 0; i < 26; ++i)
      next[i] = NULL;
  }  
};  
struct trie {
  elem *root;
  int count_pref(elem *node, const string& s) {
    if(s.empty()) return node->pref;
    char c = s[0]-'a';
    if(node->next[c] == NULL) return 0;
    return count_pref(node->next[c], s.substr(1, s.size()-1));
  }
  int count_words(elem *node, const string& s) {
    if(s.empty()) return node->words;
    char c = s[0]-'a';
    if(node->next[c] == NULL) return 0;
    return count_words(node->next[c], s.substr(1, s.size()-1));
  }  
  void insert(elem *node, const string& s) {
    if(s.empty()) {
      ++node->words;
      return ;
    }   
    else {
      char c = s[0]-'a';
      ++node->pref;
      if(node->next[c] == NULL)
        node->next[c] = new elem();
      insert(node->next[c], s.substr(1, s.size()-1)); 
    }   
  } 
   void proba() {
    string s;
    for(int x; ; ) {
      cin >> x >> s;
      if(x < 0) insert(root, s);
      else cout << "->" << count_words(root, s) << endl;
    }  
  }  
  trie() {
    root = new elem();
  }  
} tt;    
int main() {
  //tr.proba();
  //t.proba();
  tt.proba();
  scanf("\n");
  return 0;
}
/*
-1 a
-1 c
-1 s
-1 l
*/


