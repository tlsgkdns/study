#include <iostream>
#include <stack>
#include <cmath>
#include <cstring>
using namespace std;
int cls[100001], cnt[100001], L[100001];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(cls, -1, sizeof(cls));
	cin >> N;
	for (int i = 0; i < N; i++) cin >> L[i];
	stack<pair<int, int>> S1, S2;
	for (int i = 0; i < N; i++)
	{
		while (!S1.empty() && S1.top().first <= L[i]) S1.pop();
		cnt[i] += (int)S1.size();
		if (!S1.empty()) cls[i] = S1.top().second;
		S1.push({ L[i], i });
	}
	for (int i = N - 1; i >= 0; i--)
	{
		while (!S2.empty() && S2.top().first <= L[i]) S2.pop();
		cnt[i] += (int)S2.size();
		if (!S2.empty() && cls[i] == -1) cls[i] = S2.top().second;
		else if (!S2.empty() && abs(i - cls[i]) > abs(i - S2.top().second)) cls[i] = S2.top().second;
		S2.push({ L[i], i });
	}
	for (int i = 0; i < N; i++)
	{
		cout << cnt[i] << " ";
		if (cnt[i] != 0) cout << cls[i] + 1;
		cout << '\n';
	}
}

// https://www.acmicpc.net/problem/22866