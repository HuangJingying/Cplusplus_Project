//
// Created by jingying huang on 2020/5/11.
//

#include "PointsAccount.h"
#include "UserPoints.h"
#include <iostream>
#include <fstream> //for ifstream
#include <string>
#include <sstream>
#include <iomanip>      // std::get_time
using namespace std;
void PointsAccount::displayAllPoint() const{
    for(int i=0;i< uPoints_list.size();i++){//#!
        uPoints_list[i].displayPoints();
    }
}

bool PointsAccount::addMerchant(string Merchant_id,string & inUsername,string &user_id) {
//!    //#! if merchant id is in all merchant id list
    if (if_exist_merchant(Merchant_id)) {
        cout<<"Merchant_id exist."<<endl;
        return false;
    }
    else
    uMerchant_list.push_back(Merchant_id);
    //从商户文件读入
    ifstream f;
    string filename="../Data/Merchant/User_point/"+Merchant_id;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"could not open "+filename+"\n";
        cout<<"This merchant has no User Point List File.\n";
        return false;
    }
    string username,expireData;
    int pointNum;
    while(f){    //逐行读取商户的用户积分文件；
        f>>username>>pointNum>>expireData;
//        cout<<"Read :username:"<<username<<' '<<pointNum<<' '<<expireData<<endl;//! delete
        if (username == inUsername){
            UserPoints aUserPoints(Merchant_id,0,expireData,pointNum);

            if(aUserPoints.load_price_data("../Data/Merchant/Price/"+Merchant_id)){
                uPoints_list.push_back(aUserPoints);
                //写入用户文件
                aUserPoints.writeToFile(user_id);
                cout<<"Add successful."<<endl;
                f.close();
                return true;
            }
            else
                break;
        }
    }
    cout<<"This merchant id no Point for the user:"<<user_id<<endl;
    f.close();
    return false;

}
bool PointsAccount::write_allPointData(string filename) {
    ofstream writeFile;
    writeFile.open(filename);
    if (!writeFile)
    {
        cout<<"no point file"<<endl;
        return false;
    }
    for(int i=0;i<uPoints_list.size();i++) {
        writeFile<<uPoints_list[i];
    }
    return true;
}

bool PointsAccount::deleteMerchant(string Merchant_id) {
    for(int i=0;i< uMerchant_list.size();i++){//#!
        if (uMerchant_list[i]==Merchant_id){
            uPoints_list.erase(uPoints_list.begin()+i);
            cout<<"delete successful."<<endl;
            return true;
        }
    }
    cout<<"No such merchant id:"<<Merchant_id<<endl;
    return false;
}

bool PointsAccount::if_exist_merchant(string Merchant_id){
    for(int i=0;i< uMerchant_list.size();i++){//! may a better way
        if (uMerchant_list[i]==Merchant_id)
            return true;
    }
    return false;
}

UserPoints & PointsAccount::search_by_Merchant_id(string Merchant_id) {
    for(int i=0;i< uMerchant_list.size();i++){//! similar to PointsAccount::if_exist_merchant
        if (uPoints_list[i].getMerchant_id()==Merchant_id)
            return uPoints_list[i];
    }
    cout<<"no Merchant_id: "+Merchant_id<<endl;//! may need a warning or error.
}


void PointsAccount::load_Point(string _merchant_id,float _price,string _expireDate,int p) {
    uMerchant_list.push_back(_merchant_id);
    UserPoints aUserPoints(_merchant_id,_price,_expireDate,p);
//    aUserPoints.load_price_data("../Data/Merchant/Price/"+_merchant_id);
    uPoints_list.push_back(aUserPoints);
}
void PointsAccount::load_PointData(string filename) {
    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"Could not open "+filename+"\n";
    }
    string Merchant_id,expireData;
    int pointNum;
    float price;
    while(!f.eof()){    //逐行读取
        f>>Merchant_id>>pointNum>>expireData>>price;
        if (Merchant_id.empty()){
            cout<<"Empty."<<endl;
            break;
        }
        if(!if_exist_merchant(Merchant_id)){
            load_Point(Merchant_id,price,expireData,pointNum);
        }
    }
    f.close();
}



