#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;
int main()
{
	int n, k, s = 0;
	long long ans = 0;
	cin >> n >> k;
	multiset<int> bag;
	vector<pair<int, int>> jewel(n);
	for (int i = 0; i < n; i++)
		cin >> jewel[i].second >> jewel[i].first;
	for (int i = 0; i < k; i++)
	{
		int b; cin >> b;
		bag.insert(b);
	}
	sort(jewel.begin(), jewel.end(), greater<pair<int, int>>());
	for (auto j : jewel)
	{
		if (bag.empty()) break;
		auto w = bag.lower_bound(j.second);
		if (w == end(bag)) continue;
		else { bag.erase(w); ans += j.first; }
	}

	cout << ans << endl;
}

// https://www.acmicpc.net/problem/1202

/*
sort and greedy
I used multiset for the first time,
because I heard the algorithm's lower_bound is later than multiset's lower_bound
*/