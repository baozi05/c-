#include<iostream>
#include"ContactBook.hpp"
using namespace std;
int main(){
    
    ContactBook bk;
    bk.ShowMenu();
    int choice;
    cout<<"需要进行什么操作："<<endl;
    flag:
    cin>>choice;
    switch(choice)
    {
        case 0: //* 退出系统
        bk.exitSystem();
            break;
        case 1: //* 添加信息
        bk.Add_Per();
            break;
        case 2: //* 显示信息
        bk.Show_Per();
            break;
        case 3: //* 删除联系人
        bk.Del_Per();
            break;
        case 4: //* 修改联系人
        bk.Mod_Per();
            break;
        case 5:
        bk.Find_Per();//* 查找联系人
            break;
        case 6:
        bk.Sort_Per();//* 排序联系人
            break;
        default:
            cout<<"不支持该选项！"<<endl;
            break;

    }
    cout<<"还有呢："<<endl;
    goto flag;
    system("pause");
    return 0;
}