#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

//bool func( int a, int b)
//{
//	return a>b;
//}

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(1);
	vec.push_back(9);
	vec.push_back(3);
	vec.push_back(7);
	vec.push_back(4);

//	std::sort(vec.begin(),vec.end() , func );
	std::sort(vec.begin(),vec.end() , [](int a , int b){return a>b;} );  //lamda���ʽ��ʹ��
	auto func = [](int a , int b){return a>b;};
	cout<< func( 1 ,5) <<endl;

	static int i = 10;
	int j = 20;
//	auto f1 = [ ]( ){ return j;}; //���� ��׽�б�û��
	auto f2 = [ ]( ){ return i;}; //�� ��Ȼû�в�׽, ��������ȫ�ֵĺ�ʹ
	cout<< f2( ) <<endl; //10
	auto f3 = [ j ]( ){ return j;};
	auto f4 = f3;
//	auto f5 = [j]{ j =30;}   // û��mutable ���ǳ����� ����
	auto f6 = [ &j ]{ return j =30;}; //û��mutable ��Ȼ�ܹ���ֵ ,//&�Ǳ����ĸ��� , ����Ӱ�������ֵ��
	cout << f6() << " " << j <<endl; // ��� 30 , 20  jԭ��ֵ����
	cout << j <<endl;

	auto f7 = [ j ] ()mutable { return j =50;};
	cout <<"f7"<< f7() << " " << j <<endl;
	cout << j <<endl;

	auto f8 = [ &j ]()mutable{ return j = 10;};
	cout <<"f8"<< f8() << " " << j <<endl;
	cout << j <<endl;

	system("pause");
	return 0;
}

//����˵lamda���ʽ�﷨.
//auto  func = [    ]   (   )   mutable   -> return type {   ������ ;  };
//                     1.__  2.__  3._____   4.__________ 5.___________
//1. ��׽�б�: [ ....]   lamda���ʽ ��[]��ʼ   [  ] �����������,�ָ�
//[ = ] ��ֵ��������׽���б���
//[ & ] �����ô��ݲ�׽���б���  &�Ǳ����ĸ��� , ����Ӱ�������ֵ��
//[ val ] ��׽ĳval���� , ֵ����
//[ &val ] ��׽ĳval����������, ���ô���
//��׽�б�����, ��������ʹ��ȫ�ֱ���������ı�������ʹ��֮ǰ, Ҫ��ǰ���߲�׽�б� , ��Ҫ��ǰ�Ǽ�
//lamda���ʽ ��[]��ʼ , [] ������ʡ��
//�������:   
//[ = , val ] �������� , ������  �� 
//[ = , & ] ֵ���ݻ�������? ������ ��  
//[ = , &val ] ���� �� val�������ֵ����, val�����ô���
//2.�����б�
//�����Ĳ����б�, ����д�������, �����б����ʡ��( ) ���β� , Ҳ���ǵڶ�����ȫʡ�� , 
//���������mutable ���δ�, �ڶ����ֲ���ʡ��,����Ҫ��( )
//3.mutable  �ɱ��   �����Ƿ��ǳ�����
//mutable ����д�����, ��ζ�����lamda���ʽ˵���ĺ���,����һ�������� (�����Ըı����)
//��������:
//int a= 3;
//auto func = [ = ] () { a = 10;}  =������ֵ���� , û��mutable , ������ ,    a=10; �����ǲ����Ե�, ���Ը�ʽ�ӷǷ�
//--------------------------------------
//auto func = [ & ] () { a = 10;}  ���Ը�, &�Ǳ����ĸ��� , ����Ӱ�������ֵ��
//auto func = [ = ] ()mutable { a = 10;}  �Ͷ��� a��ֵ����3 , ��Ϊ��ֵ����
//auto func = [ & ] ()mutable { a = 10;}  �Ͷ���  a��ֵ��Ϊ10
//4.����ֵ  
//����ֵ����ʡ��, ��������������з���ֵ, ���Ĳ���Ҳ���Բ�д , ϵͳ�Զ�Ĭ�Ϸ���ֵ����
//auto func = [ = ] ()mutable { return a = 10;}  ��
//5.������ 
//�������ĺ���ûʲô����.