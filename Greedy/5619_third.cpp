#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
using ll = long long;
priority_queue<ll> pq;
vector<ll> arr, C;
int N, A;

int getDigit(ll num)
{
	ll ret = 1;
	while (num >= ret) ret *= 10;
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (pq.size() < 4) pq.push(A);
		else if (pq.top() > A)
		{
			pq.pop();
			pq.push(A);
		}
	}
	while (!pq.empty())
	{
		C.push_back(pq.top());
		pq.pop();
	}
	for (int i = 0; i < C.size(); i++)
		for (int j = 0; j < C.size(); j++)
		{
			if (i == j) continue;
			ll n = (getDigit(C[j]) * C[i]) + C[j];
			arr.push_back(n);
		}
	sort(arr.begin(), arr.end());
	cout << arr[2] << '\n';
}

// https://www.acmicpc.net/problem/5619