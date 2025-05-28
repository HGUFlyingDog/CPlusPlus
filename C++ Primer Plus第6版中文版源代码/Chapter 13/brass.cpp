// brass.cpp -- 银行账户类方法实现
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

// 格式化相关定义
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

// Brass类方法实现

Brass::Brass(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Brass::Deposit(double amt)
{
    if (amt < 0)
        cout << "错误：不允许存入负金额；"
             << "存款操作已取消。\n";
    else
        balance += amt;
}

void Brass::Withdraw(double amt)
{
    // 设置金额显示格式为固定小数点
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0)
        cout << "错误：取款金额必须为正数；"
             << "取款操作已取消。\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "错误：取款金额 $" << amt
             << " 超过账户余额。\n"
             << "取款操作已取消。\n";
    restore(initialState, prec);
}

double Brass::Balance() const
{
    return balance;
}

void Brass::ViewAcct() const
{
    // 设置金额显示格式
    format initialState = setFormat();
    precis prec = cout.precision(2);
    
    cout << "客户姓名: " << fullName << endl;
    cout << "账户号码: " << acctNum << endl;
    cout << "账户余额: $" << balance << endl;
    
    restore(initialState, prec); // 恢复原始格式
}

// BrassPlus类方法实现
BrassPlus::BrassPlus(const string & s, long an, double bal,
           double ml, double r) : Brass(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass & ba, double ml, double r)
           : Brass(ba)   // 使用隐式拷贝构造函数
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

void BrassPlus::ViewAcct() const
{
    // 设置金额显示格式
    format initialState = setFormat();
    precis prec = cout.precision(2);

    Brass::ViewAcct();   // 显示基类部分信息
    cout << "最高贷款额: $" << maxLoan << endl;
    cout << "当前欠款: $" << owesBank << endl;
    cout.precision(3);  // 设置利率显示格式为###.###
    cout << "贷款利率: " << 100 * rate << "%\n";
    
    restore(initialState, prec); 
}

void BrassPlus::Withdraw(double amt)
{
    // 设置金额显示格式
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal)
        Brass::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "银行预支: $" << advance << endl;
        cout << "财务费用: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    }
    else
        cout << "错误：超过信用额度。交易已取消。\n";
        
    restore(initialState, prec); 
}

format setFormat()
{
    // 设置固定小数点格式
    return cout.setf(std::ios_base::fixed, 
                std::ios_base::floatfield);
} 

void restore(format f, precis p)
{
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}