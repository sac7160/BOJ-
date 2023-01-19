#include <iostream>
#include <vector>

using namespace std;

class node
{
public:
	node() {};
	node(char data, char left_node, char right_node)
	{
		this->data = data;
		this->left_node = left_node;
		this->right_node = right_node;
	}
	char data;
	char left_node;
	char right_node;
};

node tree[26];

void preorder(node cur)
{
	cout << cur.data;
	if (cur.left_node != (char)'.') preorder(tree[cur.left_node - 65]);
	if (cur.right_node != (char)'.') preorder(tree[cur.right_node - 65]);
}
void inorder(node cur)
{
	if (cur.left_node != (char)'.') inorder(tree[cur.left_node - 65]);
	cout << cur.data;
	if (cur.right_node != (char)'.') inorder(tree[cur.right_node - 65]);
}
void postorder(node cur)
{

	if (cur.left_node != (char)'.') postorder(tree[cur.left_node - 65]);
	if (cur.right_node != (char)'.') postorder(tree[cur.right_node - 65]);
	cout << cur.data;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		char input1,input2,input3;
		cin >> input1 >> input2 >> input3;

		tree[input1-65] = node(input1, input2, input3);
	}

	preorder(tree[0]);
	cout << '\n';
	inorder(tree[0]);
	cout << '\n';
	postorder(tree[0]);

}
