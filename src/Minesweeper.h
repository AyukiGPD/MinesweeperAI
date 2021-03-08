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
	/// �Z���\���X�e�[�^�X
	/// </summary>
	enum class DisplayCellStatus : int
	{
		Empty,		// ��
		Hold,		// �ۗ�
		Flag,		// �t���O
	};

	/// <summary>
	/// �Z�����
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

		DisplayCellStatus _displayCellStatus;	// �\���X�e�[�^�X
		bool _isBomb;	// �@���t���O
		int _bombCount;	// ���ӂ̋@����
		bool _isOpened;	// ��
	};

private:
	int _cellSize;
	int _paddingSize;

	int _width;
	int _height;
	int _bombCount;

	std::vector<CellStatus> _cells;

	ofImage _imageBomb;	// ���e
	ofImage _imageFlag;	// �t���O
	ofImage _imageHold;	// �ۗ�

	ofTrueTypeFont _font;	// ����

	GameStatus _gameStatus;
	int _hoverIndex;

	bool _isHumanPlay;

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Minesweeper();

	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Minesweeper();

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

	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseExited(int x, int y);

public:
	/// <summary>
	/// �Z���̐ݒ�
	/// </summary>
	/// <param name="cellSize"></param>
	/// <param name="paddingSize"></param>
	void SetCellSize(int cellSize, int paddingSize);

	/// <summary>
	/// �Q�[���ݒ�
	/// </summary>
	/// <param name="width"></param>
	/// <param name="height"></param>
	/// <param name="bombCount"></param>
	void SetMinesweeper(int width, int height, int bombCount);

	/// <summary>
	/// �Q�[�����Z�b�g
	/// </summary>
	void ResetGame();

	/// <summary>
	/// �Z���̃N���b�N
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="button"></param>
	void ClickCell(int x, int y, int button);

	/// <summary>
	/// �Z�����̎擾
	/// </summary>
	/// <returns></returns>
	const std::vector<CellStatus>& GetCellStatus() const;

	/// <summary>
	/// �Q�[���󋵎擾
	/// </summary>
	/// <returns></returns>
	GameStatus GetGameStatus() const;

	/// <summary>
	/// �l�Ԃ��v���C���邩
	/// </summary>
	/// <param name="isHuman"></param>
	void SetIsHumanPlay(bool isHuman);

private:
	/// <summary>
	/// ���͂̔��e�J�E���g
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	void AddBombCount(int x, int y);

	/// <summary>
	/// �Z���ԍ��擾
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <returns></returns>
	int GetCellIndex(int x, int y);

	/// <summary>
	/// ���ӂ̃Z�����J����
	/// </summary>
	/// <param name="cellIndex"></param>
	void OpenAroundCell(int cellIndex);

	/// <summary>
	/// �Q�[���I�[�o�[
	/// </summary>
	void SetGameOver();

	/// <summary>
	/// �Z�����J����
	/// </summary>
	/// <param name="index"></param>
	void OpenCell(int index);

	/// <summary>
	/// �t���O�����Ă�
	/// </summary>
	/// <param name="index"></param>
	void SetFlag(int index);

	/// <summary>
	/// �N���A�`�F�b�N
	/// </summary>
	/// <returns></returns>
	bool CheckGameClear();

	/// <summary>
	/// ����̃Z���\��
	/// </summary>
	void InitializeOpenCell(int cellIndex);

	/// <summary>
	/// ���e�Z�b�g
	/// </summary>
	void SetBomb();
};

