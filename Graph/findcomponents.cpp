#include <bits/stdc++.h>
using namespace std;

int merge(int* parent, int x)
{
	if (parent[x] == x)
		return x;
	return merge(parent, parent[x]);
}

int connectedcomponents(int n, vector<vector<int> >& edges)
{
	int parent[n];
  // intializing parent of ith node to itself until find out
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
  // finding parent of each node
	for (auto x : edges) {
		parent[merge(parent, x[0])] = merge(parent, x[1]);
	}
	int ans = 0;
  // no of components = number of nodes have parent not changed => implies the node is the parent of all the node in that connected subgraph
	for (int i = 0; i < n; i++) {
		ans += (parent[i] == i);
	}
  // lets make parent of in sub graph to one main root node to classify each subgraph uniquely
	for (int i = 0; i < n; i++) {
		parent[i] = merge(parent, parent[i]);
	}
	map<int, list<int> > m;
  // grouping distinct each components of common parent
	for (int i = 0; i < n; i++) {
		m[parent[i]].push_back(i);
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		list<int> l = it->second;
		for (auto x : l) {
			cout << x << " ";
		}
		cout << endl;
	}
	return ans;
}

int main()
{
	int n = 5;
	vector<int> e1 = { 0, 1 };
	vector<int> e2 = { 2, 3 };
	vector<int> e3 = { 3, 4 };
	vector<vector<int> > e;
	e.push_back(e1);
	e.push_back(e2);
	e.push_back(e3);
	int a = connectedcomponents(n, e);
	cout << "total no. of connected components are: " << a
		<< endl;
	return 0;
}
