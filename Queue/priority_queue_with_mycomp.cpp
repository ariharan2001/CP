#include<bits/stdc++.h>
using namespace std;

// creating a struct to sort by pair using operator overloading 

struct mycompare{
    bool operator()(pair<int,int>& a,pair<int,int>& b){
        if(a.first==b.first) return a.second < b.second;
        else return a.first > b.first;
    }
};

void show(priority_queue<pair<int,int>,vector<pair<int,int>>,mycompare> p){
    while(!p.empty()){
        cout<<p.top().first<<" "<<p.top().second<<'\n';
        p.pop();
    }
}

int main(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,mycompare> p;
    p.push({7,4});
    p.push({7,5});
    p.push({8,3});
    p.push({8,6});
    p.push({8,8});
    show(p);
}
