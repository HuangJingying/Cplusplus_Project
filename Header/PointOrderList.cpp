//
// Created by jingying huang on 2020/5/12.
//
#include "PointOrderList.h"
#include <fstream> //for ifstream
#include <string>
#include <sstream>
#include <iomanip>      // std::get_time

#include <vector>
#include "PersonalUser.h"
#include "UserPoints.h"
void PointOrderList::showOrder() {
    for (int i=0;i<orderList.size();i++){
        orderList[i].showPointOrder();
    }
}
void PointOrderList::showOrderFile() {
    for (int i=0;i<orderList.size();i++){
        orderList[i].showPointOrderFile();
    }
}
bool PointOrderList::load_order(string filename) {
    //! may should change due to similar to : PointsAccount::addMerchant(string Merchant_id,string & inUsername,string &user_id) {
    ifstream readFile;
    readFile.open(filename);
    if (!readFile.is_open())
    {
//        cout<<"Could not open "+filename+"\n";
        return false;
    }
    string order_id,point,user_out_id,ac_out_id,user_in_id,ac_in_id,order_status;
    while(!readFile.eof()){    //逐行读取所有已有的用户名和密码；
        getline(readFile, order_id, ';');
        getline(readFile, point, ';');
        getline(readFile, user_out_id, ';');
        getline(readFile, ac_out_id,';');
        getline(readFile, user_in_id, ';');
        getline(readFile, ac_in_id,';');
        getline(readFile, order_status);
//        cout<<"read order_id:"<<order_id<<endl;//! delete
        if(!order_id.empty()) {
            //! if order is already in orderList, should continue
            PersonalUser user_out(user_out_id);//!!!!
            // load PersonalUser's data
            user_out.load_PointData();
            UserPoints ac_out, ac_in;
            ac_out = user_out.get_PointsAccount().search_by_Merchant_id(ac_out_id);
            ac_in = user_out.get_PointsAccount().search_by_Merchant_id(ac_in_id);
            PointOrder p_order(order_id);
            int ipoint = stoi(point);
            p_order.set(ipoint, user_out, ac_out, user_out, ac_in);
//
            orderList.push_back(p_order);
        }
    }
    readFile.close();
    showOrderFile();//!cout,should delete
    return true;
}

bool PointOrderList::process_payed_orderList() {
    string check;

    for (int i=0;i<orderList.size();i++){
        cout<<"Allow :"<<orderList[i].get_order_id()<<" ? y or n"<<endl;
        cin>>check;
        if (check=="y")orderList[i].process_payed_order();
        else continue;
    }
    return true;
}

bool PointOrderList::show_removeList(vector<PointOrder> &reList) {
    int m=0;
    for (int i=0;i<orderList.size();i++){
        if(orderList[i].get_order_id()==reList[m].get_order_id()){
            m++;
            continue;
        }
        else{
            orderList[m].showPointOrder();
        }
        assert(i < reList.size());
    }

//    for (auto i = orderList.cbegin(); i != orderList.cend(); ++i)
//    {
//        if (*i == *j) { *i = blank; ++j; }
//    }
//    assert(j == B.end());
}


