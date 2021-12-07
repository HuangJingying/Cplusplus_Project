//
// Created by jingying huang on 2020/5/24.
//

#ifndef BIGHOMEWORK_POINTTRANSACT_H
#define BIGHOMEWORK_POINTTRANSACT_H

#include "ProductList.h"
#include "ProductOrder.h"
#include <string>
using namespace std;
class PointTransact {
public:
    bool apply_product_transact(ProductOrder & t_order,PersonalUser &uSelf,string merchant_id);
//    bool apply_product_transact(ProductOrder & t_order,ProductList & a_pList, string product_id,int num=1);
    void pay_for_productOrder(ProductOrder & t_order);
};


#endif //BIGHOMEWORK_POINTTRANSACT_H
