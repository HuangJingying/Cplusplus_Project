//
// Created by jingying huang on 2020/5/26.
//

#ifndef BIGHOMEWORK_PERSONALUSERMANAGE_H
#define BIGHOMEWORK_PERSONALUSERMANAGE_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;
class PersonalUserManage {
public:
    //for system
    bool show_all_User_Name(string filename="../Data/User/registration");
    void show_a_user_info(string user_id);
    void show_a_user_all_point(string user_id);
    //for merchant
    //以导入其用户的积分
    bool add_a_new_user_point(string merchant_id, string user_name,int point,string expireData);
    //查询已经关联本商户的所有用户账户
    //查询某一用户在本商户的积分数量
//    void show_a_user_raw_point(string merchant_id,string user_id);
    void show_a_user_now_point(string merchant_id,string user_id);
//    void show_a_user_transfer_point(string merchant_id,string user_id);
//    void show_a_user_bought_point(string merchant_id,string user_id);




};


#endif //BIGHOMEWORK_PERSONALUSERMANAGE_H
