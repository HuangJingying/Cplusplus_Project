//
// Created by jingying huang on 2020/5/24.
//

#ifndef BIGHOMEWORK_PRODUCTORDER_H
#define BIGHOMEWORK_PRODUCTORDER_H

#include "Order.h"
#include "Product.h"
#include "PersonalUser.h"
#include "MerchantUser.h"
class ProductOrder :public Order{
public:
    ProductOrder();;
    void set(int p,Product & _aProduct,PersonalUser & _user_out,MerchantUser & _user_in);;
    //将订单写入文件
    bool writeToFile(string filename);
    bool writeTo_User_unPay_File();
    bool writeTo_User_Finish_File();
    bool writeTo_Sys_Finish_File();

    void showProductOrder();
    bool process_unPay_order();
private:
    int num;//购买数量
    Product aProduct;//购买商品
    PersonalUser user_out;//支付用户
    MerchantUser mer_in;//收入商户


};


#endif //BIGHOMEWORK_PRODUCTORDER_H
