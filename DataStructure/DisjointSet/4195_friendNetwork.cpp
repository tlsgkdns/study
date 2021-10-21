#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int T, F;

int find(vector<int>& parent, int n)
{
	if (parent[n] == n) return n;
	return parent[n] = find(parent, parent[n]);
}
void merge(vector<int>& parent, vector<int>& nums, int a, int b)
{
	int p = find(parent, a);
	int q = find(parent, b);
	if (p < q) swap(p, q);
	if (p == q) return;
	nums[q] += nums[p];
	parent[p] = q;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	vector<int> ans;
	for (int t = 0; t < T; t++)
	{
		cin >> F;
		string n1, n2;
		unordered_map<string, int> network;
		vector<int> parent(2 * F + 1), num(2 * F + 1, 0);
		int cnt = 1;
		for (int i = 0; i <= 2 * F; i++) parent[i] = i;
		for (int f = 0; f < F; f++)
		{
			cin >> n1 >> n2;
			if (network[n1] == 0)
			{
				network[n1] = cnt;
				num[cnt] = 1;
				cnt++;
			}
			if (network[n2] == 0)
			{
				network[n2] = cnt;
				num[cnt] = 1;
				cnt++;
			}
			merge(parent, num, network[n1], network[n2]);
			ans.push_back(num[find(parent, network[n1])]);
		}
	}
	for (int a : ans) cout << a << '\n';
}
// https://www.acmicpc.net/problem/4195