
#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6-1;

int parent[MAX];

int find(int a){  //function to find the parent of the subset this a belongs to

    while(parent[a]!=a){

        parent[a] = parent[parent[a]];

        a = parent[a];

    }

    return a;

}

void union_(int a,int b){  //function to merge two subsets

    int d = find(a);

    int e = find(b);

    parent[d] = parent[e];
}

int main(){

    int vertices;

    cin>>vertices;

    int edges;

    cin>>edges;

    vector<pair<int,pair<int,int>>>adj;      // vector to store the edges in the form - > {weight, {source, destination}}

    for(int i=0;i<edges;i++){

        int weight;

        int src,destination;

        cin>>weight>>src>>destination;

        adj.push_back({weight,{src,destination}});   // pushing back the edges one by one

    }

    sort(adj.begin(),adj.end());     // sorting the edges 

    for(int i = 0;i<MAX;i++){

        parent[i] = i;        // initialising the parent of each node as itself

    }

    vector<pair<int,int>>tree_edges;      // vector for storing the edges of the minimum spanning tree

    int totalweight = 0;     //initialising the total weight to 0

    for(auto x:adj){

        int a = x.second.first;

        int b = x.second.second;

        int cost = x.first;

        if(find(a)!=find(b)){        // if the two vertices are in different subsets, merge them into one

            totalweight+=cost;

            union_(a,b);

            tree_edges.push_back({a,b});

        }

    }

    cout<<"Edges are : "<<endl;

    for(auto x:tree_edges){  // printing the edges of the minimum spanning tree

        cout<<x.first<<" "<<x.second<<endl;

    }

    cout<<"Total weight of MST = ";

    cout<<totalweight<<endl;        //printing the total weight of the minimum spanning tree

    return 0;

}