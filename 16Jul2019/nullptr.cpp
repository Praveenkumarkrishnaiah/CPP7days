#include <iostream>
using namespace std;

void fun(int x) { cout << "fun_int: x= "<< x << endl; }
void fun(const char *cp) { cout << "fun_char_ptr:cp = " << endl;
} // << cp << endl; }

int main() {
	int i = 10;
	const char *p = "hello";

	fun(i);
	cout << "------------" << endl;
	fun(p);
	cout << "------------" << endl;

	const char *p2 = NULL;

	fun(p2);
	cout << "------------" << endl;
	fun(NULL);
	cout << "------------" << endl;
	fun(nullptr);
	cout << "------------" << endl;
	cout << "typeid(nullptr).name(): " << typeid(nullptr).name() << endl;
	cout << "------------" << endl;

}