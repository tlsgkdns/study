#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;
int N;
vector<ll> ans;
string S;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S;
		reverse(S.begin(), S.end());
		ans.push_back(stoll(S));
	}
	sort(ans.begin(), ans.end());
	for (ll a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/5648