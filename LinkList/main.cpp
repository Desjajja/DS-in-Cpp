#include<iostream>
#include"linkList.h"
using namespace std;

int main(){
    int option, i, e, output;
    LinkList<int> L;
    while(1){
    cout<<"**************���������**************"<<endl;
    cout<<"��1��ȡ��ѭ��������ĵ�i����㣻"<<endl;
    cout<<"��2���ڵ�i�����ǰ����������Ϊe�Ľ��"<<endl;

    cout<<"����������룺";
    cin>>option;

    switch(option){
        case 1:
        cout<<"������ȡ��Ԫ�ص�λ��";
        cin>>i;

        if(output = L(i))
            cout<<"��i������������Ϊ��"<<output<<endl;
        else cout<<"����ʧ�ܣ�"<<endl;
        continue;

        case 2:
        cout<<"�������λ��";
        cin>>i;
        cout<<"����������";
        cin>>e;

        if(!L.insertNode(i, e))cout<<"����ʧ�ܣ�"<<endl;
        continue;
    }
}
}