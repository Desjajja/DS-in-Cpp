#define OK 1
#define ERROR 0
typedef int Status;
#include <cstddef>

template <class T>
class LinkList; //����

template <class T>
struct Node; //������

template <class T>
struct Node
{
	T Data;		   //������
	Node<T> *next; //ָ����
};

template <class T>
class LinkList
{
	Node<T> *header; //����ͷ���ָ��
public:
	int length; //������
	LinkList();
	//ȡ��ѭ��������ĵ�i�����
	T operator()(int i) const;
	//�ڵ�i�����֮ǰ����������Ϊe�Ľ��
	Status insertNode(int i, T e);
	//�жϷ�ѭ���������Ƿ�Ϊ��
	Status ifEmpty();
	//������e����compare()��ϵ�Ľ��,Ĭ�ϲ��ҵ�һ��
	int compareNode(T e, Status (*compare)(T, T), int L = 1);
	//����ĳ���(��֪������)ǰ����λ��
	int getPrevious(T e);
	//���غ�̵�λ��
	int getNext(T e);
	//ɾ��������Ϊe�ĵ�һ�����
	Status removeFirst(T e, int L = 1);
	//ɾ���ظ��Ľ��
	Status removeRedundant();
};

//compare����ʵ��
template <class T>
Status equal(T e1, T e2)
{
	return e1 == e2;
}

template <class T>
Status lessThan(T e1, T e2)
{
	return (e1 < e2);
}

template <class T>
Status greaterThan(T e1, T e2)
{
	return (e1 > e2);
}
//compare����

template <class T>
LinkList<T>::LinkList()
{
	length = 0;
	header = new Node<T>; //���ٵ��������ڴ�
	header->Data = 0;
	header->next = NULL; //���Ϊ��
}

template <class T>
T LinkList<T>::operator()(int i) const //������أ����ص�iλָ��������
{
	if (!length || (i < 1 || i > length))
		return ERROR;	 //����Ϊ���λ�򲻺Ϸ�������error
	Node<T> *p = header; //ѭ����ʼ��ͷ�ڵ�
	while (0 < i--)
		p = p->next;
	return p->Data;
}

template <class T>
Status LinkList<T>::insertNode(int i, T e)
{ //ͷ���ʼ��Ϊ��
	if (i < 1 || i > length + 1)
		return ERROR;
	Node<T> *pnewNode, *ptargetNode = header; //�½�㼰��ǰһλ���
	while (0 < --i)
		ptargetNode = ptargetNode->next;
	pnewNode = new Node<T>;
	pnewNode->Data = e;
	pnewNode->next = ptargetNode->next; //����
	ptargetNode->next = pnewNode;		//����
	length++;
	return OK;
}

template <class T>
Status LinkList<T>::ifEmpty()
{
	return (!length) ? OK : ERROR;
}

template <class T>
inline int LinkList<T>::compareNode(T e, Status (*compare)(T, T), int L)
{
	Node<T> *pinit = header;
	for (int i = 0; i < L; i++)
		pinit = pinit->next; //����pinitΪ��Lλ���
	while (L <= length && !compare(pinit->Data, e))
	{
		pinit = pinit->next; L++;
	}
	return (L <= length) ? L : 0;
}

template <class T>
inline int LinkList<T>::getPrevious(T e)
{
	return compareNode(e, equal) ? compareNode(e, equal) - 1 : 0;
}

template <class T>
inline int LinkList<T>::getNext(T e)
{
	return compareNode(e, equal) ? compareNode(e, equal) + 1 : 0;
}

template <class T>
inline Status LinkList<T>::removeFirst(T e, int L)
{
	int ord = compareNode(e, equal);
	if (!ord)
		return ERROR; //�����ڸý�㣬ɾ��ʧ��
	Node<T> *pObjNode = header;
	for (int i = 1; i < ord; i++)
	{
		pObjNode = pObjNode->next;
	}									   //ǰһλ���
	pObjNode->next = pObjNode->next->next; //û�л��շ���ָ����ڴ棬������ָ��
	length--;
	return OK;
}

template <class T>
inline Status LinkList<T>::removeRedundant()
{
	if (length < 0) return ERROR;//���Ȳ��Ϸ�
	LinkList<T> L2;//�����������ȥ�߽��
	Node<T>* pObj = header->next;//��һλ���
	for (int i = 1; i <= length; i++) {
		if (!(L2.compareNode(pObj->Data, equal)))//��ȥ�������в�����Ŀ�����������
			L2.insertNode(L2.length + 1, pObj->Data);//���ý��������һλ
		pObj = pObj->next;
	}
	*this = L2;
	return OK;
}
