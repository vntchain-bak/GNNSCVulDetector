#include "vntlib.h"

KEY uint256 res = 100;

typedef struct fallback4 {
    uint256 balance;      
    string nickName;      
} Account;

 
KEY mapping(address, Account) accounts;

constructor Fallback5() {}

uint256 getRes(address addr) {
    accounts.key = addr;

    uint256 balance = accounts.value.balance;
    Require(balance > 0, "balance > 0");

    while(balance > 0) {
        res = U256_Add(res, balance);
    }

    return res;
}

MUTABLE
void test1(){
    uint256 res = getRes(GetSender());
    PrintUint256T("uint256", res);
}

 
_(){
   test1();
}