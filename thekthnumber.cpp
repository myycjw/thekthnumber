#include<map>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
using namespace std;
const int maxn = 1e3 + 10;
#define ll long long
int i, j, k;
int n, m;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
int a[maxn];
int quicksort(int a[], int l, int r) {
	if (l < r) {
		i = l;
		j = r;
		int value = a[i];
		while (i < j) {
			while (i < j && a[j] >= value)
				j--;
			if (i < j)
				a[i++] = a[j];
			while (i < j && a[i] < value)
				i++;
			if (i < j) a[j--] = a[i];
		}
		a[i] = value;
		return i;
	}
	return -1;
}

//main
int divide(int a[], int l, int r, int k) {
	if (l > r) 
		return -1;
	if (l == r)
		return a[l];
	i = quicksort(a, l, r);
	j = i - l + 1;
	if (j == k)
		return a[i];
	else if (j > k)
		return divide(a, l, i, k);
	else
		return divide(a, i + 1, r, k - j);
}

int main() {
	cin >> n >> m;//n 是元素个数,m是查询次数
	for (i = 1; i <= n; i++)
		cin >> a[i];
	while (m--) {
		cin >> k;//第k小数
		cout << divide(a, 1, n, k) << endl;
	}
	return 0;
}

