#include<iostream>
#include<iomanip>
using namespace std;
struct express
{
	int ex_num;         //��ݵ��ţ�
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
	int ex_cost;        //��
	string ex_trouble;     //�Ƿ����Ѽ���
	string ex_troublewrite;//���Ѽ���ע��
	express* next;
};
express* insert(express* head, express* expre);//������ݵ��ţ��������Ľڵ㡣
express* add(express* head, express* expre);//���������ӽڵ㡣
express* add_by_date(express* head, express* expre);//��������������ӽڵ㡣
express* add_by_range(express* head, express* expre);//�������������ӽڵ㡣
express* del(express* head, int ex_num);//ɾ���ڵ㡣
express* creat();//��������
void modify(express* head, int ex_num);//�޸Ŀ����Ϣ��
void print(express* head);//��ӡ���������ϸ��Ϣ��
void printpai(express* head);//������͵���Ϣ��
void printshou(express* head);//����ռ�����Ϣ��
void printweiqian(express* head);//���δǩ�տ�ݵ�����Ϣ��
void printyiqian(express* head);//�����ǩ�տ�ݵ�����Ϣ��
void printcot(express* head);//ͳ��ָ�����ڵĿ�ݵ��������ܽ�
void printyinan(express* head);//��������Ѽ���ݵ�����Ϣ��
express* ex_cst(express* head);//11.�����������ʾ���п����Ϣ��
express* ex_pp(express* head);//����������������ʾ���п����Ϣ��
express* ex_lei(express* head);//��������������ʾ���п����Ϣ��
void menu();//�˵���
void save(express* head);
void zhixing(express* head);//ִ��ָ�
