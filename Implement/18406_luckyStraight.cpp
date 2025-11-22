#include <iostream>

using namespace std;
string N;
int ans[2];
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	cin >> N;
	int h = (N.size() / 2);
	for (int i = 0; i < N.size(); i++)
	{
		ans[i < h] += (N[i] - '0');
	}
	if (ans[0] == ans[1]) cout << "LUCKY\n";
	else cout << "READY\n";
}

// https://www.acmicpc.net/problem/18406