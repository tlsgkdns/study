#include <iostream>
#include <string>

using namespace std;
int N, M, cnt = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cnt = M;
	string s = to_string(N);
	for (int i = 0; i < N && cnt > 0; i++)
	{
		if (cnt < s.size())
		{
			cout << string(s.begin(), s.begin() + cnt) << '\n';
			cnt = 0;
		}
		else
		{
			cout << N;
			cnt -= s.size();
		}
	}
}

// https://www.acmicpc.net/problem/11944