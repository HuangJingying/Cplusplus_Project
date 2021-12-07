//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_POINTSACCOUNT_H
#define BIGHOMEWORK_POINTSACCOUNT_H

#include "UserPoints.h"
#include <vector>
using namespace std;
//积分账户:由多个userPoints用户积分类组成
class PointsAccount  {
public:
    PointsAccount()= default;//!
    void displayAllPoint() const;//显示该账户下所有积分
    void load_PointData(string filename);//读入已有积分数据
    bool write_allPointData(string filename);
    bool if_exist_merchant(string Merchant_id );//判断该商户是否关联
    UserPoints & search_by_Merchant_id(string Merchant_id);//!搜索关联商户
    bool addMerchant(string Merchant_id,string & inUsername,string &user_id);//关联商户账户
    bool deleteMerchant(string Merchant_id);//删除关联商户账户


private:
    vector <UserPoints> uPoints_list; //用户积分类列表
    vector <string> uMerchant_list; //用户先关联的商户，再增加该商户的积分（列表）
    void load_Point(string _merchant_id,float _price,string _expireDate,int p);
};


#endif //BIGHOMEWORK_POINTSACCOUNT_H
