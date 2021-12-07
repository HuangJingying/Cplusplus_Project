#include <iostream>
#include <fstream> //for ifstream
#include <string>
#include "Header/PersonalUser.h"
#include "Header/PointManage.h"
#include "Header/PointOrder.h"
#include "Header/systemUser.h"
#include "Header/ProcessOrder.h"
#include "Header/MerchantUser.h"

#include "Header/PointTransact.h"
#include "Header/MerchantManage.h"
#include "Header/ProductManage.h"
#include "Header/PersonalUserManage.h"
using namespace std;

struct testPara{//~
public:
//    int role=1;
//    int login=2;
//    string username="18811110001";
//    string password="123456";
//sys
    string username="system_user1";
    string password="12345678";
//mer
//    string username="a1";
//    string password="123456";
};
testPara test1;//~,test1 only for test

bool user_login(string filename,string & user_ID,string & userName);
bool user_register(string filename, string & user_ID,string & userName,int len);
//void main_select_role();
void main_user_menu(string filename,string & userName,string & user_ID,int length_of_user_ID);
void main_user_function(PersonalUser & user);
//void main_merchant_menu();
void main_merchant_function(MerchantUser & mUser);
void main_system_menu(string & userName,string & user_ID);
void main_system_function(systemUser & sys);
string id_add(int num,int len,int m);
int main(){
    int choice;
    //===1.角色选择===
    cout<<" Hello, What is your role?""\n"
          "[1] Personal User""\n"
          "[2] Merchant User""\n"
          "[3] System User""\n"
          "[4] Exit""\n";
    cin>>choice;
//    choice=test1.role;
    string user_ID = " ";
    string userName = " ";
    if (choice==1) {
        //===2. 登录或者注册===
        main_user_menu("../Data/User/registration",userName, user_ID,4);
        cout << "Personal User ID:" << user_ID << " User Name:" << userName << endl;

        //===3. 用户功能选择===
        PersonalUser user(user_ID, userName);
        main_user_function(user);

    }
    else if(choice==2){
        //===2. 登录或者注册===
        main_user_menu("../Data/Merchant/registration",userName, user_ID,3);
        cout << "Merchant User ID:" << user_ID << " User Name:" << userName << endl;//! delete
        MerchantUser mUser(user_ID);
        main_merchant_function(mUser);
    }
    else if(choice==3){
        main_system_menu(userName, user_ID);
        cout << "User ID:" << user_ID << " User Name:" << userName << endl;//! delete
        //===3. 系统功能选择===
        systemUser sys(user_ID, userName);
        main_system_function(sys);
    }
    return 0;
};

void main_user_menu(string filename,string & userName,string & user_ID,int length_of_user_ID){
    cout<<" Would you like to log in or register?""\n"
          "[1] Login""\n"
          "[2] Register""\n"
          "[3] Exit""\n";
    int choice;
    cin>>choice;
//    string user_ID = " ";
//    string userName=test1.username;//! change
    bool login;
    bool registers;
//    string moneyFilename="../Data/User/registration";
    switch (choice)
    {
        case 1:

            login = user_login(filename,user_ID,userName);
            if(login){
                cout<<"登陆成功"<<endl;
            }
            else{
                cout<<"登录失败"<<endl;
                exit(1);
            }
            break;
        case 2:
            registers = user_register(filename,user_ID,userName,length_of_user_ID);
            if(registers){
                cout<<"注册成功"<<endl;
            }
            else {
                cout<<"注册失败"<<endl;
                exit(1);
            }
            break;
        case 3:
            exit(1);
    }

}

void main_user_function(PersonalUser & user){
    //===3. 用户功能选择===
    int choice,choice2;
    cout<<" What would you like to do？""\n"
          "[1] 基本功能""\n"
          "[2] 积分管理""\n"
          "[3] 积分转换""\n"
          "[4] 积分交易""\n"
          "[5] 资金管理""\n"
          "[6] Exit""\n";
//    cin>>choice;
    PointManage pointManage;
    PointOrder anOrder;
    bool ifOrder;

    PointTransact pointTransact;
    string merchant_id,product_id;
    int num;

    ProductOrder anProOrder;

    float money;
    string in_merchant_id,out_merchant_id;
    int Number_of_point;
    ProcessOrder processOrder;
    while(cin>>choice && choice!=6){

        switch (choice)
        {
            case 1://基本功能
                //载入基本信息
                user.load_info();
                cout<<"1. setInfo\n2. changeInfo\n3. showInfo\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2!=4) {
                    switch(choice2){
                        case 1:
                            user.setInfo();
                            break;
                        case 2:
                            //修改基本信息
                            user.changeInfo();
                            break;
                        case 3:
                            user.showInfo();
                            break;
                        case 4:
                            exit(1);
                    }
                    cout<<"1. setInfo\n2. changeInfo\n3. showInfo\n4. Save and Quit"<<endl;
                }
                break;
            case 2://积分管理
//                cout<<user.get_userName()<<endl;//!delete
                //            user.read_userData()
                user.load_PointData();//!may no here, something wrong,240541-7-23
                cout<<"1. display\n2. addMerchant\n3. deleteMerchant\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2<4) {
                    switch(choice2) {
                        case 1://查询自己所有商户的积分情况（积分数量、到期时间等）；
//                            pointManage.display(user);//!something wrong,240541-7-23
                            user.display();
                            break;
                        case 2://关联商户的账户；
                            cout<<"Input merchant_id:"<<endl;
                            cin>>merchant_id;
                            user.addMerchant(merchant_id);
//                            pointManage.addMerchant(user, merchant_id);
                            break;
                        case 3://删除关联商户的账户
                            cout<<"Input merchant_id:"<<endl;
                            cin>>merchant_id;
                            user.deleteMerchant(merchant_id);
//                            pointManage.deleteMerchant(user, merchant_id);
                            break;
                    }
                    cout<<"1. display\n2. addMerchant\n3. deleteMerchant\n4. Save and Quit"<<endl;
                }
                break;
            case 3://积分转换
                cout<<"1. apply_points_transfer\n2. show_u2u_Finish_Order\n3. show_u2u_Payed_Order\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2<4) {
                    switch(choice2) {
                        case 1:
                            user.load_PointData();//!may no here,
                            //显示
                            user.display();
                            cout << "Input in_merchant_id,out_merchant_id,Number of point:" << endl;
                            cin >> in_merchant_id >> out_merchant_id >> Number_of_point;
                            //在自己的不同商户间转换积分：选择“转出账户”、“转入账户”、转换积分数量；
                            ifOrder=pointManage.apply_points_transfer(anOrder, user, Number_of_point, in_merchant_id,
                                                              out_merchant_id);
                            user.display();

                            //支付
                            if(ifOrder) {
                                user.load_money_data();
                                pointManage.pay_for_points_transfer(user, anOrder);
                            }
                            else{
                                cout<<"Apply fail."<<endl;
                            }
                            break;
                        case 2://查看所有已完成的订单
                            if(!processOrder.show_aUser_u2u_Finish_Order(user.get_user_id())){
                                cout<<"Empty."<<endl;
                            }
                            break;
                        case 3://查看所有未完成的订单
                            if(!processOrder.show_aUser_u2u_Payed_Order(user.get_user_id())){
                                cout<<"Empty."<<endl;
                            }
                            break;
                    }
                    cout<<"1. apply_points_transfer\n2. show_u2u_Finish_Order\n3. show_u2u_Payed_Order\n4. Save and Quit"<<endl;
                }
                break;
            case 4://积分交易
                //购买商户上架的积分产品；
                cout << "Input merchant_id:" << endl;
                cin>>merchant_id;//>>product_id>>num;
                pointTransact.apply_product_transact(anProOrder,user,merchant_id);
                break;
            case 5:
                //资金管理
                user.load_money_data();
                cout<<"1. getMoney\n2. addMoney\n3. reduceMoney\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2<4) {
                    switch(choice2){
                        case 1://查询余额；
                            cout<<"Balance:"<<user.getMoney()<<endl;
                            break;
                        case 2://充值；
                            cout<<"Input adding money:"<<endl;
                            cin>>money;
                            user.addMoney(money);
                            cout<<"add successful, now balance: "<<user.getMoney()<<endl;
                            break;
                        case 3://取款；
                            cout<<"Input reducing money:"<<endl;
                            cin>>money;
                            if(user.reduceMoney(money))
                                cout<<"reduce successful, now balance: "<<user.getMoney()<<endl;
                            break;
                    }
                    cout<<"1. getMoney\n2. addMoney\n3. reduceMoney\n4. Save and Quit"<<endl;
                }
                break;
            case 6:
                exit(1);
        }
        cout<<" What would you like to do？""\n"
              "[1] 基本功能""\n"
              "[2] 积分管理""\n"
              "[3] 积分转换""\n"
              "[4] 积分交易""\n"
              "[5] 资金管理""\n"
              "[6] Exit""\n";
    }
}

//void main_merchant_menu(){}
void main_merchant_function(MerchantUser & mUser){
    //===3. 商户功能选择===
    int choice,choice2;
    cout<<" What would you like to do？""\n"
          "[1] 基本功能""\n"
          "[2] 用户管理""\n"
          "[3] 商品管理""\n"
          "[4] 积分管理""\n"
          "[5] 资金管理""\n"
          "[6] Exit""\n";
    string product_id;
    float money;
    PersonalUserManage personalUserManage;
    string user_id,user_name,data;
    int point;
    float price;

    while(cin>>choice && choice!=6){

        switch (choice)
        {
            case 1://基本管理
                //载入基本信息
                mUser.load_info();
                cout<<"1. setInfo\n2. changeInfo\n3. showInfo\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2!=4) {
                    switch(choice2){
                        case 1:
                            mUser.setInfo();
                            break;
                        case 2:
                            //修改基本信息
                            mUser.changeInfo();
                            break;
                        case 3:
                            mUser.showInfo();
                            break;
                        case 4:
                            exit(1);
                    }
                    cout<<"1. setInfo\n2. changeInfo\n3. showInfo\n4. Save and Quit"<<endl;
                }
                break;
            case 2://用户管理
                cout<<"1. add_a_new_user_point\n2. show_a_user_now_point\n3. Quit"<<endl;
                while(cin>>choice2 && choice2<3) {
                    switch(choice2) {
                        case 1://导入其用户的积分
                            cout<<"Input a new User Name, the number of points, the expired data of points"<<endl;
                            cin>>user_name>>point>>data;
                            personalUserManage.add_a_new_user_point(mUser.get_user_id(),user_name,point,data);
                            break;
                        case 2://通过用户账号可查询用户积分信息
                            cout<<"Input existed User id:"<<endl;
                            cin>>user_id;
                            personalUserManage.show_a_user_now_point(mUser.get_user_id(),user_id);
                            break;
                    }
                    cout<<"1. add_a_new_user_point\n2. show_a_user_now_point\n3. Quit"<<endl;
                }
                break;
            case 3://商品管理
                //载入产品信息
                mUser.load_product_data();
                //                aProductList.load_all_product_Data("../Data/Merchant/Product/"+mUser.get_user_id());
                cout<<"1. add_a_product\n2. show_all_product\n3. change a Product\n4. getProductSize\n5. Quit"<<endl;
                while(cin>>choice2 && choice2!=5) {
                    switch(choice2){
                        case 1:
                            //新增商品
                            mUser.add_a_product();
                            break;
        //                aProductList.add_a_product(100,10,1000,true);
        //                aProductList.showList();
                        case 2:
                            //显示所有商品信息
                            mUser.show_all_product();
                            break;
                            //修改商品信息
                        case 3:
                            cout << "Input a product ID:" << endl;
                            cin >> product_id;
                            cout<<mUser.changeProduct(product_id)<<endl;
                            break;
                        case 4:
                            //统计商品总数
                            cout << "Total:" << mUser.getProductSize() << endl;
                            break;
                        case 5:
                            exit(1);
                    }
                    cout<<"1. add_a_product\n2. show_all_product\n3. change a Product\n4. getProductSize\n5. Quit"<<endl;
                }
                break;
            case 4://积分管理
            //修改积分价格
                cout<<"1. set_point_price\n2. Quit"<<endl;
                while(cin>>choice2 && choice2<2) {
                    switch (choice2) {
                        case 1:
                            cout << "Input a price:" << endl;
                            cin >> price;
                            if(mUser.set_point_price(price))
                                cout<<"set price successful"<<endl;
                            else
                                cout<<"set price fail"<<endl;
                            break;
                    }
                    cout<<"1. set_point_price\n2. Quit"<<endl;
                }
                break;
            case 5://资金管理
                mUser.load_money_data();
                cout<<"1. getMoney\n2. addMoney\n3. reduceMoney\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2!=4) {
                    switch(choice2){
                        case 1://查询余额；
                            cout<<"Balance:"<<mUser.getMoney()<<endl;
                            break;
                        case 2://充值；
                            cout<<"Input adding value:"<<endl;
                            cin>>money;
                            mUser.addMoney(money);
                            break;
                        case 3://取款；
                            cout<<"Input reducing value:"<<endl;
                            cin>>money;
                            mUser.reduceMoney(money);
                            break;
                        case 4:
                            exit(1);
                    }
                }

                break;
            case 6:
                exit(1);
        }
        cout<<"What would you like to do？""\n"
              "[1] 基本功能""\n"
              "[2] 用户管理""\n"
              "[3] 商品管理""\n"
              "[4] 积分管理""\n"
              "[5] 资金管理""\n"
              "[6] Exit""\n";
    }

}

void main_system_menu(string & userName,string & user_ID){
    string filename="../Data/System/registration";
    bool login;
//    bool registers;//!
    login = user_login(filename,user_ID,userName);
    if(login){
        cout<<"登陆成功"<<endl;
    }
    else{
        cout<<"登录失败"<<endl;
        exit(1);
    }
}

void main_system_function(systemUser & sys){
    //===3. 平台功能选择===
    int choice,choice2;
    cout<<" What would you like to do？""\n"
          "[1] 交易""\n"
          "[2] 商户管理""\n"
          "[3] 用户管理""\n"
          "[4] 订单管理""\n"
          "[5] 商品管理""\n"
          "[6] Exit""\n";
    ProcessOrder process_order;
    string filename="../Data/System/u2u_order_list";

    MerchantManage merchantManage;
    string m_string_id="";

    ProductManage productManage;
    string product_id="";

    PersonalUserManage personalUserManage;
    string user_id="";
    while(cin>>choice && choice!=7){

        switch (choice)
        {
            case 1://交易，订单处理
                process_order.load_waiting_order("../Data/System/u2u_order_list");
                process_order.process_payed_orderList(filename.c_str());
                break;
            case 2://商户管理
                cout<<"1. show_a_MerchantInfo\n2. show_all_Merchant_Name\n3. Quit"<<endl;
                while(cin>>choice2 && choice2<3) {
                    switch(choice2) {
                        case 1://商户查询：通过账号可查询商户信息。
                            cout<<"Input existed Merchant id:"<<endl;
                            cin>>m_string_id;
                            merchantManage.show_a_MerchantInfo(m_string_id);
                            break;
                        case 2://统计并显示所有商户账号，总数；
                            merchantManage.show_all_Merchant_Name();
                            break;
                    }
                    cout<<"1. show_a_MerchantInfo\n2. show_all_Merchant_Name\n3. Quit"<<endl;
                }
                break;
            case 3://用户管理
                cout<<"1. show_a_user_info\n2. show_all_User_Name\n3. show_a_user_all_point\n4. Quit"<<endl;
                while(cin>>choice2 && choice2<4) {
                    switch(choice2) {
                        case 1://通过用户账号可查询用户基本信息
                            cout<<"Input existed User id:"<<endl;
                            cin>>user_id;
                            personalUserManage.show_a_user_info(user_id);
                            break;
                        case 2://显示所有用户账号和用户名并统计总数
                            personalUserManage.show_all_User_Name();
                            break;
                        case 3://通过用户账号可查询用户所有积分信息
                            cout<<"Input existed User id:"<<endl;
                            cin>>user_id;
                            personalUserManage.show_a_user_all_point(user_id);
                    }
                    cout<<"1. show_a_user_info\n2. show_all_User_Name\n3. show_a_user_all_point\n4. Quit"<<endl;
                }
                break;
            case 4://订单管理
                cout<<"1. show_all_u2u_Payed_Order\n2. show_all_u2u_Finish_Order\n3. Quit"<<endl;
                while(cin>>choice2 && choice2<3) {
                    switch(choice2) {
                        case 1://
                            process_order.show_all_u2u_Payed_Order();
                            break;
//                        case 2://2. show_all_m2u_Finish_Order
//                            process_order.show_all_m2u_Finish_Order();
//                            break;
                        case 2:
                            process_order.show_all_u2u_Finish_Order();
                            break;
                    }
                    cout<<"1. show_all_u2u_Payed_Order\n2. show_all_u2u_Finish_Order\n3. Quit"<<endl;                }
                break;
            case 5://商品管理
                cout<<"1. show_a_MerchantProduct\n2. show_a_Merchant_all_Product\n3. off_a_MerchantProduct\n4. Save and Quit"<<endl;
                while(cin>>choice2 && choice2<4) {
                    switch(choice2) {
                        case 1://商品查询：通过商户账户和商品编号搜索商品信息；
                            cout<<"Input existed Merchant id and its Product id:"<<endl;
                            cin>>m_string_id>>product_id;
                            productManage.show_a_MerchantProduct(m_string_id,product_id);
                            break;
                        case 2://统计并查询所有商品数量；
                            cout<<"Input existed Merchant id:"<<endl;
                            cin>>m_string_id;
                            productManage.show_a_Merchant_all_Product(m_string_id);
                            break;
                        case 3://强制下架商品；
                            cout<<"Input existed Merchant id and its Product id:"<<endl;
                            cin>>m_string_id>>product_id;
                            productManage.off_a_MerchantProduct(m_string_id,product_id);
                            break;
//                        case 4:
//                            break;
                    }
                    cout<<"1. show_a_MerchantProduct\n2. show_a_Merchant_all_Product\n3. off_a_MerchantProduct\n4. Save and Quit"<<endl;
                }

                break;
            case 6:
                exit(1);

        }
        cout<<" What would you like to do？""\n"
              "[1] 交易""\n"
              "[2] 商户管理""\n"
              "[3] 用户管理""\n"
              "[4] 订单管理""\n"
              "[5] 商品管理""\n"
              "[6] Exit""\n";
    }
}

bool user_login(string filename,string & user_ID,string & userName){
    string user_id,username, password;
    string inUsername,inPassword;

    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"could not open registration file\n";
        return false;
    }
    cout<<"Username: "<<endl;
//    cin>>inUsername;
    inUsername=test1.username;//!
    cout<<"Password: "<<endl;
//    cin>>inPassword;
    inPassword=test1.password;//!

    while(!f.eof()){    //逐行读取所有已有的用户名和密码；
        getline(f, user_id, ' ');
        getline(f, username, ' ');
        getline(f, password);
        if (username == inUsername){
            if(password == inPassword) {
                user_ID = user_id;
                userName = username;
                f.close();
                return true;
            }
            else{
                cout<<"Password is wrong"<<endl;
                f.close();
                return false;
            }
        }
    }
    cout<<"用户名不存在。"<<endl;
    f.close();
    return false;
}

bool user_register(string filename, string & user_ID,string & user_Name,int len){
    string user_id, username, password;
    string inUsername,inPassword;

    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"could not open registration file\n";
        return false;
    }

    cout<<"Username: "<<endl;
    cin>>inUsername;
    cout<<"Password: "<<endl;
    cin>>inPassword;

    int i=0;
    string tmp;
    while(f.good()){//!!!!!how to deal with the last line
        f>>user_id>>username>>password;
        if (username == inUsername){
            cout<<"用户名已经存在。"<<endl;
            return false;
        }
        i++;
    }
    f.close();
    //新建一个用户ID；
    user_ID=id_add(i-1,len,1);
    user_Name=inUsername;
    //!写入文件
    User new_user(user_ID, inUsername,inPassword);
    if (len==4)
        new_user.writeToFile("../Data/User/registration");
    else if(len==3){
        new_user.writeToFile("../Data/Merchant/registration");
    }
    return true;
}

string id_add(int num,int len,int m){
    string str =to_string(num+m);
    for (int i=0;i<=(len-str.length()+1);i++){
        str="0"+str;
    }
    return str;
}