#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
int n = 0;
struct express
{
	int ex_num=0;         //快递单号；
	string ex_range;       //快递类别；
	string exjisong_ad;    //寄送人地址；
	string exjiso_phone;   //寄送人电话；
	string exjiso_leave;   //寄送人备注信息；
	string exshou_ad;      //收件人地址；
	string exshou_phone;   //收件人电话；
	string exshou_leave;   //收件人备注信息；
	string ex_shoutime;    //收件日期；
	string ex_paitime;     //派送日期；
	string ex_qian;        //签收信息；
	int    ex_cost=0;        //金额；
	string ex_trouble;     //是否疑难件；
	string ex_troublewrite;//疑难件备注；
	express* next=NULL;
};
express* insert(express* head, express* expre)//新增快递单号，及新增的节点。
{
	express* p0, * p1, * p2=NULL;
	p1 = head; p0 = expre;
	if (head == NULL)//先判断传入的表头是否为空，即为头结点。
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
			if (p1 == head)//链表头结点 
			{
				p0->next = head; head = p0;
			}
			else//中间节点； 
			{
				p2->next = p0; p0->next = NULL;
			}
		}
		else
		{
			p1->next = p0; p0->next = NULL;//遍历到尾结点还没有找到比他大的，那么他就是最大的，直接弄为尾结点； 
		}
	}
	return head;
}
//****************************************************************************//

//****************************************************************************//
express* add(express* head, express* expre)//按金额排序加节点。
{
	express* p0, * p1, * p2=NULL;//p2为前一个节点； 
	p1 = head; p0 = expre;
	if (head == NULL)//先判断传入的表头是否为空，即为头结点。
	{
		head = p0; p0->next = NULL;
	}
	else
	{
		while ((p0->ex_cost > p1->ex_cost) && (p1->next != NULL))
		{
			p2 = p1; p1 = p1->next;
		}//遍历链表，找到比插入节点小的； 
		if (p0->ex_cost <= p1->ex_cost)
		{
			if (p1 == head)
			{
				p0->next = head; head = p0;//若插入节点小于头结点，则将头结点改为插入节点p0； 
			}
			else
			{
				p2->next = p0; p0->next = NULL;//若非头结点，则插入这个节点之前； 
			}
		}
		else
		{
			p1->next = p0; p0->next = NULL;//反之，插入其后； 
		}
	}
	return head;
}
//***************************************************************************//

//****************************************************************************//
express* add_by_date(express* head, express* expre)//按照快递派送时间进行排序（升序) 
{
	express* prev = NULL;
	express* curr = head;
	while (curr != NULL && curr->ex_paitime <= expre->ex_paitime) {
		prev = curr;
		curr = curr->next;//遍历链表，找到第一个时间节点大于插入节点的位置； 
	}
	expre->next = curr;//（当head为NULL时）也适用 
	if (prev == NULL) //当head为空时，prev也为NULL； 
	{
		head = expre;
	}
	else
	{
		prev->next = expre;//当head不为nuLL时，将prev的next指向插入节点； 
	}
	return head;
}
//*********************************************************************//

//**********************************************************************//

express* add_by_range(express* head, express* expre)//按照快递种类进行排序； 
{
	express* prev = NULL;//前一个节点； 
	express* curr = head;//当前节点为head； 
	while (curr != NULL && curr->ex_range <= expre->ex_range)
	{
		prev = curr;//指向前一节点；
		curr = curr->next;
	}//遍历链表，找节点； 
	expre->next = curr;
	if (prev == NULL) //说明头节点为空；
	{
		head = expre;
	}
	else 
	{
		prev->next = expre;//前一节点的next指向插入节点；
	}
	return head;
}

//****************************************************************************//
express* del(express* head, int ex_num)//删除快递信息；
{
	express* p1, * p2=NULL;
	if (head == NULL)//链表为空时的情况； 
	{
		cout << "list is null\n";
		return NULL;
	}
	p1 = head;//若链表不为空，那么将p1指向head； 
	while (p1->ex_num != ex_num && p1->next != NULL)
	{
		p2 = p1; p1 = p1->next;
	}//遍历链表，找出相应节点； 
	if (p1->ex_num == ex_num)
	{
		if (ex_num == head->ex_num) head = p1->next;//若为头结点，则指向p1指向的下一节点；
		else
			p2->next = p1->next;//若非头结点，则前一节点指向下一节点；
		n = n - 1;
	}
	else
	{
		cout << "Not found" << endl;//当指针执行指向尾结点的时候都还没有找到，cout<<not found; 
	}
	return head;
}
//******************************************************************//

//******************************************************************//
express* creat()//文件读入，生成链表；
{
	express* head = NULL, * p1 = NULL, * p2 = NULL;
	n = 0;

	// 打开文件并读取数据
	ifstream infile("data.txt", ios::in);//
	if (!infile)
	{
		cout << "文件打开失败" << endl;
		exit(1);
	}

	// 循环读取每个 express 结构体
	while (infile.peek() != EOF)//判断是否已经读到文件末尾；
	{
		p1 = new express;
		infile >> p1->ex_num >> p1->ex_range >> p1->exjisong_ad >> p1->exjiso_phone >> p1->exjiso_leave >> p1->exshou_ad >> p1->exshou_phone >> p1->exshou_leave >> p1->ex_shoutime >> p1->ex_paitime >> p1->ex_qian >> p1->ex_cost >> p1->ex_trouble >> p1->ex_troublewrite;

		// 判断链表是否为空，并将首节点指向当前节点
		if (head == NULL)
		{
			head = p1;
		}
		// 将 p2 的 next 指向当前节点，并更新 p2 为当前节点
		else
		{
			p2->next = p1;
		}
		p2 = p1;
	}

	// 链表结尾，将 p2 的 next 设为 NULL
	p2->next = NULL;

	// 关闭文件并返回链表头指针
	infile.close();
	return head;
}
//***************************************************************************//

//***************************************************************************//
void modify(express* head, int ex_nu)//修改快递信息；
{
	express* p1;
	p1 = head;
	if (p1 == NULL)
	{
		cout << "没有找到需要被修改信息的快递，请查证后再次输入快递单号进行查询" << endl;
		return;
	}
	while (p1 != NULL && p1->ex_num != ex_nu)
	{
		p1 = p1->next;
	}
	if (p1->ex_num == ex_nu)
	{
		cout << "已经找到需要被修改信息的快递" << endl;
		cout << "请按以下提示的指令输入，进行相应信息的删除" << endl;
		cout << "1.快递类别" << endl;
		cout << "2.寄送人地址" << endl;
		cout << "3.寄送人电话" << endl;
		cout << "4.寄送人备注信息" << endl;
		cout << "5.手机人地址" << endl;
		cout << "6.手机人电话" << endl;
		cout << "7.收件人备注信息" << endl;
		cout << "8.收件日期" << endl;
		cout << "9.派送日期" << endl;
		cout << "10.签收信息" << endl;
		cout << "11.金额" << endl;
		cout << "12.是否疑难件" << endl;
		cout << "13.疑难件备注" << endl;
		cout << "请输入指令" << endl;
		int m;
		cin >> m;
		string k;
		int q;
		switch (m)
		{
		case 1:
			cout << "请输入更改后的快递类别。" << endl;
			cin >> k;
			p1->ex_range = k;
			break;
		case 2:
			cout << "请输入更改后的寄送人地址。" << endl;
			cin >> k;
			p1->exjisong_ad = k;
			break;
		case 3:
			cout << "请输入更改后的寄送人电话。" << endl;
			cin >> k;
			p1->exjiso_phone = k;
			break;
		case 4:
			cout << "请输入更改后的急送人备注信息。" << endl;
			cin >> k;
			p1->exjiso_leave = k;
			break;
		case 5:
			cout << "请输入更改后的收件人地址。" << endl;
			cin >> k;
			p1->exshou_ad = k;
			break;
		case 6:
			cout << "请输入更改后的收件人电话。" << endl;
			cin >> k;
			p1->exshou_phone = k;
			break;
		case 7:
			cout << "请输入更改后的收件人备注信息。" << endl;
			cin >> k;
			p1->exshou_leave = k;
			break;
		case 8:
			cout << "请输入更改后的收件日期。" << endl;
			cin >> k;
			p1->ex_shoutime = k;
			break;
		case 9:
			cout << "请输入更改后的派送日期。" << endl;
			cin >> k;
			p1->ex_paitime = k;
			break;
		case 10:
			cout << "请输入更改后的签收信息。" << endl;
			cin >> k;
			p1->ex_qian = k;
			break;
		case 11:
			cout << "请输入更改后的金额。" << endl;
			cin >> q;
			p1->ex_cost = q;
			break;
		case 12:
			cout << "请输入更改后的是否疑难件。" << endl;
			cin >> k;
			p1->ex_trouble = k;
			break;
		case 13:
			cout << "请输入更改后的疑难件备注（地址模糊，用户拒收，电话无效，无人在家）" << endl;
			cin >> k;
			p1->ex_troublewrite = k;
			break;
		}

	}
	else
	{
		cout << "没有找到需要被修改信息的快递，请查证后再次输入快递单号进行查询" << endl;
	}
}
//***********************************************************************************//

//**********************************************************************************//
void print(express* head)//打印快递所有详细信息；
{
	express* p1;
	p1 = head;
	cout << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
	while (p1 != NULL)
	{
		cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;
		p1 = p1->next;
	}
}
//********************************************************************************//

//*******************************************************************************//
void printpai(express* head)//输出派送单信息；
{
	string h = "派送单";
	express* p1;
	p1 = head;
	cout << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
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
void printshou(express* head)//输出收件单信息；
{
	string h = "收件单";
	express* p1;
	p1 = head;
	cout << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
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
void printweiqian(express* head)//输出未签收快递单的信息；
{
	string h = "否";
	express* p1;
	p1 = head;
	cout << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
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
void printyiqian(express* head)//输出已签收快递单的信息；
{
	string h = "已签收";
	express* p1;
	p1 = head;
	cout << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
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
void printcot(express* head)//统计指定日期的快递单数量和总金额；
{
	string h;//h为指定的快递派送时间
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
	cout << "你所指定查询日期的快递单数为" << num << ";" << "快递总金额为" << sum << "." << endl;
}
//**********************************************************************************//
void printyinan(express* head)//输出已疑难件快递单的信息；
{

	express* p1;
	p1 = head;
	cout << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
	while (p1 != NULL)
	{
		if (p1->ex_trouble == "是")
		{
			cout << setw(9) << p1->ex_num << setw(9) << p1->ex_range << setw(12) << p1->exjisong_ad << setw(12) << p1->exjiso_phone << setw(15) << p1->exjiso_leave << setw(11) << p1->exshou_ad << setw(11) << p1->exshou_phone << setw(15) << p1->exshou_leave << setw(9) << p1->ex_shoutime << setw(9) << p1->ex_paitime << setw(10) << p1->ex_qian << setw(5) << p1->ex_cost << setw(11) << p1->ex_trouble << p1->ex_troublewrite << endl;

		}
		p1 = p1->next;
	}
}
//***************************************************************************//

//**************************************************************************//
express* ex_cst(express* head)//按金额排序显示所有快递信息；
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
express* ex_pp(express* head)//按照快递派送时间进行排序
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
express* ex_lei(express* head)//按照快递类别进行快递的排序
{
	express* p1 = head, * p2;
	express* head_sent = NULL, * tail_sent = NULL;
	express* head_receive = NULL, * tail_receive = NULL;

	while (p1 != NULL) {
		p2 = p1->next;
		if (p1->ex_range == "派送单") 
		{
			if (tail_sent == NULL) {
				head_sent = tail_sent = p1;
				tail_sent->next = NULL;
			}
			else {
				tail_sent = add_by_range(head_sent, p1);
			}
		}
		else if (p1->ex_range == "收件单")
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

	// 将收件单和派送单的链表合并
	if (tail_sent == NULL) //当派送链表为空时，只输出收件链表
	{
		return head_receive;
	}
	else if (tail_receive == NULL) //当收件链表为空时，只输出派送链表；
	{
		return head_sent;
	}
	else//连接两个不为空的链表；
	{
		tail_receive->next = head_sent;
		return head_receive;
	}
}
//********************************************************
void menu()//菜单
{
	cout << endl;
	cout << "===================================" << endl;
	cout << "      欢迎使用快递业务管理系统      " << endl;
	cout << "===================================" << endl;
	cout << "请选择您要执行的操作：" << endl;
	cout << "1. 新增快递单记录" << endl;
	cout << "2. 删除快递单记录" << endl;
	cout << "3. 修改快递单记录" << endl;
	cout << "4. 查询派送单信息" << endl;
	cout << "5. 查询收件单信息" << endl;
	cout << "6. 根据收件日期统计快递单数量、金额" << endl;
	cout << "7. 显示未签收的快递单" << endl;
	cout << "8. 显示所有的疑难件" << endl;
	cout << "9. 按日期排序显示所有快递信息" << endl;
	cout << "10.按快递类别排序显示所有快递信息" << endl;
	cout << "11.按金额排序显示所有快递信息" << endl;
	cout << "12.输出所有快递单信息" << endl;
	cout << "13.退出系统" << endl;
	cout << "===================================" << endl;
}


void save(express* head)//储存文件
{
	// 打开文件并清空内容
	ofstream outfile("data.txt", ios::trunc);

	// 遍历链表，并将每个 express 结构体的字段写入文件
	express* p = head;
	while (p != NULL)
	{
		outfile << p->ex_num << " " << p->ex_range << " " << p->exjisong_ad << " " << p->exjiso_phone << " " << p->exjiso_leave << " " << p->exshou_ad << " " << p->exshou_phone << " " << p->exshou_leave << " " << p->ex_shoutime << " " << p->ex_paitime << " " << p->ex_qian << " " << p->ex_cost << " " << p->ex_trouble << " " << p->ex_troublewrite << endl;
		p = p->next;
	}

	// 关闭文件
	outfile.close();
}


void zhixing(express * head) //快递业务管理系统的执行函数，用户通过这个函数进行指令的输入，进行对系统的操作；
{
	int m;
	cout << "请您输入您想要执行的指令:" << endl;
	while (cin >> m && m < 13 && m >= 1)
	{
		express* p1 = new express();
		express* p2 = NULL;
		switch (m)
		{
		case 1:
			cout << "请输入您想添加的快递单信息:" << endl;
			cout << left << setw(9) << "快递单号" << setw(9) << "快递类别" << setw(12) << "寄送人地址" << setw(12) << "寄送人电话" << setw(15) << "寄送人备注信息" << setw(11) << "收件人地址" << setw(11) << "收件人电话" << setw(15) << "收件人备注信息" << setw(9) << "收件日期" << setw(9) << "派送日期" << setw(10) << "签收信息" << setw(5) << "金额" << setw(11) << "是否疑难件" << "疑难件的原因" << endl;
			cin >> p1->ex_num >> p1->ex_range >> p1->exjisong_ad >> p1->exjiso_phone >> p1->exjiso_leave
				>> p1->exshou_ad >> p1->exshou_phone >> p1->exshou_leave >> p1->ex_shoutime >> p1->ex_paitime
				>> p1->ex_qian >> p1->ex_cost >> p1->ex_trouble >> p1->ex_troublewrite;
			insert(head, p1);
			break;
		case 2:
			cout << "请输入您想删除的快递单号:" << endl;
			int h;
			cin >> h;
			del(head, h);
			break;
		case 3:
			cout << "请输入您想要修改的快递单号:" << endl;
			int q;
			cin >> q;
			modify(head, q);
			break;
		case 4:
			cout << "以下是派送单的信息:" << endl;
			printpai(head);
			break;
		case 5:
			cout << "以下是收件单的信息:" << endl;
			printshou(head);
			break;
		case 6:
			cout << "请输入需要统计金额的快递单日期和快递单数（派送时间）:" << endl;
			printcot(head);
			break;
		case 7:
			cout << "以下是未签收的快递:" << endl;
			printweiqian(head);
			break;
		case 8:
			cout << "以下是疑难案件:" << endl;
			printyinan(head);
			break;
		case 9:
			cout << "以下是按照日期排序后的快递单信息:" << endl;
			p2 = ex_pp(head);
			print(p2);
			break;
		case 10:
			cout << "以下是按照快递类别排序后的快递信息:" << endl;
			p2 = ex_lei(head);
			print(p2);
			break;
		case 11:
			cout << "以下是按照金额排序后的快递信息:" << endl;
			p2 = ex_cst(head);
			print(p2);
			break;
		case 12:
			cout << "以下是所有快递单信息:" << endl;
			print(head);
			break;
		default:
			cout << "输入不合法，请重新输入" << endl;
			break;
		}
	}
	cout << "谢谢您使用本系统，再见！" << endl;
}
