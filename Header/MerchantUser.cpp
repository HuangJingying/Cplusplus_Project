//
// Created by jingying huang on 2020/5/11.
//

#include "MerchantUser.h"
#include <iostream>
#include <string>
using namespace std;
MerchantUser::MerchantUser(string _user_id) :NonSystemUser(_user_id){
    setMoneyFilename("../Data/Merchant/Money/" + _user_id);
    productList.setProductFilename("../Data/Merchant/Product/" + get_user_id());
    set_info_file("../Data/Merchant/Info/" + get_user_id());
}

bool MerchantUser::load_product_data() {
    if (sellApproveFlag){
        return productList.load_all_product_Data("../Data/Merchant/Product/" + get_user_id());
    }
    else{
        cout<<"This merchant have NO Selling Product Authority!"<<endl;
        return false;
    }
}

bool MerchantUser::add_a_product() {
    if (sellApproveFlag){
        int point=0;int _price=0;int _quantity=0;
        bool _ifListed=false;
        cout<<"Please input:point,_price,_quantity, _ifListed(1/0)"<<endl;
        cin>>point>>_price>>_quantity>> _ifListed;
        return productList.add_a_product(point,_price,_quantity, _ifListed);
    }
    else{
        cout<<"This merchant have NO Selling Product Authority!"<<endl;
    }
}


bool MerchantUser::changeProduct(string product_id) {
//    Product aProduct=productList.getProduct(product_id);
    return productList.changeProduct(product_id);

}

bool MerchantUser::write_price_data(string filename, float _price) {
    ofstream f;
    f.open(filename);
    if(_price>0){
        f<<_price;
        f.close();
        return true;
    }
    cout<<"Price must >0"<<endl;
    f.close();
    return false;
}

bool MerchantUser::set_point_price(float _price) {
    string filename="../Data/Merchant/Price/"+get_user_id();
    return write_price_data(filename,_price);
}
