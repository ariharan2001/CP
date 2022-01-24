/*
   Trie is tree datastructure 
   used to store prefix structure of keys
   therby searching for a key is max length of keys
   
   abcd, abce, abde  will be stored as shown ->             a
                                                            |
                                                            b
                                                           / \
                                                          c   d
                                                         / \  |
                                                         d e  e
 */

#include<bits/stdc++.h>
using namespace std;

struct Trie{
  Trie *nodes[26];
  bool endofword;
};

Trie *getNode(){
   Trie *node = new Trie();
   Trie *temp = node;
   for(int i=0;i<26;i++){
     temp->nodes[i] = NULL;
     temp->endofword = false;
   }
   return node;
}

void insert(Trie *root,string key){
  Trie *tmp = root;
  for(int i=0;i<key.length();i++){
    int index = key[i]-'a';
    if(tmp->nodes[index]==NULL) tmp->nodes[index] = getNode();
    tmp = tmp->nodes[index];
  }
  tmp->endofword = true;
}

bool search(Trie *root,string key){
  Trie *tmp = root;
  for(int i=0;i<key.length();i++){
    int index = key[i] - 'a';
    if(tmp->nodes[index]==NULL) return false;
    tmp = tmp->nodes[index];
  }
  return tmp->endofword;
}

int main(){
  string s[]={"aabbba","aaabbb","aabba","aaabbba"};
  Trie *root = getNode();
  for(int i=0;i<4;i++) insert(root,s[i]);
  if(search(root,"aabbba")) cout<<"existing\n";
  else cout<<"Not existing\n";
}
