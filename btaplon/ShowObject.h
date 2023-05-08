
#ifndef SHOW_OBJECT_H
#define SHOW_OBJECT_H

#include "commonfunc.h"
#include "BaseObject.h"

class ShowObject : public BaseObject
{
public:
    ShowObject();
    ~ShowObject();

    void SetNum(const int& num){number_ = num;}
    void AddPos(const int& xPos);
    void Show(SDL_Renderer* screen);
    void Init(SDL_Renderer* screen);

    void Increase();
    void Decrease();

private:
    int number_;// bao nhieu mang
    vector<int> pos_list_; // vitri

};

class ShowBall : public BaseObject
{
public:
    ShowBall();
    ~ShowBall();
    void Show(SDL_Renderer* screen);
    void Init(SDL_Renderer* screen, const string file);

    void SetPos(const int& x, const int& y){x_pos = x; y_pos = y;};
    //void Decrease();

private:
    int x_pos;
    int y_pos;

};


#endif // SHOW_OBJECT_H
