/*
Problem: Convert Adjacency Matrix to Adjacency List

Problem Statement:
Given an n × n adjacency matrix representing an unweighted graph, convert it into an adjacency list representation.

Example:

Input:
3
0 1 1
1 0 0
1 0 0

Output:
0 -> 1 2
1 -> 0
2 -> 0
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int adjacencyMatrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value;
            cin >> value;
            adjacencyMatrix[i][j] = value;
        }
    }

    vector<vector<int>> adjacencyList(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
                adjacencyList[i].push_back(j);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> ";
        for (int x : adjacencyList[i])
            cout << x << " ";

        cout << endl;
    }
    return 0;
}