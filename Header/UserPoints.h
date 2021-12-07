//
// Created by jingying huang on 2020/5/10.
//

#ifndef BIGHOMEWORK_USERPOINTS_H
#define BIGHOMEWORK_USERPOINTS_H

#include <ctime>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

//用户积分账户：继承积分基类
class UserPoints{
public:
    UserPoints(string _merchant_id,float _price,string _expireDate,int p=0):
            point(p),merchant_id(_merchant_id),price(_price),expireDate(_expireDate){};//构造函数
    UserPoints()=default;
    string getMerchant_id(){return merchant_id;};
    float getPrice(){return price;};
    string getExpireData(){return expireDate;};
    void displayPoints()const;//显示积分所属商户，数量，过期时间,调用point.show?
    bool writeToFile(string user_id);//将point信息写入文件；

    friend ostream & operator<<(ostream & out, const UserPoints & c);

    int getPointNum()const {return point;};//获取积分数量
    void addPoint(int p){point += p;};//增加积分
    void reducePoint(int p){point -= p;};//减少积分

    bool load_price_data(string filename);
private:
    int point;//积分数量
    string merchant_id; //积分所属商户
    float price;//积分价格
    string expireDate;//积分过期时间;

};


#endif //BIGHOMEWORK_USERPOINTS_H
