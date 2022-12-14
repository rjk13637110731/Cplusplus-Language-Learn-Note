#include <iostream>
using namespace std;

//左移运算符重载
class Person {
	friend ostream& operator<<(ostream& cout, Person p);
public:
	Person(int a,int b) {
		m_A = a;
		m_B = b;
	}
private:

	//利用成员函数重载左移运算符  p.operator<<(cout) 简化版本是：p << cout
	//通常不会使用成员函数重载<<运算符，因为无法实现cout在左侧。
	/*
	void operator<<(cout) {
		
	}
	*/

	int m_A;
	int m_B;
};

//只能使用全局函数重载左移运算符。
//ostream是标准输出流类，它的对象只能有一个。cout是标准输出流类对象
ostream& operator<<(ostream& cout,Person p) {//本质：operator<<(cout,p);   简化形式为：cout << p;
	cout << "m_A = " << p.m_A << " m_B = " << p.m_B;
	return cout;
}

void test01() {
	Person p(10, 10);

	cout << p << endl;

}

int main() {

	test01();

	return 0;
}
