#include "GameMain.h"
#include "MainSystem.h"
#include "Minesweeper.h"
#include "MinesweeperAI.h"
#include "Utility.h"

static const int WindowSizeWidth = 1600;
static const int WindowSizeHeight = 900;

static const int MinesweeperCellSize = 100;
static const int MinesweeperCellPadding = 2;

static const int MinesweeperWidth = 9;
static const int MinesweeperHeight = 9;
static const int MinesweeperBombCount = 10;

/// <summary>
/// �R���X�g���N�^
/// </summary>
GameMain::GameMain()
	: MinesweeperId("Minesweeper")
	, ArtificialIntelligenceId("MinesweeperAI")
	, _pMinesweeper(nullptr)
	, _pMinesweeperAI(nullptr)
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
	ofSetWindowShape(WindowSizeWidth, WindowSizeHeight);
	
	auto pMainSystem = MainSystem::GetMainSystem();

	// �}�C���X�C�[�p�[�o�^
	_pMinesweeper = new Minesweeper();
	_pMinesweeper->SetCellSize(MinesweeperCellSize, MinesweeperCellPadding);
	_pMinesweeper->SetMinesweeper(MinesweeperWidth, MinesweeperHeight, MinesweeperBombCount);
	pMainSystem->AddItem(_pMinesweeper, MinesweeperId);

	// AI�o�^
	_pMinesweeperAI = new MinesweeperAI();
	_pMinesweeperAI->SetGameObject(_pMinesweeper);
	pMainSystem->AddItem(_pMinesweeperAI, ArtificialIntelligenceId);

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
	auto pMainSystem = MainSystem::GetMainSystem();
	pMainSystem->RemoveItem(ArtificialIntelligenceId);
	pMainSystem->RemoveItem(MinesweeperId);

	Utility::SafeDelete(_pMinesweeperAI);
	Utility::SafeDelete(_pMinesweeper);
}
