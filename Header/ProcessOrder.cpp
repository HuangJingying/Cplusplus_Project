//
// Created by jingying huang on 2020/5/22.
//

#include "ProcessOrder.h"
#include <fstream> //for ifstream
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;
bool ProcessOrder::load_waiting_order(string filename) {
    orderList.load_order(filename);

}

bool ProcessOrder::process_payed_orderList(const char * filename){
    orderList.process_payed_orderList();
    if( remove( filename) != 0 ){
        cout<<"Error: remove payed order list fail!"<<endl;
    }
}

bool ProcessOrder::show_aUser_u2u_Finish_Order(string user_id) {
    orderList.load_order("../Data/User/Order/Transfer/Finish_Order/"+user_id);
    orderList.showOrderFile();
}

bool ProcessOrder::show_aUser_u2u_Payed_Order(string user_id) {
    orderList.load_order("../Data/User/Order/Transfer/Payed_Order/"+user_id);
    PointOrderList orderListFinish;
    orderListFinish.load_order("../Data/User/Order/Transfer/Finish_Order/"+user_id);
    orderList.show_removeList(orderListFinish.orderList);
}

//bool ProcessOrder::show_all_m2u_Finish_Order(string filename) {
//    ifstream readFile;
//    readFile.open(filename);
//    if (!readFile.is_open())
//    {
//        cout<<"no such file: "+filename<<endl;
//        return false;
//    }
//    string order_id,mer_in_id,product_id,user_id;
//    bool status;
//    float price;
//    int num;
//    int i=0;
//    while(!readFile.eof()) {
//        readFile >> order_id >> mer_in_id>> product_id
//                >> price >>num >>user_id>>status;
//        if (!order_id.empty()){;
//            i++;
////            cout<<"Order ID:"<<order_id <<" Merchant ID:"<< mer_in_id <<" Product ID:"<< product_id
////                <<" Price:"<< price <<" Number:"<< num<<" User ID:"<< user_id<<endl;
//        }
//    }
//    cout<<i<<endl;
//    readFile.close();
//    return true;
//}

bool ProcessOrder::show_all_u2u_Finish_Order(string filename) {
    load_waiting_order(filename);
//        orderList.showOrderFile();
}

bool ProcessOrder::show_all_u2u_Payed_Order(string filename) {
    load_waiting_order(filename);
//        orderList.showOrderFile();
}




