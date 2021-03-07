#include "MainSystem.h"
#include "Utility.h"
#include "GameMain.h"


#define CALL_ITEMS_FUNCTION(ITEMDIC_, FUNCTION_)\
for (auto pair : ITEMDIC_)\
{\
	auto* pItem = pair.second;\
	if (pItem == nullptr)\
	{\
		continue;\
	}\
	pItem->FUNCTION_;\
}\

/// <summary>
/// メイン
/// </summary>
MainSystem* MainSystem::_sMainSystem = nullptr;

/// <summary>
/// メイン取得
/// </summary>
/// <returns></returns>
MainSystem* MainSystem::GetMainSystem()
{
	return _sMainSystem;
}

/// <summary>
/// メイン作成
/// </summary>
/// <returns></returns>
MainSystem* MainSystem::CreateMainSystem()
{
	if (_sMainSystem != nullptr)
	{
		return _sMainSystem;
	}

	_sMainSystem = new MainSystem();

	return _sMainSystem;
}

/// <summary>
/// メイン解放
/// </summary>
/// <returns></returns>
void MainSystem::ReleaseMainSystem()
{
	Utility::SafeDelete<MainSystem>(_sMainSystem);
}


/// <summary>
/// コンストラクタ
/// </summary>
MainSystem::MainSystem()
	: GameMainId("GameMain")
{
}

/// <summary>
/// デストラクタ
/// </summary>
MainSystem::~MainSystem()
{
}

/// <summary>
/// 初期化
/// </summary>
void MainSystem::setup()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, setup());
	AddItem(new GameMain(), GameMainId);
}

/// <summary>
/// 更新
/// </summary>
void MainSystem::update()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, update());
}

/// <summary>
/// 描画
/// </summary>
void MainSystem::draw()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, draw());
}

/// <summary>
/// 解放
/// </summary>
void MainSystem::exit()
{
	RemoveAllItem();
}

void MainSystem::keyPressed(int key)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, keyPressed(key));
}

void MainSystem::keyReleased(int key)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, keyReleased(key));
}

void MainSystem::mouseMoved(int x, int y)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, mouseMoved(x, y));
}

void MainSystem::mouseDragged(int x, int y, int button)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, mouseDragged(x, y, button));
}

void MainSystem::mousePressed(int x, int y, int button)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, mousePressed(x, y, button));
}

void MainSystem::mouseReleased(int x, int y, int button)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, mouseReleased(x, y, button));
}

void MainSystem::mouseEntered(int x, int y)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, mouseEntered(x, y));
}

void MainSystem::mouseExited(int x, int y)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, mouseExited(x, y));
}

void MainSystem::windowResized(int w, int h)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, windowResized(w, h));
}

void MainSystem::dragEvent(ofDragInfo dragInfo)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, dragEvent(dragInfo));
}

void MainSystem::gotMessage(ofMessage msg)
{
	CALL_ITEMS_FUNCTION(_itemDictionary, gotMessage(msg));
}


/// <summary>
/// アイテム追加
/// </summary>
bool MainSystem::AddItem(ofBaseApp* item, std::string id)
{
	if (item == nullptr)
	{
		return false;
	}

	if (_itemDictionary.find(id) != _itemDictionary.end())
	{
		return false;
	}

	item->setup();
	_itemDictionary[id] = item;
	return true;
}

/// <summary>
/// アイテム解放
/// </summary>
void MainSystem::RemoveItem(std::string id)
{
	auto itr = _itemDictionary.find(id);
	if (itr == _itemDictionary.end())
	{
		return;
	}

	auto* pItem = itr->second;
	if (pItem != nullptr)
	{
		pItem->exit();
	}

	_itemDictionary.erase(itr);
}

/// <summary>
/// アイテム取得
/// </summary>
ofBaseApp* MainSystem::GetItem(std::string id)
{
	if (_itemDictionary.find(id) == _itemDictionary.end())
	{
		return nullptr;
	}

	return _itemDictionary[id];
}

/// <summary>
/// アイテム全削除
/// </summary>
void MainSystem::RemoveAllItem()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, exit());
	_itemDictionary.clear();
}



