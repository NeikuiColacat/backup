#include <cstring>
#include <iostream>
#include <queue>
#include<algorithm>
#include<vector>
using namespace std;
#define ll long long
void solve()
{
	ll n, c, d;
	cin >> n >> c >> d;
	ll sum = 0;
	vector<int>a(n + 1);
	vector<ll>pre(n + 1);
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a.begin() + 1, a.end(), [](int x, int y)
	{
		return x > y;
	});
	for (int i = 1; i <= min(d,n); i++)sum += a[i];
	for (int i = 1; i <= n; i++)pre[i] = pre[i - 1] + a[i];
	if(a[1]*d<c)
	{
		cout<<"Impossible"<<'\n';
		return;
	}
	if(sum>=c)
	{
		cout<<"Infinity" << "\n";
		return;
	}
	ll l = 0, r = d , ans = 0;
	while(l<=r)
	{
		ll mid = (l + r) >> 1;
		ll ans1 = 0;
		ll td = d;
		ans1 += d/(mid + 1) * (pre[min(mid + 1,n)])+pre[min(d%(mid+1),n)];
		if (ans1 >= c)ans=mid,l = mid + 1;
		else r = mid - 1;
	}
	cout << ans << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--)solve();

	return 0;

}