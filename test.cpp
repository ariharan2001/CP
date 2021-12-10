#include<bits/stdc++.h>
using namespace std;
const int size = 7;
vector<vector<int>> g;
vector<bool> vis;
queue<int> que;

void addEdge(int u,int v){
  g[u].push_back(v);
}

void bfs(int at){
     que.push(at);
     vis[at] = true;
     while(!que.empty()){
         int e = que.front();
         que.pop();
         cout<<e<<" ";
         for(auto x: g[e]){
             if(!vis[x]){
              que.push(x);
              vis[x] = true;
             }
         }
     }   
}

int main(){
  g.assign(size,vector<int>());
  vis.assign(size,false);
  addEdge(1,2);
  addEdge(1,3);
  addEdge(2,4);
  addEdge(4,5);
  addEdge(4,6);
 
  bfs(1);
  cout<<endl;

 return 0;
}