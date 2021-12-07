//
// Created by jingying huang on 2020/5/12.
//

#ifndef BIGHOMEWORK_ORDER_H
#define BIGHOMEWORK_ORDER_H
#include <ctime>
#include <string>
#include <iostream>
using namespace std;
//订单类:个人用户下单，生成订单
class Order {
public:
    Order(int Type=1);;
    Order(string _order_id);;
    float get_payMoney(){return payMoney;};
    string get_order_id(){return order_id;};
    void set_payMoney(float p){payMoney=p;};
    int get_orderStatus(){return orderStatus;};
    void change_orderStatus(int status){orderStatus= status;}
private:
    string order_id;//订单编号
    time_t order_time; //交易时间；
    float payMoney;//支付金额,手续费
    int orderStatus;//交易状态：1：未支付；2：已支付；3：已完成；
    string orderName;

};


#endif //BIGHOMEWORK_ORDER_H
