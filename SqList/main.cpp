#include "sqlist.h"
#include<iostream>
using namespace std;

int main(){
    int option, i, e, e2;
    printf("*******˳������*******\n");
    SqList<int> L, L2, L3;
    while(1)
    {
    cout<<"��ǰ˳���Ϊ";
    L.dispList();
    printf("�������룺");
    scanf("%d", &option);
    switch(option){
        case 1:
        printf("����Ԫ�ص�λ��ֵ��");
        printf("\n");
        scanf("%d %d", &i, &e);
        if(L.insertElem(e, i))printf("�����ɹ���\n");
        else printf("����ʧ�ܡ�\n");
        printf("\n");
        L.dispList();
        printf("*********************************************\n");
        printf("\n");
        printf("\n");
        printf("*********************************************\n");
        continue;
        case 2:
        printf("�ж��Ƿ�Ϊ�ձ�\n");
        if(L.listEmpty())printf("�ǿձ�\n");
        else printf("�ǿ�\n");
        continue;

        case 3:
        printf("ȡָ��λ���Ԫ�أ��������λ�ã�");
        scanf("%d", &i);
        if(L.getElem(i, e))printf("ȡ�õ�%dλԪ��%d\n", i, e);
        else printf("����ʧ��\n");
        continue;

        case 4:
        cout<<"�Ƚ�Ԫ��"<<endl;
        cout<<"���Ƚ�Ԫ��"<<endl;
        cin>>e;
        cout<<"��1�����Ԫ�أ���2�����ڸ�Ԫ�أ���3��С�ڸ�Ԫ��"<<endl;
        cin>>option;
        switch(option){
            case 1:
            if(!(i = L.compareElem(e, equal)))cout<<"û��ƥ�䵽��Ԫ��"<<endl;
            else {
                L.getElem(i, e);
                cout<<"��"<<i<<"λԪ��"<<e<<"����ù�ϵ"<<endl;
                }
            break;

            case 2:
            if(!(i = L.compareElem(e, greaterThan)))cout<<"û��ƥ�䵽��Ԫ��"<<endl;
            else {
                L.getElem(i, e);
                cout<<"��"<<i<<"λԪ��"<<e<<"����ù�ϵ"<<endl;
                }
            break;

            case 3:
            if(!(i = L.compareElem(e, lessThan)))cout<<"û��ƥ�䵽��Ԫ��"<<endl;
            else {
                L.getElem(i, e);
                cout<<"��"<<i<<"λԪ��"<<e<<"����ù�ϵ"<<endl;
                }
            break;
        }
        continue;

        case 5:
        cout<<"ȡǰһ��Ԫ�أ�������Ŀ��Ԫ��"<<endl;
        cin>>e;
        if(!L.getPrevious(e, e2))cout<<"�����ڸ�Ԫ��"<<endl;
        else cout<<"ǰ��Ϊ"<<e2<<endl;
        continue;

        case 6:
        cout<<"ȡ��һ��Ԫ�أ�������Ŀ��Ԫ��"<<endl;
        cin>>e;
        if(!L.getNext(e, e2))cout<<"�����ڸ�Ԫ��"<<endl;
        else cout<<"���Ϊ"<<e2<<endl;
        continue;

        case 7:
        cout<<"������Ҫɾ��Ԫ�ص�λ��"<<endl;
        cin>>i;
        if(!L.deleteElem(i, e))cout<<"λ�򲻺Ϸ�������ʧ��"<<endl;
        else cout<<"�ɹ�ɾ����"<<i<<"λԪ��"<<e<<endl;
        continue;

        case 8:
        cout<<"��˳���ֵ����һ��˳���"<<endl;
        if(!L.inheratateList(L2))cout<<"����ʧ�ܣ�"<<endl;
        else{
            cout<<"�����ɹ���������˳���";
            L2.dispList();
            cout<<endl;
        }
        continue;

        case 9:
        cout<<"�ÿյ�ǰ˳���"<<endl;
        if(L.emptyList())cout<<"�����ɹ�"<<endl;
        else cout<<"����ʧ��"<<endl;
        continue;

        case 10:
        cout<<"��������б�"<<endl;
        if(!L.spawnList())cout<<"����ʧ��"<<endl;
        else{
            cout<<"�����ɹ�!"<<endl;
        }
        continue;

        case 11:
        cout<<"����˳���:"<<endl;
        cout<<"������˳����ȣ�Ĭ�ϳ���Ϊ8����";
        cin>>i;
        cout<<endl;
        if(!L.inputList(i))cout<<"����ʧ��"<<endl;
        else cout<<"�����ɹ�"<<endl;
        continue;

        case 12:
        cout<<"������"<<endl;
        cout<<"��1��";
        L.dispList();
        cout<<"��2��";
        L2.dispList();
        L3 = L + L2;
        cout<<"����Ϊ"<<endl;
        L3.dispList();
        continue;
    
        case 13:
        cout<<"����ѧ����Ϣϵͳ"<<endl;
        Student Stu;
        SqList<Student> L3;
        while(1){
            cout<<"��ǰѧ����Ϊ��";
            L3.dispStu();
            cout<<"�������������";
            cin>>option;
            switch(option){
                case 1:
                cout<<"����ѧ����Ϣ��"<<endl;
                L3.inputStudent(Stu);
                L3.insertElem(Stu,1);
                continue;
            default:
                break;
            }
        }
    }
    }
}