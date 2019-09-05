#include <iostream>
#include <cstdio>
#include <string>
#include <dos.h>
#include <conio.h>
#include <iomanip>   
#include <windows.h>
using namespace std;

struct list1
{
	char a;
	list1* next;
	list1* prev;
};
struct list
{
	char man[32];
	char street[18];
	unsigned short number_home;
	unsigned short number_apart;
	char date[10];
	list* next;
	list* prev;
};
struct listup
{
	list* a;
	listup *next;
	listup *prev;
};
struct code
{
	float h;
	float l;
};
struct symbol
{
	char a;
	long double q;
	long double p;
};

class listc1
{
protected:
	list1 *head, *tail;
	int length;
public:
	listc1(int i) : head(NULL), tail(NULL)
	{
		length = 0;
		push(i);
	}
	listc1() : head(NULL), tail(NULL)
	{
		length = 0;
	}
	listc1& operator = (const listc1 & klass) {
		if (this != &klass)
		{
			head = tail = NULL;
			length = 0;
			list1* tmp = klass.head;
			while (tmp != NULL)
			{
				push(tmp->a);
				tmp = tmp->next;
			}
		}
		return *this;
	}
	void setLength(int x)
	{
		if (x == 0) length = 0;
		else length += x;
	}
	void setHead(list1* x)
	{
		head = x;
	}
	void setTail(list1* x)
	{
		tail = x;
	}
	int getLength()
	{
		return length;
	}
	list1* getHead()
	{
		return head;
	}
	list1* getTail()
	{
		return tail;
	}
	void push(char i)
	{
		length++;
		if (head == NULL)
		{
			struct list1* tmp = new list1;
			tmp->a = i;
			tmp->next = NULL;
			tmp->prev = NULL;
			head = tmp;
			tail = tmp;
		}
		else
		{
			struct list1* tmp = new list1;
			tmp->a = i;
			tmp->next = NULL;
			tmp->prev = tail;
			tail->next = tmp;
			tail = tmp;
		}
	}
	void output()
	{
		struct list1* tmp = head;
		cout << "  ";
		if (tmp == NULL) cout << "List is empty" << endl;
		else
		{
			try
			{
				while (1)
				{
					cout << (int)tmp->a << "";
					tmp = tmp->next;
					if (tmp == NULL) throw 1;
				}
			}
			catch (int i)
			{
			};
			cout << " " << length << endl;
		}
	}
	void DeleteList()
	{
		list1* tmp = getHead();
		while (tmp != NULL)
		{
			setHead(tmp->next);
			delete tmp;
			tmp = getHead();
		}
		length = 0;
	}
	void insert(int i, char n)
	{
		//cout << "0: " << (int)head->a << " " << (int)tail->a << endl;
		//cout << "1: " << i << " "<<length<< " " << (int)n<<endl;
		//cout << "2: ";
		//output();
		if ((i <= length) && (i>0))
		{
			length++;
			if (i == 1)
			{
				list1* tmp = new list1;
				tmp->a = n;
				tmp->next = head;
				head->prev = tmp;
				head = tmp;
				tmp->prev = NULL;
				tail = tail->next;
			}
			else
			{
				list1* ch = head;
				for (int j = 1; j < i; j++)
				{
					ch = ch->next;
				}
				list1* tmp = new list1;
				tmp->a = n;
				tmp->next = ch;
				tmp->prev = ch->prev;
				tmp->prev->next = tmp;
				ch->prev = tmp;
				tail = tail->next;
			}
		}
		else push(n);
		//cout << "3: ";
		//output();
	}
};
class listc
{
protected:
	list *head, *tail, *pauseh, *pauset;
	listup *headup, *tailup, *pausehu, *pausetu;
	int length;
	int page, pageup;
	int lastp;
	list **mass;
public:
	listc() : head(NULL), tail(NULL), pauseh(NULL), pauset(NULL), headup(NULL), tailup(NULL), pausehu(NULL), pausetu(NULL)
	{
		length = 0;
		page = 0;
		lastp = 0;
		pageup = 0;
	}
	listc& operator = (const listc & klass) {
		if (this != &klass)
		{
			head = tail = NULL;
			length = 0;
			page = 0;
			lastp = 0;
			if (&klass)
			{
				list* tmp = klass.head;
				while (tmp != NULL)
				{
					push(tmp->man, tmp->street, tmp->number_home, tmp->number_apart, tmp->date);
					tmp = tmp->next;
				}
			}
		}
		return *this;
	}
	void setLength(int x)
	{
		if (x == 0) length = 0;
		else length += x;
	}
	void setHead(list* x)
	{
		head = x;
	}
	void setTail(list* x)
	{
		tail = x;
	}
	int getLength()
	{
		return length;
	}
	list* getHead()
	{
		return head;
	}
	listup* getHeadup()
	{
		return headup;
	}
	listup* getTailup()
	{
		return tailup;
	}
	list* getTail()
	{
		return tail;
	}
	void push(char *name, char *street, unsigned int home, unsigned int apart, char *date)
	{
		length++;
		if (head == NULL)
		{
			struct list* tmp = new list;
			struct listup* tmpup = new listup;
			strcpy_s(tmp->man, name);
			strcpy_s(tmp->street, street);
			strcpy_s(tmp->date, date);
			tmp->number_home = home;
			tmp->number_apart = apart;
			tmp->next = NULL;
			tmp->prev = NULL;
			tmpup->a = tmp;
			tmpup->next = NULL;
			tmpup->prev = NULL;
			head = tmp;
			tail = tmp;
			headup = tmpup;
			tailup = headup;
		}
		else
		{
			struct list* tmp = new list;
			struct listup* tmpup = new listup;
			strcpy_s(tmp->man, name);
			strcpy_s(tmp->street, street);
			strcpy_s(tmp->date, date);
			tmp->number_home = home;
			tmp->number_apart = apart;
			tmp->next = NULL;
			tmp->prev = tail;
			tmpup->next = NULL;
			tmpup->a = tmp;
			tmpup->prev = tailup;
			tailup->next = tmpup;
			tailup = tmpup;
			tail->next = tmp;
			tail = tmp;
		}
	}
	void outputMEM(int n, int k)
	{
		int i = 1;
		if (headup == NULL) cout << "List is empty" << endl;
		else
		{
			if (k == 1)
			{
				if (pageup == 0)
				{
					pausetu = headup;
				}
				if (pausetu->next != NULL)
				{
					pausehu = pausetu;
				}
				else if (length%n != 1) pausetu = pausehu;
				else pausehu = pausetu;
				pageup++;
				if (length%n != 0)
				{
					if (length / n + 1 < pageup) {
						pageup--;
					}
				}
				else if (length / n < pageup) {
					pageup--;
				}
				while (i <= n)
				{
					cout << setw(6) << ((pageup -1)*n) + i << setw(33) << pausetu->a->man << setw(19) << pausetu->a->street
						<< setw(6) << pausetu->a->number_home << setw(6) << pausetu->a->number_apart << setw(11) << pausetu->a->date << endl;
					if (pausetu->next == NULL) break;
					pausetu = pausetu->next;
					i++;
				}
			}
			else if (k == 0)
			{
				if (pageup <= 1)
				{
					pausehu = pausetu = headup;
				}
				else if (pageup > 1)
				{
					while (i <= n)
					{
						pausehu = pausehu->prev;
						i++;
					}
					pausetu = pausehu;
					pageup--;
				}
				i = 1;
				while ((i <= n))
				{
					cout <<setw(6)<<((pageup-1)*n)+i << setw(33) << pausetu->a->man << setw(19) << pausetu->a->street
						<< setw(6) << pausetu->a->number_home << setw(6) << pausetu->a->number_apart << setw(11) << pausetu->a->date << endl;
					if (pausetu->next == NULL) break;
					pausetu = pausetu->next;
					i++;
				}
			}
		}
		while (i < n) { cout << endl; i++; }
		char r = '<', l = '>';
		if (pageup == 1) r = ' ';
		if (length%n != 0)
		{
			if (length / n + 1 == pageup) l = ' ';;
		}
		else if (length / n == pageup) l = ' ';
		cout <<r<<r<<" "<< pageup <<" " <<l<<l<< endl;
		cout << "0. Exit" << endl;
	}
	void output(int n, int k)
	{
		int i = 1;
		if (head == NULL) cout << "List is empty" << endl;
		else
		{
			if (k == 1)
			{
				if (page == 0)
				{
					pauset = head;
				}
				if (pauset->next != NULL)
				{
					pauseh = pauset;
				}
				else if (length%n != 1) pauset = pauseh;
				else pauseh = pauset;
				page++;
				if (length%n != 0)
				{
					if (length / n + 1 < page) {
						page--;
					}
				}
				else if (length / n < page) {
					page--;
				}
				while (i <= n)
				{
					cout << setw(6) << ((page - 1)*n) + i << setw(33) << pauset->man << setw(19) << pauset->street
						<< setw(6) << pauset->number_home << setw(6) << pauset->number_apart << setw(11) << pauset->date << endl;
					if (pauset->next == NULL) break;
					pauset = pauset->next;
					i++;
				}
			}
			else if (k == 0)
			{
				if (page <= 1)
				{
					pauseh = pauset = head;
				}
				else if (page > 1)
				{
					while (i <= n)
					{
						pauseh = pauseh->prev;
						i++;
					}
					pauset = pauseh;
					page--;
				}
				i = 1;
				while ((i <= n))
				{
					cout << setw(6) << ((page - 1)*n) + i << setw(33) << pauset->man << setw(19) << pauset->street
						<< setw(6) << pauset->number_home << setw(6) << pauset->number_apart << setw(11) << pauset->date << endl;
					if (pauset->next == NULL) break;
					pauset = pauset->next;
					i++;
				}
			}
		}
		while (i < n) { cout << endl; i++; }
		char r = '<', l = '>';
		if (page == 1) r = ' ';
		if (length%n != 0)
		{
			if (length / n + 1 == page) l = ' ';;
		}
		else if (length / n == page) l = ' ';
		cout << r << r << " " << page << " " << l << l << endl;
		cout << "0. Exit" << endl;
	}
	void output()
	{
		struct list* tmp = head;
		cout << "  ";
		if (tmp == NULL) cout << "List is empty" << endl;
		else
		{
			try
			{
				while (1)
				{
					cout << (int)tmp->number_home << " ";
					tmp = tmp->next;
					if (tmp == NULL) throw 1;
				}
			}
			catch (int i)
			{
			};
			cout << " " << length << endl;
		}
	}
	void DeleteList()
	{
		list* tmp = getHead();
		listup* tmpup = headup;
		while (tmp != NULL)
		{
			setHead(tmp->next);
			headup = tmpup->next;
			delete tmp;
			delete tmpup;
			tmp = getHead();
			tmpup = headup;
		}
		length = 0;
		page = 0;
		pageup = 0;
		lastp = 0;
	}
	list** GetMass()
	{
		list *tmp = head;
		mass = new list*[length+1];
		int i = 0;
		while (tmp != NULL)
		{
			mass[i] = tmp;
			tmp = tmp->next;
			i++;
		}
		mass[i] = NULL;
		return mass;
	}
};

class BTreeNode
{
	listc *keys;
	int t;
	BTreeNode **C;
	int n;
	bool leaf;
public:
	BTreeNode(int _t, bool _leaf);
	void insertNonFull(listc& k);
	void splitChild(int i, BTreeNode *y);
	void traverse();
	void DeleteTree();
	int heigth();
	int sumheigth(int l);
	listc* search(int k);
	friend class BTree;
};
class BTree
{
	BTreeNode *root;
	int t;
	int Value;
	int N;
public:
	BTree(int _t)
	{
		root = NULL;  t = _t; Value = 0; N = 0;
	}
	void traverse()
	{
		if (root != NULL) root->traverse();
	}
	void DeleteTree()
	{
		if (root != NULL) //root->DeleteTree();
		root = NULL;
	}
	listc* search(int k)
	{
		if (root)
		return root->search(k);
	}
	void insert(listc& k);
	int value()
	{
		return Value;
	}
	int n()
	{
		return N;
	}
	int heigth()
	{
		return root->heigth();
	}
	float mheigth()
	{
		return ((float)root->sumheigth(1) / N);
	}
};
BTreeNode::BTreeNode(int t1, bool leaf1)
{
	t = t1;
	leaf = leaf1;
	keys = new listc[2 * t - 1];
	C = new BTreeNode *[2 * t];
	n = 0;
}
void BTreeNode::traverse()
{
	//cout << "" << endl;
	int i;
	for (i = 0; i < n; i++)
	{
		//	cout << " " << keys[i];
		if (leaf == false)
			C[i]->traverse();
		cout << leaf << " ";
		keys[i].output(keys[i].getLength(),1);
	}
	if (leaf == false)
		C[i]->traverse();
}
listc* BTreeNode::search(int k)
{
	int i = 0;
	while (i < n && k > keys[i].getHead()->number_home)
		i++;
	if (keys[i].getHead() != NULL)
	if (keys[i].getHead()->number_home == k)
		return &keys[i];
	if (leaf == false)
	{
		C[i]->search(k);
	}
	else return NULL;
}
void BTree::insert(listc& k)
{
	Value += k.getHead()->number_home;
	N++;
	if (root == NULL)
	{
		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
	}
	else
	{
		if (root->n == 2 * t - 1)
		{
			int i = root->n-1; int kk = 0;
			while (i >= 0 /*&& root->keys[i].getHead()->number_home >= k.getHead()->number_home*/)
			{
				if (root->keys[i].getHead()->number_home == k.getHead()->number_home)
				{
					root->keys[i].push(k.getHead()->man, k.getHead()->street, k.getHead()->number_home,
						k.getHead()->number_apart, k.getHead()->date);
					kk = 1;
				}
				i--;
			}
			if (kk == 0)
			{
				BTreeNode *s = new BTreeNode(t, false);
				s->C[0] = root;
				s->splitChild(0, root);
				int i = 0;
				if (s->keys[0].getHead()->number_home < k.getHead()->number_home)
					i++;
				s->C[i]->insertNonFull(k);
				root = s;
			}
		}
		else
			root->insertNonFull(k);
	}
	//traverse();
}
void BTreeNode::insertNonFull(listc& k)
{
	//cout << "-----" << k.getHead()->number_home << endl;
	int i = n-1, kk=0;
	if (leaf == true)
	{
		while (i >= 0 /*&& keys[i].getHead()->number_home >= k.getHead()->number_home*/)
		{
			if (keys[i].getHead()->number_home == k.getHead()->number_home)
			{
				keys[i].push(k.getHead()->man, k.getHead()->street, k.getHead()->number_home,
					k.getHead()->number_apart, k.getHead()->date);
				kk = 1;
			}
			i--;
		}
		if (kk == 0)
		{
			i = n - 1;
			while (i >= 0 && keys[i].getHead()->number_home > k.getHead()->number_home)
			{
				keys[i + 1] = keys[i];
				i--;
			}
			keys[i + 1] = k;
			n++;
		}
	}
	else
	{
		while (i >= 0 /*&& keys[i].getHead()->number_home >= k.getHead()->number_home*/)
		{
			if (keys[i].getHead()->number_home == k.getHead()->number_home)
			{
				keys[i].push(k.getHead()->man, k.getHead()->street, k.getHead()->number_home,
					k.getHead()->number_apart, k.getHead()->date);
				kk = 1;
			}
			i--;
		}
		i = n-1;
		if (kk == 0)
		{
			while (i >= 0 && keys[i].getHead()->number_home > k.getHead()->number_home)
			{
				i--;
			}
			if (C[i + 1]->n == 2 * t - 1)
			{
				splitChild(i + 1, C[i + 1]);
				if (keys[i + 1].getHead()->number_home == k.getHead()->number_home)
				{
					keys[i + 1].push(k.getHead()->man, k.getHead()->street, k.getHead()->number_home,
						k.getHead()->number_apart, k.getHead()->date);
					kk = 1;
				}
				else if (keys[i + 1].getHead()->number_home < k.getHead()->number_home) i++;
			}
			if (kk==0)
			C[i + 1]->insertNonFull(k);
		}
	}
}
void BTreeNode::splitChild(int i, BTreeNode *y)
{
	BTreeNode *z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;
	for (int j = 0; j < t - 1; j++)
		z->keys[j] = y->keys[j + t];
	if (y->leaf == false)
	{
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}
	y->n = t - 1;
	//cout << n;
	for (int j = n; j >= i + 1; j--)
		C[j + 1] = C[j];
	C[i + 1] = z;
	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];
	keys[i] = y->keys[t - 1];
	n++;
}
int BTreeNode::heigth()
{
	if (leaf == true)
		return 1;
	else
	{
		int *a, i, max = 0;
		a = new int[t * 2];
		for (i = 0; i <= n; i++)
		{
			if (leaf == false)
			{
				a[i] = 1 + C[i]->heigth();
				if (max < a[i]) max = a[i];
			}
			else max = 0;
		}
		return max;
	}
	//return 1;
}
int BTreeNode::sumheigth(int l)
{
	if (leaf == true) return l;
	int sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += C[i]->sumheigth(l + 1);
	}
	sum += l;
	return sum;
}

void merge(listc &a, int q, listc &b, int r, listc &c)
{
	list* temp_a = a.getHead();
	list* temp_b = b.getHead();
	while (q&&r)
	{
		char s1[3], s2[3];
		memset(s1,'\0', 3);
		memset(s2, '\0', 3);
		s1[0] = temp_a->date[6]; s1[1] = temp_a->date[7];
		s2[0] = temp_b->date[6]; s2[1] = temp_b->date[7];
		if (strcmp(s1,s2)<0)
		{
			c.push(temp_a->man, temp_a->street, temp_a->number_home, temp_a->number_apart, temp_a->date);
			temp_a = temp_a->next;
			a.setHead(a.getHead()->next);
			q--;
		}
		else if (strcmp(s1, s2)>0)
		{
			c.push(temp_b->man, temp_b->street, temp_b->number_home, temp_b->number_apart, temp_b->date);
			temp_b = temp_b->next;
			b.setHead(b.getHead()->next);
			r--;
		}
		else if (strcmp(temp_a->street, temp_b->street) <=0)
		{
			c.push(temp_a->man, temp_a->street, temp_a->number_home, temp_a->number_apart, temp_a->date);
			temp_a = temp_a->next;
			a.setHead(a.getHead()->next);
			q--;
		}
		else 
		{
			c.push(temp_b->man, temp_b->street, temp_b->number_home, temp_b->number_apart, temp_b->date);
			temp_b = temp_b->next;
			b.setHead(b.getHead()->next);
			r--;
		}
	}
	while (q > 0)
	{
		c.push(temp_a->man, temp_a->street, temp_a->number_home, temp_a->number_apart, temp_a->date);
		temp_a = temp_a->next;
		a.setHead(a.getHead()->next);
		q--;
	}
	while (r > 0)
	{
		c.push(temp_b->man, temp_b->street, temp_b->number_home, temp_b->number_apart, temp_b->date);
		temp_b = temp_b->next;
		b.setHead(b.getHead()->next);
		r--;
	}
}
void separation(listc &c, listc &a, listc &b, int &n)
{
	a.setHead(c.getHead());
	b.setHead(c.getHead()->next);
	list* temp_a = a.getHead();
	list* temp_b = b.getHead();
	n = 1;
	while (temp_b != NULL)
	{
		n = n + 1;
		temp_a->next = temp_b->next;
		temp_a = temp_b;
		temp_b = temp_b->next;
	}
	c.setHead(0);
	c.setTail(0);
}
void MergeSort(listc &list)
{
	int n = list.getLength();
	listc a, b;
	listc c[2];
	separation(list, a, b, n);
	int p = 1, q, r;
	while (p < n)
	{
		int i = 0, m = n;
		c[0].setHead(0);
		c[1].setHead(0);
		c[0].setTail(c[0].getHead());
		c[1].setTail(c[1].getHead());
		while (m > 0)
		{

			if (m >= p) q = p;
			else q = m;
			m -= q;
			if (m >= p) r = p;
			else r = m;
			m -= r;
			merge(a, q, b, r, c[i]);
			i = 1 - i;
		}
		a.setHead(c[0].getHead());
		b.setHead(c[1].getHead());
		a.setTail(c[0].getTail());
		b.setTail(c[1].getTail());
		p = 2 * p;
	}
	list.setHead(c[0].getHead());
	list.setTail(c[0].getTail());
}
void Search(list** mass,int l ,int r, char *s, listc &a)
{
	if (mass[0] != NULL)
	{
		int m;
		char s1[3], s2[3];
		memset(s1, '\0', 3);
		s1[0] = s[0]; s1[1] = s[1];
		while (l < r) {
			m = ((l + r) / 2);
			memset(s2, '\0', 3);
			s2[0] = mass[m]->date[6]; s2[1] = mass[m]->date[7];
			if (strcmp(s1, s2) > 0) l = m + 1;
			else r = m;
		}
		memset(s2, '\0', 3);
		s2[0] = s1[0]; s2[1] = s1[1];
		while ((strcmp(s2, s1) == 0) && (mass[r] != NULL))
		{
			s2[0] = mass[r]->date[6]; s2[1] = mass[r]->date[7];
			if (strcmp(s2, s1) == 0) {
				a.push(mass[r]->man, mass[r]->street, mass[r]->number_home, mass[r]->number_apart, mass[r]->date);
				r++;
			}
		}
	}
}

void BuildTree(listc a, BTree& tree)
{
	listup* tmp = a.getHeadup();
	listc k;
	while (tmp != NULL)
	{
		k.DeleteList();
		k.push(tmp->a->man, tmp->a->street, tmp->a->number_home, tmp->a->number_apart, tmp->a->date);
		tree.insert(k);
		tmp = tmp->next;
	}
}
code GilbMur(int n, double* P, double* Q, int* L, listc1* C)
{
	code ll;
	ll.h = 0, ll.l = 0;
	Q[0] = 0;
	L[0] = (int)(-1 * log2(P[0]) + 1);
	for (int i = 1; i <= n; i++)
	{
		Q[i] = Q[i - 1] + P[i - 1];
		if (P[i] > 0)
		{
			L[i] = (int)(-1 * log2(P[i]) + 2);
		}
		ll.h += -P[i] * (log2(P[i]));
		ll.l += P[i] * L[i];
	}
	for (int i = 0; i < n; i++)
	{
		Q[i] += P[i] / 2;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < L[i]; j++)
		{
			Q[i] *= 2;
			if ((char)(Q[i]) == 2)
			{
				C[i].push(0);
			}
			else
			{
				C[i].push(Q[i]);
			}
			if (Q[i] > 1)
			{
				Q[i]--;
			}
		}
	}
	return ll;
}
void QuickSortScnd(symbol *a, int l, int n)
{
	int k = 0;
	while (l < n)
	{
		double x = a[(n + l) / 2].p;
		int  i = l, j = n;
		while (i < j)
		{
			while (a[i].p < x)
			{
				i++;
			}
			while (a[j].p > x)
			{
				j--;
			}
			if (i <= j)
			{
				symbol t = a[j];
				a[j] = a[i];
				a[i] = t;
				i++;
				j--;
			}
		}
		if ((j - l) < (n - i))
		{
			QuickSortScnd(a, l, j);
			l = i;
		}
		else
		{
			QuickSortScnd(a, i, n);
			n = j;
		}
	}
}
void reverse(symbol *a, int N)
{
	symbol tt;
	char t;
	for (int i = 1; i < N / 2; i++)
	{
		tt = a[(N)-i];
		a[(N)-i] = a[i];
		a[i] = tt;
	}
}
void reverse1(symbol *a, int N)
{
	symbol tt;
	for (int i = 0; i < N / 2; i++)
	{
		tt = a[(N - 1) - i];
		a[(N - 1) - i] = a[i];
		a[i] = tt;
	}
}
int main()
{
	code ll;
	symbol sym[256];
	FILE *f;
	unsigned char chtmp[1];
	char ch = 1, ch1 = 1;
	char m[32], d[10];
	char str[18], tmpstr[18];
	short int ap, h;
	long double lll=0;
	int n, n_ch, stop_i = 0;
	listc1* c; int *l; double *p, *q;
	c = new listc1[256];
	p = new double[256];
	q = new double[256];
	l = new int[256];
	listc ah, ck;
	list** mass;
	BTree tree1(2);
	while (ch != '0')
	{
		system("CLS");
		cout << "1. Show Base" << endl;
		cout << "2. Read File" << endl;
		cout << "3. Sort Base" << endl;
		cout << "4. Show Sorted Base" << endl;
		cout << "5. Binary Search" << endl;
		cout << "6. Build Tree" << endl;
		cout << "7. Search in Tree" << endl;
		cout << "8. Gilbert-Moore" << endl;
		//cout << "9. Sort Base" << endl;
		cout << "0. Exit" << endl;
		//cin >> ch;
		ch = _getch();
		system("CLS");
		switch (ch)
		{
		case '1':
			ah.outputMEM(20, 1);
			while (ch1 != '0')
			{
				ch1 = _getch();
				//cin >> ch1;
				switch (ch1)
				{
				case '2':
					system("CLS");
					ah.outputMEM(20, 1);
					break;
				case '1':
					system("CLS");
					ah.outputMEM(20, 0);
					break;
				}
			}
			ch1 = 1;
			break;
		case '2':
			fopen_s(&f, "testBase4.dat", "r");
			n_ch = 0;
			while (!feof(f))
			{
				fread(m, sizeof(char), 32, f);
				fread(str, sizeof(char), 18, f);
				fread(&h, sizeof(unsigned short), 1, f);
				fread(&ap, sizeof(unsigned short), 1, f);
				fread(d, sizeof(char), 10, f);
				ah.push(m, str, h, ap, d);
			}
			fclose(f);
			fopen_s(&f, "testBase4.dat", "r");
			for (int i = 0; i < 256; i++)
			{
				sym[i].a = i;
				sym[i].p = 0;
				sym[i].q = 0;
			}
			while (!feof(f))
			{
				fread(chtmp, sizeof(unsigned char), 1, f);
				sym[chtmp[0]].p++;
				n_ch++;
			}
			QuickSortScnd(sym, 0, 255);
			reverse(sym, 256);
			for (int i = 1; i < 256; i++)
			{
				if ((sym[i].p < 26)&&(sym[i].p!=0))
				{
					n_ch += (26 - sym[i].p);
					sym[i].p = 26;
				}
			}
			for (int i = 1; i < 256; i++)
			{
				if (sym[i].p == 0)
				{
					stop_i = i;
					//cout << stop_i << endl;
					break;
				}
				sym[i].p = sym[i].p / n_ch;
			}
			c = new listc1[stop_i + 1];
			p = new double[stop_i + 1];
			for (int i = 0; i < stop_i; i++)
			{
				p[i] = sym[i].p;
			}
			q = new double[stop_i + 1];
			l = new int[stop_i + 1];
			fclose(f);
			break;
		case '3':
			if(ah.getHead())
			MergeSort(ah);
			break;
		case '4':
			ah.output(20, 1);
			while (ch1 != '0')
			{
				ch1 = _getch();
				//cin >> ch1;
				switch (ch1)
				{
				case '2':
					system("CLS");
					ah.output(20, 1);
					break;
				case '1':
					system("CLS");
					ah.output(20, 0);
					break;
				}
			}
			ch1 = 1;
			break;
		case '5':
			ck.DeleteList();
			mass = ah.GetMass();
			char aa[20];
			memset(aa, '/0', 20);
			cin >> aa;
			Search(mass, 0, ah.getLength(), aa, ck);
			ck.output(20, 1);
			while (ch1 != '0')
			{
				ch1 = _getch();
				//cin >> ch1;
				switch (ch1)
				{
				case '2':
					system("CLS");
					ck.output(20, 1);
					break;
				case '1':
					system("CLS");
					ck.output(20, 0);
					break;
				}
			}
			ch1 = 1;
			break;
		case '6':
			tree1.DeleteTree();
			BuildTree(ah, tree1);
			tree1.traverse();
			system("PAUSE");
			break;
		case '7':
			//ck.DeleteList();
			int k;
			cin>>k;
			ck = *tree1.search(k);
			ck.output(20, 1);
			while (ch1 != '0')
			{
				ch1 = _getch();
				//cin >> ch1;
				switch (ch1)
				{
				case '2':
					system("CLS");
					ck.output(20, 1);
					break;
				case '1':
					system("CLS");
					ck.output(20, 0);
					break;
				}
			}
			ch1 = 1;
			break;
		case '8':
			ll = GilbMur(stop_i-1, p, q, l, c);
			//cout << stop_i << endl;
			for (int i = 0; i < stop_i; i++)
			{
				cout << setw(4) << sym[i].a << setw(15) << sym[i].p;
				c[i].output();
				lll += p[i];
			}
			cout << ll.h << " " << ll.l << " " << lll;
			system("PAUSE");
			break;
		case '9':
			break;
		}
		//system("pause");
	}
	return 0;
}


