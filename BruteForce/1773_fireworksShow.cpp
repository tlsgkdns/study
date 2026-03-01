#include <iostream>

using namespace std;
int N, C, F, ans = 0;
bool T[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> F;
        for (int t = F; t <= C; t += F)
        {
            if (!T[t])
            {
                T[t] = true;
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
// https://www.acmicpc.net/problem/1773