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
//	//unique_ptr ��ʼ��
//	{
//		std::unique_ptr<AA> up1( new AA("using unique_ptr1"));
//
//		std::unique_ptr<AA> up2;
//		up2.reset( new AA("using unique_ptr2") ); //���ͷ�ԭ���ռ�
//
//		// make_unique<>() 
//		up1->say();
//		//up2->say();  get����   up1 ��up1.get() ��һ����
//		up2.get()->say();
//
//		//��ͬ�ĵ� : unique_ptr Ҫ���������������ָ�����Ψһ. 
//		//����������ָ��ָ��ͬһ������
//		//std::unique_ptr<AA>  up3 = up1; // ������
//		std::unique_ptr<AA>  up3;
//	//	up3 = up1; //��ֵҲ�ǲ����Ե�.  
//		//��ʹ��Ȩ����ȥ  ������ʽ��ʹ��, ������auto_ptr Ī���ľͰѿռ佻��ȥ
//		up3 = std::move(up1); //��up1���� ����up3 , up1 �Ϳ���, ��Ҫ������
//
//		up3->say();
//		//up1->say(); //up1 ����, ��Ҫ������
//	}
//	system("pause");
//	return 0;
//}