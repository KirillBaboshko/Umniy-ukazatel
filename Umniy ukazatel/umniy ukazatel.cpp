#include<iostream>
#include <memory>
using namespace std;

class X 
{
	int a;
	double b;
public:
	bool Func()
	{
		return 1;
	}

};

class Ower
{
public:
	shared_ptr<X> owingPtr;
	Ower()
	{
		owingPtr = make_shared<X>();
	}
};

class User
{
public:
	weak_ptr<X> usingPtr;
	User(weak_ptr<X>object)
	{
		usingPtr = object;
	}
	void use()
	{
		if (shared_ptr<X> object = usingPtr.lock())
		{
			object->Func();
		}
	}
};

//class videoBuffer
//{
//	int* myPixels;
//public:
//	videoBuffer()
//	{
//		myPixels = new int[2560 * 1440];
//
//	}
//	void makeFrame()
//	{
//	}
//	~videoBuffer()
//	{
//		delete[]myPixels;
//	}
//};
//int game()
//{
//	videoBuffer screen;
//	screen.makeFrame();
//
//}
//int game()
//{
//	int* myPixels=new int[2560 * 1440];
//
//	delete[]myPixels;
//
//}
//
//int game()
//{
//	int* myPixels = new int[2560 * 1440];
//
//	if (someCondition)
//	{
//		delete[]myPixels;
//		return 1;
//	}
//	if (someCondition)
//	{
//		delete[]myPixels;
//		return 4;
//	}
//	delete[]myPixels;
//}
//
//class Foo
//{
//	int* data1;
//	double* data2;
//	char* data3;
//public:
//	Foo() 
//	{
//		data1 = new int(5);
//	}
//	~Foo()
//	{
//		delete data1 ;
//	}
//};
//template<typename T>
//class smart_pointer
//{
//	T* m_obj;
//public:
//	smart_pointer(T* obj) :m_obj = obj;
//	~smart_pointer()
//	{
//		delete m_obj;
//	}
//	T* operator->()
//	{
//		return m_obj;
//	}
//	T& operator*()
//	{
//		return *m_odj;
//	}
//};
//int test()
//{
//	smart_pointer<MyClass> pMyClass(new MyClass());
//	pMyclass->something();
//	cout << *pMyClass<<endl;
//
//}
void func(X* a) {};
void main()
{
	/*X* ptr = nullptr;
	{
		X* ptr2 = new X();
		ptr = ptr2;
	}
	delete ptr;

	X* ptr = new X();
	if (ptr->Func())
	{
		func2();
		return;

	}
	delete ptr;*/

	//int* func();
	// 
	//unique_ptr<X> ptr(new X());
	// 
	//auto ptr=make_unique<X>;

	/*func(unique_ptr<X>(new X()), unique_ptr<X>(new X()));*/

	auto a = make_unique<X>();

	func(a.get());

	/*func(move(a));*/

	bool* n=new bool(5);
	auto t = n;
	bool* o = t;
	cout << *o;

	Ower owner;
	User user(owner.owingPtr);
	user.use();
}
int test() 
{
	shared_ptr<MyObject> p1(new MyObject);
	shared_ptr<MyObject> p2;
	p2 = p1;
	if (p2)
	{
		cout << "Hello, world!\n";
	}
}
//thread_local
//exprtimental::observer_ptr - еще не вошел в стандарт
//shared_ptr
//weak_ptr