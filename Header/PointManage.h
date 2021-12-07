//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_POINTMANAGE_H
#define BIGHOMEWORK_POINTMANAGE_H
#include "PointsAccount.h"
#include "PersonalUser.h"
#include "MerchantUser.h"
#include "PointOrder.h"
#include "PointOrder.h"
#include "systemUser.h"

class PointManage {
public:

    //用户申请积分转换，形成订单；
    bool apply_points_transfer(PointOrder & t_order,PersonalUser & uSelf,int num_point,string in_merchant_id,
            string out_merchant_id);
    //用户支付手续费
    bool pay_for_points_transfer(PersonalUser & uSelf,PointOrder & t_order);

};




#endif //BIGHOMEWORK_POINTMANAGE_H
