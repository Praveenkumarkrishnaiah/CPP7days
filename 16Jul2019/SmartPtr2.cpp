#include <iostream>
using namespace std;

class cA {
	int m_i;
public:
	cA(int x = 0) :m_i(x) { cout << "cA Cons: this= " << this << endl; }
	void display()const { cout << "cA::display: this= " << this << endl; }
	~cA() { cout << "cA Des: this= " << this << "->m_i=" << m_i << endl; }
};

class cB {
	int m_j;
public:
	cB(int y = 1) :m_j(y) { cout << "cB Cons: this= " << this << endl; }
	void display()const { cout << "cB::display: this= " << this << endl; }
	~cB() { cout << "cB Des: this= " << this << "->m_j=" << m_j << endl; }
};

template <typename Type1>
class SmartPtr {
	Type1 *m_p;
public:
	explicit SmartPtr(Type1 *p = NULL) :m_p(p) {}
	~SmartPtr() { if (m_p)			delete m_p; }
	Type1* operator -> () { return m_p; }
};

/*
class SmartPtr {
	cA *m_p;
public:
	explicit SmartPtr(cA *p = NULL) :m_p(p) {}
	~SmartPtr() {		if (m_p)			delete m_p;	}
	cA* operator -> () { return m_p; }
};
class SmartPtrcB {
	cB *m_p;
public:
	explicit SmartPtrcB(cB *p = NULL) :m_p(p) {}
	~SmartPtrcB() {		if (m_p)			delete m_p;	}
	cB* operator -> () { return m_p; }
};
*/
int main_udt() {
	SmartPtr<cA> ap(new cA());	
	ap->display(); 

	cout << "-------------" << endl;
//	cB *bp = new cB();
	SmartPtr<cB> bp ( new cB());
	bp->display();
	// bp.operator->()->display()

	cout << "-------------" << endl;
	return 0;
}// ap.~SmartPtr()


int main() {
	auto_ptr<cA> ap(new cA());
	ap->display();

	cout << "-------------" << endl;
	//	cB *bp = new cB();
	auto_ptr<cB> bp(new cB());
	bp->display();
	// bp.operator->()->display()

	cout << "-------------" << endl;
}// ap.~SmartPtr()
