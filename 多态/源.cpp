//下面是用于Brass Account支票账户的信息：
//客户姓名；
//账号；
//当前结余。
//下面是可以执行的操作：
//创建账户；
//存款；
//取款；
//显示账户信息。
//
//Pontoon银行希望Brass Plus支票账户包含Brass Account的所有信息及如下信息：
//透支上限；
//透支贷款利率；
//当前的透支总额。
//不需要新增操作，但有两种操作的实现不同：
//对于取款操作，必须考虑透支保护；
//显示操作必须显示Brass Plus账户的其他信息。
#include"brass.hpp"
//int main()
//{
//	Brass dom("Dominic Banker", 11224, 4183.45);
//	BrassPlus dot("Dorothy Banker", 12118, 2592.00);
//	Brass& bl_ref = dom;
//	Brass& b2_ref = dot;
//	bl_ref.ViewAcct(); //use Brass::ViewAcct();
//	b2_ref.ViewAcct(); //useBrass::ViewAcct();
//}
int main()
{
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
}