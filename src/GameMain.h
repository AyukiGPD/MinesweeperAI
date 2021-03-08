#pragma once
#include "Include.h"

class Minesweeper;
class MinesweeperAI;

class GameMain : public ofBaseApp
{
public:
	const std::string MinesweeperId;			// マインスイーパーID
	const std::string ArtificialIntelligenceId;	// AIのID

private:
	Minesweeper* _pMinesweeper;
	MinesweeperAI* _pMinesweeperAI;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	GameMain();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameMain();

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void setup();

	/// <summary>
	/// 更新
	/// </summary>
	void update();

	/// <summary>
	/// 描画
	/// </summary>
	void draw();

	/// <summary>
	/// 解放
	/// </summary>
	void exit();
};

