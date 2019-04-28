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

//��ʼ��
list::list()
{
	head=new node;
	head->next=NULL;
	count=0;
}

//�󳤶�
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

//�����ȡԪ��
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

//��ֵ����Ԫ��
node *list::locate(const elementtype x) const
{
	node *p=head->next;
	while (p!=NULL)
		if (p->data == x) return p;
		else p=p->next;
	return NULL;
}

//����
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

//ɾ��
error_code list::delete_element(const int i)
{
	node *p,*u;
	p=head; int j=0;
	while (j!=i-1 && p!=NULL) {p=p->next; j++;}
	if (p==NULL || p->next==NULL) //if ��i<1 || i>count��
		return rangeerror;
	u=p->next; p->next=u->next; delete u;
	count--; return success;
}
//ͷ�巨����
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
//β�巨����
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
//��ʾ����
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
			s->data=p->data;//��������B�� //s->next=q->next;β�巨���������в�һ���ĵط�
			s->next=NULL;
			q->next=s;// β�嵽B
			q=s;
			n++;
			u=p;

// + �Ĳ�����Aȫɾ��
// ++ �ǳ���ʧ��
// ȷ��˼·:ֻɾ���½ڵ㣬Ŀ������һ��Ҫ��pre-p��nextָ��p��next
			// A.get_head()->next = p->next;//+
			pre->next = p->next; pre = p->next;
			// Coincidence �����н��ͼ����ע�͵�����һ�в�����,Ҫ�û��ȥ̽��ԭ���ˣ�������Ϊûѧ�����
			cout<<"Coincidece!"<<A.get_head()->next->next->data<<" n:"<<n<<"?"<<endl;1
			p=p->next;
			delete u;
			cout<<"Coincidece!"<<A.get_head()->next->next->data<<" n:"<<n<<endl;

		}
		else {// ��A����
			// u = p;//+
			// A.get_head()->next = p->next;//+
			// p=&p->next; // ++ֱ�ӻ�ȡ��ַ error: cannot convert 'LinkNode**' to 'node* {aka LinkNode*}' in assignment
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
