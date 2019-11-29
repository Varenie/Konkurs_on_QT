#ifndef PLAY_DATA_H
#define PLAY_DATA_H
#include <QString>

class Play_data
{
public:
    int id;
    QString name;
    int score;
public:
    int getScore(){return score;}
};
#endif // PLAY_DATA_H
