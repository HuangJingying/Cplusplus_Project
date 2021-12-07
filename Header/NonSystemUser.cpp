////
//// Created by jingying huang on 2020/5/11.
////
//
#include "NonSystemUser.h"
#include <fstream> //for ifstream
#include <string>
#include <iostream>
#include <sstream>



void NonSystemUser::changeInfo() {
    info.changeInfo();
    info.writeToFile(infoFile);
}

void NonSystemUser::setInfo() {
    if(info.setInfo())
        info.writeToFile(infoFile);
}
