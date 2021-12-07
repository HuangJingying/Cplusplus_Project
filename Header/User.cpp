//
// Created by jingying huang on 2020/5/11.
//

#include "User.h"
#include "iostream"
#include <fstream>
using namespace std;
bool User::writeToFile(string regist_filename) {
    ofstream f;
    f.open(regist_filename,ios::app);//add
    if (!f.is_open())
    {
        cout<<"Could not open "+regist_filename+"\n";
        return false;
    }
    f<<user_id<<' '<<userName<<' '<<password<<endl;
    f.close();
    return true;
}


User::User(string _user_id) : user_id(_user_id) {
//    money.load_a_float_Data(moneyFilename);
}
User::User(string _user_id, string _userName) : user_id(_user_id),userName(_userName) {
//    money.load_a_float_Data(moneyFilename);
}
User::User(string _user_id, string _userName, string _password) {
    user_id=_user_id;
    userName=_userName;
    password=_password;
}
User::~User() {
    if(changeMoneyFlag)
        money.write_a_float_Data(moneyFilename);
}

bool User::reduceMoney(float m) {
    changeMoneyFlag=true;
    return money.reduce(m);
}

void User::load_money_data() {money.load_a_float_Data(moneyFilename) ;}




