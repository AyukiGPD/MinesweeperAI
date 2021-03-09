#include "MinesweeperAI.h"
#include "Minesweeper.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
MinesweeperAI::MinesweeperAI()
	: _pMinesweeper(nullptr)
{
}

/// <summary>
/// �f�X�g���N�^
/// </summary>
MinesweeperAI::~MinesweeperAI()
{
}

/// <summary>
/// ������
/// </summary>
void MinesweeperAI::setup()
{
}

/// <summary>
/// �X�V
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
/// �`��
/// </summary>
void MinesweeperAI::draw()
{
}

/// <summary>
/// ���
/// </summary>
void MinesweeperAI::exit()
{
	_pMinesweeper = nullptr;
}

/// <summary>
/// �Q�[���ݒ�
/// </summary>
/// <param name="pMinesweeper"></param>
void MinesweeperAI::SetGameObject(Minesweeper* pMinesweeper)
{
	_pMinesweeper = pMinesweeper;
//	_pMinesweeper->SetIsHumanPlay(false);
}
