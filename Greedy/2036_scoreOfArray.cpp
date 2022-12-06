#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
vector<int> neg, pos;
int N, arr[100001], num;
bool Z = false;
ll ans = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num < 0) neg.push_back(-num);
		else if (num > 0) pos.push_back(num);
		else Z = true;
	}
	sort(neg.begin(), neg.end()); sort(pos.begin(), pos.end());
	if (neg.size() % 2)
	{
		if (!Z) ans -= neg[0];
		for (int i = 1; i < neg.size(); i += 2)
			ans += (ll)neg[i] * (ll)neg[i + 1];
	}
	else
	{
		for (int i = 0; i < neg.size(); i += 2)
			ans += (ll)neg[i] * (ll)neg[i + 1];
	}
	int idx = 0;
	while (idx < pos.size() && pos[idx] == 1) ans += pos[idx++];
	if ((pos.size() - idx) % 2) ans += pos[idx++];
	for (; idx < pos.size(); idx += 2)
		ans += (ll)pos[idx] * (ll)pos[idx + 1];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/2036