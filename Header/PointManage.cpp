//
// Created by jingying huang on 2020/5/11.
//

#include "PointManage.h"
#include "PointOrder.h"
#include "systemUser.h"
//void PointManage::display(const PersonalUser &uSelf) const {
//    uSelf.PointsAccount.displayAllPoint();
//}
//void PointManage::addMerchant(PersonalUser &uSelf,string Merchant_id) {
//    string username=uSelf.get_userName();
//    string user_id=uSelf.get_user_id();
//    uSelf.PointsAccount.addMerchant(Merchant_id,username,user_id);
//
//}
//void PointManage::deleteMerchant(PersonalUser &uSelf, string Merchant_id) {
//    uSelf.PointsAccount.deleteMerchant(Merchant_id);
//}

bool PointManage::apply_points_transfer(PointOrder & t_order,PersonalUser &uSelf, int t_point,
        string in_merchant_id, string out_merchant_id) {
    //判断商户id是否已经关联
    assert(uSelf.PointsAccount.if_exist_merchant(in_merchant_id));
    assert(uSelf.PointsAccount.if_exist_merchant(out_merchant_id));
    //判断积分数量是否足够
    UserPoints user_out;
    user_out = uSelf.PointsAccount.search_by_Merchant_id(out_merchant_id);
    int point = user_out.getPointNum();
    if(point >= t_point){
        UserPoints user_in;
        user_in = uSelf.PointsAccount.search_by_Merchant_id(in_merchant_id);
        //生成积分转换订单
//        PointOrder t_order;
//        PointOrder
        t_order.set(t_point,uSelf,user_out,uSelf,user_in);
        t_order.calculate_fee(1);//1：未支付；
        t_order.showPointOrder();
        //确认订单
        string check;
        cout<<"Check order: y or n"<<endl;
        cin>>check;
        if(check=="y"){
            //写入文件
            t_order.writeTo_User_unPay_File();
            return true;
        }
        else
            return false;
    }
    else{
        cout<<"not enough point in "+out_merchant_id<<endl;
        return false;
    }
}


bool PointManage::pay_for_points_transfer(PersonalUser & uSelf,PointOrder & t_order) {

    float fee = t_order.get_payMoney();
    cout<<"fee:"<<fee<<endl;
    //确认支付
    string check;
    cout<<"check pay "+to_string(fee)+" : y or n"<<endl;
    cin>>check;
    if(check=="y"){
        // reduce personalUser's money
        float ubalance=uSelf.getMoney();
        if(ubalance>=fee){//! may be better;
//            uSelf.money = uSelf.money-fee;
            //reduce user's money
            uSelf.reduceMoney(fee);
            cout<<"Pay successful ; balance: "<< uSelf.getMoney()<<endl;
            // change status of order
            t_order.change_orderStatus(2);
            //存储于系统文件
            t_order.writeTo_Sys_Payed_File();
            //存储于用户已支付订单文件
            t_order.writeTo_User_Payed_File();
            //!从用户未支付订单文件中删除

            // add sysUser's money
            systemUser sysUser;
            sysUser.addMoney(fee);
//            sysUser.changeMoneyFlag=true;
//            sysUser.money.add(fee);

            //reduce user's point
            uSelf.PointsAccount.search_by_Merchant_id(t_order.getOutMerchant_id()).reducePoint(t_order.getPoint());
            //覆盖文件
            uSelf.PointsAccount.write_allPointData("../Data/User/Point/"+uSelf.get_user_id());

            return true;
        }
        else {
            cout<<"no enough money! Balance: "<<ubalance<<endl;
            return false;
        }
    }
    else
        return false;
}



//void PointManage::transfer_user_user(PointOrder &t_order) {
//    //transfer points
//    int t_point=t_order.getPoint();
//    //减积分
//    UserPoints tmp_out;
//    tmp_out = t_order.get_ac_out();
//    tmp_out.reducePoint(t_point);
//
//    //扣款
//
//
//    //加积分
//    UserPoints tmp_in;
//    tmp_in = t_order.get_ac_in();
//    tmp_in.addPoint(t_point);
//
//    //支付
//
//}








