#include <sqlist.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include<iomanip>
#include"sqlist.h"
#include <iomanip>

struct Student
{
    int series=0;//ѧ��
    std::string name="";//����
    int Chinese=0;
    int English=0;
    int Math=0;
    float Average=0;
    int Total = 0;
};//����ѧ���������ͽṹ��


template<class ElemType>
class SqList
{
private:
    ElemType       *elem;//ָ��Ԫ�ص�ַ
    int            length;//˳���ǰ����
    int            listsize;//�������
public:
    SqList();//Ϊ˳�������ڴ�
    ~SqList();
    int insertElem(ElemType e, int i);//�ڵ�iλ֮ǰ����Ԫ��e
    int listEmpty();//�ж����Ա��Ƿ�Ϊ��
    int getElem(int i, ElemType &e);//ȡ��i��Ԫ�أ�
    int compareElem(ElemType e, int (*compare)(ElemType, ElemType));//���ص�һ����e����compare��ϵ��Ԫ�����
    int getPrevious(ElemType e, ElemType &e2);
    int getNext(ElemType e, ElemType &e2);//ȡĳԪ�ص�ǰ������̣���e2����   
    int deleteElem(int i,ElemType &e);//ɾ����i��Ԫ��
    int inheratateList(SqList<ElemType> &L2);//����˳���ֵ����һ��˳���
    int emptyList();//�ÿ�˳���
    int spawnList(int=8/*Ĭ�ϳ���Ϊ8*/);
    int inputList(int=8);
    void dispList();//��ӡ˳���
    int inputStudent(ElemType& Stu);//���뵥��ѧ������Ϣ�����ô��ݸ�Stu
    void dispStu();//û�취 ֻ�ܵ�����ѧ����д����ӡ�����ˡ���
};

template<class ElemType>
SqList<ElemType>::SqList()
{
    listsize = LISTMAXSIZE;
    elem = new ElemType[listsize];
    length = 0;
}

template<class ElemType>
SqList<ElemType>::~SqList()
{
    delete[] elem;
}

template<class ElemType>
int SqList<ElemType>::insertElem(ElemType e, int i)
{
    ElemType *newbase; int istart, iend;
    if(i<1||i>length+1)return 0;//Ԫ��λ�ò��Ϸ�
    if (length + 1 > LISTMAXSIZE)
    {//�����������������
        newbase = new ElemType[length+LISTINCREMENT];
        if(!newbase)return 0;//����ʧ�ܣ�����ʧ��
        for(istart=0;istart<length;istart++){
            newbase[istart] = elem[istart];
            delete[] elem;//ɾ��ԭ�ڴ�
            elem = newbase;//elemָ�����ڴ�ռ�
            listsize += LISTINCREMENT;
        }
    }
    for(iend=length;iend>=i;iend--){
            elem[iend] = elem[iend-1];
        }//i֮��Ԫ�������λ
        elem[i-1] = e;
        ++length;
    return 1;//����ɹ�
}

template<class ElemType>
int SqList<ElemType>::listEmpty(){
    if (length == 0) return 1;//��
    return 0;//�ǿ�
}

template<class ElemType>
int SqList<ElemType>::getElem(int i, ElemType &e)
{
    if(i<1||i>length)return 0;//λ����Ч
    e = elem[i-1];
    return 1;//��ȡ�ɹ�
}

template<typename ElemType>
int equal(ElemType e1, ElemType e2){
    return (e1==e2)?(1):(0);
}

template<typename ElemType>
int greaterThan(ElemType e1, ElemType e2){
    return (e1>e2)?(1):(0);
}

template<typename ElemType>
int lessThan(ElemType e1, ElemType e2){
    return (e1<e2)?(1):(0);
}

template<class ElemType>
int SqList<ElemType>::compareElem(ElemType e, int (*compare)(ElemType, ElemType))
{
    int i;
    for(i=0;i<length;i++){
        if(compare(elem[i], e))return(i+1);//����λ����ţ���1��ʼ��
    }
    return 0;//û��ƥ��
}

template<class ElemType>
int SqList<ElemType>::getPrevious(ElemType e, ElemType &e2)
{
    int i = compareElem(e, equal) - 1;//ǰһ��Ԫ�ص�i
    return getElem(i, e2);
}

template<class ElemType>
int SqList<ElemType>::getNext(ElemType e, ElemType &e2)
{
    int i = compareElem(e, equal) + 1;//��һ��Ԫ�ص�i
    return getElem(i, e2);
}

template<class ElemType>
int SqList<ElemType>::deleteElem(int i, ElemType &e)
{
    int j;
    if(i<1||i>length)return 0;
    getElem(i, e);
    for(j=i-1;j<length-1;j++){
        elem[j] = elem[j+1];
    }
    --length;
    return 1;
}

template<class ElemType>
int SqList<ElemType>::inheratateList(SqList<ElemType> &L2)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(L2.insertElem(elem[i],i+1))continue;
        else return 0;
    }
    return 1;
}

template<class ElemType>
int SqList<ElemType>::emptyList()
{
    length = 0;
    return 1;//�����к����ж��Ƿ��ÿ�
}

template<class ElemType>
int SqList<ElemType>::spawnList(int l)
{
    int i;
    if(emptyList()){
        unsigned seed = std::time(0);
        std::srand(seed);
        for(i=0;i<l;i++){
            insertElem(std::rand()%100, 1);
        }
    return 1;
    }
    else return 0;
}

template<class ElemType>
int SqList<ElemType>::inputList(int l)
{
    int i, input;
    emptyList();
    for(i=0;i<l;i++){
        std::cout<<"�������"<<i+1<<"��Ԫ�أ���"<<l<<"����"<<std::endl;
        std::cin>>input;
        if(insertElem(input,i+1))continue;
        else return 0;
    }
    return 1;
}

template<class ElemType>
void SqList<ElemType>::dispList()
{
    int i;
    if(length==0){std::cout<<"�ձ�"<<std::endl;return;}
    std::cout<<"��ǰ˳���Ԫ��Ϊ��"<<std::endl;
    for(i=0;i<length;i++){
        std::cout<<"��"<<std::setw(2)<<i+1<<"��";
        //printf("��%2d��",i+1);
    }
    std::cout<<std::endl;
    for(i=0;i<length;i++){
        std::cout<<"  "<<std::setw(2)<<elem[i]<<"  ";
        //printf("  %2d  ",elem[i]);
    }
    printf("\n");

}

template<class ElemType>
int SqList<ElemType>::inputStudent(ElemType &Stu)
{
    std::cout<<"�������ѧ����ѧ�ţ�";
    std::cin>>Stu.series;
    std::cout<<std::endl;
    std::cout<<"������";
    std::cin>>Stu.name;
    std::cout<<std::endl;
    std::cout<<"���ĳɼ���";
    std::cin>>Stu.Chinese;
    std::cout<<std::endl;
    std::cout<<"Ӣ��ɼ���";
    std::cin>>Stu.English;
    std::cout<<std::endl;
    std::cout<<"��ѧ�ɼ���";
    std::cin>>Stu.Math;
    std::cout<<std::endl;
    Stu.Average = (Stu.Chinese+Stu.English+Stu.Math)/3.0;
    Stu.Total = Stu.Chinese + Stu.English + Stu.Math;
    return 1;
}

template<class ElemType>
void SqList<ElemType>::dispStu()
{
    int i;
    if(length==0){std::cout<<"�ձ�"<<std::endl;return;}
    std::cout<<"��ӡѧ����Ϣ"<<std::endl;
    std::cout<<" ѧ��   ����   ����   Ӣ��   ��ѧ   ƽ����   �ܷ�"<<std::endl;
    for(i=0;i<length;i++){
        std::cout<<" "<<std::setw(2)<<elem[i].series
        <<"   "<<std::setw(6)<<std::setiosflags(std::ios::right)<<elem[i].name
        <<"   "<<std::setiosflags(std::ios::right)<<std::setw(3)<<elem[i].Chinese
        <<"    "<<std::setiosflags(std::ios::right)<<std::setw(3)<<elem[i].English
        <<"    "<<std::setiosflags(std::ios::right)<<std::setw(3)<<elem[i].Math
        <<"    "<<std::setiosflags(std::ios::right)<<std::setw(3)<<std::setprecision(5)<<elem[i].Average
        <<"   "<<std::setiosflags(std::ios::right)<<elem[i].Total<<std::endl;
    }
}
