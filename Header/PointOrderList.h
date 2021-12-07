//
// Created by jingying huang on 2020/5/12.
//

#ifndef BIGHOMEWORK_POINTORDERLIST_H
#define BIGHOMEWORK_POINTORDERLIST_H

#include "PointOrder.h"
//#include <vector>
class PointOrderList {
public:
    void showOrder();
    void showOrderFile();
    bool load_order(string filename);
//    int getSize(){return orderList.size();}

    bool process_payed_orderList();
    bool show_removeList(vector <PointOrder> & reList);
    friend class ProcessOrder;
private:
    vector <PointOrder> orderList;//订单列表



};


#endif //BIGHOMEWORK_POINTORDERLIST_H
