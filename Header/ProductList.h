//
// Created by jingying huang on 2020/5/12.
//

#ifndef BIGHOMEWORK_PRODUCTLIST_H
#define BIGHOMEWORK_PRODUCTLIST_H

#include <vector>
#include "Product.h"
using namespace std;
//商品列表类：有多个商品类组成
class ProductList {
public:
    ProductList() {};

    ProductList(string _productFile);;

    ~ProductList();

    void setProductFilename(string _filename) { productFile = _filename; }

    bool add_a_product(int point = 0, int _price = 0, int _quantity = 0, bool _ifListed = false);//新增商品
    void showList();
    void showOnList();
    bool delete_a_product(string delete_id);//删除商品

    bool load_all_product_Data(string filename);

    bool write_all_product_Data(string filename);
//    bool write_a_produce_Data(string moneyFilename);

    //搜索商品
    bool if_product_exist(string product_id);

    Product &getProduct(string product_id);

    int getProductSize() { return productList.size(); }

    bool changeProduct(string product_id);

    void offListed(string product_id);

private:
    int produceNum = 0;
    vector<Product> productList;
    string productFile;
    bool ifChangedFlag = false;

};


#endif //BIGHOMEWORK_PRODUCTLIST_H
