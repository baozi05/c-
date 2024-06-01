#pragma once
#include<iostream>
using namespace std;
class person{
    public:
    person();
    
    person(string number,string name,string sex,string address,string email,string memo,string type,int id=0);

    friend class ContactBook; //* 友元类--通讯录，进行对 person 的各种操作

    void ShowInfor();//* 展示所有信息
    
    private:

    string number; //* 电话号码

    string name; //* 姓名

    string sex; //* 性别

    string address; //* 地址

    string email; //* 电子邮箱

    string memo; //* 备注

    string type; //* 分类（例如：家人、朋友）

    int id;//* 索引
//-----------------上述为链表的 data 
    person *next; //* 链表结构
};

