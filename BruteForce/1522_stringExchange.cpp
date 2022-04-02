#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> arr;
string str, tmp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	int N = (int)str.size(), cnt = 0, ans = 1001, A = 0;
	for (int i = 0; i < N; i++)
		if (str[i] == 'a')
			A++;
	for (int i = 0; i < A; i++) tmp.push_back('a');
	for (int i = 0; i < (N - A); i++) tmp.push_back('b');
	for (int i = 0; i < N; i++)
	{
		string s(tmp.begin() + 1, tmp.end());
		s.push_back(tmp[0]);
		arr.push_back(s);
		tmp = s;
	}
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++)
			if (arr[i][j] != str[j])
				cnt++;
		ans = min(cnt, ans);
	}
	cout << ans / 2 << '\n';
}

// https://www.acmicpc.net/problem/1522