#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
int N, M, num;
unordered_map<int, int> um;
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		um[num]++;
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		ans.push_back(um[num]);
	}
	for (int a : ans) cout << a << " ";
	cout << '\n';
}

// https://www.acmicpc.net/problem/10816