//#include<iostream>
//#include<string>
//#include<memory>
//
//using namespace std;
//
//// ��ͬ�ĵ�: shared_ptr  --> ���ü��� �����ƶ���Ļ���  , ���ü�����0 �Ż���
////��Ҫ���� , ����ʹ��weak_ptr , ʹ���� , ���ü�������1
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
//	//shared_ptr ��ʼ��
//	{
//		std::shared_ptr<AA> sp1( new AA("using shared_ptr1"));
//
//		std::shared_ptr<AA> sp2;
//		sp2.reset( new AA("using shared_ptr2") ); //���ͷ�ԭ���ռ�
//
//		// make_unique<>() 
//		// make_shared<>()
//		std::shared_ptr<AA>  sp3;
//		sp3 = make_shared<AA>("using shared_ptr3");
//
//		sp1->say();
//		//sp2->say();  get����   sp1 ��sp1.get() ��һ����
//		sp2.get()->say();
//
//		sp3->say();
//		{
//			std::shared_ptr<AA>  sp4;
//			sp4 = sp1; //ָ��ͬһ���ռ�
//			sp4->say();
//			sp1->say();  //����ͬʱʹ��
//			cout<< "using count:"<<sp1.use_count() <<endl; //2
//		}
//		cout<< "using count:"<<sp1.use_count() <<endl;//1
//	}
//	cout<<"---------------------"<<endl;
//	// ����: ѭ������
//	{
//		shared_ptr<AAAA> pAA(new AAAA);
//		shared_ptr<BBBB> pBB(new BBBB);
//		pAA->spb = pBB; //spb�ĳ� weak_ptr ���ü�������1
//		pBB->spa = pAA;
//		cout<< "pAA using count:"<<pAA.use_count()<<endl;
//		cout<< "pBB using count:"<<pBB.use_count()<<endl;
//	}//û�л���
//	system("pause");
//	return 0;
//}