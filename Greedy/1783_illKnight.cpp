#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int main() {

    cin >> N >> M;
    N--; M--;
    if (N == 0 || M == 0)
    {
        cout << 1 << '\n';
    }
    else if (N == 1)
    {
        cout << min((M / 2) + 1, 4) << '\n';
    }
    else if (M < 6)
    {
        cout << min(M + 1, 4) << '\n';
    }
    else
    {
        cout << M - 1 << '\n';
    }
    return 0;
}

// https://www.acmicpc.net/problem/1783