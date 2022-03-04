#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int N, l, r, a1, a2;
ll sub = 2000000001;
vector<ll> water;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	water.resize(N);
	l = 0; r = N - 1;
	for (int i = 0; i < N; i++)
		cin >> water[i];
	while (l < r)
	{
		if (sub > abs(water[l] + water[r]))
		{
			a1 = l;
			a2 = r;
			sub = abs(water[l] + water[r]);
		}
		if (water[l] + water[r] > 0) r--;
		else l++;
	}
	cout << water[a1] << " " << water[a2] << '\n';
}

// https://www.acmicpc.net/problem/2467