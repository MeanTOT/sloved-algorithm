#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Node
{
public:
	int Data;
	vector<Node*> Adjacent;
	bool bMarked;
public:
	Node(int data) : Data(data), bMarked(false)
	{		
		
	}
};

class Graph
{
public:
	vector<Node*> Nodes;
	stack<Node*> Stack;
	queue<Node*> Queue;
public:
	Graph()
	{
		for (int i = 0; i < 9; i++)
		{
			Nodes.push_back(new Node(i));
		}
	}
	~Graph()
	{
		Clear();
	}

	void AddEdge(int i1, int i2)
	{		
		Nodes[i1]->Adjacent.push_back(Nodes[i2]);
		Nodes[i2]->Adjacent.push_back(Nodes[i1]);
	}

	void DFS()
	{
		Stack.push(Nodes[0]);
		Nodes[0]->bMarked = true;
		DFSInternalResursive(Stack.top());
	}

	void BFS()
	{
		Queue.push(Nodes[0]);
		Nodes[0]->bMarked = true;
		BFSInternalResursive(Queue.front());
	}

	void Clear()
	{
		Init();

		for (int i = 0; i < Nodes.size(); i++)
		{
			delete Nodes[i];
			Nodes[i] = nullptr;
		}

		Nodes.clear();
	}

	void Init()
	{
		while (!Stack.empty())
		{
			Stack.pop();
		}
		while (!Queue.empty())
		{
			Queue.pop();
		}

		for (int i = 0; i < Nodes.size(); i++)
		{
			Nodes[i]->bMarked = false;
		}
	}

private:
	void DFSInternalResursive(Node* node)
	{		
		Stack.pop();
		cout << node->Data << endl;

		for (int i = 0; i < node->Adjacent.size(); i++)
		{
			if (!node->Adjacent[i]->bMarked)
			{
				node->Adjacent[i]->bMarked = true;
				Stack.push(node->Adjacent[i]);
			}				
		}		

		if (!Stack.empty())
		{
			DFSInternalResursive(Stack.top());
		}	
		else
		{
			return;
		}
	}

	void BFSInternalResursive(Node* node)
	{
		Queue.pop();
		cout << node->Data << endl;

		for (int i = 0; i < node->Adjacent.size(); i++)
		{
			if (!node->Adjacent[i]->bMarked)
			{
				node->Adjacent[i]->bMarked = true;
				Queue.push(node->Adjacent[i]);
			}
		}

		if (!Queue.empty())
		{
			BFSInternalResursive(Queue.front());
		}
		else
		{
			return;
		}
	}
};

