//
// Created by jingying huang on 2020/5/12.
//

#ifndef BIGHOMEWORK_PRODUCT_H
#define BIGHOMEWORK_PRODUCT_H

#include <string>
#include <iostream>
using namespace std;
//商品类
class Product{
public:
    Product(){};
    Product(string _produce_id,int _point=0,float _price=0,int _quantity=0,bool _ifListed=false);
    void onListed(){ifListed=true;};//上架;
    void offListed(){ifListed=false;};//下架;
    bool changeQuantity(int i);;//修改数量
    void setPrice(float i){ price=i;};//修改价格
    void setQuantity(int i){quantity=i;};//修改数量
    void setPoint(int p){ point=p;}//修改积分数量

    string getProduct_id(){return product_id;};
    bool getIfListed(){return ifListed;};
    int getPoint(){return point;};
    int getQuantity(){return quantity;};
    float getPrice(){return price;};

    void showProduct();
    bool write_a_product(string filename);
    friend ostream & operator<<(ostream & out, const Product & c);
private:
    string product_id;
    bool ifListed;//是否上架;
    int point;//积分数量
    float price;//商品价格
    int quantity;//商品数量

};

#endif //BIGHOMEWORK_PRODUCT_H
