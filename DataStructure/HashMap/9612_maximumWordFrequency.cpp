#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, int> um;
string W, ans = "";
int N, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> W;
		um[W]++;
	}
	for (auto iter = um.begin(); iter != um.end(); iter++)
	{
		int c = (*iter).second;
		if (cnt < c)
		{
			cnt = c;
			ans = (*iter).first;
		}
		if (cnt == c && ans < (*iter).first)
		{
			ans = (*iter).first;
		}
	}
	cout << ans << " " << cnt << '\n';
}

// https://www.acmicpc.net/problem/9612