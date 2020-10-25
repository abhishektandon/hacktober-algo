#include <iostream>
#include<bits/stdc++.h>
using namespace std;


//*********** ALGORITHM ***************//

// given a weighted graph(should not have negative edges) (can be bidirectional or unidirectional) dijkstra's algorithm is used to find the shortest distance between any two nodes

// here, what we shall do is, given a source vertex, we shall calculate the shortest distance betweeen that vertex and all other vertices
// assuming zero to be the source, disatnce of zero from zero is 0 and infinite for all others
// we shall also maintian a visited array

// we shall pick the vertex with minimum diatance and mark it visited
// then we shall visit its neighbouring vertices and update the distance values

// now from all the unvisited vertices, we shall select the certex with minimum distance
// and explore its neighbours

// now path cost via that node is path cost via 0 to 1 anfd then from 1 to 2
// so we also need to maintain a path array
// also if this is less than current distane, update the current distance value


// and we need to repeat the above process


void dijkstras(int **edges, bool *visited, int *distance, int V )
{
    int min_dist = INT_MAX;
    int index = -1;
    
    for(int i = 0; i < V; i++)
    {
        if(distance[i] < min_dist && !visited[i])
        {
            min_dist = distance[i];
            index = i;
        }
    }
	
    visited[index] = true;
    
    for(int i = 0; i < V; i++)
    {
        if(edges[index][i] != 0 && !visited[i])
        {
            int d = distance[index] + edges[index][i];
            
            if(d < distance[i])
            {
                distance[i] = d;
            }
        }
    }
    

}

void print(int *distance, int V)
{
    for(int i = 0; i < V; i++)
    {
        cout<<i<<" "<<distance[i]<<'\n';
    }
}

int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;


    
	int **edges = new int*[V];
  	for(int i = 0; i < V; i++)
  	{
  	
  	edges[i] = new int[V];
  	for(int j = 0; j < V; j++)
  	{
  		edges[i][j] = 0;
  	}

  	}
    
    for(int i = 0; i < E; i++)
    {
  	int v1,v2,w;
  	cin>>v1>>v2>>w;

  	edges[v1][v2] = w;
  	edges[v2][v1] = w;
    }
    
  bool *visited = new bool[V];
  int *distance = new int[V];
  for(int i = 0; i < V; i++)
  {
  	visited[i] = false;
    distance[i] = INT_MAX;
  }

    
    distance[0] = 0;
    
    for(int i = 0; i < V; i++)
    {
        dijkstras(edges, visited, distance, V);
    }
    
    
	print(distance, V);

  return 0;
}
