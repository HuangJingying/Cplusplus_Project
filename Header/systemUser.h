//
// Created by jingying huang on 2020/5/22.
//

#ifndef BIGHOMEWORK_SYSTEMUSER_H
#define BIGHOMEWORK_SYSTEMUSER_H

#include "User.h"
#include "Money.h"
class systemUser :public User{
public:
    systemUser();
    systemUser(string _user_id);
    systemUser(string _user_id,string _userName);
    friend class PointManage;
    friend class ProductManage;
private:


};


#endif //BIGHOMEWORK_SYSTEMUSER_H
