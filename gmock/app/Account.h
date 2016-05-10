 #include <string> 

 class Account 
 { 
 private: 
    std::string accountId;  //账号
     
    long balance;           //存款 呃 还是叫余额吧

 public: 
    Account(); 

    Account(const std::string& accountId, long initialBalance); 

    //消费
    void debit(long amount); 

    //收入
    void credit(long amount); 

    //获取存款
    long getBalance() const; 

    //获取账号
    std::string getAccountId() const; 
 }; 
