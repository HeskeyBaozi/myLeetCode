#include <iostream>
#include <deque>
#include "TreeNode.h"
using namespace std;


class Solution
{
public:
	static int maxDepth(TreeNode* root)
	{
		if (root == nullptr)
			return 0;

		int depth = 0;

		deque<TreeNode*> Q; Q.push_back(root);

		/* 关键: 这代表了每一层中结点的个数 */
		int node_number_of_the_layer = Q.size();

		/* 
		* 每一次循环:
		* 开始时: depth 为已经完成的搜索深度
		* 弹出目前搜索的这一层的元素, 将其子节点作为下一层的元素压入队列尾部
		*/
		while (!Q.empty())
		{
			displayQueue(Q);
			TreeNode* u = Q.front(); Q.pop_front();
			node_number_of_the_layer--;

			if (u->left != nullptr)
				Q.push_back(u->left);
			if (u->right != nullptr)
				Q.push_back(u->right);

			/* 当队列pop完了一层的所有元素的时候 */
			if (node_number_of_the_layer == 0)
			{
				depth++;
				node_number_of_the_layer = Q.size();
				cout << "depth = " << depth
					<< " , Q.size() = "
					<< node_number_of_the_layer << endl << endl;
			}
		}
		return depth;
	}

	static void displayQueue(const deque<TreeNode*>& Q)
	{
		cout << "Deque Q:";
		for (const auto& ele : Q)
		{
			cout << " | " << ele->val;
		}
		cout << endl;
	}
};

void test_104()
{
	//  A Tree for test, height is 3
	//         0(root)  depth is 1, level is 0
	//          \
	//           2      depth is 2, level is 1
	//          / \
	//         5   6    depth is 3, level is 2
	//            / 
	//           7      depth is 4, level is 3

	TreeNode root(0), c2(2), c5(5), c6(6), c7(7);
	root.right = &c2;
	c2.left = &c5;
	c2.right = &c6;
	c6.right = &c7;

	/* solution */
	Solution sol;
	cout << sol.maxDepth(&root) << endl; // output: 4
}
