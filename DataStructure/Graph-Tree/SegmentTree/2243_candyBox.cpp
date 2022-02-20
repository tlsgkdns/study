#include <iostream>
#include <vector>
using namespace std;

vector<int> ans;
const int MAX = 1000001;
int tree[MAX * 4], N, A, B, C;

void update(int node, int target, int diff, int s, int e)
{
	if (target < s || target > e) return;
	tree[node] += diff;
	if (s == e) return;
	int m = (s + e) / 2;
	update(node * 2, target, diff, s, m);
	update(node * 2 + 1, target, diff, m + 1, e);
}
int query(int node, int target, int s, int e)
{
	if (s == e) return s;
	int m = (s + e) / 2;
	if (target <= tree[node * 2])
		return query(node * 2, target, s, m);
	else
		return query(node * 2 + 1, target - tree[node * 2], m + 1, e);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (A == 1)
		{
			cin >> B;
			int a = query(1, B, 1, MAX);
			ans.push_back(a);
			update(1, a, -1, 1, MAX);
		}
		else
		{
			cin >> B >> C;
			update(1, B, C, 1, MAX);
		}
	}
	for (int i = 0; i < (int)ans.size(); i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/2243