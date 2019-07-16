#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << "cA Cons: this= " << this << endl; }
	void display()const { cout << "cA::display: this= " << this << endl; }
	~cA() { cout << "cA Des: this= " << this << "->m_i=" << m_i << endl; }
};

class SmartPtr {
	cA *m_p;
public:
	explicit SmartPtr(cA *p = NULL) :m_p(p) {}
	~SmartPtr() {
		if (m_p)
			delete m_p;
	}
	cA* operator -> () { return m_p; }
};

int main() {
//	cA *ap = new cA();
	//SmartPtr ap = new cA();
	SmartPtr ap ( new cA() );	/*
		void *temp = ::operator new(sizeof(cA))
		push 0 //x
		push (cA*const)temp // this
		call cA::cA(int=0)

		sub esp, sizeof(SmartPtr) // for ap
		push (cA*)temp // p
		call SmartPtr::SmartPtr(cA*=NULL)
	*/
	ap->display(); /*
				   push ap.operator->() // this
				   call cA::display
				   */

	cout << "-------------" << endl;
	ap.operator->()->display();
	cout << "-------------" << endl;
}// ap.~SmartPtr()
