#pragma once
#include <main.h>
#include <iostream>

class GameObject {
public:
	// �Լ�ȣ�� �μ��� moveSpeed�� �߰�. �̵��ӵ� ������ �����ϰ� ��.
	// load�Լ� �ȿ� currentRow�� currentFrame�� �־ �̹����� �������� ����. ��?
	// main.cpp ���� ������ init�� �ѹ��� ����ǰ� update, render, handleEvents�� while�� �ȿ��� ����ؼ� ȣ��Ǳ� ������
	// ��
	 /* load�� currentRow���� currentFrame���� �����Ͽ� init���� ȣ���ϸ� GameObject�� �ִ� m_currentRow�� m_currentFrame�� ������.
	 ������ Game�� �ִ� init�� main���� �ѹ��� ȣ���ϱ� ������ ���� ���� ��ȭ�� ��� �����̹����� ����.
	 m_currentFrame�� Game���� update�� �ص� Game�� �ִ� m_currentFrame�� ��ȭ�� �� GameObject�� ����� m_currentFrame�� ��ȭ���� ����.
	 drawFrame�� currentRow���� currentFrame���� �����Ͽ� render���� ȣ���ϸ� GameObject�� �ִ� drawFrame ȣ���μ� currentRow�� currentFrame�� ������.
	 init�� �޸� Game�� �ִ� render�� main���� update, handleEvents�� ���� while�� �ȿ��� ����ؼ� ȣ��Ǳ� ������ ��ȭ�� ����.
	 render���� drawFrame�� ȣ���� �� ����� m_currentFrame�� Game�ȿ��� ���Ǵ� �����̹Ƿ� GameObject�ȿ� �ִ� m_currentFrame�� �������� ����.
	 */
	void load(int x, int y, int width, int height, int moveSpeed, std::string textureID);

	void draw(SDL_Renderer* pRenderer);
	void drawFrame(int currentRow, int currentFrame, SDL_Renderer* pRenderer); // �Լ�ȣ�� �μ��� currentRow, currentFrame�� �߰�. ������ ������ �����ϰ� ��.
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