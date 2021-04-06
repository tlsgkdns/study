#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> air, gate;
int main()
{
	int g, p, ans = 0;
	cin >> g >> p;
	air.resize(p), gate.resize(g + 1, 0);
	for (int i = 0; i < p; i++) cin >> air[i];
	for (int i = 1; i <= g; i++) gate[i] = i;
	for (int i = 0; i < p; i++)
	{
		auto it = --upper_bound(gate.begin(), gate.end(), air[i]);
		if (it == gate.begin()) break;
		gate.erase(it);
		ans++;
	}
	cout << ans << '\n';
}

//https://solved.ac/contribute/10775
/*
Site said it can be solved by Union-find
But I selected just greedy.
Although its execution time is long, I solved it.
*/