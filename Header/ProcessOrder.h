//
// Created by jingying huang on 2020/5/22.
//

#ifndef BIGHOMEWORK_PROCESSORDER_H
#define BIGHOMEWORK_PROCESSORDER_H


#include "PointOrderList.h"
#include <vector>
using namespace std;

class ProcessOrder {
public:
    ProcessOrder()= default;
    // for system
    bool load_waiting_order(string filename="../Data/System/u2u_order_list");
    bool process_payed_orderList(const char * filename);
    bool show_all_u2u_Payed_Order(string filename="../Data/System/u2u_order_list");;
//    bool show_all_m2u_Finish_Order(string filename="../Data/System/m2u_order_list_finish");
    bool show_all_u2u_Finish_Order(string filename="../Data/System/u2u_order_list_finish");;

    //for user
    bool show_aUser_u2u_Finish_Order(string user_id);
    bool show_aUser_u2u_Payed_Order(string user_id);
private:
    PointOrderList orderList;
};


#endif //BIGHOMEWORK_PROCESSORDER_H
