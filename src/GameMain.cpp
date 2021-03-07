#include "GameMain.h"
#include "MainSystem.h"
#include "Minesweeper.h"

/// <summary>
/// コンストラクタ
/// </summary>
GameMain::GameMain()
	: MinesweeperId("Minesweeper")
{
}

/// <summary>
/// デストラクタ
/// </summary>
GameMain::~GameMain()
{
}

/// <summary>
/// 初期化
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
/// 更新
/// </summary>
void GameMain::update()
{
}

/// <summary>
/// 描画
/// </summary>
void GameMain::draw()
{
}

/// <summary>
/// 解放
/// </summary>
void GameMain::exit()
{
}
