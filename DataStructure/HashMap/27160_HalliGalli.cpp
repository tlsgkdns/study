#include <iostream>
#include <unordered_map>

using namespace std;
int N, X;
string F, ans = "NO";
unordered_map<string, int> um;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    while (N--)
    {
        cin >> F >> X;
        um[F] += X;
    }
    for (pair<string, int> p : um)
    {
        if (p.second == 5)
            ans = "YES";
    }
    cout << ans << '\n';
}

// https://www.acmicpc.net/problem/27160