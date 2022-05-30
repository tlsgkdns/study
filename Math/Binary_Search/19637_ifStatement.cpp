#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> ans;
string nick[100001];
vector<int> power;
int N, M, P;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	power.resize(N);
	for (int i = 0; i < N; i++)
		cin >> nick[i] >> power[i];
	for (int i = 0; i < M; i++)
	{
		cin >> P;
		int idx = lower_bound(power.begin(), power.end(), P) - power.begin();
		ans.push_back(nick[idx]);
	}
	for (string a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/19637