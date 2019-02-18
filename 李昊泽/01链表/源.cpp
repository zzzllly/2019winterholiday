/*第二次作业是写一个链表, 要求:  测试能运行, 能增加内容,删除内容,修改内容,能显示存储的所有内容.   [禁止抄袭禁止复制粘贴!!!]*/
#include<iostream>
using namespace std;

template <typename T>
class Node {//节点类
public:
	/*成员变量*/
	T element;
	Node* next;//下一个节点
};

template <typename T>
class List {
private:
	Node<T>* head = new Node<T>;//头节点
public:
	Node<T>* getHead() { return head; };//获取头结点,注意返回值类型
	/*功能接口*/
	void createList(Node<T>* head);//创建链表
	void travel(Node<T>* head);//遍历链表
	void addNode(Node<T>* head);//末尾增加新节点
	void delNode(Node<T>* head);//根据数据内容，删除指定节点
	void change(Node<T>* head);//根据数据内容,修改指定节点
	void delList(Node<T>* head);//释放整个链表
};

template <typename T>
void List<T> ::createList(Node<T>* head) {	//尾插法创建单链表
	int i = 0, num;//val用作数据输入,num表示创建链表时数据的个数
	T val;
	Node<T>* p = head;

	cout << "请输入链表数据个数 : ";
	cin >> num;
	cout << "链表创建中..." << endl;

	for (; i < num; i++) {
		Node<T>* s = new Node<T>;//s为新节点
		cout << "请输入数据" << i + 1 << " : ";
		cin >> val;

		s->element = val;
		s->next = NULL;
		p->next = s;
		p = p->next;//节点p向下移动
	}
	cout << "链表创建完成!" << endl;
}

template <typename T>
void List<T>::travel(Node<T>* head){//链表遍历
	int i = 1;//表示第i个数据
	Node<T>* p = head;
	cout << "执行链表遍历数据如下 : " << endl;
	p = p->next;
	while (p) {
		cout << "数据" << i << "为 : " << p->element << endl;
		p = p->next;//节点向下移动
		i++;
	}
	cout << "链表遍历结束!" << endl;
}

template <typename T>
void List<T>::addNode(Node<T>* head) {//找到最后一个节点并在其后面链接新节点
	T val;//用来存储新数据
	Node<T>* p = head;
	cout << "即将添加新的节点" << endl;
	while (p->next) {//找到最后一个节点,注意循环判断条件
		p = p->next;
	}
	Node<T>* s = new Node<T>;
	cout << "请输入新节点储存的数据 : ";
	cin >> val;
	s->element = val;
	p->next = s;
	s->next = NULL;
	cout << "新节点添加完毕!" << endl;
}

template <typename T>
void List<T>::delNode(Node<T>* head) {//通过数据确认节点位置再删除节点
	int judge = 0;//用来判断数据是否存在于链表中,默认为0不存在
	T val;//被删除节点数据内容
	Node<T>* p = head;
	cout << "请输入要删除的节点数据 : ";
	cin >> val;
	while (p) {
		if (p->next->element == val) {//此处若找到数据则为该数据的前一节点
			judge = 1;
			break;
		}
		else
			p = p->next;
	}
	if (judge == 1) {
		/*将p节点赋值给s节点，接着将s移向数据节点，
		使数据节点的指针域赋值给前一指针达到删除效果*/
		Node<T>* s = p;
		s = s->next;
		p->next = s->next;
		delete s;//释放被删除节点
		cout << "节点删除成功!" << endl;
	}
	else
		cout << "未找到该数据" << endl;
}

template <typename T>
void List<T>::change(Node<T>* head) {//想法类似删除，但只进行数据的修改
	int judge = 0;//用来判断数据是否存在于链表中,默认为0不存在
	T val;//被修改节点数据内容
	Node<T>* p = head;
	cout << "请输入要修改的节点数据 : ";
	cin >> val;
	while (p) {
		if (p->element == val) {//此处若找到数据则为该数据节点(与删除有区别)
			judge = 1;
			break;
		}
		else
			p = p->next;
	}
	if (judge == 0) {
		cout << "未找到该数据" << endl;
	}
	else {
		cout << "成功找到该数据，请输入修改后的数据 : " ;
		cin >> val;
		p->element = val;
		cout << "修改成功!" << endl;
	}
}

template <typename T>
void List<T>::delList(Node<T>*head){//用两个相邻节点，一边移动一边释放
	int num = 1;//记录释放的节点数
	Node<T>* p = head;//用来移动的节点,最后释放
	cout << "即将释放链表中节点" << endl;
	while (p->next) {
		Node<T>* s = p;//用来释放的节点
		p = p->next;//节点移动到下一个
		delete s;//释放节点
		cout << "释放第" << num << "个节点" << endl;
		num++;
	}
	delete p;//最终释放
	cout << "释放第" << num << "个节点" << endl;
}

int main() {
	List<int>* list = new List<int>;
	int n;//用来执行各种功能接口
	cout << "****************************************************" << endl;
	cout << "*      欢迎使用USTIL第二次假期作业的链表程序       *" << endl;
	cout << "****************************************************" << endl;
	list->createList(list->getHead());
	cout << "****************************************************" << endl;
	cout << "*              请输入数字执行功能接口              *" << endl;
	cout << "*    1增加   2修改   3删除   4遍历   -1结束程序    *" << endl;
	cout << "****************************************************" << endl;
	while (cin >> n && n != -1) {
		if (n == 1)
			list->addNode(list->getHead());
		else if (n == 2)
			list->change(list->getHead());
		else if (n == 3)
			list->delNode(list->getHead());
		else if (n == 4)
			list->travel(list->getHead());
		else
			cout << "输入有误!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!啦啦啦" << endl;
		cout << "****************************************************" << endl;
	}
	list->delList(list->getHead());//释放链表
	cout << "程序即将关闭...." << endl;
	return 0;
}