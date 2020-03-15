#include<stdio.h>
#include<iostream>

using namespace std;

class A {
public:
	A() {
		data = 10;
		cout << "enter the A class" << endl;
	}
	~A() {
		cout << "exit the A class" << endl;
	}
private:
	int data;
};

int main(void)
{
	A a;
	A* b;
	b = new A;
	delete b;
	return 0;
}
