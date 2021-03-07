#pragma once
#include "Include.h"

class GameMain : public ofBaseApp
{
private:
	const std::string MinesweeperId;

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

