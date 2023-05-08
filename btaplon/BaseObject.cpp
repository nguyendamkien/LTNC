

#include "BaseObject.h"

BaseObject::BaseObject()
{
    //Initialize
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;
    rect_.h = 0;
    rect_.w = 0;
}

BaseObject::~BaseObject()
{
    //Deallocate // giao phong
    Free();
}

bool BaseObject:: LoadImg(std::string path, SDL_Renderer* gRenderer)
{
    Free(); // xoa baseobject va cho vung  nho moi, tran hien tuong rac vung nho
    SDL_Texture* new_texture = NULL;

    SDL_Surface* load_Surface = IMG_Load(path.c_str());

    if(load_Surface != NULL)
    {
        SDL_SetColorKey( load_Surface, SDL_TRUE, SDL_MapRGB( load_Surface->format, 0x00, 0x00, 0x00 ) );
        new_texture = SDL_CreateTextureFromSurface( gRenderer, load_Surface );
        if(new_texture != NULL)
        {
            rect_.w = load_Surface->w;
            rect_.h = load_Surface->h;
        }

        SDL_FreeSurface( load_Surface );
    }

    p_object_ = new_texture;

    return p_object_ != NULL;
}

void BaseObject::Render( SDL_Renderer* des, const SDL_Rect* clip /*= NULL*/ )
{
    SDL_Rect renderquad = {rect_.x, rect_.y, rect_.w, rect_.h};
    SDL_RenderCopy(des, p_object_, clip, &renderquad);

}

void BaseObject::Free()
{
    if(p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;
        rect_.w = 0;
        rect_.h = 0;
    }
}

