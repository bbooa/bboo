//#include<iostream>
//#include<string>
//#include<memory>
//
//using namespace std;
//
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
//int main()
//{
//	//unique_ptr 初始化
//	{
//		std::unique_ptr<AA> up1( new AA("using unique_ptr1"));
//
//		std::unique_ptr<AA> up2;
//		up2.reset( new AA("using unique_ptr2") ); //会释放原来空间
//
//		// make_unique<>() 
//		up1->say();
//		//up2->say();  get方法   up1 和up1.get() 是一样的
//		up2.get()->say();
//
//		//不同的点 : unique_ptr 要求对象所属的智能指针必须唯一. 
//		//不可以两个指针指向同一个对象
//		//std::unique_ptr<AA>  up3 = up1; // 不可以
//		std::unique_ptr<AA>  up3;
//	//	up3 = up1; //赋值也是不可以的.  
//		//把使用权交出去  必须显式的使用, 不会像auto_ptr 莫名的就把空间交出去
//		up3 = std::move(up1); //将up1对象 交给up3 , up1 就空了, 不要再用了
//
//		up3->say();
//		//up1->say(); //up1 空了, 不要再用了
//	}
//	system("pause");
//	return 0;
//}