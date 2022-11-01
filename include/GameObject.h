#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	// 함수호출 인수에 moveSpeed를 추가. 이동속도 변경을 가능하게 함.
	// load함수 안에 currentRow와 currentFrame을 넣어도 이미지가 움직이지 않음. 왜?
	// main.cpp 에서 생성자 init은 한번만 실행되고 update, render, handleEvents는 while문 안에서 계속해서 호출되기 때문에
	// 예
	 /* load에 currentRow값과 currentFrame값을 포함하여 init에서 호출하면 GameObject에 있는 m_currentRow와 m_currentFrame에 저장함.
	 하지만 Game에 있는 init은 main에서 한번만 호출하기 때문에 이후 값의 변화가 없어서 정지이미지만 나옴.
	 m_currentFrame도 Game에서 update를 해도 Game에 있는 m_currentFrame만 변화할 뿐 GameObject에 저장된 m_currentFrame은 변화하지 않음.
	 drawFrame에 currentRow값과 currentFrame값을 포함하여 render에서 호출하면 GameObject에 있는 drawFrame 호출인수 currentRow와 currentFrame에 적용함.
	 init과 달리 Game에 있는 render는 main에서 update, handleEvents과 같이 while문 안에서 계속해서 호출되기 때문에 변화가 있음.
	 render에서 drawFrame을 호출할 때 사용한 m_currentFrame은 Game안에서 사용되는 변수이므로 GameObject안에 있는 m_currentFrame을 가져오지 않음.
	 */
	void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);

	void draw(SDL_Renderer* pRenderer);
	void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // 함수호출 인수에 currentRow, currentFrame을 추가. 프레임 변경을 가능하게 함.
	void update();

	void clean();
	
private:
	bool Left = false;

protected:
	std::string m_textureID;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_moveSpeed;

	int m_currentFrame;
	int m_currentRow;
};