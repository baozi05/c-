#include"Person.hpp"
#include<cstring>
person::person(){
	next=NULL;
}

person::person(string number,string name,string sex,string address,string emil,string memo,string type,int id)
:number(number),name(name),sex(sex),address(address),email(emil),memo(memo),type(type),next(NULL),id(id){}
void person::ShowInfor(){
	cout<<"姓名："<<name<<endl
	<<"电话号码："<<number<<endl
	<<"性别："<<sex<<endl
	<<"住址："<<address<<endl
	<<"邮箱："<<email<<endl
	<<"备注："<<memo<<endl
	<<"组别："<<type<<endl
	<<endl;
}