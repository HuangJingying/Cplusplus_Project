//
// Created by jingying huang on 2020/5/10.
//
#include <iostream>
#include <fstream> //for ifstream
#include <string>
#include "UserPoints.h"
#include <sstream>
#include <iomanip>
#include <ctime>
using namespace std;

//string UserPoints::showTime_t()const{// convert tm structure to string .
//    tm *ltm = localtime(&expireDate);
//    string data=to_string(1900+ltm->tm_year) +"-"+ to_string(1+ltm->tm_mon)+"-"+ to_string(ltm->tm_mday);
//    return data;
//    //    cout << data << endl;
//}
void UserPoints::displayPoints() const{
    cout<<"Belongs to(Merchant ID):"<<merchant_id<<" Number:"<<point<<" Expired Data: "<<expireDate<<endl;
}

bool UserPoints::writeToFile(string user_id) {
    ofstream writeFile;
    string filename="../Data/User/point/"+user_id;
    writeFile.open(filename,ios::app);//新增内容
    if (!writeFile)
    {
        cout<<"no point file"<<endl;
        return false;
    }
    //添加数据到文件尾
//    writeFile<<merchant_id<<' '<<point<<' '<<expireDate<<' '<<price<<endl;
    writeFile<<*this;
    writeFile.close();
    return true;
}
ostream & operator<<(ostream &out, const UserPoints &c) {
    out<<c.merchant_id<<' '<<c.point<<' '<<c.expireDate<<' '<<c.price<<endl;
    return out;
}

bool UserPoints::load_price_data(string filename) {
    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"could not open "+filename+"\n";
        return false;
    }
    float _price;
    f>>_price;
    if(_price!=0){
        price=_price;
        f.close();
        return true;
    }
    f.close();
    return true;
}
