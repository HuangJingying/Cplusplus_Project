# Cpulsplus_Project

A project achieved by C++ for the course, C++ Programming



# Introduction

The purpose of this project is to build a point conversion and trading system, in which users can see their points under multiple merchants at the same time and convert points from different merchants when the conditions are met, in addition, merchants can sell points in the system for users to buy, and users can also trade points directly with each other.

In the actual production environment, the project system can be used as a third-party platform to connect with the cooperating merchants and realize the flexible conversion of the cooperating merchants' points, so as to broaden the use channels and value of their points. For example, airlines and hotels, which are upstream and downstream companies in the supply chain, can directly improve the market competitiveness of both companies and "attract" each other.

 There are three roles of using this system: platform, merchant and user, and two kinds of transaction scenarios are supported.

- Point conversion: Users can convert their points from different merchants in the platform.

- Points trading: Users can buy points sold by merchants with cash on the platform.

  

# Usage  (see user manual.pdf for details)

Run "main.cpp"  



# Test Case (see user Test_Cases.pdf for details)

- Register  

![img](https://github.com/HuangJingying/Cpulsplus_Project/blob/main/Test_Case.png)



 

# Function

There are three roles for using this system: platform, merchant, and user, and two transaction scenarios are supported.

- Points conversion: Users can convert their points under different merchants in the platform.

- Points transaction: Users can buy points sold by merchants with cash in the platform.

 The following is the detailed functional design for each of the three roles:

#### I. Functions of the platform

As a third party, the platform does not issue any points, but only merchant, user and points management and transaction.

1. Basic operation

- Login/logout login: the system has a default administrator account, and the password can be changed after login.

2. Merchant management

- Merchant query: You can query merchant information through your account.

- Statistics and display of all merchant accounts, the total number of merchants.

3. User Management

- User query: You can query the basic information and order information of users through their accounts.

- Displaying all user accounts and user names and counting the total number.

4. Order management.

- Querying all completed and unfinished orders.

5. Transaction.

- Generating transaction orders according to the point conversion applications submitted by users, submitting bills to merchants and deducting payments.

- Generating transaction orders according to the point conversion applications submitted by users, submitting bills to merchants and making payments.

6. Commodity management

- Product search: search product information by merchant account and product number.

- Statistics and display of all commodity information and the total number of commodities under a merchant account.

- Forced removal of commodities.

#### II. Functions of merchant account.

1. Basic functions

- Registration: After entering the platform and choosing to register, merchants need to fill in basic information, wait for the platform to pass the audit and automatically obtain authorization, i.e. successful registration.

- Logging in: after successful registration, merchants can log in to the platform according to their user names and passwords.

- Modification of basic information.

- Logging out.

2. User management

- merchants can import users' points.

- The number of user points can be queried through the user account.

3. Points commodity management

- Release goods: format: number of points-price-inventory.

Release the merchant's integral goods, such as 1000A company points - 10RMB - 100 copies in stock.

- Modify commodity information.

- Downlisting commodities.

4. Points conversion management

- Points value management: set the cash value of points

5. Funds management

- Recharge.

- Withdrawal.

- Checking balance.

#### III. Functions of users.

1. Basic functions

- Registration: after the user enters the platform, selects registration and fills in the basic information, the registration is successful.

- Logging in: after successful registration, users can log in to the platform according to their user names and passwords.

- Modify the basic information.

2. Points management

- Querying the points status of all their merchants (number of points, expiration time, etc.).

- Affiliated merchants' accounts.

- Deleting accounts of associated merchants.

3. Points conversion

- Convert points between different merchants: select "Transfer out account", "Transfer in account" and the number of points to be converted.

- View all completed orders.

- View all paid and unfinished orders.

4. Points transaction

- Purchase the points products on the shelves of merchants.

5. Funds Management

- Recharge.

- Withdrawal of funds.

- Checking balance.

- Payments.

# Programming Paradigm (see Program_Design_Info.pdf for details)

![Classes_diagram](https://github.com/HuangJingying/Cpulsplus_Project/blob/main/Classes_diagram.png)





