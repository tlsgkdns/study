#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int D, N;
vector<int> oven, dough, diameter;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> D >> N;
	oven.resize(D); dough.resize(N);
	diameter.resize(D);
	for (int i = 0; i < D; i++)
	{
		cin >> oven[i];
		if (i == 0)
		{
			diameter[i] = oven[i];
			continue;
		}
		diameter[i] = min(oven[i], diameter[i - 1]);
	}
	for (int i = 0; i < N; i++) cin >> dough[i];
	int s = D;
	for (int i = 0; i < N; i++)
	{
		int it = upper_bound(diameter.begin(), diameter.begin() + s, dough[i], greater<int>()) - diameter.begin();
		s = it - 1;
		if (s < 0) break;
	}
	cout << s + 1 << '\n';
}

// https://www.acmicpc.net/problem/1756