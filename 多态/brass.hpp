#pragma once
// Brass Account Class
#include<iostream>
using namespace std;
// 格式化相关定义
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
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

class Brass
{
private:
	std::string fullName;
	long acctNum;
	double balance;
public:
	Brass(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0)
		:fullName(s), acctNum(an), balance(bal)
	{
	}
	void Deposit(double amt);//​存款操作，增加账户余额。
	virtual void Withdraw(double amt)//取款
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

	double Balance() const//返回当前账户余额。
	{
		return balance;
	}
	virtual void ViewAcct() const//​查看账户详细信息​
	{
		cout << "父类ViewAcct()" << endl;
		// 设置金额显示格式
		format initialState = setFormat();
		precis prec = cout.precision(2);

		cout << "客户姓名: " << fullName << endl;
		cout << "账户号码: " << acctNum << endl;
		cout << "账户余额: $" << balance << endl;

		restore(initialState, prec); // 恢复原始格式
	}
	virtual ~Brass() {}
};

class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank = 0;
	//透支上限；
	//透支贷款利率；
	//当前的透支总额。
public:
	BrassPlus(const std::string& s = "Nullbody", long an = -1,
		double bal = 0.0, double ml = 500,
		double r = 0.11125)
		:Brass(s, an, bal), maxLoan(ml), rate(r), owesBank(0.0)
	{
	
	}
	BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125)
		:Brass(ba), maxLoan(ml), rate(r),owesBank(0.0)
	{
	
	}

	virtual void ViewAcct()const//​查看账户详细信息​
	{
		cout << "子类ViewAcct()" << endl;
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
	virtual void Withdraw(double amt)//​查看账户详细信息​
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

	void ResetMax(double m) { maxLoan = m; }
	void ResetRate(double r) { rate = r; };
	void ResetOwes() { owesBank = 0; }
};

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "错误：不允许存入负金额；"
		<< "存款操作已取消。\n";
	else
		balance += amt;
}

//读到了3．演示虚方法的行为