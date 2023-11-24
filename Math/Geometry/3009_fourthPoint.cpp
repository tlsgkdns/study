#include <iostream>

using namespace std;

int A, B, C, D, E, F;

int v1[1001], v2[1001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B >> C >> D >> E >> F;
	++v1[A]; ++v2[B]; ++v1[C]; ++v2[D]; ++v1[E]; ++v2[F];
	if (v1[A] == 1) cout << A << " ";
	else if (v1[C] == 1) cout << C << " ";
	else cout << E << " ";
	if (v2[B] == 1) cout << B << '\n';
	else if (v2[D] == 1) cout << D << '\n';
	else cout << F << '\n';
}

// https://www.acmicpc.net/problem/3009