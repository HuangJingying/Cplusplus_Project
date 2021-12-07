//
// Created by jingying huang on 2020/5/11.
//

#include "Info.h"
#include <fstream> //for ifstream
#include <string>
#include <iostream>
#include <sstream>
bool Info::setInfo() {
    string _mobile_phone,_sex;
    int _years;
    cout<<"Input: string mobile_phone(11), string sex(male/female), int years"<<endl;
    cin>>_mobile_phone>>_sex>>_years;

    if(_mobile_phone.size()==11)
        mobile_phone=_mobile_phone;
    else{
        cout<<"Please input right mobile phone(11)."<<endl;
        return false;
    }
//    if(sex=="female"||sex=="male")
        sex=_sex;
//    else{
//        cout<<"Please input right sex(male/female)."<<endl;
//        return false;
//    }
//    if(_years<120&&_years>0)
        years=_years;
//    else{
//        cout<<"Please input right years(0-120)."<<endl;
//        return false;
//    }
    return true;
}
void Info::changeInfo() {
    //string _mobile_phone, string _sex,string _birthday,string _years
    int choice=0;
    string str;
    int y;
    do{
        cout<<"What would you like to change?\n1. mobile_phone\n2. sex\n3. years\n4. Exit"<<endl;
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Please input mobile_phone(string,11):"<<endl;
                cin>>str;
                mobile_phone=str;
                continue;
            case 2:
                cout<<"Please input sex(male/female)."<<endl;
                cin>>str;
                sex=str;
                continue;
            case 3:
                cout<<"Please input years(0-120)."<<endl;
                cin>>y;
                years=y;
                continue;
        }
    }while(choice>=4);
}

bool Info::writeToFile(string filename) {
    ofstream writeFile;
    writeFile.open(filename);
    if (!writeFile)
    {
        cout<<"no such file: "+filename<<endl;
        return false;
//        writeFile.open(moneyFilename);
    }
    //添加 信息 数据到文件尾
    writeFile<<mobile_phone<<" "<<sex<<" "<<years<<endl;;
    writeFile.close();
    return true;
}


bool Info::readFromFIle(string filename) {
    ifstream readFile;
    readFile.open(filename);
    if (!readFile.is_open())
    {
        cout<<"Could not open "+filename+"\n";
        return false;
    }
    while(readFile.good()){    //逐行读取
        readFile>>mobile_phone>>sex>>years;
    }
    readFile.close();
    return true;
}
void Info::showInfo() const {
    cout<<" mobile_phone:"<<mobile_phone<<" sex:"<<sex<<" years:"<<years<<endl;
}



