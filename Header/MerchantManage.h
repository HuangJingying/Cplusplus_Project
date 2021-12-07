//
// Created by jingying huang on 2020/5/26.
//

#ifndef BIGHOMEWORK_MERCHANTMANAGE_H
#define BIGHOMEWORK_MERCHANTMANAGE_H

#include "MerchantUser.h"
#include <fstream>
#include <iostream>
class MerchantManage {
public:
    bool show_a_MerchantInfo(string merchant_id);
    bool show_all_Merchant_Name(string filename="../Data/Merchant/registration");
    bool if_merchant_exist(string user_id);

private:
    vector <MerchantUser> mUser_list;

};


#endif //BIGHOMEWORK_MERCHANTMANAGE_H
