//
// Created by jingying huang on 2020/5/11.
//

#include "PersonalUser.h"
#include <fstream> //for ifstream
#include <string>
#include <sstream>
#include <iomanip>      // std::get_time
#include <iostream>

PersonalUser::PersonalUser(string _user_id) :NonSystemUser(_user_id){
    setMoneyFilename("../Data/User/Money/" + _user_id);
    set_info_file("../Data/User/Info/" + get_user_id());
}
PersonalUser::PersonalUser(string _user_id, string _userName) :NonSystemUser(_user_id,_userName){
    setMoneyFilename("../Data/User/Money/" + _user_id);
    set_info_file("../Data/User/Info/" + get_user_id());
}
void PersonalUser::display() const {
    PointsAccount.displayAllPoint();
}
void PersonalUser::addMerchant(string Merchant_id) {
    string username=get_userName();
    string user_id=get_user_id();
    PointsAccount.addMerchant(Merchant_id,username,user_id);
}
void PersonalUser::deleteMerchant(string Merchant_id) {
    PointsAccount.deleteMerchant(Merchant_id);
    PointsAccount.write_allPointData("../Data/User/Point/" + get_user_id());
}

void PersonalUser::load_PointData() {
    PointsAccount.load_PointData("../Data/User/Point/" + get_user_id());
}



