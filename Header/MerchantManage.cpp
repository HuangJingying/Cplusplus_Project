//
// Created by jingying huang on 2020/5/26.
//

#include "MerchantManage.h"

bool MerchantManage::show_a_MerchantInfo(string merchant_id) {
    MerchantUser mUser(merchant_id);
    mUser.load_info();
    mUser.showInfo();
}

bool MerchantManage::show_all_Merchant_Name(string filename) {
    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"could not open registration file\n";
        return false;
    };
    string user_id, username, password;
    while(f.good()){//!!!!!how to deal with the last line
        f>>user_id>>username>>password;
        if(!if_merchant_exist(user_id)){
            cout<<user_id<<' '<<username<<endl;//统计并显示所有商户账号
            MerchantUser mUser(user_id);
            mUser_list.push_back(mUser);
        }
    }
    cout<<"Total:"<<mUser_list.size()<<endl;
    f.close();
}

bool MerchantManage::if_merchant_exist(string user_id) {
    for(int i=0;i<mUser_list.size();i++){
        if(mUser_list[i].get_user_id()==user_id){
            //productList[i].showProduct();
            return true;
        }
    }
    return false;
}
