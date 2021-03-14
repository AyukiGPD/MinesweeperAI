#pragma once
#include "Include.h"

class Minesweeper;

class MinesweeperAI : public ofBaseApp
{
private:
	Minesweeper* _pMinesweeper;

	int _gameEndCount;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	MinesweeperAI();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~MinesweeperAI();

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

public:
	/// <summary>
	/// �Q�[���ݒ�
	/// </summary>
	/// <param name="pMinesweeper"></param>
	void SetGameObject(Minesweeper* pMinesweeper);
};

