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

	/* you only have to complete the function given below.  
	Node is defined as  
	
	class Node {
	    public:
	        int data;
	        Node *left;
	        Node *right;
	        Node(int d) {
	            data = d;
	            left = NULL;
	            right = NULL;
	        }
	};
	
	*/

	void postOrder(Node* root)
	{
		if (!root) return;

		stack<Node*> nodes_stk;
		nodes_stk.push(root);
		stack<int> val_stk;

		while (!nodes_stk.empty())
		{
			Node* curr = nodes_stk.top();
			nodes_stk.pop();

			val_stk.push(curr->data);

			if (curr->left) nodes_stk.push(curr->left);
			if (curr->right) nodes_stk.push(curr->right);
		}

		while (!val_stk.empty())
		{
			cout << val_stk.top() << " ";
			val_stk.pop();
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

	myTree.postOrder(root);
	return 0;
}
