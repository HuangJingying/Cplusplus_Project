//
// Created by jingying huang on 2020/5/13.
//

#ifndef BIGHOMEWORK_POINTORDER_H
#define BIGHOMEWORK_POINTORDER_H

#include "Order.h"
#include "PersonalUser.h"
#include "UserPoints.h"
#include <string>
//积分交易订单：继承自订单基类
class PointOrder :public Order{
public:
    PointOrder():Order(){};
    PointOrder(string _order_id):Order(_order_id){};
    PointOrder(string _order_id,PersonalUser _user_out,UserPoints _ac_out,
               PersonalUser _user_in,UserPoints _ac_in):Order(_order_id),
                                                        user_out(_user_out),ac_out(_ac_out),user_in(_user_in),ac_in(_ac_in){};

    void set(int p,PersonalUser & _user_out,UserPoints & _ac_out,
             PersonalUser & _user_in,UserPoints & _ac_in);;
    //将订单写入文件
    bool writeTo_User_unPay_File();
    bool writeTo_User_Payed_File();
    bool writeTo_User_Finish_File();
    bool writeTo_Sys_Payed_File();
    bool writeTo_Sys_Finish_File();
    //计算手续费
    void calculate_fee(int type_of_order);
    //show
    void showPointOrder();
    void showPointOrderFile();

    int getPoint(){return point;};
    float getOutMoney(){return point * ac_out.getPrice() * 0.95/100;}
    int getInPoint(){return point * ac_out.getPrice() / ac_in.getPrice();};
    float getInMoney(){return point * ac_out.getPrice() * 0.9/100;}//! should get from config
    string getOutMerchant_id(){return ac_out.getMerchant_id();}

    bool process_payed_order();
private:
    int point;
    PersonalUser user_out;//积分支付用户
    UserPoints ac_out;//积分支付账户
    PersonalUser user_in;//积分收入用户
    UserPoints ac_in;//积分收入账户
    bool writeToFile(string filename);
};


#endif //BIGHOMEWORK_POINTORDER_H
