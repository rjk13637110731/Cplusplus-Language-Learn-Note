#include <iostream>
using namespace std;

//继承中的构造和析构的顺序
class Base {
public:
	Base() {
		cout << "Base构造函数！" << endl;
	}

	~Base() {
		cout << "Base析构函数！"  << endl;
	}
};

//子类继承父类
class Son : public Base {
public:
	Son() {
		cout << "Son构造函数！" << endl;
	}

	~Son() {
		cout << "Son析构函数！" << endl;
	}
};

void test01() {
	//Base b;
	Son s;
	//继承中的构造和析构顺序如下：
	//先构造父类，再构造子类，析构的顺序与构造的顺序相反。
}

int main() {
	
	test01();

	return 0;
}
