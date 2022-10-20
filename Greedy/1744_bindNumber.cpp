#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> pos, neg;
bool Z = false;
int arr[51], N, num, ans = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (num == 0)
		{
			Z = true;
			continue;
		}
		if (num > 0) pos.push_back(num);
		else neg.push_back(-num);
	}
	sort(pos.begin(), pos.end()); sort(neg.begin(), neg.end());
	if (pos.size() % 2)
	{
		ans += pos[0];
		for (int i = 1; i < pos.size(); i += 2)
		{
			if (pos[i] == 1) ans += pos[i + 1] + 1;
			else	ans += pos[i] * pos[i + 1];
		}
	}
	else
		for (int i = 0; i < pos.size(); i += 2)
		{
			if (pos[i] == 1) ans += pos[i + 1] + 1;
			else	ans += pos[i] * pos[i + 1];
		}
	if (neg.size() % 2)
	{
		ans -= ((Z) ? 0 : neg[0]);
		for (int i = 1; i < neg.size(); i += 2)
			ans += neg[i] * neg[i + 1];
	}
	else
		for (int i = 0; i < neg.size(); i += 2)
			ans += neg[i] * neg[i + 1];
	cout << ans << '\n';
}

// https://www.acmicpc.net/problem/1744