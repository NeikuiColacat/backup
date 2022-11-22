#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define int long long 
int n, m;
const int N = 1e6;
int ne[N], e[N], h[N], idx,cnt[N];
queue<int> q;
void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool topsort() {
	for (int i = 1; i <= n; i++) {
		if (!cnt[i])q.push(i);
	}
	while (q.size()) {
		auto t = q.front();
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = ne[i];
			cnt[j]--;
			if (cnt[j] == 0)q.push(j);
		}
	}
	return q.size() == n - 1;
}
signed main() {
	cin >> n >> m;
	memset(h, -1, sizeof(h));
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		add(x, y);
		cnt[y]++;
	}
	if (topsort()) {
		while (q.size())cout << q.front() << ' ', q.pop();
		cout << '\n';
	}
	else cout << "-1\n";

}