//
// Created by jingying huang on 2020/5/26.
//

#ifndef BIGHOMEWORK_PRODUCTMANAGE_H
#define BIGHOMEWORK_PRODUCTMANAGE_H

#include "MerchantUser.h"
#include <fstream>
#include <iostream>
using namespace std;
class ProductManage {
public:

    bool show_a_Merchant_all_Product(string merchant_id){
        MerchantUser mUser(merchant_id);
        mUser.load_product_data();
        mUser.show_all_product();
        cout<<"Total:"<<mUser.getProductSize()<<endl;
    }
    bool show_a_MerchantProduct(string merchant_id,string product_id){
        MerchantUser mUser(merchant_id);
        mUser.load_product_data();
        mUser.productList.getProduct(product_id).showProduct();
    }
    bool off_a_MerchantProduct(string merchant_id,string product_id){
        MerchantUser mUser(merchant_id);
        mUser.load_product_data();
        mUser.offListed(product_id);
//        mUser.productList.getProduct(product_id).offListed();
    }
};


#endif //BIGHOMEWORK_PRODUCTMANAGE_H
