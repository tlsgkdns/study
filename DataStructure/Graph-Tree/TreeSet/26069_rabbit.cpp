#include <iostream>
#include <set>

using namespace std;
set<string> S;
int N;
string A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	S.insert("ChongChong");
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (S.find(A) != S.end()) S.insert(B);
		else if (S.find(B) != S.end()) S.insert(A);
	}
	cout << S.size() << '\n';
}

// https://www.acmicpc.net/problem/26069