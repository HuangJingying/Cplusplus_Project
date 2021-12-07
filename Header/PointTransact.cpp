//
// Created by jingying huang on 2020/5/24.
//

#include "PointTransact.h"
#include "MerchantUser.h"
#include <iostream>
using namespace std;

void PointTransact::pay_for_productOrder(ProductOrder & t_order) {
    t_order.process_unPay_order();
}

bool PointTransact::apply_product_transact(ProductOrder & t_order,PersonalUser &uSelf,string merchant_id) {
    string filename="../Data/Merchant/Product/"+merchant_id;
    MerchantUser merUser(merchant_id);
    ProductList a_pList(filename);
    a_pList.showOnList();
    string product_id;
    int num;
    cout<<"Input product_id,Number of products you want:"<<endl;
    cin>>product_id>>num;
    if(a_pList.if_product_exist(product_id)){
        //修改商品库存数据

        if(a_pList.getProduct(product_id).changeQuantity(-num)) {
            //生成订单
            Product t_product=a_pList.getProduct(product_id);
            t_order.set(num, t_product, uSelf, merUser);
            t_order.showProductOrder();//!cout
            //确认订单
            string check;
            cout << "check order: y or n" << endl;
            cin >> check;
            if (check == "y") {
                //写入文件
                t_order.writeTo_User_unPay_File();
                //支付
                pay_for_productOrder(t_order);
                //修改商品数量，写入文件
                a_pList.write_all_product_Data(filename);
                return true;
            } else
                return false;
        }
        else{
            return false;
        }

    }
    else{
        cout<<"no product_id:"<<product_id<<endl;
        return false;
    }
}



