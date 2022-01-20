#include<bits/stdc++.h>
using namespace std;

void show(priority_queue<pair<int,int>> p){
    while(!p.empty()){
        cout<<p.top().first<<" "<<p.top().second<<'\n';
        p.pop();
    }
}

int main(){
    priority_queue<pair<int,int>> p;
    p.push({1,2});
    p.push({2,3});
    p.push({3,4});
    p.push({4,5});
    p.push({5,6});
    show(p);
}
