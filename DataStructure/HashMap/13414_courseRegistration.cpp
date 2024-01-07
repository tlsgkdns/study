#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<string> ans;
string S[500001];
int cnt, K, L;
unordered_map<string, int> C;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> S[i];
		++C[S[i]];
	}
	for (int i = 0; i < L && ans.size() < K; i++)
	{
		--C[S[i]];
		if (C[S[i]] == 0)
			ans.push_back(S[i]);
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << '\n';
}

// https://www.acmicpc.net/problem/13414