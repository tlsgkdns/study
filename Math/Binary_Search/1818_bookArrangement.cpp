#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> B;
int N, A[200001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	B.push_back(A[0]);
	for (int i = 1; i < N; i++)
	{
		auto iter = lower_bound(B.begin(), B.end(), A[i]);
		if (iter == B.end()) B.push_back(A[i]);
		else *iter = A[i];
	}
	cout << N - B.size() << '\n';
}
// https://www.acmicpc.net/problem/1818