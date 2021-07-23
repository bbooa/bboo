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
	std::sort(vec.begin(),vec.end() , [](int a , int b){return a>b;} );  //lamda表达式的使用
	auto func = [](int a , int b){return a>b;};
	cout<< func( 1 ,5) <<endl;

	static int i = 10;
	int j = 20;
//	auto f1 = [ ]( ){ return j;}; //错误 捕捉列表没有
	auto f2 = [ ]( ){ return i;}; //对 虽然没有捕捉, 但是他是全局的好使
	cout<< f2( ) <<endl; //10
	auto f3 = [ j ]( ){ return j;};
	auto f4 = f3;
//	auto f5 = [j]{ j =30;}   // 没有mutable 他是常函数 错误
	auto f6 = [ &j ]{ return j =30;}; //没有mutable 虽然能够赋值 ,//&是变量的副本 , 不能影响外面的值的
	cout << f6() << " " << j <<endl; // 输出 30 , 20  j原来值不变
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

//先来说lamda表达式语法.
//auto  func = [    ]   (   )   mutable   -> return type {   函数体 ;  };
//                     1.__  2.__  3._____   4.__________ 5.___________
//1. 捕捉列表: [ ....]   lamda表达式 以[]开始   [  ] 里面的内容用,分隔
//[ = ] 以值传递来捕捉所有变量
//[ & ] 以引用传递捕捉所有变量  &是变量的副本 , 不能影响外面的值的
//[ val ] 捕捉某val变量 , 值传递
//[ &val ] 捕捉某val变量的引用, 引用传递
//捕捉列表作用, 函数可以使用全局变量或外面的变量不过使用之前, 要提前告诉捕捉列表 , 需要提前登记
//lamda表达式 以[]开始 , [] 不可以省略
//问题举例:   
//[ = , val ] 出现歧义 , 有问题  × 
//[ = , & ] 值传递还是引用? 有问题 ×  
//[ = , &val ] 可以 √ val以外的用值传递, val是引用传递
//2.参数列表
//函数的参数列表, 可以写多个参数, 参数列表可以省略( ) 和形参 , 也就是第二部分全省略 , 
//但是如果有mutable 修饰词, 第二部分不可省略,至少要有( )
//3.mutable  可变的   交代是否是常函数
//mutable 当不写这个词, 意味着这个lamda表达式说明的函数,他是一个常函数 (不可以改变变量)
//错误例子:
//int a= 3;
//auto func = [ = ] () { a = 10;}  =代表是值传递 , 没有mutable , 常函数 ,    a=10; 操作是不可以的, 所以该式子非法
//--------------------------------------
//auto func = [ & ] () { a = 10;}  可以改, &是变量的副本 , 不能影响外面的值的
//auto func = [ = ] ()mutable { a = 10;}  就对了 a的值还是3 , 因为是值传递
//auto func = [ & ] ()mutable { a = 10;}  就对了  a的值变为10
//4.返回值  
//返回值可以省略, 如果函数体里面有返回值, 第四部分也可以不写 , 系统自动默认返回值类型
//auto func = [ = ] ()mutable { return a = 10;}  对
//5.函数体 
//跟正常的函数没什么区别.