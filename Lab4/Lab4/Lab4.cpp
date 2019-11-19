using namespace std;
#include <stdio.h>
#include <iostream>

#define V 11

int minKey(int key[], bool mstSet[])
{	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}
 
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] + 1 << " - " << i + 1 << " \t" << graph[i][parent[i]] << " \n";
}

void primMST(int graph[V][V])
{
	int parent[V];

	int key[V];

	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;
	parent[0] = -1;  
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet);

		mstSet[u] = true;

		
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}
 
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = {
		{0, 4, 3, 2, 0, 0, 0, 0, 0, 0, 0},
		{4, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0},
		{3, 0, 0, 0, 1, 7, 0, 0, 0, 0, 0},
		{7, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
		{0, 2, 1, 0, 0, 0, 0, 4, 7, 0, 0},
		{0, 0, 7, 2, 0, 0, 0, 4, 0, 5, 0},
		{0, 1, 0, 2, 0, 0, 0, 0, 3, 3, 0},
		{0, 0, 0, 0, 4, 4, 0, 0, 0, 0, 4},
		{0, 0, 0, 0, 7, 0, 3, 0, 0, 0, 6},
		{0, 0, 0, 0, 0, 5, 3, 0, 0, 0, 5},
		{0, 0, 0, 0, 0, 0, 0, 4, 6, 5, 0}
	};

	/*for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			cout << "Enter weight " << i + 1 << " to " << j + 1 << endl;
			cin >> graph[i][j];
		}
	}*/

	primMST(graph);

	return 0;
}