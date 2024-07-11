

// MEET IN THE MIDDLE ALGO
// VEDIO SOLN ARYAN MEET IN THE ALGO
// problem statement -----------> https://cses.fi/problemset/task/1628/

#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, sum;
    cin >> n >> sum;
    vector<long long> left, right;
    for (long long i = 0; i < n / 2; i++) {
        long long a;
        cin >> a;
        left.push_back(a);
    }
    for (long long i = n / 2; i < n; i++) {
        long long b;
        cin >> b;
        right.push_back(b);
    }

    long long n1 = n / 2;
    long long n2 = n - n / 2;
    unordered_map<long long, long long> mp;

    for (long long i = 0; i < (1 << n1); i++) {
        long long x = 0, y = 0, st = i;
        while (st > 0) {
            if (st & 1) {
                x += left[y];
            }
            y++;
            st >>= 1;
        }
        mp[x]++;
    }

    long long ans = 0;
    for (long long i = 0; i < (1 << n2); i++) {
        long long x = 0, y = 0, st = i;
        while (st > 0) {
            if (st & 1) {
                x += right[y];
            }
            y++;
            st >>= 1;
        }
        if (mp.count(sum - x)) ans += mp[sum - x];
    }

    cout << ans << endl;

    return 0;
}
