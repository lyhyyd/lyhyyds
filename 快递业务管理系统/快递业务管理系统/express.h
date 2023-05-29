#include<iostream>
#include<iomanip>
using namespace std;
struct express
{
	int ex_num;         //快递单号；
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
	int ex_cost;        //金额；
	string ex_trouble;     //是否疑难件；
	string ex_troublewrite;//疑难件备注；
	express* next;
};
express* insert(express* head, express* expre);//新增快递单号，及新增的节点。
express* add(express* head, express* expre);//按金额排序加节点。
express* add_by_date(express* head, express* expre);//按派送日期排序加节点。
express* add_by_range(express* head, express* expre);//按派送类别排序加节点。
express* del(express* head, int ex_num);//删除节点。
express* creat();//创造链表。
void modify(express* head, int ex_num);//修改快递信息；
void print(express* head);//打印快递所有详细信息；
void printpai(express* head);//输出派送单信息；
void printshou(express* head);//输出收件单信息；
void printweiqian(express* head);//输出未签收快递单的信息；
void printyiqian(express* head);//输出已签收快递单的信息；
void printcot(express* head);//统计指定日期的快递单数量和总金额；
void printyinan(express* head);//输出已疑难件快递单的信息；
express* ex_cst(express* head);//11.按金额排序显示所有快递信息；
express* ex_pp(express* head);//按派送日期排序显示所有快递信息；
express* ex_lei(express* head);//按快递类别排序显示所有快递信息；
void menu();//菜单；
void save(express* head);
void zhixing(express* head);//执行指令；
