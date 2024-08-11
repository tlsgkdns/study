#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
vector<int> arr;
bool v[361];
int N, K, A;
int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A;
		arr.push_back(A);
		v[A] = true;
	}
	for (int i = 0; i < arr.size(); i++)
	{
		int now = arr[i];
		for (int j = i + 1; j < arr.size(); j++)
		{
			int nxt1 = (now + arr[j]) % 360;
			int nxt2 = abs(now - arr[i]);
			if (!v[nxt1])
			{
				v[nxt1] = true;
				arr.push_back(nxt1);
			}
			if (!v[nxt2])
			{
				v[nxt2] = true;
				arr.push_back(nxt2);
			}
		}
		now = (now * 2) % 360;
		while (!v[now])
		{
			v[now] = true;
			arr.push_back(now);
			now = (now + arr[i]) % 360;
		}
	}
	for (int i = 0; i < K; i++)
	{
		cin >> A;
		if (v[A]) cout << "YES\n";
		else cout << "NO\n";
	}
}

// https://www.acmicpc.net/problem/2916