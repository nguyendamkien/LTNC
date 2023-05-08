
#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "commonfunc.h"
#include "BaseObject.h"

#define GRAVITY_SPEED 0.8 // trong luc roi
#define MAX_FALL_SPEED 10 // toc do roi toi da
#define PLAYER_SPEED 5.5 //  toc do nhan vat
#define PLAYER_JUMP_VAL 15

class MainObject : public BaseObject // ke thua
{
    public:
        MainObject();
        ~MainObject();

        enum WalkType  // dinh nghia kieu du lieu moi gom danh sach cac hang duoc dat ten
        {
            WALK_NONE ,
            WALK_RIGHT,
            WALK_LEFT,
        };

        bool LoadImg(std::string path, SDL_Renderer* gRenderer);
        void Show(SDL_Renderer* gRenderer);
        void HandelInputaction(SDL_Event event, SDL_Renderer* gRenderer); // nhan su kien tu ban phim
        void set_clips();

        // kiem tra map
        void DoPlayer(Map& map_data, Mix_Chunk* gHigh ); // nguoi choi
        void CheckToMap( Map& map_data, Mix_Chunk* gHigh); // check va cham map
        void SetmapXY(const int map_x, const int map_y){map_x_ = map_x; map_y_ = map_y;}; // vi tri ban do - camera
        void CenterEntityOnMap(Map& map_data);//thong so cua map khi di chuyen nhan vat
        void updateimageplayer(SDL_Renderer* gRenderer); // trang thai nhan vat

        SDL_Rect GetRectFrame();
        void increaseballred();
        void increaseballblue();
        void set_come_back_time_(const int& comebacktime){come_back_time_ = comebacktime;};
        int getballredeat() const{return count_ball_red;};
        int getballblueeat() const{return count_ball_blue;};
        void increse_falling();
        int get_number_falling() const{return number_falling;}
        void increaselife();
        int get_number_life() const {return number_life;}
        bool get_win() {return win;}

    private:
        int count_ball_red;
        int count_ball_blue;

        float x_val_;
        float y_val_;

        float x_pos_; // vi tri hien tai nhan vat
        float y_pos_;

        int width_frame_; // kich thuoc frame
        int height_frame_;

        SDL_Rect frame_clip_[5];
        Input input_type_; // kieu dau vao
        int frame_; //luu trang thai frame
        int status_; // kieu di chuyen
        bool on_ground_; // kiem tra con dung tren map

        int map_x_; //luu vi tri ban do
        int map_y_;

        int come_back_time_;
        int number_falling;
        int number_life;

        bool win;
};

#endif // MAIN_OBJECT_H_
