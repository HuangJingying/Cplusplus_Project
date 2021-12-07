//
// Created by jingying huang on 2020/5/12.
//

#include "ProductList.h"
#include "Product.h"
#include <string>
#include <iostream>
#include <fstream>
using  namespace std;

bool ProductList::add_a_product(int _point,int _price,int _quantity,bool _ifListed) {
    produceNum=produceNum+1;
    string produce_id=to_string(produceNum);//! may better
    Product aProduce(produce_id,_point,_price,_quantity,_ifListed);
    productList.push_back(aProduce);
//    ifChangedFlag=true;
    aProduce.write_a_product(productFile);
    return true;
}

void ProductList::showList() {
    for(int i=0;i<productList.size();i++){
        productList[i].showProduct();
    }
}

void ProductList::showOnList() {
    for(int i=0;i<productList.size();i++){
        if(productList[i].getIfListed())
            productList[i].showProduct();
    }
}
bool ProductList::delete_a_product(string delete_id) {
    for(int i=0;i<productList.size();i++){
        if(productList[i].getProduct_id()==delete_id){
            productList.erase(productList.begin()+i);
            ifChangedFlag=true;
            produceNum=produceNum-1;
            return true;
        }
    }
    cout<<"no Product ID:"<<delete_id<<endl;
    return false;
}

bool ProductList::if_product_exist(string product_id) {
    for(int i=0;i<productList.size();i++){
        if(productList[i].getProduct_id()==product_id){
            //productList[i].showProduct();
            return true;
        }
    }
    return false;
}

bool ProductList::write_all_product_Data(string filename) {
//    for(int i=0;i<productList.size();i++){
//        productList[i].write_a_product(moneyFilename);
//    }
//    return false;
//! similar to bool UserPoints::writeToFile(string user_id)
//! similar to bool PointOrder::writeToFile(string moneyFilename)
    ofstream writeFile;
    writeFile.open(filename);//覆盖内容
    if (!writeFile)
    {
        cout<<"no such file: "+filename<<endl;
        return false;
//        writeFile.open(moneyFilename);
    }
    //添加 商品 数据到文件尾
    for(int i=0;i<productList.size();i++) {
//        writeFile << product_id << ' ' << point << ' ' << price << ' ' << quantity << ' ' << ifListed << "\n";
        writeFile<<productList[i];
    }
    writeFile.close();
    return true;
}

bool ProductList::load_all_product_Data(string filename) {
//! similar to bool PointOrderList::load_order(string moneyFilename) {
//! may should change due to similar to : PointsAccount::addMerchant(string Merchant_id,string & inUsername,string &user_id) {
    ifstream readFile;
    readFile.open(filename);
    if (!readFile.is_open())
    {
        cout<<"Could not open "+filename+"\n";
        return false;
    }
    string product_id;
    int _point;
    float _price;
    int _quantity;
    bool _ifListed;
    while(readFile.good()){    //逐行读取
        readFile>>product_id>>_point>>_price>>_quantity>>_ifListed;//!something wrong,read the last line twice
        if (product_id.empty())
            break;
//        cout<<"read produce_id:"<<product_id<<';'<<_point<<';'<<_price<<';'<<_quantity<<';'<<_ifListed<<endl;//! delete

        //! if order is already in orderList, should continue
        if(!if_product_exist(product_id)) {//! may not a good way
            Product aProduce(product_id, _point, _price, _quantity, _ifListed);
            productList.push_back(aProduce);
        }
    }
    readFile.close();
    produceNum=productList.size();
//    showList();//!cout,should delete
    return true;

}

Product & ProductList::getProduct(string product_id) {
    for(int i=0;i<productList.size();i++) {
        if (productList[i].getProduct_id() == product_id) {
            return productList[i];
        }
    }
    cout<<"no product_id:"<<product_id<<endl;//!may need a error
}

bool ProductList::changeProduct(string product_id) {
    ifChangedFlag=true;
    int choice;
    float i;int p;
    string if_listed;
    cout<<"What would you like to change?\n1. if listed(1/0)\n2. Price\n3. Quantity\n4. Point\n5. Save and Quit"<<endl;
    cin>>choice;
    switch (choice){
        case 1:
            cout<<"Input true/false:"<<endl;
            cin>>if_listed;
            if(if_listed=="true") getProduct(product_id).onListed();else getProduct(product_id).offListed();
            break;
        case 2:
            cout<<"Input Price(float):"<<endl;
            cin>>i;
            getProduct(product_id).setPrice(i);
            break;
        case 3:
            cout<<"Input Quantity(float):"<<endl;
            cin>>i;
            getProduct(product_id).setQuantity(i);
            break;
        case 4:
            cout<<"Input Point(int):"<<endl;
            cin>>p;
            getProduct(product_id).setPoint(p);
            break;
        case 5:
            break;
    }
    return true;
}

ProductList::~ProductList() {
    if (ifChangedFlag) {
        write_all_product_Data(productFile);
    }
}

ProductList::ProductList(string _productFile) {
    productFile = _productFile;
    load_all_product_Data(productFile);
}

void ProductList::offListed(string product_id) {
    ifChangedFlag = true;
    getProduct(product_id).offListed();
}



