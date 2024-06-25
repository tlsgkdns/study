#include <iostream>

using namespace std;
using ll = long long;
ll N, K;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	if (N * 26 < K || N > K) cout << "!\n";
	else
	{
		string ans = "";
		while ((N - ans.size() - 1) * 26 > K)
		{
			ans.push_back('A');
			--K;
		}
		ans.push_back((K + 25) % 26 + 'A');
		while (ans.size() < N) ans.push_back('Z');
		cout << ans << '\n';
	}
}

// https://www.acmicpc.net/problem/17828