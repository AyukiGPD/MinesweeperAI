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
	/// コンストラクタ
	/// </summary>
	MinesweeperAI();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~MinesweeperAI();

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

public:
	/// <summary>
	/// ゲーム設定
	/// </summary>
	/// <param name="pMinesweeper"></param>
	void SetGameObject(Minesweeper* pMinesweeper);
};

