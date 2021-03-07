#include "GameMain.h"
#include "MainSystem.h"
#include "Minesweeper.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameMain::GameMain()
	: MinesweeperId("Minesweeper")
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameMain::~GameMain()
{
}

/// <summary>
/// ������
/// </summary>
void GameMain::setup()
{
	ofSetBackgroundColor(40, 40, 40);
	ofSetWindowShape(1600, 900);
	
	auto pMainSystem = MainSystem::GetMainSystem();
	auto pMinesweeper = new Minesweeper();
	pMinesweeper->SetCellSize(50, 2);
	pMinesweeper->SetMinesweeper(16, 16, 30);
	pMainSystem->AddItem(pMinesweeper, MinesweeperId);
}

/// <summary>
/// �X�V
/// </summary>
void GameMain::update()
{
}

/// <summary>
/// �`��
/// </summary>
void GameMain::draw()
{
}

/// <summary>
/// ���
/// </summary>
void GameMain::exit()
{
}
