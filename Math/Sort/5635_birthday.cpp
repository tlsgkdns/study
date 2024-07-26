#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N, Y, M, D;
string name[101];
unordered_map<string, int> y, m, d;

bool cmp(string s1, string s2)
{
	if (y[s1] != y[s2]) return y[s1] < y[s2];
	if (m[s1] != m[s2]) return m[s1] < m[s2];
	return d[s1] < d[s2];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> name[i] >> D >> M >> Y;
		y[name[i]] = Y;
		d[name[i]] = D;
		m[name[i]] = M;
	}
	sort(name, name + N, cmp);
	cout << name[N - 1] << '\n' << name[0] << '\n';
}

// https://www.acmicpc.net/problem/5635