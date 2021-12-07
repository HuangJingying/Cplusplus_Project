//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_PERSONALUSER_H
#define BIGHOMEWORK_PERSONALUSER_H

#include "NonSystemUser.h"
#include "PointsAccount.h"
//#include "Money.h"


class PersonalUser :public NonSystemUser{
public:
    PersonalUser():NonSystemUser(){};

    PersonalUser(string _user_id);//
    PersonalUser(string _user_id,string _userName);//for login
    void load_PointData();

    //积分管理
    void display()const;
    void addMerchant(string Merchant_id);
    void deleteMerchant(string Merchant_id);
    //积分转换:在自己的不同商户间转换积分：选择“转出账户”、“转入账户”、转换积分数量; 
    friend class PointManage;
    friend class PointOrder;

    //积分交易
    friend class ProductOrder;
    PointsAccount & get_PointsAccount(){return PointsAccount;}
    //资金管理 NonSystemUser
    //订单管理



private:
    PointsAccount PointsAccount; //积分账户: 一个用户有多个不同商户的积分

};


#endif //BIGHOMEWORK_PERSONALUSER_H
