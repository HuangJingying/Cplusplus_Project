//
// Created by jingying huang on 2020/5/22.
//

#include "systemUser.h"
#include <fstream> //for ifstream
#include <string>
#include <iostream>
#include <sstream>

systemUser::systemUser():User(){
    setMoneyFilename("../Data/System/money");
}

systemUser::systemUser(string _user_id) : User(_user_id) {
    setMoneyFilename("../Data/System/money");
//    money.load_a_float_Data(moneyFilename);
}
systemUser::systemUser(string _user_id, string _userName) : User(_user_id, _userName) {
//    money.load_a_float_Data(moneyFilename);
    setMoneyFilename("../Data/System/money");

}
//systemUser::~systemUser() {
//    if(changeMoneyFlag)
//        money.write_a_float_Data(moneyFilename);
//}


