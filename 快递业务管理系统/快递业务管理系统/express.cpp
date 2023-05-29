#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int n = 0;
struct express
{
	int ex_num=0;         //��ݵ��ţ�
	string ex_range;       //������
	string exjisong_ad;    //�����˵�ַ��
	string exjiso_phone;   //�����˵绰��
	string exjiso_leave;   //�����˱�ע��Ϣ��
	string exshou_ad;      //�ռ��˵�ַ��
	string exshou_phone;   //�ռ��˵绰��
	string exshou_leave;   //�ռ��˱�ע��Ϣ��
	string ex_shoutime;    //�ռ����ڣ�
	string ex_paitime;     //�������ڣ�
	string ex_qian;        //ǩ����Ϣ��
	int    ex_cost=0;        //��
	string ex_trouble;     //�Ƿ����Ѽ���
	string ex_troublewrite;//���Ѽ���ע��
	express* next=NULL;
};
express* insert(express* head, express* expre)//������ݵ��ţ��������Ľڵ㡣
{
	express* p0, * p1, * p2=NULL;
	p1 = head; p0 = expre;
	if (head == NULL)//���жϴ���ı�ͷ�Ƿ�Ϊ�գ���Ϊͷ��㡣
	{
		head = p0; p0->next = NULL;
	}
	else
	{
		while ((p0->ex_num > p1->ex_num) && (p1->next != NULL))
		{
			p2 = p1; p1 = p1->next;
		}
		if (p0->ex_num <= p1->ex_num)
		{
			if (p1 == head)//����ͷ��� 
			{
				p0->next = head; head = p0;
			}
			else//�м�ڵ㣻 
			{
				p2->next = p0; p0->next = NULL;
			}
		}
		else
		{
			p1->next = p0; p0->next = NULL;//������β��㻹û���ҵ�������ģ���ô���������ģ�ֱ��ŪΪβ��㣻 
		}
	}
	return head;
}
//****************************************************************************//

//****************************************************************************//
express* add(express* head, express* expre)//���������ӽڵ㡣
{
	express* p0, * p1, * p2=NULL;//p2Ϊǰһ���ڵ㣻 
	p1 = head; p0 = expre;
	if (head == NULL)//���жϴ���ı�ͷ�Ƿ�Ϊ�գ���Ϊͷ��㡣
	{
		head = p0; p0->next = NULL;
	}
	else
	{
		while ((p0->ex_cost > p1->ex_cost) && (p1->next != NULL))
		{
			p2 = p1; p1 = p1->next;
		}//���������ҵ��Ȳ���ڵ�С�ģ� 
		if (p0->ex_cost <= p1->ex_cost)
		{
			if (p1 == head)
			{
				p0->next = head; head = p0;//������ڵ�С��ͷ��㣬��ͷ����Ϊ����ڵ�p0�� 
			}
			else
			{
				p2->next = p0; p0->next = NULL;//����ͷ��㣬���������ڵ�֮ǰ�� 
			}
		}
		else
		{
			p1->next = p0; p0->next = NULL;//��֮��������� 
		}
	}
	return head;
}
//***************************************************************************//

//****************************************************************************//
express* add_by_date(express* head, express* expre)//���տ������ʱ�������������) 
{
	express* prev = NULL;
	express* curr = head;
	while (curr != NULL && curr->ex_paitime <= expre->ex_paitime) {
		prev = curr;
		curr = curr->next;//���������ҵ���һ��ʱ��ڵ���ڲ���ڵ��λ�ã� 
	}
	expre->next = curr;//����headΪNULLʱ��Ҳ���� 
	if (prev == NULL) //��headΪ��ʱ��prevҲΪNULL�� 
	{
		head = expre;
	}
	else
	{
		prev->next = expre;//��head��ΪnuLLʱ����prev��nextָ�����ڵ㣻 
	}
	return head;
}
//*********************************************************************//

//**********************************************************************//

express* add_by_range(express* head, express* expre)//���տ������������� 
{
	express* prev = NULL;//ǰһ���ڵ㣻 
	express* curr = head;//��ǰ�ڵ�Ϊhead�� 
	while (curr != NULL && curr->ex_range <= expre->ex_range)
	{
		prev = curr;//ָ��ǰһ�ڵ㣻
		curr = curr->next;
	}//���������ҽڵ㣻 
	expre->next = curr;
	if (prev == NULL) //˵��ͷ�ڵ�Ϊ�գ�
	{
		head = expre;
	}
	else 
	{
		prev->next = expre;//ǰһ�ڵ��nextָ�����ڵ㣻
	}
	return head;
}

//****************************************************************************//
express* del(express* head, int ex_num)//ɾ�������Ϣ��
{
	express* p1, * p2=NULL;
	if (head == NULL)//����Ϊ��ʱ������� 
	{
		cout << "list is null\n";
		return NULL;
	}
	p1 = head;//������Ϊ�գ���ô��p1ָ��head�� 
	while (p1->ex_num != ex_num && p1->next != NULL)
	{
		p2 = p1; p1 = p1->next;
	}//���������ҳ���Ӧ�ڵ㣻 
	if (p1->ex_num == ex_num)
	{
		if (ex_num == head->ex_num) head = p1->next;//��Ϊͷ��㣬��ָ��p1ָ�����һ�ڵ㣻
		else
			p2->next = p1->next;//����ͷ��㣬��ǰһ�ڵ�ָ����һ�ڵ㣻
		n = n - 1;
	}
	else
	{
		cout << "Not found" << endl;//��ָ��ִ��ָ��β����ʱ�򶼻�û���ҵ���cout<<not found; 
	}
	return head;
}
//******************************************************************//

//******************************************************************//
express* creat()//�ļ����룬��������
{
	express* head = NULL, * p1 = NULL, * p2 = NULL;
	n = 0;

	// ���ļ�����ȡ����
	ifstream infile("data.txt", ios::in);//
	if (!infile)
	{
		cout << "�ļ���ʧ��" << endl;
		exit(1);
	}

	// ѭ����ȡÿ�� express �ṹ��
	while (infile.peek() != EOF)//�ж��Ƿ��Ѿ������ļ�ĩβ��
	{
		p1 = new express;
		infile >> p1->ex_num >> p1->ex_range >> p1->exjisong_ad >> p1->exjiso_phone >> p1->exjiso_leave >> p1->exshou_ad >> p1->exshou_phone >> p1->exshou_leave >> p1->ex_shoutime >> p1->ex_paitime >> p1->ex_qian >> p1->ex_cost >> p1->ex_trouble >> p1->ex_troublewrite;

		// �ж������Ƿ�Ϊ�գ������׽ڵ�ָ��ǰ�ڵ�
		if (head == NULL)
		{
			head = p1;
		}
		// �� p2 �� next ָ��ǰ�ڵ㣬������ p2 Ϊ��ǰ�ڵ�
		else
		{
			p2->next = p1;
		}
		p2 = p1;
	}

	// �����β���� p2 �� next ��Ϊ NULL
	p2->next = NULL;

	// �ر��ļ�����������ͷָ��
	infile.close();
	return head;
}
//***************************************************************************//

//***************************************************************************//
void modify(express* head, int ex_nu)//�޸Ŀ����Ϣ��
{
	express* p1;
	p1 = head;
	if (p1 == NULL)
	{
		cout << "û���ҵ���Ҫ���޸���Ϣ�Ŀ�ݣ����֤���ٴ������ݵ��Ž��в�ѯ" << endl;
		return;
	}
	while (p1 != NULL && p1->ex_num != ex_nu)
	{
		p1 = p1->next;
	}
	if (p1->ex_num == ex_nu)
	{
		cout << "�Ѿ��ҵ���Ҫ���޸���Ϣ�Ŀ��" << endl;
		cout << "�밴������ʾ��ָ�����룬������Ӧ��Ϣ��ɾ��" << endl;
		cout << "1.������" << endl;
		cout << "2.�����˵�ַ" << endl;
		cout << "3.�����˵绰" << endl;
		cout << "4.�����˱�ע��Ϣ" << endl;
		cout << "5.�ֻ��˵�ַ" << endl;
		cout << "6.�ֻ��˵绰" << endl;
		cout << "7.�ռ��˱�ע��Ϣ" << endl;
		cout << "8.�ռ�����" << endl;
		cout << "9.��������" << endl;
		cout << "10.ǩ����Ϣ" << endl;
		cout << "11.���" << endl;
		cout << "12.�Ƿ����Ѽ�" << endl;
		cout << "13.���Ѽ���ע" << endl;
		cout << "������ָ��" << endl;
		int m;
		cin >> m;
		string k;
		int q;
		switch (m)
		{
		case 1:
			cout << "��������ĺ�Ŀ�����" << endl;
			cin >> k;
			p1->ex_range = k;
			break;
		case 2:
			cout << "��������ĺ�ļ����˵�ַ��" << endl;
			cin >> k;
			p1->exjisong_ad = k;
			break;
		case 3:
			cout << "��������ĺ�ļ����˵绰��" << endl;
			cin >> k;
			p1->exjiso_phone = k;
			break;
		case 4:
			cout << "��������ĺ�ļ����˱�ע��Ϣ��" << endl;
			cin >> k;
			p1->exjiso_leave = k;
			break;
		case 5:
			cout << "��������ĺ���ռ��˵�ַ��" << endl;
			cin >> k;
			p1->exshou_ad = k;
			break;
		case 6:
			cout << "��������ĺ���ռ��˵绰��" << endl;
			cin >> k;
			p1->exshou_phone = k;
			break;
		case 7:
			cout << "��������ĺ���ռ��˱�ע��Ϣ��" << endl;
			cin >> k;
			p1->exshou_leave = k;
			break;
		case 8:
			cout << "��������ĺ���ռ����ڡ�" << endl;
			cin >> k;
			p1->ex_shoutime = k;
			break;
		case 9:
			cout << "��������ĺ���������ڡ�" << endl;
			cin >> k;
			p1->ex_paitime = k;
			break;
		case 10:
			cout << "��������ĺ��ǩ����Ϣ��" << endl;
			cin >> k;
			p1->ex_qian = k;
			break;
		case 11:
			cout << "��������ĺ�Ľ�" << endl;
			cin >> q;
			p1->ex_cost = q;
			break;
		case 12:
			cout << "��������ĺ���Ƿ����Ѽ���" << endl;
			cin >> k;
			p1->ex_trouble = k;
			break;
		case 13:
			cout << "��������ĺ�����Ѽ���ע����ַģ�����û����գ��绰��Ч�������ڼң�" << endl;
			cin >> k;
			p1->ex_troublewrite = k;
			break;
		}

	}
	else
	{
		cout << "û���ҵ���Ҫ���޸���Ϣ�Ŀ�ݣ����֤���ٴ������ݵ��Ž��в�ѯ" << endl;
	}
}
//***********************************************************************************//

//**********************************************************************************//
void print(express* head)//��ӡ���������ϸ��Ϣ��
{
	express* p1;
	p1 = head;
	cout << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
	while (p1 != NULL)
	{
		cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;
		p1 = p1->next;
	}
}
//********************************************************************************//

//*******************************************************************************//
void printpai(express* head)//������͵���Ϣ��
{
	string h = "���͵�";
	express* p1;
	p1 = head;
	cout << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
	while (p1 != NULL)
	{
		if (p1->ex_range == h)
		{
			cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;
		}
		p1 = p1->next;
	}

}
//***********************************************************************************//

//**********************************************************************************//
void printshou(express* head)//����ռ�����Ϣ��
{
	string h = "�ռ���";
	express* p1;
	p1 = head;
	cout << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
	while (p1 != NULL)
	{
		if (p1->ex_range == h)
		{
			cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;
		}
		p1 = p1->next;
	}
}
//**********************************************************************//

//*********************************************************************//
void printweiqian(express* head)//���δǩ�տ�ݵ�����Ϣ��
{
	string h = "��";
	express* p1;
	p1 = head;
	cout << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
	while (p1 != NULL)
	{
		if (p1->ex_qian == h)
		{
			cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;
		}
		p1 = p1->next;
	}
}
//********************************************************************//

//*********************************************************************//
void printyiqian(express* head)//�����ǩ�տ�ݵ�����Ϣ��
{
	string h = "��ǩ��";
	express* p1;
	p1 = head;
	cout << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
	while (p1 != NULL)
	{
		if (p1->ex_qian == h)
		{
			cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;
		}
		p1 = p1->next;
	}
}
//*****************************************************************//

//********************************************************************//
void printcot(express* head)//ͳ��ָ�����ڵĿ�ݵ��������ܽ�
{
	string h;//hΪָ���Ŀ������ʱ��
	cin >> h;
	express* p1;
	p1 = head;
	int num = 0;
	int sum = 0;
	while (p1 != NULL)
	{
		if (p1->ex_shoutime == h)
		{
			num++;
			sum += p1->ex_cost;
		}
		p1 = p1->next;
	}
	cout << "����ָ����ѯ���ڵĿ�ݵ���Ϊ" << num << ";" << "����ܽ��Ϊ" << sum << "." << endl;
}
//**********************************************************************************//
void printyinan(express* head)//��������Ѽ���ݵ�����Ϣ��
{

	express* p1;
	p1 = head;
	cout << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
	while (p1 != NULL)
	{
		if (p1->ex_trouble == "��")
		{
			cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;

		}
		p1 = p1->next;
	}
}
//***************************************************************************//

//**************************************************************************//
express* ex_cst(express* head)//�����������ʾ���п����Ϣ��
{
	express* head2 = NULL, * p1;
	p1 = head;
	while (p1 != NULL)
	{
		head2 = add(head2, p1);
		p1 = p1->next;
	}
	return head2;
}
//************************************************************************//

//************************************************************************//
express* ex_pp(express* head)//���տ������ʱ���������
{
	express* p1 = head;
	express* head2 = NULL;

	while (p1 != NULL) {
		
		head2 = add_by_date(head2, p1);
		p1 = p1->next;
	}

	return head2;
}
//************************************************************************//

//************************************************************
express* ex_lei(express* head)//���տ�������п�ݵ�����
{
	express* p1 = head, * p2;
	express* head_sent = NULL, * tail_sent = NULL;
	express* head_receive = NULL, * tail_receive = NULL;

	while (p1 != NULL) {
		p2 = p1->next;
		if (p1->ex_range == "���͵�") 
		{
			if (tail_sent == NULL) {
				head_sent = tail_sent = p1;
				tail_sent->next = NULL;
			}
			else {
				tail_sent = add_by_range(head_sent, p1);
			}
		}
		else if (p1->ex_range == "�ռ���")
		{
			if (tail_receive == NULL) {
				head_receive = tail_receive = p1;
				tail_receive->next = NULL;
			}
			else {
				tail_receive = add_by_range(head_receive, p1);
			}
		}
		p1 = p2;
	}

	// ���ռ��������͵�������ϲ�
	if (tail_sent == NULL) //����������Ϊ��ʱ��ֻ����ռ�����
	{
		return head_receive;
	}
	else if (tail_receive == NULL) //���ռ�����Ϊ��ʱ��ֻ�����������
	{
		return head_sent;
	}
	else//����������Ϊ�յ�����
	{
		tail_receive->next = head_sent;
		return head_receive;
	}
}
//********************************************************
void menu()//�˵�
{
	cout << endl;
	cout << "===================================" << endl;
	cout << "      ��ӭʹ�ÿ��ҵ�����ϵͳ      " << endl;
	cout << "===================================" << endl;
	cout << "��ѡ����Ҫִ�еĲ�����" << endl;
	cout << "1. ������ݵ���¼" << endl;
	cout << "2. ɾ����ݵ���¼" << endl;
	cout << "3. �޸Ŀ�ݵ���¼" << endl;
	cout << "4. ��ѯ���͵���Ϣ" << endl;
	cout << "5. ��ѯ�ռ�����Ϣ" << endl;
	cout << "6. �����ռ�����ͳ�ƿ�ݵ����������" << endl;
	cout << "7. ��ʾδǩ�յĿ�ݵ�" << endl;
	cout << "8. ��ʾ���е����Ѽ�" << endl;
	cout << "9. ������������ʾ���п����Ϣ" << endl;
	cout << "10.��������������ʾ���п����Ϣ" << endl;
	cout << "11.�����������ʾ���п����Ϣ" << endl;
	cout << "12.������п�ݵ���Ϣ" << endl;
	cout << "13.�˳�ϵͳ" << endl;
	cout << "===================================" << endl;
}


void save(express* head)//�����ļ�
{
	// ���ļ����������
	ofstream outfile("data.txt", ios::trunc);

	// ������������ÿ�� express �ṹ����ֶ�д���ļ�
	express* p = head;
	while (p != NULL)
	{
		outfile << p->ex_num << " " << p->ex_range << " " << p->exjisong_ad << " " << p->exjiso_phone << " " << p->exjiso_leave << " " << p->exshou_ad << " " << p->exshou_phone << " " << p->exshou_leave << " " << p->ex_shoutime << " " << p->ex_paitime << " " << p->ex_qian << " " << p->ex_cost << " " << p->ex_trouble << " " << p->ex_troublewrite << endl;
		p = p->next;
	}

	// �ر��ļ�
	outfile.close();
}


void zhixing(express * head) //���ҵ�����ϵͳ��ִ�к������û�ͨ�������������ָ������룬���ж�ϵͳ�Ĳ�����
{
	int m;
	cout << "������������Ҫִ�е�ָ��:" << endl;
	while (cin >> m && m < 13 && m >= 1)
	{
		express* p1 = new express();
		express* p2 = NULL;
		switch (m)
		{
		case 1:
			cout << "������������ӵĿ�ݵ���Ϣ:" << endl;
			cout << left << setw(9) << "��ݵ���" << setw(9) << "������" << setw(12) << "�����˵�ַ" << setw(12) << "�����˵绰" << setw(15) << "�����˱�ע��Ϣ" << setw(11) << "�ռ��˵�ַ" << setw(11) << "�ռ��˵绰" << setw(15) << "�ռ��˱�ע��Ϣ" << setw(9) << "�ռ�����" << setw(9) << "��������" << setw(10) << "ǩ����Ϣ" << setw(5) << "���" << setw(11) << "�Ƿ����Ѽ�" << "���Ѽ���ԭ��" << endl;
			cin >> p1->ex_num >> p1->ex_range >> p1->exjisong_ad >> p1->exjiso_phone >> p1->exjiso_leave
				>> p1->exshou_ad >> p1->exshou_phone >> p1->exshou_leave >> p1->ex_shoutime >> p1->ex_paitime
				>> p1->ex_qian >> p1->ex_cost >> p1->ex_trouble >> p1->ex_troublewrite;
			insert(head, p1);
			break;
		case 2:
			cout << "����������ɾ���Ŀ�ݵ���:" << endl;
			int h;
			cin >> h;
			del(head, h);
			break;
		case 3:
			cout << "����������Ҫ�޸ĵĿ�ݵ���:" << endl;
			int q;
			cin >> q;
			modify(head, q);
			break;
		case 4:
			cout << "���������͵�����Ϣ:" << endl;
			printpai(head);
			break;
		case 5:
			cout << "�������ռ�������Ϣ:" << endl;
			printshou(head);
			break;
		case 6:
			cout << "��������Ҫͳ�ƽ��Ŀ�ݵ����ںͿ�ݵ���������ʱ�䣩:" << endl;
			printcot(head);
			break;
		case 7:
			cout << "������δǩ�յĿ��:" << endl;
			printweiqian(head);
			break;
		case 8:
			cout << "���������Ѱ���:" << endl;
			printyinan(head);
			break;
		case 9:
			cout << "�����ǰ������������Ŀ�ݵ���Ϣ:" << endl;
			p2 = ex_pp(head);
			print(p2);
			break;
		case 10:
			cout << "�����ǰ��տ����������Ŀ����Ϣ:" << endl;
			p2 = ex_lei(head);
			print(p2);
			break;
		case 11:
			cout << "�����ǰ��ս�������Ŀ����Ϣ:" << endl;
			p2 = ex_cst(head);
			print(p2);
			break;
		case 12:
			cout << "���������п�ݵ���Ϣ:" << endl;
			print(head);
			break;
		default:
			cout << "���벻�Ϸ�������������" << endl;
			break;
		}
	}
	cout << "лл��ʹ�ñ�ϵͳ���ټ���" << endl;
}
