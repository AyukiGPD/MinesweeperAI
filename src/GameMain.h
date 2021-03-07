#pragma once
#include "Include.h"

class GameMain : public ofBaseApp
{
private:
	const std::string MinesweeperId;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	GameMain();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameMain();

public:
	/// <summary>
	/// ������
	/// </summary>
	void setup();

	/// <summary>
	/// �X�V
	/// </summary>
	void update();

	/// <summary>
	/// �`��
	/// </summary>
	void draw();

	/// <summary>
	/// ���
	/// </summary>
	void exit();
};

