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
/// ���C��
/// </summary>
MainSystem* MainSystem::_sMainSystem = nullptr;

/// <summary>
/// ���C���擾
/// </summary>
/// <returns></returns>
MainSystem* MainSystem::GetMainSystem()
{
	return _sMainSystem;
}

/// <summary>
/// ���C���쐬
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
/// ���C�����
/// </summary>
/// <returns></returns>
void MainSystem::ReleaseMainSystem()
{
	Utility::SafeDelete<MainSystem>(_sMainSystem);
}


/// <summary>
/// �R���X�g���N�^
/// </summary>
MainSystem::MainSystem()
	: GameMainId("GameMain")
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
MainSystem::~MainSystem()
{
}

/// <summary>
/// ������
/// </summary>
void MainSystem::setup()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, setup());
	AddItem(new GameMain(), GameMainId);
}

/// <summary>
/// �X�V
/// </summary>
void MainSystem::update()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, update());
}

/// <summary>
/// �`��
/// </summary>
void MainSystem::draw()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, draw());
}

/// <summary>
/// ���
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
/// �A�C�e���ǉ�
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
/// �A�C�e�����
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
/// �A�C�e���擾
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
/// �A�C�e���S�폜
/// </summary>
void MainSystem::RemoveAllItem()
{
	CALL_ITEMS_FUNCTION(_itemDictionary, exit());
	_itemDictionary.clear();
}



