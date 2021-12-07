//
// Created by jingying huang on 2020/5/11.
//

#ifndef BIGHOMEWORK_MONEY_H
#define BIGHOMEWORK_MONEY_H

#include <string>
using namespace std;
//余额类
class Money {
public:

    Money(float b=0){balance=b;};
    float get(){return balance;};
    void add(float m){balance=balance+m;};
    bool reduce(float m);
//    void set(float m){balance=m;}; //设置余额，用于从文件中读取余额值调用
    bool load_a_float_Data(string filename);
    bool write_a_float_Data(string filename);
private:
    float balance;//数量
};


#endif //BIGHOMEWORK_MONEY_H
