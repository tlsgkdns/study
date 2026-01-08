#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int N, D, W, ans = 0;
vector<pair<int, int>> A;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> D >> W;
        A.push_back({ D, W });
    }
    sort(A.begin(), A.end(), [](pair<int, int>& p1, pair<int, int>& p2) {if (p1.first == p2.first) return p1.first > p2.first; else return p1.first < p2.first; });
    for (int i = 0; i < A.size(); i++)
    {
        if (pq.size() < A[i].first)
        {
            pq.push(-A[i].second);
        }
        else if (-pq.top() < A[i].second)
        {
            pq.pop();
            pq.push(-A[i].second);
        }
    }
    while (!pq.empty())
    {
        ans -= pq.top();
        pq.pop();
    }
    cout << ans << '\n';
    return 0;
}

// https://www.acmicpc.net/problem/13904