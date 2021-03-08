#pragma once
#include "Include.h"

class Minesweeper : public ofBaseApp
{
public:
	enum class GameStatus : int
	{
		None,
		Start,
		Playing,
		GameClear,
		GameOver,
	};

	/// <summary>
	/// セル表示ステータス
	/// </summary>
	enum class DisplayCellStatus : int
	{
		Empty,		// 空
		Hold,		// 保留
		Flag,		// フラグ
	};

	/// <summary>
	/// セル情報
	/// </summary>
	struct CellStatus
	{
		CellStatus()
		: _displayCellStatus(DisplayCellStatus::Empty)
		, _isBomb(false)
		, _bombCount(0)
		, _isOpened(false)
		{

		}

		DisplayCellStatus _displayCellStatus;	// 表示ステータス
		bool _isBomb;	// 機雷フラグ
		int _bombCount;	// 周辺の機雷数
		bool _isOpened;	// 空き
	};

private:
	int _cellSize;
	int _paddingSize;

	int _width;
	int _height;
	int _bombCount;

	std::vector<CellStatus> _cells;

	ofImage _imageBomb;	// 爆弾
	ofImage _imageFlag;	// フラグ
	ofImage _imageHold;	// 保留

	ofTrueTypeFont _font;	// 文字

	GameStatus _gameStatus;
	int _hoverIndex;

	bool _isHumanPlay;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Minesweeper();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Minesweeper();

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

	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseExited(int x, int y);

public:
	/// <summary>
	/// セルの設定
	/// </summary>
	/// <param name="cellSize"></param>
	/// <param name="paddingSize"></param>
	void SetCellSize(int cellSize, int paddingSize);

	/// <summary>
	/// ゲーム設定
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="bombCount"></param>
	void SetMinesweeper(int width, int height, int bombCount);

	/// <summary>
	/// ゲームリセット
	/// </summary>
	void ResetGame();

	/// <summary>
	/// セルのクリック
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="button"></param>
	void ClickCell(int x, int y, int button);

	/// <summary>
	/// セル情報の取得
	/// </summary>
	/// <returns></returns>
	const std::vector<CellStatus>& GetCellStatus() const;

	/// <summary>
	/// ゲーム状況取得
	/// </summary>
	/// <returns></returns>
	GameStatus GetGameStatus() const;

	/// <summary>
	/// 人間がプレイするか
	/// </summary>
	/// <param name="isHuman"></param>
	void SetIsHumanPlay(bool isHuman);

private:
	/// <summary>
	/// 周囲の爆弾カウント
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void AddBombCount(int x, int y);

	/// <summary>
	/// セル番号取得
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	int GetCellIndex(int x, int y);

	/// <summary>
	/// 周辺のセルを開ける
	/// </summary>
	/// <param name="cellIndex"></param>
	void OpenAroundCell(int cellIndex);

	/// <summary>
	/// ゲームオーバー
	/// </summary>
	void SetGameOver();

	/// <summary>
	/// セルを開ける
	/// </summary>
	/// <param name="index"></param>
	void OpenCell(int index);

	/// <summary>
	/// フラグを建てる
	/// </summary>
	/// <param name="index"></param>
	void SetFlag(int index);

	/// <summary>
	/// クリアチェック
	/// </summary>
	/// <returns></returns>
	bool CheckGameClear();

	/// <summary>
	/// 初回のセル表示
	/// </summary>
	void InitializeOpenCell(int cellIndex);

	/// <summary>
	/// 爆弾セット
	/// </summary>
	void SetBomb();
};

