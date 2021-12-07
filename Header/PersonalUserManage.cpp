//
// Created by jingying huang on 2020/5/26.
//

#include "PersonalUserManage.h"
#include "Info.h"
//#include "UserPoints.h"
#include "PointsAccount.h"
#include "PersonalUser.h"
bool PersonalUserManage::show_all_User_Name(string filename) {
    ifstream f;
    f.open(filename);
    if (!f.is_open())
    {
        cout<<"could not open registration file "<<filename<<endl;
        return false;
    };
    string user_id, username, password;
    int i=0;
    while(f.good()){//!!!!!how to deal with the last line
        f>>user_id>>username>>password;
        if(!user_id.empty()){
            cout<<"user_id:"<<user_id<<" username"<<username<<endl;//统计并显示所有商户账号
            i++;
        }
    }
    cout<<"Total:"<<i<<endl;
    f.close();
    return true;
}

void PersonalUserManage::show_a_user_info(string user_id) {
    string filename="../Data/User/Info/"+user_id;
    Info a_info;
    if(a_info.readFromFIle(filename)){
        a_info.showInfo();
    }
}

void PersonalUserManage::show_a_user_all_point(string user_id) {
    string filename="../Data/User/Point/"+user_id;
    PointsAccount a_PointsAccount;
    a_PointsAccount.load_PointData(filename);
    a_PointsAccount.displayAllPoint();
}

void PersonalUserManage::show_a_user_now_point(string merchant_id, string user_id) {
    string filename="../Data/User/Point/"+user_id;
    PersonalUser a_PersonalUser(user_id);
    a_PersonalUser.load_PointData();
    a_PersonalUser.get_PointsAccount().search_by_Merchant_id(merchant_id).displayPoints();
}

bool PersonalUserManage::add_a_new_user_point(string merchant_id, string user_name,int point,string expireData) {
    ofstream f;
    string filename="../Data/Merchant/User_point/"+merchant_id;
    f.open(filename,ios::app);
//    if (!f.is_open())
////    {
////        cout<<"could not open file "<<filename<<endl;
//////        return false;
////    };
//!if usr_name exist, should return false
    f<<user_name<<' '<<point<<' '<<expireData<<endl;
    f.close();
    cout<<"Add successful."<<endl;
    return true;
}
