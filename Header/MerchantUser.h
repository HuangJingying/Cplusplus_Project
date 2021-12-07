//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_MERCHANTUSER_H
#define BIGHOMEWORK_MERCHANTUSER_H

#include "NonSystemUser.h"
#include "Money.h"
#include "ProductList.h"
#include "PointOrderList.h"

//商户用户：继承非系统角色基类
class MerchantUser:public NonSystemUser{
public:
    MerchantUser(){};
    MerchantUser(string _user_id);
    //积分商品管理
    bool load_product_data();
    bool add_a_product();
    void show_all_product(){productList.showList();};
    bool changeProduct(string product_id);
    int getProductSize(){return productList.getProductSize();}
    void offListed(string product_id){productList.offListed(product_id);}
    bool set_point_price(float _price);

    friend class ProductManage;

private:
    bool sellApproveFlag=true;//授权的商户可以销售商品；
    ProductList productList;//商品列表
    bool write_price_data(string filename,float _price);
};


#endif //BIGHOMEWORK_MERCHANTUSER_H
