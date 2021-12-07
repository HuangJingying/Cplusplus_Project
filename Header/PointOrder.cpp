//
// Created by jingying huang on 2020/5/13.
//

#include "PointOrder.h"
#include <iostream>
#include <fstream> //for ifstream
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
#include "MerchantUser.h"
#include "systemUser.h"
using namespace std;

bool PointOrder::writeToFile(string filename) {//! similar to bool UserPoints::writeToFile(string user_id)
    ofstream writeFile;
    writeFile.open(filename,ios::app);//新增内容
    if (!writeFile)
    {
        cout<<"no such file: "+filename<<endl;
        return false;
//        writeFile.open(moneyFilename);
    }
    //添加 订单 数据到文件尾
    writeFile<<get_order_id()<<';'<<point<<';'<<
            user_out.get_user_id()<<';'<<ac_out.getMerchant_id()<<';'<<
            user_in.get_user_id()<<';'<<ac_in.getMerchant_id()<<';'
            <<get_orderStatus()<<endl;
    writeFile.close();
    return true;
}

bool PointOrder::writeTo_Sys_Payed_File() {
    string filename="../Data/System/u2u_order_list";
    writeToFile(filename);
    return true;
}
bool PointOrder::writeTo_Sys_Finish_File() {
    string filename="../Data/System/u2u_order_list_finish";
    writeToFile(filename);
    return true;
}
bool PointOrder::writeTo_User_unPay_File() {
    string filename="../Data/User/Order/Transfer/unPay_Order/"+user_out.get_user_id();
    writeToFile(filename);
    return true;

}
bool PointOrder::writeTo_User_Payed_File() {
    string filename="../Data/User/Order/Transfer/Payed_Order/"+user_out.get_user_id();
    writeToFile(filename);
    return true;
}
bool PointOrder::writeTo_User_Finish_File() {
    string filename="../Data/User/Order/Transfer/Finish_Order/"+user_out.get_user_id();
    writeToFile(filename);
    return true;
}
void PointOrder::calculate_fee(int type_of_order) {
    if(type_of_order==1){
        float fee=0.05*point*ac_out.getPrice()/100.0;
        set_payMoney(fee);
    }
//    return fee;
}

void PointOrder::showPointOrder() {
    cout<<"Order ID: "<<get_order_id()<<
    " From: "<<user_out.get_userName()<<", "<<ac_out.getMerchant_id()<<", "<<point<<" Points "<<
    " To: "<<user_in.get_userName()<<", "<<ac_in.getMerchant_id()<<", "<<getInPoint()<<" Points "<<
    " fee: "<<get_payMoney()<<endl;
}

void PointOrder::showPointOrderFile() {
    cout<<"Order ID: "<<get_order_id()<<
        " From: "<<ac_out.getMerchant_id()<<", "<<point<<" Points "<<
        " To: "<<ac_in.getMerchant_id()<<", "<<getInPoint()<<" Points "<<endl;

}

bool PointOrder::process_payed_order() {
    //读取商户信息
    string merchant_id_out=ac_out.getMerchant_id();
    MerchantUser out_mer(merchant_id_out);

    string merchant_id_in=ac_in.getMerchant_id();
    MerchantUser in_mer(merchant_id_in);

    //pay

    //out point merchant: reduce money
    float out_money=getOutMoney();
    string out_filename="../Data/Merchant/Money/"+merchant_id_out;
//    out_mer.load_a_float_Data(out_filename);
//    out_mer.setMoneyFilename(out_filename);
    out_mer.load_money_data();
    out_mer.reduceMoney(out_money);
    cout<<merchant_id_out<<" reduce money:"<<out_money<<endl;
//    out_mer.write_a_float_Data(out_filename);

    //in point merchant: add money
    float in_money=getInMoney();
    string in_filename="../Data/Merchant/Money/"+merchant_id_in;
//    out_mer.load_a_float_Data(in_filename);
//    in_mer.setMoneyFilename(in_filename);
    in_mer.load_money_data();
    cout<<merchant_id_in<<" add money:"<<in_money<<endl;
    in_mer.addMoney(in_money);
//    out_mer.write_a_float_Data(in_filename);

    //change sys money
    systemUser a_sys_user;
    a_sys_user.addMoney(out_money-in_money);

    //process point
    int out_point= getPoint();
    int in_point = getInPoint();
    string out_user_id=user_out.get_user_id();
    string in_user_id=user_in.get_user_id();

    if (out_user_id==in_user_id)
    {

        //reduce point
//        ac_out.reducePoint(out_point);
//        ac_out.writeToFile(out_user_id);
//        user_out.PointsAccount.search_by_Merchant_id(merchant_id_out).reducePoint(out_point);//!failed why?
//        //覆盖文件
//        user_out.PointsAccount.write_allPointData("../Data/User/Point/"+out_user_id);
        //add point;
        user_in.PointsAccount.search_by_Merchant_id(merchant_id_in).addPoint(in_point);
        //覆盖文件
        user_in.PointsAccount.write_allPointData("../Data/User/Point/"+in_user_id);
//        ac_in.addPoint(in_point);
//        ac_in.writeToFile(in_user_id);//!write to file something wrong ,should be replace the line not add

    }
    //change order status
    change_orderStatus(3);

    //write to file
    writeTo_Sys_Finish_File();
    writeTo_User_Finish_File();
    return false;
}

void PointOrder::set(int p, PersonalUser &_user_out, UserPoints &_ac_out, PersonalUser &_user_in, UserPoints &_ac_in) {
    point=p;
    user_out=_user_out;
    ac_out=_ac_out;
    user_in=_user_in;
    ac_in=_ac_in;
}








