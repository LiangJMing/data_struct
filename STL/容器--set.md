#### 容器--set

> 集合

例：

~~~c++
const int N = 6;
string s1[N] = {"buffoon","thinkers","for","heavy","can","for"};
set<string> A(s1, s1+N); //使用数组初始化

A.inser("bb");  //插入元素

//迭代器 打印值
set<string>::iterator pr;
	for (pr = A.begin();pr != A.end(); pr++) {
		cout << *pr << endl;
	}
~~~



**元素查找**

> find调用返回一个迭代器。如果给定关键字在set中， 迭代器指向该关键字。否则，find返回尾后迭代器。

**数组去重**

~~~c++
#include <set>

vector<int> insersection(vector<int>& nums1, vector<int>& nums2) {

		set<int> record(nums1.begin(), nums1.end());

		set<int> resultSet;

		for (int i = 0;i < nums2.size();i++) {
			if (record.find(nums2[i]) != record.end())//如果num2元素在record中
				resultSet.insert(nums2[i]);
		}

		return vector<int>(resultSet.begin(), resultSet.end());

	}
~~~

