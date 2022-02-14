#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = NULL;
		right = NULL;
	}
};

class Solution
{
public:
	Node* insert(Node* root, int data)
	{
		if (root == NULL)
		{
			return new Node(data);
		}
		else
		{
			Node* cur;
			if (data <= root->data)
			{
				cur = insert(root->left, data);
				root->left = cur;
			}
			else
			{
				cur = insert(root->right, data);
				root->right = cur;
			}

			return root;
		}
	}

	void preOrder(Node* root)
	{
		if (!root) return;

		stack<Node*> nodes_stk;
		nodes_stk.push(root);
		queue<int> val_que;

		while (!nodes_stk.empty())
		{
			Node* curr = nodes_stk.top();
			nodes_stk.pop();

			val_que.push(curr->data);

			if (curr->right) nodes_stk.push(curr->right);
			if (curr->left) nodes_stk.push(curr->left);
		}
		while (!val_que.empty())
		{
			cout << val_que.front() << " ";
			val_que.pop();
		}
	}
}; //End of Solution

int main()
{
	Solution myTree;
	Node* root = NULL;

	int t;
	int data;

	std::cin >> t;

	while (t-- > 0)
	{
		std::cin >> data;
		root = myTree.insert(root, data);
	}

	myTree.preOrder(root);
	return 0;
}
