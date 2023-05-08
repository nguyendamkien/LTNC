
#ifndef GAME_MAP_H
#define GAME_MAP_H

#include "commonfunc.h"
#include "BaseObject.h"

#define MAX_TILES 20 // loai map

class TileMat : public BaseObject // hinh anh vao o
{
public:
    TileMat(){;}
    ~TileMat(){;}
};

class gamemap//xay dung map
{
public:
    gamemap(){;}
    ~gamemap(){;}

    void LoadMap(char* name); // doc thong tin trong so do map
    void LoadTiles(SDL_Renderer* gRenderer); // load hinh anh cho tile mat
    void DrawMap(SDL_Renderer* gRenderer); // xay dung map
    Map getMap() const {return game_map_;};
    void SetMap(Map& map_data){game_map_ = map_data;};

private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES]; // loai hinh anh

};



#endif // GAME_MAP_H
