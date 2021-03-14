#include "MinesweeperAI.h"
#include "Minesweeper.h"

#include <sqlite/sqlite3.h>
#pragma comment(lib, "sqlite3.lib")

/// <summary>
/// コンストラクタ
/// </summary>
MinesweeperAI::MinesweeperAI()
	: _pMinesweeper(nullptr)
	, _gameEndCount(0)
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
	sqlite3* db;

	// open db connection
	int rtn = sqlite3_open_v2("test_bench.db", &db, SQLITE_OPEN_CREATE | SQLITE_OPEN_READWRITE, nullptr);
	if (rtn != SQLITE_OK)
	{
		cerr << sqlite3_errmsg(db) << endl;
	}

	/* exec query */

	// close db connection 
	sqlite3_close_v2(db);

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
