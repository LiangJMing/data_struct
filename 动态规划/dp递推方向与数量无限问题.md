#### dp递推方向与数量无限问题

> 洛谷问题
>
> 疯狂的采药https://www.luogu.com.cn/problem/P1616
>
> 与普通采药https://www.luogu.com.cn/problem/P1048（即01背包问题）的主要不同在于
>
> 此题的药品数量不限，可无限采



先贴普通采药代码

~~~c++
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

#define MAXNUM 105

int totalTime, mediNum;
int dp[1000];
int timeArr[MAXNUM];
int valueArr[MAXNUM];


int main() {

	//input
	cin >> totalTime >> mediNum;

	for (int i = 1;i <= mediNum;++i) {
		cin >> timeArr[i] >> valueArr[i];
	}

    
	//初始化
	for (int t = 1; t <= totalTime;++t) {
		
		dp[t] = t >= timeArr[1] ? valueArr[1] : 0;

	}


	//dp
	for (int i = 2;i <= mediNum;++i) {

		for (int t = totalTime;t >= timeArr[i];--t) {

			if (dp[t - timeArr[i]] + valueArr[i] > dp[t]) {

				dp[t] = dp[t - timeArr[i]] + valueArr[i];
			}
		}
	}


	cout << dp[totalTime] <<endl;

	return 0;
}
~~~

> 这里用了滚动数组压缩空间
>
> 可看到递推方向是dp数组从后往前的
>
> 这是因为不压缩前，还是二维数组时
>
> 状态转移方程为
>
> $dp[i][t] = max(dp[i-1][t - timeArr[i]] + valueArr[i],  dp[i-1][t]);$
>
> 新状态取决于上一行的左与上两个状态



那么再看数量不限时二维数组的状态转移方程是怎样的呢？

> $dp[i][t] = max(dp[i-1][t - n*timeArr[i]] + n*valueArr[i],  dp[i-1][t]);$    n = 1、2、3.......

形象的从二维数组上看

> C D E F 
>
> ​       B A

状态B需要用CDE确定，状态A需要用CDEF确定，则A可以用BF确定

状态转移方程变为

> $dp[i][t] = max(dp[i][t - timeArr[i]] + valueArr[i],  dp[i][t]);$

可看到递推方向从左到右

同时需注意数组的初始化的不同

~~~c++
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXNUM 10005

int totalTime, mediNum;
int dp[100001];
int timeArr[MAXNUM];
int valueArr[MAXNUM];


int main() {

	//input
	cin >> totalTime >> mediNum;

	for (int i = 1;i <= mediNum;++i) {
		cin >> timeArr[i] >> valueArr[i];
	}



	//dp
	for (int i = 1;i <= mediNum;++i) {

		for (int t = timeArr[i];t <= totalTime; ++t) {

			if (dp[t - timeArr[i]] + valueArr[i] > dp[t]) {

				dp[t] = dp[t - timeArr[i]] + valueArr[i];

			}
		}

	}

	cout << dp[totalTime] <<endl;


	return 0;
}
~~~

