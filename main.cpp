#include <iostream>
using namespace std;
#include "speechManger.h"


int main()
{
    //cout << "Hello, World!" << std::endl;

    //�������������
    SpeechManager sm;


    int choice=0; //�洢�û�����

    while (true){
        sm.show_Menu();
        cout<< "����������ѡ�� "<<endl;
        cin>>choice;

        switch(choice)
        {
            case 1:
                //start
                break;
            case 2:
                //search
                break;
            case 3:
                //clear
                break;
            case 0:
                //exit
                sm.exitSystem();
                break;
            default:
                //����

                system("cls");

        }
    }


    system("pause");
    return 0;
}



