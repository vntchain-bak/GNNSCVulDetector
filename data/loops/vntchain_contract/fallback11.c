#include "vntlib.h"

KEY uint32 count = 10;

constructor Fallback1(){}

 
CALL uint32 test(CallParams params, uint32 amount);
CallParams params = {Address("0xaaaa"), U256(10000), 100000};   

MUTABLE
uint64 test1(uint32 amount){
    test(params, amount);
    return amount;
}

MUTABLE
uint64 test2(uint32 amount){
    PrintStr("Fallback", "Fallback");
    test1(amount);
    uint32 res = amount + 1;
    return res;
}

MUTABLE
void test3(){
    string s = "Input data error";
    PrintStr("ERROR:", s);
}

_(){
   test3();
}
