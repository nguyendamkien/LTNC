
#include "gamemap.h"

void gamemap::LoadMap(char* name)
{
    ifstream file(name);

    game_map_.max_x_ = 0;
    game_map_.max_y_ = 0;
    if(file)
    {
        for(int i=0; i<MAX_MAP_Y; i++)
            for(int j=0; j<MAX_MAP_X; j++)
            {
                file >> game_map_.tile[i][j]; // doc phan tu trong mang
                int val = game_map_.tile[i][j];

                if(val>0)
                {
                    if(j > game_map_.max_x_)
                    {
                        game_map_.max_x_ = j;
                    }
                    if(i > game_map_.max_y_)
                    {
                        game_map_.max_y_ = i;
                    }
                }
            }
    }

    game_map_.max_x_ = (game_map_.max_x_ + 1)*TILE_SIZE; // cong 1 do i, j chay tu 0
    game_map_.max_y_ = (game_map_.max_y_ + 1)*TILE_SIZE;

    game_map_.start_x_ = 0;
    game_map_.start_y_ = 0;

    game_map_.file_name = name;
    file.close();


}

void gamemap::LoadTiles( SDL_Renderer* gRenderer)
{
    char file_img[100];
    FILE* fp = NULL;

    for(int i=0; i< MAX_TILES; i++)
    {
        sprintf_s(file_img, "map/%d.png", i ); // luu chuoi den duong dan  mo ah vao file_img va dinh dang bang bien i

        fopen_s(&fp, file_img, "rb"); // mo tep luu trong file_img va luu vao fp

        if(fp == NULL)
        {
            continue;
        }

        fclose(fp);

        tile_mat[i].LoadImg(file_img, gRenderer);
    }


}

void gamemap::DrawMap(SDL_Renderer* gRenderer) // ve map
{
    int x1 = 0;
    int x2 = 0;

    int y1 = 0;
    int y2 = 0;

    int map_x = 0;
    int map_y = 0;

    map_x = game_map_.start_x_/TILE_SIZE;
    x1 = (game_map_.start_x_%TILE_SIZE)*-1;
    x2 = x1 + SCREEN_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);

    map_y = game_map_.start_y_/TILE_SIZE;
    y1 =  (game_map_.start_y_%TILE_SIZE)*-1;
    y2 = y1 + SCREEN_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);



    for(int i = y1; i < y2; i+= TILE_SIZE)
    {
        map_x = game_map_.start_x_/TILE_SIZE;
        for(int j = x1; j < x2; j += TILE_SIZE)
        {
            int val = game_map_.tile[map_y][map_x];
            if(val>0)
            {
                tile_mat[val].SetRect(j,i);
                tile_mat[val].Render(gRenderer, NULL);
            }
            map_x++;
        }
        map_y++;
    }
}
