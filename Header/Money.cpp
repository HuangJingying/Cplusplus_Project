//
// Created by jingying huang on 2020/5/11.
//

#include "Money.h"
#include <string>
#include <iostream>
#include <fstream> //for ifstream
#include <sstream>
using namespace std;

bool Money::reduce(float m) {
    if(balance-m>=0){
        balance=balance-m;
        return true;
    }
    else{
        cout<<"no enough money! Balance: "+to_string(balance)<<endl;
        return false;
    }
}
bool Money::load_a_float_Data(string filename) {
    //! may should change due to similar to : PointsAccount::addMerchant(string Merchant_id,string & inUsername,string &user_id) {
    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"Could not open "+filename+"\n";
        return false;
    }
    float _balance;
    while(!f.eof()){    //逐行读取所有已有的用户名和密码；
        f>>_balance;
        balance=_balance;
//        cout<<"balance:"<<balance<<endl;//! delete
    }
    f.close();
    return true;
}
bool Money::write_a_float_Data(string filename) {
    ofstream f;
    f.open(filename);//覆盖原来的文件
    if (!f.is_open())
    {
        cout<<"Could not open "+filename+"\n";
        return false;
    }
    f<<balance;
//    cout<<"write balance:"<<balance<<endl;//! delete
    f.close();
    return true;
}
