//
// Created by jingying huang on 2020/5/24.
//

#include "ProductOrder.h"
#include <iostream>
#include <fstream>
using namespace std;

bool ProductOrder::writeToFile(string filename) {//! similar to bool UserPoints::writeToFile(string user_id)
    ofstream writeFile;
    writeFile.open(filename,ios::app);//新增内容
    if (!writeFile)
    {
        cout<<"no such file: "+filename<<endl;
        return false;
//        writeFile.open(moneyFilename);
    }
    //添加 订单 数据到文件尾
    writeFile << get_order_id() << ' ' << mer_in.get_user_id() << ' ' << aProduct.getProduct_id()
             <<' '<<aProduct.getPrice()<<' '<<num<<' '<<
             user_out.get_user_id()<<' '<<get_orderStatus()<<endl;
    writeFile.close();
    return true;
}

//bool PointOrder::writeTo_Sys_Payed_File() {
//    string moneyFilename="../Data/System/m2u_order_list_payed";
//    writeToFile(moneyFilename);
//    return true;
//}
bool ProductOrder::writeTo_Sys_Finish_File() {
    string filename="../Data/System/m2u_order_list_finish";
    writeToFile(filename);
    return true;
}
bool ProductOrder::writeTo_User_unPay_File() {
    string filename="../Data/User/Order/Transact/unPay_Order/"+user_out.get_user_id();
    writeToFile(filename);
    return true;

}
bool ProductOrder::writeTo_User_Finish_File() {
    string filename="../Data/User/Order/Transact/Finish_Order/"+user_out.get_user_id();
    writeToFile(filename);
    return false;
}

void ProductOrder::showProductOrder() {
    cout << "Order ID: " << get_order_id() << " Seller:" << mer_in.get_user_id() << " Product ID:" << aProduct.getProduct_id()
        <<" Price"<<aProduct.getPrice()<<" Quantity:"<<num<<" Buyer:"<<
        user_out.get_user_id()<<" Status:"<<get_orderStatus()<<endl;
}

bool ProductOrder::process_unPay_order() {
    float fee = num*aProduct.getPrice();
//    cout<<"Price:"<<fee<<endl;
    //确认支付
    string check;
    user_out.load_money_data();
//    user_out
    cout<<"check pay "+to_string(fee)+" : y or n"<<endl;
    cin>>check;
    if(check=="y"){
        float ubalance=user_out.getMoney();
        if(ubalance>=fee){//! may be better;
            //add user's point
            int in_point=num*aProduct.getPoint();
            //!should change and write all point to one file
            user_out.load_PointData();

            user_out.PointsAccount.search_by_Merchant_id(mer_in.get_user_id()).addPoint(in_point);
            //覆盖文件
            user_out.PointsAccount.write_allPointData("../Data/User/Point/" + user_out.get_user_id());

            //reduce user's money
            user_out.reduceMoney(fee);//money write to file by self.
            cout<<"Pay successful ; balance: "<< user_out.getMoney()<<endl;

            // add merchant's money
            mer_in.addMoney(fee);




            // change status of order
            change_orderStatus(3);
            //存储于系统文件
//            writeTo_Sys_Payed_File();
            writeTo_Sys_Finish_File();
//            //存储于用户已支付订单文件
//            writeTo_User_Payed_File();
            writeTo_User_Finish_File();
            //!从用户未支付订单文件中删除
        }
        else{
            cout<<"no enough money! Balance: "<<ubalance<<endl;
            return false;
        }
    }
    return false;
}

void ProductOrder::set(int p, Product &_aProduct, PersonalUser &_user_out, MerchantUser &_user_in) {
    num=p;
    aProduct=_aProduct;
    user_out=_user_out;
    mer_in=_user_in;
}

ProductOrder::ProductOrder() :Order(2){}
