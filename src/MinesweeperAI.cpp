#include "MinesweeperAI.h"
#include "Minesweeper.h"

/// <summary>
/// コンストラクタ
/// </summary>
MinesweeperAI::MinesweeperAI()
	: _pMinesweeper(nullptr)
{
}

/// <summary>
/// デストラクタ
/// </summary>
MinesweeperAI::~MinesweeperAI()
{
}

/// <summary>
/// 初期化
/// </summary>
void MinesweeperAI::setup()
{
}

/// <summary>
/// 更新
/// </summary>
void MinesweeperAI::update()
{
	if (_pMinesweeper == nullptr)
	{
		return;
	}

	auto gameStatus = _pMinesweeper->GetGameStatus();

	switch (gameStatus)
	{
	case Minesweeper::GameStatus::None:
		break;
	case Minesweeper::GameStatus::Start:
		break;
	case Minesweeper::GameStatus::Playing:
		break;
	case Minesweeper::GameStatus::GameClear:
		break;
	case Minesweeper::GameStatus::GameOver:
		break;
	default:
		break;
	}

	const auto& cellStatus = _pMinesweeper->GetCellStatus();
	double elapsedTime = _pMinesweeper->GetElapsedTimeMsec();
}

/// <summary>
/// 描画
/// </summary>
void MinesweeperAI::draw()
{
}

/// <summary>
/// 解放
/// </summary>
void MinesweeperAI::exit()
{
	_pMinesweeper = nullptr;
}

/// <summary>
/// ゲーム設定
/// </summary>
/// <param name="pMinesweeper"></param>
void MinesweeperAI::SetGameObject(Minesweeper* pMinesweeper)
{
	_pMinesweeper = pMinesweeper;
//	_pMinesweeper->SetIsHumanPlay(false);
}
