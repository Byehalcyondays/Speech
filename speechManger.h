//
// Created by Halcyon on 2020/11/13.
//
#ifndef SPEECH_SPEECHMANGER_H
#define SPEECH_SPEECHMANGER_H

#include <iostream>
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>
using namespace std;

class SpeechManager{
public:
    //constructor
    SpeechManager();

    void show_Menu();

    void exitSystem();

    //create 12 players
    void createSpeaker();

    //start contest
    void startSpeech();

    //draw lot
    void speechDraw();

    //contest
    void speechContest();

    //show scores
    void showScore();

    //save record
    void saveRecord();

    //destructor
    ~SpeechManager();

    //initialize containers
    void initSpeech();
    //member attributes
    //first round players
    vector<int>v1;
    //second round players
    vector<int>v2;
    //final round players
    vector<int>vVictory;
    //name + number
    map<int,Speaker>m_Speaker;

    //round
    int m_Index=1;

};






#endif //SPEECH_SPEECHMANGER_H

