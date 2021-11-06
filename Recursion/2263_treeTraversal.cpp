#include <iostream>
#include <vector>

using namespace std;

vector<int> inOrder, postOrder, preOrder, nodeId;
int N;
void recursion(int inIdxStart, int inIdxEnd, int postIdxStart, int postIdxEnd)
{
	if (inIdxStart > inIdxEnd || postIdxStart > postIdxEnd) return;
	int node = postOrder[postIdxEnd];
	preOrder.push_back(node);
	int idx = nodeId[postOrder[postIdxEnd]];
	if (postIdxStart == postIdxEnd) return;
	int ls = idx - inIdxStart;
	recursion(inIdxStart, idx - 1, postIdxStart, postIdxStart + ls - 1);
	recursion(idx + 1, inIdxEnd, postIdxStart + ls, postIdxEnd - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	inOrder.resize(N); postOrder.resize(N);
	nodeId.resize(N + 1);
	for (int i = 0; i < N; i++)
	{
		cin >> inOrder[i];
		nodeId[inOrder[i]] = i;
	}
	for (int i = 0; i < N; i++) cin >> postOrder[i];
	recursion(0, N - 1, 0, N - 1);
	for (int node : preOrder) cout << node << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/2263