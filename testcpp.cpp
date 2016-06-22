#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	explicit TreeNode(int x)
		: val(x), left(nullptr), right(nullptr)
	{
	}
};

int main()
{
	TreeNode k(1);
	TreeNode l(2);
	k.left = &l;
	k.left = nullptr;
	if (k.left)
	{
		cout << "left chile = " << k.left->val << endl;
	}
	return 0;
}