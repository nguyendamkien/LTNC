
#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "commonfunc.h"
#include "BaseObject.h"

class explosion: public BaseObject
{
public:
    explosion();
    ~explosion();

    void set_clips();
    void set_frame(const int& fr){ frame_ = fr;}
    bool LoadImg(string path, SDL_Renderer* gRenderer);
    void Show(SDL_Renderer* gRenderer);
    int get_width_frame() const {return width_frame_;} // de chech va cham
    int get_height_frame() const {return height_frame_;}
private:
    int width_frame_;
    int height_frame_;

    int frame_;
    SDL_Rect frame_clip_[4];


};
#endif // EXPLOSION_H
