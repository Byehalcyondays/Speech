//
// Created by Halcyon on 2020/11/13.
//

#include "speechManger.h"

SpeechManager::SpeechManager()
{
    //call initSpeech
    this->initSpeech();
    //call create
    this->createSpeaker();
    //load record
    this->loadRecord();
}

void SpeechManager::show_Menu()
{
    cout << "************************************" << endl;
    cout << "**********��ӭ�����ݽ�����*************" << endl;
    cout << "**********1.��ʼ�ݽ�����**************" << endl;
    cout << "**********2.�鿴�����¼**************" << endl;
    cout << "**********3.��ձ�����¼**************" << endl;
    cout << "**********0.�˳���������**************" << endl;
    cout << "************************************" << endl;
    cout << endl;
}

void SpeechManager::exitSystem()
{
    cout << "��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void SpeechManager::initSpeech()
{
    this->v1.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_Speaker.clear();
    this->m_Record.clear();

    this->m_Index = 1;
}

void SpeechManager::createSpeaker()
{
    string nameSeed = "ABCDEFGHIJKL";
    for (int i = 0; i < nameSeed.size(); i ++)
    {
        string name = "ѡ��";
        name += nameSeed[i];

        //create 1 player
        Speaker sp;
        sp.m_Name = name;
        for (int j = 0; j < 2; j ++)
        {
            sp.m_Score[j] = 0;
        }

        //create player's number
        this->v1.push_back(i + 10001);
        //number and speaker into map
        this->m_Speaker.insert(make_pair(i + 10001, sp));

    }
}

void SpeechManager::startSpeech()
{
    //first round

    //draw lot
    this->speechDraw();
    //contest
    this->speechContest();
    //show promotion result
    this->showScore();
    //second round
    this->m_Index ++;
    //draw lot
    this->speechDraw();
    //contest
    this->speechContest();
    //show final result
    this->showScore();
    //save score
    this->saveRecord();


    //update data
    //call initSpeech
    this->initSpeech();
    //call create
    this->createSpeaker();
    //load record
    this->loadRecord();

    cout << "�����������" << endl;
    system("pause");
    system("cls");

}

void SpeechManager::speechDraw()
{
    cout << "��<<" << this->m_Index << ">>�ֱ���ѡ���ڳ�ǩ" << endl;
    cout << "---------------------------------" << endl;
    cout << "��ǩ��˳�����£� " << endl;

    if (this->m_Index == 1)
    {
        //first round
        random_shuffle(v1.begin(), v1.end());
        for (vector<int>::iterator it = v1.begin(); it != v1.end(); it ++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    else
    {
        random_shuffle(v2.begin(), v2.end());
        for (vector<int>::iterator it = v2.begin(); it != v2.end(); it ++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
    system("pause");
    cout << endl;
}

void SpeechManager::speechContest()
{
    cout << "------------��" << this->m_Index << "�ֱ�����ʽ��ʼ----------" << endl;

    multimap<double, int, greater<double>> groupScore;
    int num = 0;

    vector<int> v_Src;
    if (this->m_Index == 1)
    {
        v_Src = v1;
    }
    else
    {
        v_Src = v2;
    }

    for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it ++)
    {
        num ++;
        //judges give score

        deque<double> d;
        for (int i = 0; i < 10; i ++)
        {
            double score = (rand() % 401 + 600) / 10.0f;
            cout << score << " ";
            d.push_back(score);

        }
        cout << endl;
        sort(d.begin(), d.end(), greater<double>());
        d.pop_front();
        d.pop_back();

        double sum = accumulate(d.begin(), d.end(), 0.0f);
        double avg = sum / (double) d.size(); //double/int=int

        //print avg
        cout << "��ţ� " << *it << "������ " << this->m_Speaker[*it].m_Name << "��ȡƽ���֣� " << avg << endl;
        this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

        groupScore.insert(make_pair(avg, *it));
        //get 3 from 6 players
        if (num % 6 == 0)
        {
            cout << "��" << num / 6 << "С���������£� " << endl;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end(); it ++)
            {
                cout << "���: " << it->second << "������ " << this->m_Speaker[it->second].m_Name << "�ɼ��� "
                     << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;

            }
            int count = 0;
            for (multimap<double, int, greater<double>>::iterator it = groupScore.begin();
                 it != groupScore.end() && count < 3; it ++, count ++)
            {
                if (this->m_Index == 1)
                {
                    v2.push_back((*it).second);

                }
                else
                {
                    vVictory.push_back((*it).second);
                }

            }
            groupScore.clear();
        }

    }

    cout << "----------------��" << this->m_Index << "�ֱ������----------------" << endl;
    system("pause");

}

void SpeechManager::showScore()
{
    cout << "----------------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£� ----------------" << endl;
    vector<int> v;
    if (this->m_Index == 1)
    {
        v = v2;
    }
    else
    {
        v = vVictory;
    }
    for (vector<int>::iterator it = v.begin(); it != v.end(); it ++)
    {
        cout << "ѡ�ֱ��: " << *it << "������ " << this->m_Speaker[*it].m_Name << "�ɼ��� "
             << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
    }
    cout << endl;
    system("pause");
    system("cls");
    this->show_Menu();

}

void SpeechManager::saveRecord()
{
    ofstream ofs;
    ofs.open("speech.csv", ios::out | ios::app);


    for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it ++)
    {
        ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
    }
    ofs << endl;

    ofs.close();
    cout << "�ļ��Ѿ�����" << endl;
    this->fileIsEmpty = false;
}

void SpeechManager::loadRecord()
{
    ifstream ifs("speech.csv", ios::in);

    if (! ifs.is_open())
    {
        this->fileIsEmpty = true;
        cout << "�ļ�������" << endl;
        ifs.close();
        return;
    }

    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "�ļ�Ϊ��" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    this->fileIsEmpty = false;
    ifs.putback(ch);

    string data;
    int index;
    while (ifs >> data)
    {
        vector<string> v;
        int pos = - 1;//look for position of ","
        int start = 0;

        while (true)
        {
            pos = data.find(',', start);
            if (pos == - 1)
            {
                //not find it
                break;
            }
            string temp = data.substr(start, pos - start);
            //cout<<temp<<endl;
            start = pos + 1;
            v.push_back(temp);

        }
        this->m_Record.insert(make_pair(index, v));
        index ++;
    }
    ifs.close();

//    for(map<int,vector<string>>::iterator it=m_Record.begin();it!=m_Record.end();it++)
//    {
//        cout<<it->first<<"�ھ���ţ� "<<it->second[0]<<"������ "<<it->second[1]<<endl;
//    }
}

void SpeechManager::showRecord()
{
    if (this->fileIsEmpty)
    {
        cout << "�ļ�Ϊ��" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_Record.size(); i ++)
        {
            cout << "��" << i + 1 << "��"
                 << "�ھ���ţ� " << this->m_Record[i][0] << "�÷֣� " << this->m_Record[i][1] << " "
                 << "�Ǿ���ţ� " << this->m_Record[i][2] << "�÷֣� " << this->m_Record[i][3] << " "
                 << "������ţ� " << this->m_Record[i][4] << "�÷֣� " << this->m_Record[i][5] << " "
                 << endl;
        }

    }
    system("pause");
    system("cls");
}

void SpeechManager::clearRecord()
{
    cout << "�Ƿ�ȷ����գ� " << endl;
    cout << "1-��" << endl;
    cout << "2-��" << endl;

    int select = 0;

    cin >> select;

    if (select == 1)
    {
        ofstream ofs("speech.csv", ios::trunc);
        ofs.close();

        this->initSpeech();

        this->createSpeaker();

        this->loadRecord();

        cout << "��ճɹ���" << endl;
    }

    system("pause");
    system("cls");
}


SpeechManager::~SpeechManager()
{

}

//����ͬ��