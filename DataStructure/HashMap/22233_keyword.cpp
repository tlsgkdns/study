#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

string str, tmp;
int N, M, cnt;
unordered_map<string, bool> m;
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cnt = N;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		m.insert({ str, false });
	}
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		stringstream ss(str);
		while (getline(ss, tmp, ','))
		{
			if (m.count(tmp) > 0 && !m[tmp])
			{
				m[tmp] = true;
				cnt--;
			}
		}
		ans.push_back(cnt);
	}
	for (int a : ans) cout << a << '\n';
}

// https://www.acmicpc.net/problem/22233