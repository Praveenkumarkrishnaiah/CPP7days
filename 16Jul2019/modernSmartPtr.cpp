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

int main_unique() {
//	cA aObj;
//	unique_ptr<cA> ap0( &aObj); // Should not be allowed

//	cout << "ap0= " << ap0 << endl;

	cout << "-------------" << endl;

	unique_ptr<cA> ap(new cA());
	ap->display();

	cout << "ap = " << ap << endl;

	cout << "-------------" << endl;
	unique_ptr<cA> ap2; 

	//ap2 = ap;
	cout << "ap2 = " << ap2 << endl;

	cout << "-------------" << endl;
	ap2 = (unique_ptr<cA>)new cA();

	cout << "ap2 = " << ap2 << endl;
	cout << "-------------" << endl;

	unique_ptr<cA> ap4;

	cout << "ap = " << ap << endl;
	cout << "ap4 = " << ap4 << endl;
//	ap4 = ap;
	cout << "ap4 = " << ap4 << endl;
	cout << "ap = " << ap << endl;
	cout << "-------------" << endl;
	return 0;
}// ap.~SmartPtr()


int main() {
	cA *temp = new cA();
	shared_ptr<cA> ap1 (temp );
	temp = NULL;
	if(temp)
		delete temp;

	cout << "-------------" << endl;
	cout << "ap1= " << ap1 << endl;
	cout << " ap1.use_count= " << ap1.use_count() << endl;
	cout << "-------------" << endl;
	shared_ptr<cA> ap2(ap1);

	cout << "ap1= " << ap1 << endl;
	cout << "ap2= " << ap2 << endl;
	//cout << " ap1.use_count= " << shared_ptr<cA>::use_count() << endl;
	cout << " ap1.use_count= " << ap1.use_count() << endl;
	cout << " ap2.use_count= " << ap2.use_count() << endl;
	cout << "-------------" << endl;

	{
		shared_ptr<cA> ap3(ap2);
		cout << "ap1= " << ap1 << endl;
		cout << "ap2= " << ap2 << endl;
		cout << "ap3= " << ap3 << endl;
		cout << " ap1.use_count= " << ap1.use_count() << endl;
		cout << " ap2.use_count= " << ap2.use_count() << endl;
		cout << " ap3.use_count= " << ap3.use_count() << endl;
		cout << "-------------" << endl;
	}

	cout << "ap1= " << ap1 << endl;
	cout << "ap2= " << ap2 << endl;
	cout << " ap1.use_count= " << ap1.use_count() << endl;
	cout << " ap2.use_count= " << ap2.use_count() << endl;
	cout << "-------------" << endl;
	return 0;
}
