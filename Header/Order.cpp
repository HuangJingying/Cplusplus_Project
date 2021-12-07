//
// Created by jingying huang on 2020/5/12.
//

#include "Order.h"


Order::Order(int Type) {
    order_time = time(0);// current date/time based on current system
    orderName=(1 == Type ? "u2u" : "m2u");
    order_id=to_string(order_time)+"_"+orderName;
    orderStatus=1;//默认订单状态1：未支付
}

Order::Order(string _order_id) {
    order_id=_order_id;
}
