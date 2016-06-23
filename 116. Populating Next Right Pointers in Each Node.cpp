#include <iostream>
#include <deque>
// #define BFS
#define DFS
using namespace std;

/**
* Definition for binary tree with next pointer.
*/
 struct TreeLinkNode
{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

#ifdef BFS
class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (!root)return;
		deque<TreeLinkNode*> Q;
		Q.push_back(root);
		int nodeNumber = Q.size();
		while (!Q.empty())
		{
			TreeLinkNode* nodePtr = Q.front(); Q.pop_front();
			nodeNumber--;

			if (nodePtr->left)
				Q.push_back(nodePtr->left);
			if (nodePtr->right)
				Q.push_back(nodePtr->right);

			if (nodeNumber == 0)
			{
				nodePtr->next = nullptr;
				nodeNumber = Q.size();
			}				
			else nodePtr->next = Q.front();
		}
	}
};
#endif // BFS


#ifdef DFS
class Solution
{
public:
	void connect(TreeLinkNode *root)
	{
		if (!root)return;
		deque<TreeLinkNode*> Q;
		Q.push_back(root);

		// node number of the same distance from the root in the BFS tree
		int nodeNumber = Q.size();
		while (!Q.empty())
		{
			TreeLinkNode* nodePtr = Q.front(); Q.pop_front();
			nodeNumber--;

			if (nodePtr->left)
				Q.push_back(nodePtr->left);
			if (nodePtr->right)
				Q.push_back(nodePtr->right);

			if (nodeNumber == 0)
			{
				nodePtr->next = nullptr;
				nodeNumber = Q.size();
			}
			else // nodeNumber != 0
				nodePtr->next = Q.front();
		}
	}
};

#endif // DFS

void test_116()
{
	//  A Tree for test, height is 3
	//         0(root)  depth is 1, level is 0
	//          \
	//           2      depth is 2, level is 1
	//          / \
	//         5   6    depth is 3, level is 2
	//            / 
	//           7      depth is 4, level is 3
TreeLinkNode root(0), c2(2), c5(5), c6(6), c7(7);
	root.right = &c2;
	c2.left = &c5;
	c2.right = &c6;
	c6.right = &c7;

	/* solution */
	Solution sol;
	sol.connect(&root);
}

int main()
{
	test_116();
}