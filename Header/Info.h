//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_INFO_H
#define BIGHOMEWORK_INFO_H
#include <string>
#include <iostream>

using namespace std;

class Info {
public:
    bool setInfo();
    void changeInfo();//修改基本信息
    void showInfo() const;
    bool writeToFile(string filename);
    bool readFromFIle(string filename);
private:
    string mobile_phone;
    string sex;
    int years;

};


#endif //BIGHOMEWORK_INFO_H
