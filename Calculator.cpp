#include <iostream>
using namespace std;
#include <string>

//分别使用普通和多态实现计算器
//1.普通写法实现计算器
class Calculator {
public:

	int getResult(string oper) {
		if (oper == "+") {
			return m_Num1 + m_Num2;
		}else if (oper == "-") {
			return m_Num1 - m_Num2;
		}else if (oper == "*") {
			return m_Num1 * m_Num2;
		}
		//如果想扩展新的功能，需要修改源码
		//在实际开发中，为我们提倡"开闭原则"
		//"开闭原则":对扩展进行开放，对修改进行关闭
	}

	int m_Num1;//操作数1
	int m_Num2;//操作数2
};

//2.利用多态实现计算器
//实现计算器抽象类
class AbstractCalculator {
public:

	virtual int getResult() {
		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//加法计算器类
class AddCalculator : public AbstractCalculator{
	//重写
	int getResult() {
		return m_Num1 + m_Num2;
	}
};
//减法计算器类
class SubCalculator : public AbstractCalculator {
	//重写
	int getResult() {
		return m_Num1 - m_Num2;
	}
};
//乘法计算器类
class MulCalculator : public AbstractCalculator {
	//重写
	int getResult() {
		return m_Num1 * m_Num2;
	}
};

void test01() {
	//创建计算器的对象
	Calculator c;
	c.m_Num1 = 10;
	c.m_Num2 = 10;

	cout << c.m_Num1 << " + " << c.m_Num2  << " = " << c.getResult("+") << endl;
	cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
	cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
}

void test02() {
	//多态使用条件：父类指针或者引用指向子类对象
	//加法运算
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
	//用完后记得销毁
	delete abc;

	//减法运算
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
	
	//乘法运算
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}

int main() {
	
	test01();

	cout << endl;

	test02();

	return 0;
}
