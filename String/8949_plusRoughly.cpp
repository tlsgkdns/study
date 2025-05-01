#include <iostream>

using namespace std;

string A, B;
bool f = false;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	if (A.size() > B.size()) swap(A, B);
	int s = B.size() - A.size();
	for (int i = 0; i < s; i++) A = '0' + A;
	for (int i = 0; i < A.size(); i++)
		cout << (A[i] + B[i] - '0' - '0');
	cout << '\n';
}

// https://www.acmicpc.net/problem/8949