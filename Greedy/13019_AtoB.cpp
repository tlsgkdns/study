#include <iostream>

using namespace std;

string A, B;
int cnt1[26], cnt2[26];
bool f = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A;
	cin >> B;
	for (int i = 0; i < A.size(); i++) ++cnt1[A[i] - 'A'];
	for (int i = 0; i < B.size(); i++) ++cnt2[B[i] - 'A'];
	for (int i = 0; i < 26; i++)
	{
		if (cnt1[i] != cnt2[i])
		{
			f = true;
			cout << -1 << '\n';
			break;
		}
	}
	if (!f)
	{
		int bidx = B.size() - 1, ans = 0;
		for (int aidx = A.size() - 1; aidx >= 0; aidx--)
			if (A[aidx] == B[bidx])
			{
				bidx--;
				++ans;
			}
		cout << B.size() - ans << '\n';
	}
}

// https://www.acmicpc.net/problem/13019