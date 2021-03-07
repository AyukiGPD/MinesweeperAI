#pragma once
#include "Include.h"

class MainSystem
{
private:
	/// <summary>
	/// ���C��
	/// </summary>
	static MainSystem* _sMainSystem;

public:
	/// <summary>
	/// ���C���擾
	/// </summary>
	/// <returns></returns>
	static MainSystem* GetMainSystem();

	/// <summary>
	/// ���C���쐬
	/// </summary>
	/// <returns></returns>
	static MainSystem* CreateMainSystem();

	/// <summary>
	/// ���C�����
	/// </summary>
	/// <returns></returns>
	static void ReleaseMainSystem();

private:
	/// <summary>
	/// �A�C�e���̃��X�g
	/// </summary>
	std::unordered_map<std::string, ofBaseApp*> _itemDictionary;

	const std::string GameMainId;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	MainSystem();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~MainSystem();

public:
	/// <summary>
	/// ������
	/// </summary>
	void setup();

	/// <summary>
	/// �X�V
	/// </summary>
	void update();

	/// <summary>
	/// �`��
	/// </summary>
	void draw();

	/// <summary>
	/// ���
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
	/// �A�C�e���ǉ�
	/// </summary>
	bool AddItem(ofBaseApp* item, std::string id);

	/// <summary>
	/// �A�C�e�����
	/// </summary>
	void RemoveItem(std::string id);

	/// <summary>
	/// �A�C�e���擾
	/// </summary>
	ofBaseApp* GetItem(std::string id);

private:
	/// <summary>
	/// �A�C�e���S�폜
	/// </summary>
	void RemoveAllItem();

};

