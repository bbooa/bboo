//#include<iostream>
//#include<string>
//#include<memory>
//
//using namespace std;
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
//int main()
//{
//	//��ʼ��ָ��ָ�� auto_ptr
//	//��ʼ������1
//	//{
//	//	std::auto_ptr<AA> ap1(new AA("using auto_ptr")); //ap1 ��������ָ��
//	//	ap1->say();  //������������, ָ����ն������Զ���.
//	//}
//	//cout<<"------------------"<<endl;
//	////��ʼ������2 ����ͨ��reset()����
//	//{
//	//	std::auto_ptr<AA> ap1;
//	//	ap1.reset( new AA("using auto_ptr"));
//	//	ap1->say(); 
//	//}
//	//cout<<"------------------"<<endl;
//	//���Ը�ֵ
//	{
//		std::auto_ptr<AA> ap1(new AA("using auto_ptr"));   //�п��� �Ѿ���unique_ptrȡ����
//		std::auto_ptr<AA> ap2;  // unique_ptr
//	 	ap2 = ap1;  // ap2��ȡap1�Ķ���
//		ap1->say(); // ap2��ȡap1�Ķ���, ap1����û����,�ٵ��þͳ�����.
//	}
//
//	system("pause");
//	return 0;
//}