#include <iostream>

using namespace std;

#include "speechManger.h"
#include <string>
#include <ctime>

int main()
{
    //random seed
    srand((unsigned int) time(NULL));

    //cout << "Hello, World!" << std::endl;

    //Create object of management class
    SpeechManager sm;
    //for test
//    for(map<int,Speaker>::iterator it=sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++)
//    {
//        cout<<"选手编号： "<<it->first<<"姓名： "<<it->second.m_Name<<"分数： "<<it->second.m_Score[0]<<endl;
//
//    }


    int choice = 0; //Store users' input

    while (choice != 100)
    {
        sm.show_Menu();
        cout << "请输入您的选择： " << endl;
        cin >> choice;

        switch (choice)
        {
            case 1:
                //start speech contest
                sm.startSpeech();
                break;
            case 2:
                //search record
                sm.showRecord();
                break;
            case 3:
                //clear record
                sm.clearRecord();
                break;
            case 0:
                //exit system
                sm.exitSystem();
                break;
            default:
                //clear screen

                system("cls");

        }
    }


    system("pause");
    return 0;
}



