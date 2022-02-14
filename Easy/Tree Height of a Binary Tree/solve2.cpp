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

	int height(Node* root)
	{
		if (!root) return -1;

		int ans = -1;
		queue<Node*> q;
		q.push(root);

		while (!q.empty())
		{
			ans++;
			int size = q.size();

			while (size--)
			{
				auto node = q.front();
				q.pop();

				if (node->left) q.push(node->left);
				if (node->right) q.push(node->right);
			}
		}
		return ans;
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

	int height = myTree.height(root);

	std::cout << height;

	return 0;
}
