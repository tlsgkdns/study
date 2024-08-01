#include <iostream>
using namespace std;

int N, L, A, B, P[300001];
bool v[300001];
int find(int a)
{
	if (a == P[a]) return a;
	return P[a] = find(P[a]);
}
void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	P[a] = b;
	cout << "LADICA\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 1; i <= L; i++) P[i] = i;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B;
		if (!v[A])
		{
			v[A] = true;
			merge(A, B);
		}
		else if (!v[B])
		{
			v[B] = true;
			merge(B, A);
		}
		else if (!v[find(A)])
		{
			v[find(A)] = true;
			merge(A, B);
		}
		else if (!v[find(B)])
		{
			v[find(B)] = true;
			merge(B, A);
		}
		else
			cout << "SMECE\n";
	}
}

// https://www.acmicpc.net/problem/9938