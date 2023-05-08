
#ifndef TEXT_OBJECT_H
#define TEXT_OBJECT_H

#include "commonfunc.h"

class TextObject
{
public:
    TextObject();
    ~TextObject();

    enum TextColor
    {
        RED_TEXT,
        WHITE_TEXT,
        BLACK_TEXT,
    };

    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
    void Free();

    void SetColor(Uint8 red, Uint8 green, Uint8 blue);
    void SetColor(int type);

    void RenderText(SDL_Renderer* screen, int xp, int yp, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

    int GetWidth() const {return width_;}
    int GetHeight() const {return height_;}

    void SetText(const string& text) { str_val_ = text;}
    string GetText() const {return str_val_;}

private:
    string str_val_; // noi dung
    SDL_Color text_color_; // mau noi dung
    SDL_Texture* texture_;
    int width_;
    int height_;

};





#endif // TEXT_OBJECT_H
