// usebrass2.cpp -- 多态特性演示
// 需与 brass.cpp 一起编译
#include <iostream>
#include <string>
#include "brass.h"
const int CLIENTS = 4;

int main()
{
   using std::cin;
   using std::cout;
   using std::endl;

   Brass * p_clients[CLIENTS];  // 基类指针数组
   std::string temp;            // 临时存储姓名
   long tempnum;                // 临时存储账号
   double tempbal;              // 临时存储余额
   char kind;                   // 账户类型选择

   // 输入客户信息
   for (int i = 0; i < CLIENTS; i++)
   {
       cout << "请输入客户姓名：";
       getline(cin,temp);
       cout << "请输入账户号码：";
       cin >> tempnum;
       cout << "请输入初始余额：$";
       cin >> tempbal;
       cout << "选择账户类型 (1-普通账户，2-高级账户)：";
       while (cin >> kind && (kind != '1' && kind != '2'))
           cout << "请输入1或2：";
       if (kind == '1')
           p_clients[i] = new Brass(temp, tempnum, tempbal);
       else
       {
           double tmax, trate;
           cout << "请输入透支额度：$";
           cin >> tmax;
           cout << "请输入贷款利率（小数形式）：";
           cin >> trate;
           p_clients[i] = new BrassPlus(temp, tempnum, tempbal,
                                        tmax, trate);
        }
        while (cin.get() != '\n')  // 清除输入缓冲
            continue;
   }

   // 显示所有账户信息
   cout << endl;
   for (int i = 0; i < CLIENTS; i++)
   {
       p_clients[i]->ViewAcct();  // 多态调用
       cout << endl;
   }

   // 释放内存
   for (int i = 0; i < CLIENTS; i++)
   {
       delete p_clients[i];
   }
   cout << "程序结束。\n";

   /* 如需保持窗口打开
   if (!cin)
      cin.clear();
   while (cin.get() != '\n')
      continue;
   */
   return 0; 
}