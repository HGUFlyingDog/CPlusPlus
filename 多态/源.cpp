//����������Brass Account֧Ʊ�˻�����Ϣ��
//�ͻ�������
//�˺ţ�
//��ǰ���ࡣ
//�����ǿ���ִ�еĲ�����
//�����˻���
//��
//ȡ�
//��ʾ�˻���Ϣ��
//
//Pontoon����ϣ��Brass Plus֧Ʊ�˻�����Brass Account��������Ϣ��������Ϣ��
//͸֧���ޣ�
//͸֧�������ʣ�
//��ǰ��͸֧�ܶ
//����Ҫ�����������������ֲ�����ʵ�ֲ�ͬ��
//����ȡ����������뿼��͸֧������
//��ʾ����������ʾBrass Plus�˻���������Ϣ��
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
    cout << "��Hogg�˻�����1000��Ԫ��\n";
    Hoggy.Deposit(1000.00);
    cout << "����$" << Hoggy.Balance() << endl;

    cout << "��Pigg�˻�ȡ��4200��Ԫ��\n";
    Piggy.Withdraw(4200.00);
    cout << "Pigg�˻���$" << Piggy.Balance() << endl;

    cout << "��Hogg�˻�ȡ��4200��Ԫ��\n";
    Hoggy.Withdraw(4200.00);
    Hoggy.ViewAcct();  // �鿴Hogg�˻�����
}