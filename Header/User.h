//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_USER_H
#define BIGHOMEWORK_USER_H

#include <string>
#include "Money.h"
using namespace std;

//角色基类
class User {
public:
    User(){};
    User(string _user_id);
    User(string _user_id,string _userName);
    User(string _user_id,string _userName,string _password);;
    ~User();

    string get_user_id(){return user_id;};
    string get_userName(){return userName;};
    string get_password(){return password;};

    bool writeToFile(string regist_filename);//将新注册的用户信息写入文件
    //资金管理
    void addMoney(float m){changeMoneyFlag=true;money.add(m);};
    bool reduceMoney(float m);;
    float getMoney(){return money.get();};
    void load_money_data();
//    bool changePassword();//修改密码:输入两次新密码,string old_pw,string new_str,string new_str_again
protected:
    void setMoneyFilename(string _filename){ moneyFilename=_filename;};//设置资金存储文件路径
private:
    string user_id;//用户ID
    string userName;//用户名
    string password;//密码

    Money money;//资金帐户
    string moneyFilename;//资金帐户文件路径
    bool changeMoneyFlag=false;//only if change money,write to file


};


#endif //BIGHOMEWORK_USER_H
