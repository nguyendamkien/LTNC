
#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "commonfunc.h"

class BaseObject
{
	public:
		//Initializes variables
		BaseObject();

		//Deallocates memory - giai phong bo nho
		~BaseObject();

		void SetRect(const int& x, const int& y){rect_.x = x, rect_.y = y;} // thiet lap vi tri
		SDL_Rect GetRect() const {return rect_;} // tra ve vi tri
		SDL_Texture* GetObject() {return p_object_;} // tra ve con tro den doi tuong texture dai dien cho hinh anh duoc chon


		//Loads image at specified path -  loa anh theo duong dan chi dinh
		virtual bool LoadImg( std::string path, SDL_Renderer* screen ); // virtual khai bao ham ao

		//Renders texture at given point // ket xuat ket cau tai diem nhat dinh
		void Render( SDL_Renderer* des, const SDL_Rect* clip = NULL );

        void Free();


	protected: // cho phép cac lop ke thua goi bien
		SDL_Texture* p_object_;
		SDL_Rect rect_;

};


#endif // BASE_OBJECT_H_
