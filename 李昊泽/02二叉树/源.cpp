#include<iostream>
using namespace std;

template <typename T>
class binNode {
public:
	/*成员变量*/
	T element;
	binNode<T>* lChild;
	binNode<T>* rChild;
	binNode<T>* parent;//双亲节点
	/*构造函数*/
	binNode() :parent(NULL) {};
	binNode(T val, binNode<T>* lC, binNode<T>* rC, binNode<T>* par)
		:element(val), lChild(lC), rChild(rC), parent(par) {};
};

template <typename T>
class binTree {
private:
	binNode<T>* root;//根节点
public:
	/*构造函数*/
	binTree() :root(NULL) {};
	/*功能接口*/
	binNode<T>* getRoot() { return root; }//获取根节点
	void insert(T val);//插入数据
	void insert(binNode<T>*& root, binNode<T>* node);//插入节点
	void preTrav(binNode<T>* root);//先序遍历
	void inTrav(binNode<T>* root);//中序遍历
	void postTrav(binNode<T>* root);//后序遍历
};

template <typename T> void binTree<T>::insert(binNode<T>*& root, binNode<T>* node) {
	binNode<T>* y = NULL;
	binNode<T>* x = root;
	/*找到插入位置*/
	while (x != NULL) {//排除空树影响
		/*若有根节点则从向下搜索到插入的位置*/
		y = x;//将这个位置赋值给y
		if (node->element > x->element)
			x = x->rChild;
		else
			x = x->lChild;
	}
	/*插入节点*/
	node->parent = y;//使y变成新节点的双亲结点
	if (y == NULL)	/*若空树则使新节点成为树根*/
		root = node;
	/*将大的值放在右孩子小值放左*/
	else if (node->element > y->element)
		y->rChild = node;
	else
		y->lChild = node;
}

template <typename T> void binTree<T>::insert(T val) {
	binNode<T>* node = new binNode<T>(val, NULL, NULL, NULL);
	insert(root, node);
}

template <typename T> void binTree<T>::preTrav(binNode<T>* root) {//先序遍历
	if (root) {
		cout << root->element << ' ';
		preTrav(root->lChild);
		preTrav(root->rChild);
	}
}
template <typename T> void binTree<T>::inTrav(binNode<T>* root) {//中序遍历
	if (root) {
		inTrav(root->lChild);
		cout << root->element << ' ';
		inTrav(root->rChild);
	}
}
template <typename T> void binTree<T>::postTrav(binNode<T>* root) {//后序遍历
	if (root) {
		postTrav(root->lChild);
		postTrav(root->rChild);
		cout << root->element << ' ';
	}
}

int main() {
	int val, num;
	binTree<int>* tree = new binTree<int>;
	cout << "即将开始建树，请输入数据， 输入-1时停止建树 : ";
	while (cin >> val && val != -1)
		tree->insert(val);
	cout << "************************************************" << endl;
	cout << "建树完成  请输入1， 2， 3 来分别执行先中后序遍历" << endl;
	cout << "************************************************" << endl;
	while (cin >> num && num != 0) {
		if (num == 1) {
			cout << "先序遍历 :";
			tree->preTrav(tree->getRoot());
			cout << "输入0退出程序" << endl;
		}
		else if (num == 2) {
			cout << "中序遍历 :";
			tree->inTrav(tree->getRoot());
			cout << "输入0退出程序" << endl;
		}
		else if (num == 3) {
			cout << "后序遍历 :";
			tree->postTrav(tree->getRoot());
			cout << "输入0退出程序" << endl;
		}
		else
		cout << "Wrong!" << endl;
	}
	return 0;
}