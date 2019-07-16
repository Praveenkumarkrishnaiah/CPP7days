#include <iostream>
using namespace std;

#if 0
namespace auto_decltype {
	float ret_float() {
		return (float)12.45;
	}

#if 0
	auto ret_expn(auto x, auto y) { // Auto on arg cannot happen
		return x + y;
	}
#endif

	auto ret_expn(int x = 0, int y = 0) { // Auto on arg cannot happen
		cout << " I'm here 1" << endl;
		return x + y;
	}


	auto ret_expnc(char x = 'A', char y = 'B') { // Auto on arg cannot happen
		// ret_expnc i ii
		cout << " I'm here 2" << endl;
		if (0)
			return x + y;
		if (1)
			//return 56.67 + 45;
			return 56 + 45;

	}

	void fun_auto() {
		auto i = 10;
		cout << " typeid(i).name(): " << typeid(i).name() << endl;

		auto fVal = ret_float();
		cout << " typeid(fVal).name(): " << typeid(fVal).name() << " : fVal= " << fVal << endl;

		//	cout << " ret_expn(10,20): " << ret_expn(10, 20) << endl;
		auto result = ret_expn();
		cout << " typeid(result).name()= " << typeid(result).name() << endl;

		auto newD = 45.67 + 89.12;
		cout << "typeid(newD).name()= " << typeid(newD).name() << ", newD= " << newD << endl;


		auto newC = ret_expnc();
		cout << "typeid(newC).name()= " << typeid(newC).name() << ", newC= " << newC << endl;

		cout << "=============" << endl;
		decltype (ret_expnc()) newC2; // deduces only the expression end-result-type
		cout << "typeid(newC2).name()= " << typeid(newC2).name() << endl; // << ", newC2= " << newC2 << endl;
		cout << "=============" << endl;


	}

	decltype(10 + 5) retExpn();
	//auto retExpn() <-decltype(10 + 5);

	int x, y;

	//decltype(x + y) retExpn5(int x2, int y2);
	auto fun1() { cout << "inside fun1111" << endl;  return 10; }

	auto fun2() { cout << "inside fun2222" << endl;  return 20; }

	//decltype(fun1() + fun2()) retExpn5(int x2, int y2);
	auto retExpn6(int x2, int y2);

	auto retExpn6(int x2, int y2) {
		cout << "I'm here 6" << endl;
		return fun1() + fun2();
	}

	struct sA {
		sA() {
			cout << "sA Cons: this= " << this << endl;
		}
	};

	void fun_decltype() {
		//	auto retVal = retExpn();
			//decltype(retExpn()) retVal  ;
			//cout << "typeid(retVal).name(): " << typeid(retVal).name() << endl; // << ", retVAl= " << retVal << endl;

			//int i=0, j=0;

			//decltype(retExpn5(i,j)) retVal;
			//cout << "typeid(retVal).name(): " << typeid(retVal).name() << endl; // << ", retVAl= " << retVal << endl;

			//decltype(retExpn6(i, j)) retVal;
			//auto retVal = retExpn6(i, j);
			//cout << "typeid(retVal).name(): " << typeid(retVal).name() << endl; // << ", retVAl= " << retVal << endl;

			//auto wrongVal;

		auto udt = sA();
		cout << "typeid(udt).name()= " << typeid(udt).name() << endl;
		cout << " &udt= " << &udt << endl;

		cout << "---------------------" << endl;
		//auto udt2 = sA();
		//decltype(sA()) udt2;
		decltype(sA::sA()) udt2;
		cout << "typeid(udt2).name()= " << typeid(udt2).name() << endl;
		cout << " &udt2= " << &udt2 << endl;

	}

	int main() {
		//fun_auto();


		fun_decltype();

		return 0;
	}


	decltype(10 + 5) retExpn() {
		cout << " I'm here 4" << endl;
		return 10 + 5;
	}


	decltype(fun1() + fun2()) retExpn5(int x2, int y2) {
		cout << "I'm here 5" << endl;
		return x2 + y2;
	}

	void gfun(auto x = 0) {}
	//template <typename T = int>
	//T gfun(T x=0) { return x; }

	struct sA {};

	int main() {
		//	auto retVal = gfun(sA());
		auto retVal = gfun();

		cout << "typeid(retVal).name(): " << typeid(retVal).name() << endl;
		return 0;
	}

}

#endif

#if 0 // For_each loop
int main() {
	int myArr[] = { 1,2,3,4,5 };

	for (int i = 0; i < 5; i++)
		cout << "myArr[" << i << "]= " << myArr[i] << endl;

	for (auto val : myArr)
		cout << "val = " << val << endl;
}

#endif

namespace Functor {
	struct Base {
		//virtual void doJob() = 0;
		virtual void operator () () { /// Functor
			cout << "Base () called" << endl;
		}
	};
	struct MyStruct : Base {
		void doJob() { cout << " MyStruct::doJob" << endl; }
		virtual void operator () () {
			cout << "MyStruct () called" << endl;
		}
	};


	struct MyStruct2 :Base {
		void doJob2() { cout << " MyStruct2::doJob" << endl; }
		virtual void operator () () {
			cout << "MyStruct2222 () called" << endl;
		}
	};

	void gfun(Base& obj) {
		cout << " Do Initial job..." << endl;
		//obj.doJob();
		obj(); // Callable
		cout << " Release the resources..." << endl;
		cout << "-------------------" << endl;
	}

	int main() {
		MyStruct mysObj;
		gfun(mysObj);

		MyStruct2 mys2Obj;
		gfun(mys2Obj);
		return 0;
	}

}

namespace default_nm {
	struct Base {
		Base(int x) :m_i(x) { cout << "Base Single param Cons" << endl; }
		~Base() { cout << "Base Des: m_i= " << m_i << endl; }
		//	Base() {}
		Base() = default;
	private:
		int m_i;
	};

	int main() {
		Base bObj(10);

		Base bObj2;

		cout << "-----------------" << endl;
		return 0;
	}
}

namespace delete_nm {
	struct sA {
		sA * getAddress() { return &(*this); }
	private:
		sA* operator & () { cout << " I'm here" << endl; return  this; }
	};

	int main() {
		sA obj1;

		//	cout << " &obj1= " << &obj1 << endl;
		cout << " obj1.getAddress()= " << obj1.getAddress() << endl;
		return 0;
	}
}

namespace delete_nm2 {
	struct sA {
		sA* operator & () = delete;
		void m_fun(int, ...) {
			cout << " I'm here in m_fun" << endl;
			cout << "---------------" << endl;
		}
		void m_fun(int, int) = delete; // { cout << " I'm in m_funii" << endl; }
	};

	void gfun() = delete; // { cout << " gfun" << endl; }

	int main() {
		sA obj1;

		//	cout << " &obj1= " << &obj1 << endl;

		//	obj1.m_fun(1, 2);
		obj1.m_fun(4, 5, 6, 7);
		obj1.m_fun(10);

//		gfun();
		return 0;
	}
}

namespace nm_override {
	struct Base {
		virtual
			void fun() { cout << "Base :: fun" << endl; }
	};

	struct Derived : Base {
		//virtual void fun(int x) override
		//{ cout << "Derived :: fun: x= "<< x << endl; }
		void fun() override
		{
			Base::fun();
			cout << "Derived :: fun: " << endl;
		}
	};

	int main() {
		//	Derived dObj;

		//	dObj.fun();

		Base *bp = new Derived();

		bp->fun();
		return 0;
	}

}

namespace nm__override2 {
	struct Base {
		//virtual	
		void fun() {
			Base::fun2();
			cout << "Base :: fun" << endl;
		}
		virtual void fun2() { cout << "Base::fun22" << endl; }
	};

	struct Derived : Base {
		void fun() //override
		{
			//Base::fun();
			Base::fun2();
			cout << "Derived :: fun: " << endl;
		}
		virtual void fun2() { cout << "Derived::fun22" << endl; }
	};

	int main() {
		Base *bp = new Derived();

		bp->fun();
		bp->fun2();

		return 0;
	}
}


namespace r_value {
	int gfun() {
		return 50;
		/*
			mov Acc, 50
			jmp Epilogue
		*/
		//-----
	}// Epilogue
	void premitives() {
		int i = gfun();
		int j = 60;
		int k = 60;	
		int l = 60;

		//int & ref = k;// int *const ref = &k;
		//const int & ref = k;// const int *const ref = &k;
		
		//int &ref = 60;
		int && ref = 60; // R-value reference
		ref = 12345;
		cout << " &i = " << &i << endl;

		cout << "k = " << k << endl;
		cout << "ref = " << ref << ", &ref = "<< &ref << endl;
	}
	void main() {
		premitives();
	}
}

struct SQUARES {
	SQUARES(int x=1):m_i(x) {}
	auto operator () () { return (m_i * m_i); }
private:
	int m_i;
};
void myLambdas() {
	int i = 5;

	//auto result = SQUARES(i) () ;
	// [1](2) 3 ->4 {5}
	/*
		1 -> Capture
		2 -> Args
		3 -> mutable
		4 -> Return type
		5 -> function body
	*/
	//auto result = ([](int x) { return x * x; }) (i);

	auto SQ = [](int x) { return x * x; };
	//int (*SQ)(int) = [](int x) { return x * x; };
	auto result = SQ(i);
	cout << "result = " << result << endl;

	cout << "typeid(result).name()= " << typeid(result).name() << endl;
	cout << "typeid(SQ).name()= " << typeid(SQ).name() << endl;
}

int main02() {
	//r_value::main();

	myLambdas();
	return 0;
}































































