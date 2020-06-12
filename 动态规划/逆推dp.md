#### 逆推dp

> 洛谷问题
>
> 挖地雷https://www.luogu.com.cn/problem/P2196



###### 思路

> dpi为以i为终点的最大雷数
>
> 找到dpj，找到从j到i的权重最大的有效通路



###### 状态转移方程

> dp[i] = dp[i] + max(dp[i-1],   dp[i-2].....)



~~~c++
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

#define maxn 201

bool rd[maxn][maxn];
int a[maxn], dp[maxn], p[maxn], pos;

void dfs(int x) {
	if (p[x]) dfs(p[x]);
	cout << x << " ";
}


int main() {

	int n, ans = 0;
	cin >> n;

	for (int i = 1;i <= n;++i) {
		cin >> a[i];  //每个坑的雷数
	}

	for (int i = 1; i <= n - 1;++i) {
		for (int j = i + 1;j <= n;++j) {
			cin >> rd[i][j];
		}
	}

	//逆推
	//找到dpj ，从j到i有通路并且是所有通路中的最大权值

	dp[1] = a[1];
	for (int i = 2;i <= n;++i) {

		dp[i] = a[i];  //初始化，终点为ai
		for (int j = i - 1;j > 0;--j) {

			if (rd[j][i] && dp[i] < dp[j] + a[i]) {

				dp[i] = dp[j] + a[i];
				p[i] = j;  //表示从j到i的路径
			}
		}

		//更新ans
		if (ans < dp[i]) {

			ans = dp[i];
			pos = i;

		}
	}


	dfs(pos);
	cout << endl << ans;

	
	getchar();
	cin.get();

	return 0;
}
~~~

