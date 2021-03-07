#pragma once
#include "Include.h"

class MainSystem
{
private:
	/// <summary>
	/// メイン
	/// </summary>
	static MainSystem* _sMainSystem;

public:
	/// <summary>
	/// メイン取得
	/// </summary>
	/// <returns></returns>
	static MainSystem* GetMainSystem();

	/// <summary>
	/// メイン作成
	/// </summary>
	/// <returns></returns>
	static MainSystem* CreateMainSystem();

	/// <summary>
	/// メイン解放
	/// </summary>
	/// <returns></returns>
	static void ReleaseMainSystem();

private:
	/// <summary>
	/// アイテムのリスト
	/// </summary>
	std::unordered_map<std::string, ofBaseApp*> _itemDictionary;

	const std::string GameMainId;

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	MainSystem();

	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~MainSystem();

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

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

public:
	/// <summary>
	/// アイテム追加
	/// </summary>
	bool AddItem(ofBaseApp* item, std::string id);

	/// <summary>
	/// アイテム解放
	/// </summary>
	void RemoveItem(std::string id);

	/// <summary>
	/// アイテム取得
	/// </summary>
	ofBaseApp* GetItem(std::string id);

private:
	/// <summary>
	/// アイテム全削除
	/// </summary>
	void RemoveAllItem();

};

