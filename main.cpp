#include <iostream>
using namespace std;
#include "speechManger.h"


int main()
{
    //cout << "Hello, World!" << std::endl;

    //创建管理类对象
    SpeechManager sm;


    int choice=0; //存储用户输入

    while (true){
        sm.show_Menu();
        cout<< "请输入您的选择： "<<endl;
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
                //清屏

                system("cls");

        }
    }


    system("pause");
    return 0;
}



