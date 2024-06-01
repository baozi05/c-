#include"ContactBook.hpp"
void ContactBook::ShowMenu(){
    cout << "****************************" << endl;
	cout << "**欢迎使用通讯录管理系统!***" << endl;
	cout << "******0.退出通讯录系统******" << endl;
	cout << "******1.增加联系人信息******" << endl;
	cout << "******2.显示联系人信息******" << endl;
	cout << "******3.删除联系人**********" << endl;
	cout << "******4.修改联系人信息******" << endl;
	cout << "******5.查找联系人信息******" << endl;
	cout << "******6.选择方式排序********" << endl;
	cout << "****************************" << endl;
	cout << endl;
}
void ContactBook::exitSystem(){
	cout<<"欢迎下次使用！"<<endl;
    system("pause");
   	exit(0); //* 退出程序
}
ContactBook::ContactBook(){
    //* 打开通讯录文件
    ifstream ifs;
    ifs.open(File,ios::in); //* 读取文件
    if(ifs.fail())//*  如果文件不存在
    {
        cout<<"通讯录读取失败！请重试！"<<endl;
        //* 初始化数据
        head=NULL;
        p_num=0;
        ifs.close();
        system("pause");
        exit(0);
    }
    //* 文件存在，可以正常增删改查
    
    p_num=this->get_num(); //* 记录人数
    // cout<<"共有联系人"<<p_num<<"人!"<<endl;
    init_Per();
}
void ContactBook::save(){
    ofstream ofs;
    ofs.open(File,ios::out);//* 读写文件
    person *curr=head;
    while(curr!=NULL){
        ofs<<curr->number<<' '<<curr->name<<' '<<curr->sex<<' '<<curr->address
        <<' '<<curr->email<<' '<<curr->memo<<' '<<curr->type<<endl;
        curr=curr->next;
     }
    //* 将链表移到末尾--即刚刚添加的联系人，将其保存进入文件
    
    ofs.close();
}
void ContactBook::Add_Per(){
    cout<<"正在添加联系人..."<<endl;
    person *temp=new person;
    cout<<"请输入该联系人的姓名："<<endl;
    cin>>temp->name;
    cout<<"请输入该联系人的电话号码："<<endl;
    cin>>temp->number;
    cout<<"该联系人的性别是："<<endl;
    cin>>temp->sex;
    cout<<"请输入该联系人的地址："<<endl;
    cin>>temp->address;
    cout<<"请输入该联系人的邮箱："<<endl;
    cin>>temp->email;
    cout<<"你给ta备注为:"<<endl;
    cin>>temp->memo;
    cout<<"请输入该联系人的分组："<<endl;
    cin>>temp->type;
    temp->next=NULL;
   
    if(head==NULL) //* 如果文件里面没人(添加在表头)
    {
        head=temp;
    }
    else 
    {
        person* curr=head;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=temp;
    }   
    this->save();//* 保存数据到文件
    cout<<"添加成功！"<<endl;
}
void ContactBook::init_Per(){
    ifstream ifs;
    //* 读取文件里的联系人信息，并将这些信息赋给一个链表节点
    ifs.open(File,ios::in);
    string xnumber,xname,xsex,
           xadd,xema,xme,xtype;
    
    //* 如果可以从文件里读取到这些数据
    while(ifs>>xnumber&&ifs>>xname&&ifs>>xsex
    &&ifs>>xadd&&ifs>>xema&&ifs>>xme&&ifs>>xtype){
        person* temp=new person(xnumber,xname,xsex,xadd,xema,xme,xtype);
        if(head==NULL) //* 如果是构建头结点
        {
            temp->next=head;
            head=temp;
        }
        else //* 如果不是头结点
        {
            person *curr=head;
            while(curr->next!=NULL)
            curr=curr->next;
            temp->next=curr->next;
            curr->next=temp;
        }
            p_num++;
    }
    ifs.close();
}
ContactBook::~ContactBook(){
    person* curr=head;
    while(curr){
        person* next=curr->next;
        delete curr;
        curr=next;
    }
    head=NULL;
}
int ContactBook::get_num(){
    ifstream ifs;
    ifs.open(File,ios::in);
    string xnumber,xname,xsex,
           xadd,xema,xme,xtype;
    int xid;
    int num=0;
    while(ifs>>xnumber&&ifs>>xname&&ifs>>xsex
    &&ifs>>xadd&&ifs>>xema&&ifs>>xme&&ifs>>xtype)
        num++;
    return num;
}
void ContactBook::Show_Per(){
    if(p_num==0) 
    {
    cout<<"通讯录为空！"<<endl;
    return ;
    }
    person *curr=head;
    while(curr){
        curr->ShowInfor();
        curr=curr->next;
    }
}
void ContactBook::Find_Per1()//? 精确查找
{
    cout<<"想通过什么方式查找？请输入："<<endl
    <<"1、姓名"<<endl
    <<"2、电话号码"<<endl
    <<"3、备注"<<endl;
    int way;
    flag:
    cin>>way;
    person *curr=head;
    switch(way){
        case 1:{
        string xname;
        cout<<"请输入姓名： ";
        cin>>xname;
        int num=0;
        while(curr){    
            if(curr->name==xname)
           {
            num++;
            if(num==1)
            {
            cout<<"找到该联系人！"<<endl;
            curr->ShowInfor();
            }
            else if(num>1){
                cout<<"还查找到可能的同名联系人："<<endl;
                curr->ShowInfor();
            }
            }
            curr=curr->next;
        }
        if(num==0&&curr==NULL) cout<<"该联系人不存在！！"<<endl;
        break;
        }
        case 2:{
        string xnum;
        cout<<"请输入电话号码： ";
        cin>>xnum;
        while(curr){
            if(curr->number==xnum)
           {
            cout<<"找到该联系人！~"<<endl;
            curr->ShowInfor();
            return ;
            }
            curr=curr->next;
        }
        if(curr==NULL) cout<<"该联系人不存在！！"<<endl;
        break;
        }
        case 3:{
        string xme;
        cout<<"请输入你给ta的备注： ";
        cin>>xme;
        while(curr){
            if(curr->memo==xme)
           {
            cout<<"找到该联系人！~"<<endl;
            curr->ShowInfor();
            return ;
            }
            curr=curr->next;
        }
        if(curr==NULL) cout<<"该联系人不存在！！"<<endl;
        break;
        }
        default:
        {
            cout<<"无该选项，请重试！"<<endl;
            goto flag;
        }
    }
}
void ContactBook::Find_Per2(){
    cout<<"请输入ta的居住地(模糊定位)：";
    string xadd;
    cin>>xadd;
    int num=0;//* 统计符合条件的联系人个数
    person *curr=head;
    while(curr){
        string s=curr->address;
        if(s.find(xadd)!=-1){
            num++;
        cout<<"为你找到可能的第"<<num<<"位联系人:"<<endl;
        curr->ShowInfor();
        }
    curr=curr->next;
    }
    cout<<"模糊查找完毕！共找到"<<num<<"位可能的联系人"<<endl<<endl;
}
void ContactBook::Find_Per3(){
    cout<<"你想要查找什么分组：";
    string xtype;
    cin>>xtype;
    person *curr=head;
    int num=0;
    cout<<"查找分组："<<xtype<<endl<<endl;
    while(curr){
        if(curr->type.find(xtype)!=-1){
            curr->ShowInfor();
            num++;
        }
        curr=curr->next;
    }
    cout<<"共查找到"<<num<<"位联系人！"<<endl;
}
void ContactBook::Find_Per(){
    cout<<"请输入查找方式："<<endl
    <<"1、精确查找"<<endl
    <<"2、模糊查找"<<endl
    <<"3、查找同一类别联系人"<<endl;
    int choice;
    flag:
    cin>>choice;
    switch(choice){
        case 1:
        this->Find_Per1();
            break;
        case 2:
        this->Find_Per2();
            break;
        case 3:
        this->Find_Per3();
            break;
        default:
        {
            cout<<"无该选项，请重试！"<<endl;
            goto flag;
            
        }
    }
}
void ContactBook::Revise(person *&head){
    cout<<"请输入你要修改的信息（若不修改请输入0）："<<endl;
    string xnumber,xname,xsex,
           xadd,xema,xme,xtype;
    cout<<"姓名：";
    cin>>xname;
    if(xname!="0") head->name=xname;
	cout<<"电话号码：";
    cin>>xnumber;
    if(xnumber!="0") head->number=xnumber;
	cout<<"性别：";
    cin>>xsex;
    if(xsex!="0") head->sex=xsex;
	cout<<"住址：";
    cin>>xadd;
    if(xadd!="0") head->address=xadd;
	cout<<"邮箱：";
    cin>>xema;
    if(xema!="0") head->email=xema;
	cout<<"备注：";
    cin>>xme;
    if(xme!="0") head->memo=xme;
	cout<<"组别：";
    cin>>xtype;
    if(xtype!="0") head->type=xtype;
	cout<<endl;
    save();

}
void ContactBook::Mod_Per(){
    cout<<"修改联系人信息"<<endl;
    cout<<"请查找你想要修改的联系人："<<endl
    <<"1、姓名"<<endl
    <<"2、电话号码"<<endl;
    int choice;
    flag:
    cin>>choice;
    person *curr=head;
    switch(choice){
        case 1:{
            cout<<"请输入姓名：";
            string s;
            cin>>s;
            while(curr){
                if(curr->name==s){
                    cout<<"找到该联系人！"<<endl;
                    curr->ShowInfor();
                    Revise(curr);
                    cout<<"修改成功！修改后联系人信息为："<<endl;
                    curr->ShowInfor();
                    return ;
                }
                curr=curr->next;
            }
            if(curr==NULL){
            cout<<"查无此人！"<<endl;
            return ;
            }
        }
        case 2:{
            cout<<"请输入号码：";
            string s;
            cin>>s;
            while(curr){
                if(curr->number==s){
                    cout<<"找到该联系人！"<<endl;
                    curr->ShowInfor();
                    Revise(curr);
                    cout<<"修改成功！修改后联系人信息为："<<endl;
                    curr->ShowInfor();
                    return ;
                }
                curr=curr->next;
            }
            if(curr==NULL){
            cout<<"查无此人！"<<endl;
            return ;
            }
        }
        default:
        {
            cout<<"无该选项，请重试！"<<endl;
            goto flag;
        }
    }
}
void ContactBook::Delete(person *pre,person *&curr){
    cout<<"删除联系人："<<endl;
        curr->ShowInfor();
        cout<<"确定删除？"<<endl;
        int choice;
        cout<<"1---是    2---否"<<endl;
        cin>>choice;
        if(choice==2) return ;
        else{
    if(curr==head){
        curr=curr->next;
        delete head;
        head=curr;
        p_num--; 
        save();
        cout<<"删除成功！"<<endl;
        return ;
    }
    else{       
        pre->next=curr->next;
        delete curr;
        p_num--; 
        save();
        cout<<"删除成功！"<<endl;   
        return ; 
    } 
        }
}
void ContactBook::Del_Per(){
    cout<<"删除联系人"<<endl;
    cout<<"查找你想要删除的联系人："<<endl
    <<"1、姓名"<<endl
    <<"2、电话号码"<<endl;
    int choice;
    flag:
    cin>>choice;
    person *curr=head,*pre=NULL;
    switch(choice){
        case 1:
        {
            string s;
            cout<<"请输入姓名：";
            cin>>s;
            //* 先检查重名联系人
            int num=0;
            while(curr){
                if(curr->name==s) num++;
                curr=curr->next;
            }
            curr=head;
            //* 若无重名联系人
            if(num==1)
            {
            if(head->name==s)//* 如果删除的的是头结点
                {   
                    Delete(pre,curr);
                    return ;
                }
            while(curr){
                if(curr->name==s){
                    Delete(pre,curr);
                    return ;
                }
                pre=curr;
                curr=curr->next;
            }
            }
            else if(num==0)
            {
            cout<<"查无此人！"<<endl;
            return;
            }
            //* 若存在重名联系人
            else if(num>1){
                int k=1;
                cout<<"为你查找到可能的联系人："<<endl;
                while(curr){
                    if(curr->name==s) {
                        cout<<"第"<<k<<"位："<<endl;
                        curr->id=k;
                        curr->ShowInfor();
                        k++;
                    }
                    curr=curr->next;
                }
                curr=head;
                cout<<"请输入你想删除的联系人的编号："<<endl;
                int index;
                cin>>index;
               if(head->id==index)//* 如果删除的的是头结点
                {   
                    Delete(pre,curr);
                    return ;
                }
            while(curr){
                if(curr->id==index){
                    Delete(pre,curr);
                    return ;
                }
                pre=curr;
                curr=curr->next;
            }
            }
        
        }
           case 2:
        {
            string s;
            cout<<"请输入号码：";
            cin>>s;
            if(head->number==s)
                {   
                    Delete(pre,curr);
                }
             while(curr){
                if(curr->number==s){
                    Delete(pre,curr);
                    return ;
                }
                pre=curr;
                curr=curr->next;
            }
            cout<<"查无此人！"<<endl;
            return;
        }
        default:
        {
            cout<<"无该选项，请重试！"<<endl;
            goto flag;
        }
    }
}
void ContactBook::Sort_Per(){
    cout<<"排序联系人"<<endl
    <<"请选择排序方式："<<endl
    <<"1、姓名"<<endl
    <<"2、号码"<<endl;
    int choice;
    person *curr=head,*temp;
    flag:
    cin>>choice;
    if (choice==1){
    for(curr;curr!=NULL;curr=curr->next){
        for(temp=curr->next;temp!=NULL;temp=temp->next){
            if(temp->name<curr->name)
            swap(temp->name,curr->name),
            swap(temp->number,curr->number),
            swap(temp->sex,curr->sex),
            swap(temp->type,curr->type),
            swap(temp->address,curr->address),
            swap(temp->email,curr->email),
            swap(temp->memo,curr->memo); //* 交换所有信息
        }
    }
    cout<<"按姓名首字母排序完成！"<<endl;
    Show_Per();
    }
    else if(choice==2){
        for(curr;curr!=NULL;curr=curr->next){
        for(temp=curr->next;temp!=NULL;temp=temp->next){
            if(temp->number<curr->number)
            swap(temp->name,curr->name),
            swap(temp->number,curr->number),
            swap(temp->sex,curr->sex),
            swap(temp->type,curr->type),
            swap(temp->address,curr->address),
            swap(temp->email,curr->email),
            swap(temp->memo,curr->memo); 
        }
    }
    cout<<"按电话号码排序完成！"<<endl;
    Show_Per();
}
    else {
        cout<<"无该选项，请重试！"<<endl;
        goto flag;
    }
}