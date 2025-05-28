// usebrass1.cpp -- testing bank account classes
// compile with brass.cpp
#include <iostream>
#include "brass.h"

int main()
{
    using std::cout;
    using std::endl;

    Brass Piggy("Porcelot Pigg", 381299, 4000.00);
    BrassPlus Hoggy("Horatio Hogg", 382288, 3000.00);
    Piggy.ViewAcct();
    cout << endl;
    Hoggy.ViewAcct();
    cout << endl;
    cout << "向Hogg账户存入1000美元：\n";
Hoggy.Deposit(1000.00);
cout << "新余额：$" << Hoggy.Balance() << endl;

cout << "从Pigg账户取出4200美元：\n"; 
Piggy.Withdraw(4200.00);
cout << "Pigg账户余额：$" << Piggy.Balance() << endl;

cout << "从Hogg账户取出4200美元：\n";
Hoggy.Withdraw(4200.00);
Hoggy.ViewAcct();  // 查看Hogg账户详情
	// std::cin.get();
    return 0; 
}
