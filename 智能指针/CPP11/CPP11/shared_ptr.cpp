//#include<iostream>
//#include<string>
//#include<memory>
//
//using namespace std;
//
//// 不同的点: shared_ptr  --> 引用计数 来控制对象的回收  , 引用计数归0 才回收
////想要回收 , 可以使用weak_ptr , 使用它 , 引用计数不加1
//
//class AA
//{
//public:
//	AA(const string s)
//	{
//		str= s;
//		cout<<"AA()"<<endl;
//	}
//	~AA()
//	{
//		cout<< "~AA()"<<endl;
//	}
//	void say()
//	{
//		cout<<str<<endl;
//	}
//private:
//	string str;
//};
//
//class BBBB;
//class AAAA
//{
//public:
//	AAAA()
//	{
//		cout<<"AAAA()"<<endl;
//	}
//	~AAAA()
//	{
//		cout<<"~AAAA"<<endl;
//	}
//	//shared_ptr<BBBB> spb;
//	weak_ptr<BBBB> spb;
//};
//class BBBB
//{
//public:
//	BBBB()
//	{
//		cout<<"BBBB()"<<endl;
//	}
//	~BBBB()
//	{
//		cout<<"~BBBB"<<endl;
//	}
//	shared_ptr<AAAA> spa;
//};
//int main()
//{
//	//shared_ptr 初始化
//	{
//		std::shared_ptr<AA> sp1( new AA("using shared_ptr1"));
//
//		std::shared_ptr<AA> sp2;
//		sp2.reset( new AA("using shared_ptr2") ); //会释放原来空间
//
//		// make_unique<>() 
//		// make_shared<>()
//		std::shared_ptr<AA>  sp3;
//		sp3 = make_shared<AA>("using shared_ptr3");
//
//		sp1->say();
//		//sp2->say();  get方法   sp1 和sp1.get() 是一样的
//		sp2.get()->say();
//
//		sp3->say();
//		{
//			std::shared_ptr<AA>  sp4;
//			sp4 = sp1; //指向同一个空间
//			sp4->say();
//			sp1->say();  //可以同时使用
//			cout<< "using count:"<<sp1.use_count() <<endl; //2
//		}
//		cout<< "using count:"<<sp1.use_count() <<endl;//1
//	}
//	cout<<"---------------------"<<endl;
//	// 问题: 循环引用
//	{
//		shared_ptr<AAAA> pAA(new AAAA);
//		shared_ptr<BBBB> pBB(new BBBB);
//		pAA->spb = pBB; //spb改成 weak_ptr 引用计数不加1
//		pBB->spa = pAA;
//		cout<< "pAA using count:"<<pAA.use_count()<<endl;
//		cout<< "pBB using count:"<<pBB.use_count()<<endl;
//	}//没有回收
//	system("pause");
//	return 0;
//}