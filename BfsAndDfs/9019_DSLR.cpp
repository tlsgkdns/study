#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

vector<string> anss;
int T, idx[10001];
char route[10001];
int D(int num)
{
	num *= 2;
	num %= 10000;
	return num;
}
int S(int num)
{
	num--;
	if (num < 0) num = 9999;
	return num;
}
int L(int num)
{
	int f = num / 1000;
	int b = num % 1000;
	int ret = b * 10 + f;
	return ret;
}
int R(int num)
{
	int f = num / 10;
	int b = num % 10;
	int ret = b * 1000 + f;
	return ret;
}
int A, B;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	anss.resize(T);
	while (T--)
	{
		cin >> A >> B;
		memset(idx, -1, sizeof(idx));
		queue<int> q;
		q.push(A);
		idx[A] = -2;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			if (cur == B) break;
			int nxt = D(cur);
			if (idx[nxt] == -1)
			{
				idx[nxt] = cur;
				route[nxt] = 'D';
				q.push(nxt);
			}
			nxt = S(cur);
			if (idx[nxt] == -1)
			{
				idx[nxt] = cur;
				route[nxt] = 'S';
				q.push(nxt);
			}
			nxt = L(cur);
			if (idx[nxt] == -1)
			{
				idx[nxt] = cur;
				route[nxt] = 'L';
				q.push(nxt);
			}
			nxt = R(cur);
			if (idx[nxt] == -1)
			{
				idx[nxt] = cur;
				route[nxt] = 'R';
				q.push(nxt);
			}
		}
		string str; int dst = B;
		while (A != B)
		{
			str.push_back(route[B]);
			B = idx[B];
		}
		reverse(str.begin(), str.end());
		cout << str << '\n';
	}
}

// https://www.acmicpc.net/problem/9019