#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
using ll = long long;
const int MAX = 5000001;
ll N, A, B, s[2];
bool P[MAX], r[MAX];
priority_queue<ll> pq[2];

void setScore(ll n, bool t)
{
	if (P[n])
	{
		if (r[n])
		{
			s[t] -= 1000;
			return;
		}
		r[n] = true;
		pq[t].push(-n);
		if (pq[t].size() >= 4) pq[t].pop();
		return;
	}
	if (pq[!t].size() < 3) s[!t] += 1000;
	else
		s[!t] -= pq[!t].top();
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	memset(P, true, sizeof(P));
	P[0] = P[1] = false;
	for (ll i = 2; i * i < MAX; i++)
		if (P[i])
			for (ll j = i * i; j < MAX; j += i)
				P[j] = false;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		setScore(A, 0);
		setScore(B, 1);
	}
	if (s[0] == s[1])  cout << "우열을 가릴 수 없음\n";
	else if (s[0] > s[1]) cout << "소수의 신 갓대웅\n";
	else cout << "소수 마스터 갓규성\n";
}

// https://www.acmicpc.net/problem/14622