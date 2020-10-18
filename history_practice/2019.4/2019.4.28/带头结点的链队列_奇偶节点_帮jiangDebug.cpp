//linklist.cpp
#include <iostream>
using namespace std;
enum error_code{success,overflow,underflow,rangeerror};
const int end_of_list=-9999;
typedef int elementtype;

typedef struct LinkNode{
	elementtype data;
	struct LinkNode *next;
}node;

class list{
private:
	int count;
	node *head;
public:
	list();
	~list() {};
	int length() const;
	error_code get_element(const int i,elementtype &x) const;
	node *locate(const elementtype x) const;
	error_code insert(const int i,const elementtype x);
	error_code delete_element(const int i);
	node *get_head() const {return head;}
	void create1();
	void create2();
	void display();
	void insert1(elementtype x);
};

//初始化
list::list()
{
	head=new node;
	head->next=NULL;
	count=0;
}

//求长度
int list::length() const
{
	node *p=head->next;
	int n=0;
	while (p!=NULL)
	{
		n++;
		p=p->next;
	}
	return n;
}

//按序号取元素
error_code list::get_element(const int i,elementtype &x) const
{
	node *p=head->next; int j=1;
	while (j!=i && p!=NULL)
	{
		p=p->next; j++;
	}
	if (p==NULL) return rangeerror;
	x=p->data;
	return success;
}

//按值查找元素
node *list::locate(const elementtype x) const
{
	node *p=head->next;
	while (p!=NULL)
		if (p->data == x) return p;
		else p=p->next;
	return NULL;
}

//插入
error_code list::insert(const int i,const elementtype x)
{
	node *p,*s; int j=0; p=head;
	while (j!=i-1 && p!=NULL) {p=p->next; j++;}
	if (p == NULL)  //if (i<1 || i>count+1)
		return rangeerror;
	s=new node; s->data=x;
	s->next=p->next; p->next=s;
	count++;
	return success;
}

//删除
error_code list::delete_element(const int i)
{
	node *p,*u;
	p=head; int j=0;
	while (j!=i-1 && p!=NULL) {p=p->next; j++;}
	if (p==NULL || p->next==NULL) //if （i<1 || i>count）
		return rangeerror;
	u=p->next; p->next=u->next; delete u;
	count--; return success;
}
//头插法建表
void list::create1()
{
	elementtype x; node *s;
	cin>>x;
	while (x!=end_of_list)
	{
		count++;
		s=new node; s->data=x;
		s->next=head->next; head->next=s;
		cin>>x;
	}
}
//尾插法建表
void list::create2()
{
	elementtype x;
	node *s,*rear;
	cin>>x;
	rear=head;
	while (x!=end_of_list)
	{
		count++;
		s=new node;
		s->data=x;
		s->next=NULL;
		rear->next=s;
		rear=s;
		cin>>x;
	}
}
//显示链表
void list::display()
{
	node *p;
	p=head->next;
	while (p!=NULL) {cout<<p->data<<"  "; p=p->next;}
	cout<<endl;
}
void O_E(list &A,list &B)
{
	node *p,*q,*s,*u;
	node *pre; pre=A.get_head()->next;
	p=A.get_head()->next;
	q=B.get_head();
	int n=1;
	while(p!=NULL){
		if(n%2==0) {
			s=new node;
			s->data=p->data;//将结点插入B中 //s->next=q->next;尾插法插入数字有不一样的地方
			s->next=NULL;
			q->next=s;// 尾插到B
			q=s;
			n++;
			u=p;

// + 的操作把A全删了
// ++ 是尝试失败
// 确定思路:只删当下节点，目标任务，一定要让pre-p的next指向p的next
			// A.get_head()->next = p->next;//+
			pre->next = p->next; pre = p->next;
			// Coincidence 的运行结果图都是注释掉上面一行产生的,要用汇编去探索原因了，所以因为没学不深究了
			cout<<"Coincidece!"<<A.get_head()->next->next->data<<" n:"<<n<<"?"<<endl;1
			p=p->next;
			delete u;
			cout<<"Coincidece!"<<A.get_head()->next->next->data<<" n:"<<n<<endl;

		}
		else {// 对A操作
			// u = p;//+
			// A.get_head()->next = p->next;//+
			// p=&p->next; // ++直接获取地址 error: cannot convert 'LinkNode**' to 'node* {aka LinkNode*}' in assignment
			p=p->next;
			n++;
			// delete u;// +
		}
	}
}

int main()
{
	list A,B;
	A.create2();
	A.display();
	O_E(A,B);
	A.display();
	cout<<endl;
	B.display();
	return 0;
}
