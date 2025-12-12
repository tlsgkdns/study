#include <iostream>

using namespace std;
string N;
int A, W;

int main()
{
    while (true)
    {
        cin >> N >> A >> W;
        if (N == "#" && A == 0 && W == 0) break;
        string B = ((A > 17 || W >= 80) ? "Senior" : "Junior");
        cout << N << " " << B << '\n';
    }
}

// https://www.acmicpc.net/problem/2083