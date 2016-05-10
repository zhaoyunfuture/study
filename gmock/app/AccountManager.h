 #include <string> 

 #include "Account.h" 

 class AccountManager 
 { 
 public: 
     //通过账户号，找到对应的用户
    virtual Account findAccountForUser(const std::string& userId) = 0; 
    //更新用户的信息这里
    virtual void updateAccount(const Account& account) = 0; 
 }; 
