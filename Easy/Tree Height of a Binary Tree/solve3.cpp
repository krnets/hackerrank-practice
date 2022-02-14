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

		stack<tuple<Node*, int>> stk;
		stk.push({root, 0});
		int ans = 0;

		while (!stk.empty())
		{
			auto [node, depth] = stk.top();
			stk.pop();

			if (node->left) stk.push({node->left, 1 + depth});
			if (node->right) stk.push({node->right, 1 + depth});
			ans = max(ans, depth);
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
