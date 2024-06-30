#include <iostream>
#include <vector>
using namespace std;

void dfs(char tree[][2], char c, vector<char>& preorder, vector<char>& inorder, vector<char>& postorder);

int main() {
	char tree[26][2];
	int N;
	cin >> N;

	vector<char> inorder;
	vector<char> preorder;
	vector<char> postorder;

	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;
		// root의 왼쪽 
		tree[root - 'A'][0] = left;
		// root의 오른쪽
		tree[root - 'A'][1] = right;
	}

	dfs(tree, 'A', inorder, preorder, postorder);

	for (auto it = inorder.begin(); it != inorder.end(); it++)
		cout << *it;
	cout << '\n';
	for (auto it = preorder.begin(); it != preorder.end(); it++)
		cout << *it;
	cout << '\n';
	for (auto it = postorder.begin(); it != postorder.end(); it++)
		cout << *it;
}

void dfs(char tree[][2], char c, vector<char>& preorder, vector<char>& inorder, vector<char>& postorder) 
{

	if (c == '.') return;
	preorder.push_back(c);

	// 왼쪽으로 탐색 
	dfs(tree, tree[c - 'A'][0], preorder, inorder, postorder);
	inorder.push_back(c);

	// 오른쪽으로 탐색
	dfs(tree, tree[c - 'A'][1], preorder, inorder, postorder);
	postorder.push_back(c);
}