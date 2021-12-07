//
// Created by jingying huang on 2020/5/12.
//

#include "Product.h"
#include <iostream>
#include <fstream> //for ifstream
void Product::showProduct() {
    cout<<"Produce ID:"<<product_id<<" Point:"<<point<<" Price:"<<price<<" Quantity:"<<quantity<<
    " ifListed:"<<ifListed<<endl;
}

bool Product::write_a_product(string filename) {
//! similar to bool UserPoints::writeToFile(string user_id)
//! similar to bool PointOrder::writeToFile(string moneyFilename)
        ofstream writeFile;
        writeFile.open(filename,ios::app);//新增内容
        if (!writeFile)
        {
            cout<<"no such file: "+filename<<endl;
            return false;
//        writeFile.open(moneyFilename);
        }
        //添加 商品 数据到文件尾
        writeFile<<product_id<<' '<<point<<' '<<price<<' '<<quantity<<' '<<ifListed<<"\n";
        writeFile.close();
        return true;
}


//bool Product::write_a_candidate_product(string filename,string merchant_id) {
////! similar to bool UserPoints::writeToFile(string user_id)
////! similar to bool PointOrder::writeToFile(string moneyFilename)
//    ofstream writeFile;
//    writeFile.open(filename,ios::app);//新增内容
//    if (!writeFile)
//    {
//        cout<<"no such file: "+filename<<endl;
//        return false;
////        writeFile.open(moneyFilename);
//    }
//    //添加 商品 数据到文件尾
//    writeFile<<product_id<<' '<<merchant_id<<' '<<point<<' '<<price<<' '<<quantity<<"\n";
//    writeFile.close();
//    return true;
//}

ostream & operator<<(ostream &out, const Product &c) {
    out<<c.product_id<<' '<<c.point<<' '<<c.price<<' '<<c.quantity<<' '<<c.ifListed<<"\n";
    return out;
}

bool Product::changeQuantity(int i) {
    quantity=quantity+i;
    if(quantity+i>=0){
        quantity=quantity+i;
        return true;
    }
    else{
        cout<<"Too much number"<<endl;
        return false;
    }
}

Product::Product(string _produce_id, int _point, float _price, int _quantity, bool _ifListed) {
    product_id=_produce_id;
    ifListed=_ifListed;
    point=_point;
    price=_price;
    quantity=_quantity;
}
