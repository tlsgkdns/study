#include <iostream>
#include <unordered_map>
using namespace std;
using ll = long long;
int N, ans = 0;
char K;
string str;
unordered_map<string, bool> um;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	while (N--)
	{
		cin >> str;
		if (um.count(str) > 0) continue;
		um[str] = true;
	}
	switch (K)
	{
	case 'Y':
		ans = um.size();
		break;
	case 'F':
		ans = um.size() / 2;
		break;
	default:
		ans = um.size() / 3;
	}
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/25757