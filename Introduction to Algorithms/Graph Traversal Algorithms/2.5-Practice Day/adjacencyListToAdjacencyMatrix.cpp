/*
Problem: Convert Adjacency List To Adjacency Matrix

Problem Statement:
Given an adjacency list, convert it into an n × n adjacency matrix representation.

Example:
Input:
3 2
0 1
0 2

Output:
0 1 1
1 0 0
1 0 0
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertices, edges;
    cin >> vertices >> edges;

    vector<vector<int>> adjacencyList(vertices);
    while (edges--)
    {
        int a, b;
        cin >> a >> b;

        adjacencyList[a].push_back(b);
        adjacencyList[b].push_back(a);
    }

    int adjacencyMatrix[vertices][vertices];
    memset(adjacencyMatrix, 0, sizeof(adjacencyMatrix));

    for (int i = 0; i < vertices; i++)
    {
        for (int x : adjacencyList[i])
            adjacencyMatrix[i][x] = 1;
    }

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}