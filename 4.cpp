#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
struct BSTreeNode
{
	int val;
	BSTreeNode * left;
	BSTreeNode * right;
};
void AddNode(BSTreeNode *&Cur, int val)
{
	if(NULL == Cur)
	{
		BSTreeNode *node = new BSTreeNode();
		node->left = NULL;
		node->right = NULL;
		node->val = val;
		Cur = node;
	}
	else if(Cur->val > val)
	{
		AddNode(Cur->left, val);
	}
	else if(Cur->val < val)
	{
		AddNode(Cur->right, val);
	}
	else{
		printf("duplicate val!\n");
	}
}
void findpath(BSTreeNode *root, int dst, vector<int> &path, int src)
{
	if(root)
	{
		src += root->val;
		bool isleaf = !(root->left)&&!(root->right);
		path.push_back(root->val);
		if(src == dst && isleaf)
		{
			for(vector<int>::iterator p = path.begin(); p != path.end(); p++)
				cout<<*p<<" ";
			cout<<endl;
		}
		if(root->left)
			findpath(root->left, dst, path, src);
		if(root->right)
			findpath(root->right, dst, path, src);
		src -= root->val;
		path.pop_back();
	}
}
int main()
{
	BSTreeNode *root = NULL;
	int val = 22;
	int sum = 0;
	vector<int> a;
	AddNode(root, 10);
	AddNode(root, 12);
	AddNode(root, 5);
	AddNode(root, 7);
	AddNode(root, 4);
	findpath(root, val, a, sum);
	system("pause");
	return 0;
}