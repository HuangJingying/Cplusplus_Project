cmake_minimum_required(VERSION 3.15)
project(bigHomework)

set(CMAKE_CXX_STANDARD 14)

add_executable(bigHomework main.cpp
        Header/UserPoints.cpp Header/UserPoints.h
        Header/PointsAccount.cpp Header/PointsAccount.h
        Header/Money.cpp Header/Money.h
        Header/User.cpp Header/User.h
        Header/NonSystemUser.cpp Header/NonSystemUser.h
        Header/Info.cpp Header/Info.h
        Header/PersonalUser.cpp Header/PersonalUser.h
        Header/PointManage.cpp Header/PointManage.h
        Header/MerchantUser.cpp Header/MerchantUser.h
        Header/PointOrder.cpp Header/PointOrder.h
        Header/Product.cpp Header/Product.h
        Header/ProductList.cpp Header/ProductList.h
        Header/Order.cpp Header/Order.h
        Header/pointOrder.cpp Header/pointOrder.h
        Header/PointOrderList.cpp Header/PointOrderList.h
        Header/systemUser.cpp Header/systemUser.h
        Header/ProcessOrder.cpp Header/ProcessOrder.h
        Header/PointTransact.cpp Header/PointTransact.h
        Header/ProductOrder.cpp Header/ProductOrder.h
        Header/ProductManage.cpp Header/ProductManage.h
        Header/MerchantManage.cpp Header/MerchantManage.h
        Header/PersonalUserManage.cpp Header/PersonalUserManage.h
        )