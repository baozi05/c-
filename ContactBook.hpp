#include"Person.hpp"
#include<fstream>
#define File "Final/Contacts.txt"
class ContactBook{
    public:
    person *head;//* 链表结点

    int p_num; //* 统计联系人数目

    ContactBook();//* 构造函数

    ~ContactBook();//* 析构函数

    void ShowMenu(); //*展示菜单

    void exitSystem(); //*退出程序

    void Add_Per(); //* 添加联系人

    int get_num();//* 获取联系人数量

    void Sort_Per();//* 排序联系人

    void Del_Per();//* 删除联系人

    void Find_Per();//* 查找联系人

    void Show_Per();//* 显示联系人信息

    void Mod_Per();//* 修改联系人信息

    void init_Per();//* 初始化联系人（链表节点）

    void save();//* 保存数据进文件

    void Find_Per1();//* 精确查找

    void Find_Per2();//* 模糊查找

    void Find_Per3();//* 查找同一类别联系人

    void Revise(person *&head);//* 修改联系人的具体操作

    void Delete(person *pre,person *&curr);//* 删除联系人的具体操作

};