/*1.把二元查找树转变成排序的双向链表*/
#include<iostream>
#include<cstdlib>
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
void inorder(BSTreeNode *root)
{
	if(root)
	{
		inorder(root->left);
		cout<<root->val<<" ";
		inorder(root->right);
	}
}
void BStoList(BSTreeNode *root, BSTreeNode *&head)
{
	if(root)
	{
		BStoList(root->left, head);
		root->left = head;
		if(NULL != head)
			head->right = root;
		head = root;
		BStoList(root->right, head);
	}
}
int main()
{
	BSTreeNode *root = NULL;
	BSTreeNode *tail =NULL;
	AddNode(root, 10);
	AddNode(root, 4);
	AddNode(root, 6);
	AddNode(root, 8);
	AddNode(root, 12);
	AddNode(root, 14);
	AddNode(root, 17);
	AddNode(root, 8);
	AddNode(root, 15);
	inorder(root);
	BStoList(root, tail);
	cout<<endl;
	while(tail != NULL)
	{
		cout<<tail->val;
		if(tail->left)
			cout<<"<->";
		tail = tail->left;
	}
	system("pause");
	return 0;
}