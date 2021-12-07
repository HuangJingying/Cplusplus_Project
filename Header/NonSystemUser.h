//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_NONSYSTEMUSER_H
#define BIGHOMEWORK_NONSYSTEMUSER_H

#include "User.h"
#include "Info.h"
#include "Money.h"
//非系统角色基类：继承角色基类
class NonSystemUser:public User{
public:
    NonSystemUser(){};
    NonSystemUser(string _user_id):User(_user_id){};
    NonSystemUser(string _user_id,string _userName):User(_user_id,_userName){};

    //管理基本信息
    void changeInfo();
    void setInfo();
    void showInfo(){info.showInfo();}
    bool load_info(){info.readFromFIle(infoFile);}

protected:
    void set_info_file(string filename){infoFile=filename;};

private:
    Info info;//基本信息
    string infoFile;
};


#endif //BIGHOMEWORK_NONSYSTEMUSER_H
