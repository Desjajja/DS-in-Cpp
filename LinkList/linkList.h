#define OK 1
#define ERROR 0
typedef int Status;
#include <cstddef>

template<class T>
class LinkList;//����

template<class T>
struct Node;//������

template<class T>
struct Node{
    T   Data;//������
    Node<T> *next;//ָ����
};

template<class T>
class LinkList{
    int length;//������
    Node<T> *header;//����ͷ���ָ��
    public:
    LinkList();
    //ȡ��ѭ��������ĵ�i�����
    T operator()(int i)const;
    //�ڵ�i�����֮ǰ����������Ϊe�Ľ��
    Status insertNode(int i, T e);
};

template<class T>
LinkList<T>::LinkList()
{
    length = 0;
    header      = new Node<T>;//���ٵ��������ڴ�
    header->Data = 0;
    header->next = NULL;//���Ϊ��
}

template<class T>
T LinkList<T>::operator()(int i)const
{
    if(!length || (i<1 || i>length))return ERROR;
    Node<T> *p = header;
    while(0 < i--) p = p->next;
    return p->Data;
}

template<class T>
Status LinkList<T>::insertNode(int i, T e)
{//ͷ���ʼ��Ϊ��
    Node<T> *pnewNode, *ptargetNode = header;//�½�㼰��ǰһλ���
    if(i<1||i>length+1)return ERROR;
    while (0 < --i) ptargetNode = ptargetNode->next;
    pnewNode = new Node<T>;
    pnewNode->Data = e;
    pnewNode->next = ptargetNode->next;
    ptargetNode->next = pnewNode;
    length++;
    return OK;
}
