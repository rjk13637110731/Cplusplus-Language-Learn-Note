#include <iostream>
#include <map>
using namespace std;

//map查找与统计

void test01() {
	map<int, int>m;
	
	//查找
	m.insert(pair<int,int>(1,10));
	m.insert(pair<int,int>(2,20));
	m.insert(pair<int,int>(3,30));
	m.insert(pair<int, int>(3, 40));

	map<int,int>::iterator pos = m.find(3);
	if (pos != m.end()) {
		cout << "查到了元素：key = " << (*pos).first << "\tvalue = " << pos->second << endl;
	}else{
		cout << "未找到元素！" << endl;
	}
	
	//统计
	//map中不允许插入重复的key元素，count统计而言，结果要么是0要么是1。
	//multimap的count统计可能大于1.
	int num = m.count(3);
	cout << "num = " << num << endl;
}


int main() {
	
	test01();

	return 0;
}
