#include "Minesweeper.h"
#include "Utility.h"

/// <summary>
/// コンストラクタ
/// </summary>
Minesweeper::Minesweeper()
: _cellSize(100)
, _paddingSize(2)
, _width(1)
, _height(1)
, _bombCount(1)
, _isGameOver(false)
, _isGameClear(false)
, _isInitialized(false)
, _hoverIndex(-1)
{
}

/// <summary>
/// デストラクタ
/// </summary>
Minesweeper::~Minesweeper()
{
}

/// <summary>
/// 初期化
/// </summary>
void Minesweeper::setup()
{
	// 画像読み込み
	_imageBomb.load("resource/Bomb.png");
	_imageFlag.load("resource/Flag.png");
	_imageHold.load("resource/Hold.png");

	// フォント
	_font.load("resource/arial.ttf", 32);

}

/// <summary>
/// 更新
/// </summary>
void Minesweeper::update()
{

}

/// <summary>
/// 描画
/// </summary>
void Minesweeper::draw()
{
	int xSize = _cellSize * _width;
	int ySize = _cellSize * _height;
	ofSetColor(ofColor::gray);
	ofDrawRectangle(0, 0, xSize, ySize);
	ofSetColor(ofColor::white);

	for (int x = 0; x < _width; ++x)
	{
		float xCell = x * _cellSize;
		ofDrawLine(xCell, 0, xCell, ySize);
	}

	for (int y = 0; y < _height; ++y)
	{
		float yCell = y * _cellSize;
		ofDrawLine(0, yCell, xSize, yCell);
	}

	int halfCellSize = _cellSize / 2;
	for (int x = 0; x < _width; ++x)
	{
		float xCell = x * _cellSize;

		for (int y = 0; y < _height; ++y)
		{
			float yCell = y * _cellSize;

			int index = Utility::IndexCall(x, y, _width);
			const CellStatus& cell = _cells[index];
			if (cell._isOpened)
			{
				if (cell._isBomb)
				{
					ofSetColor(ofColor::white);
					_imageBomb.draw(xCell, yCell, _cellSize, _cellSize);
				}
				else if (cell._bombCount > 0)
				{
					ofSetColor(ofColor::black);
					_font.drawString(std::to_string(cell._bombCount), xCell + halfCellSize - 16, yCell + halfCellSize + 16);
				}
			}
			else
			{
				if (_hoverIndex == index)
				{
					ofSetColor(ofColor::mediumBlue);
				}
				else
				{
					ofSetColor(ofColor::royalBlue);
				}
				ofDrawRectangle(xCell + _paddingSize, yCell + _paddingSize, _cellSize - _paddingSize * 2, _cellSize - _paddingSize * 2);

				switch (cell._displayCellStatus)
				{
				case Minesweeper::DisplayCellStatus::Hold:
					ofSetColor(ofColor::white);
					_imageHold.draw(xCell, yCell, _cellSize, _cellSize);
					break;
				case Minesweeper::DisplayCellStatus::Flag:
					ofSetColor(ofColor::white);
					_imageFlag.draw(xCell, yCell, _cellSize, _cellSize);
					break;

				default:
					break;
				}
			}
		}
	}

	if (_isGameOver == true)
	{
		ofSetColor(ofColor::white);
		_font.drawString("GameOver", xSize + 32, 64);
	}
	else if (_isGameClear == true)
	{
		ofSetColor(ofColor::white);
		_font.drawString("GameClear", xSize + 32, 64);
	}
}

/// <summary>
/// 解放
/// </summary>
void Minesweeper::exit()
{
	_cells.clear();
}

void Minesweeper::mouseMoved(int x, int y)
{
	int index = GetCellIndex(x, y);
	_hoverIndex = index;
}

void Minesweeper::mouseDragged(int x, int y, int button)
{
	int index = GetCellIndex(x, y);
	_hoverIndex = index;
}

void Minesweeper::mouseReleased(int x, int y, int button)
{
	if (_isGameOver || _isGameClear)
	{
		ResetGame();
		return;
	}

	int xSize = _cellSize * _width;
	int ySize = _cellSize * _height;

	// 上限チェック
	if (x < 0 || x > xSize || y < 0 || y > ySize)
	{
		return;
	}

	int xIndex = x / _cellSize;
	int yIndex = y / _cellSize;

	ClickCell(xIndex, yIndex, button);
}

void Minesweeper::mouseExited(int x, int y)
{
	_hoverIndex = -1;
}

/// <summary>
/// セルの設定
/// </summary>
/// <param name="cellSize"></param>
/// <param name="paddingSize"></param>
void Minesweeper::SetCellSize(int cellSize, int paddingSize)
{
	_cellSize = cellSize;
	_paddingSize = paddingSize;
}

/// <summary>
/// ゲーム設定
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
/// <param name="bombCount"></param>
void Minesweeper::SetMinesweeper(int width, int height, int bombCount)
{
	if (width == 0 || height == 0)
	{
		return;
	}

	_width = width;
	_height = height;
	_bombCount = bombCount;

	_cells.clear();

	int cellCount = _width * _height;
	
	std::vector<CellStatus> widthCells;
	CellStatus status;
	_cells.assign(cellCount, status);
}

/// <summary>
/// ゲームオーバーフラグ
/// </summary>
/// <returns></returns>
bool Minesweeper::IsGameOver() const
{
	return _isGameOver;
}

/// <summary>
/// ゲームリセット
/// </summary>
void Minesweeper::ResetGame()
{
	_isGameOver = false;
	_isGameClear = false;
	_isInitialized = false;
	SetMinesweeper(_width, _height, _bombCount);
}

/// <summary>
/// セルのクリック
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="button"></param>
void Minesweeper::ClickCell(int x, int y, int button)
{
	int index = Utility::IndexCall(x, y, _width);
	int cellCount = _width * _height;
	if (index < 0 || index >= cellCount)
	{
		return;
	}

	if (button == 0)
	{
		// 左クリック
		OpenCell(index);
	}
	else if (button == 2)
	{
		// 右クリック
		SetFlag(index);
	}
}

/// <summary>
/// セル情報の取得
/// </summary>
/// <returns></returns>
std::vector<Minesweeper::CellStatus> Minesweeper::GetCellStatus() const
{
	std::vector<CellStatus> result(_cells);
	return result;
}


/// <summary>
/// 周囲の爆弾カウント
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void Minesweeper::AddBombCount(int x, int y)
{
	int index = Utility::IndexCall(x, y, _width);
	if (_cells[index]._isBomb == false)
	{
		_cells[index]._bombCount++;
	}
}

/// <summary>
/// セル番号取得
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <returns></returns>
int Minesweeper::GetCellIndex(int x, int y)
{
	int xSize = _cellSize * _width;
	int ySize = _cellSize * _height;

	// 上限チェック
	if (x < 0 || x > xSize || y < 0 || y > ySize)
	{
		return -1;
	}

	int xIndex = x / _cellSize;
	int yIndex = y / _cellSize;

	return Utility::IndexCall(xIndex, yIndex, _width);
}

/// <summary>
/// 周辺のセルを開ける
/// </summary>
/// <param name="cellIndex"></param>
void Minesweeper::OpenAroundCell(int cellIndex)
{
	auto& cell = _cells[cellIndex];
	if (cell._displayCellStatus != Minesweeper::DisplayCellStatus::Empty || cell._isBomb == true || cell._isOpened == true)
	{
		return;
	}

	cell._isOpened = true;
	if (cell._bombCount > 0)
	{
		return;
	}

	int y = cellIndex / _width;
	int x = cellIndex - y * _width;

	bool isXPlus = x + 1 < _width;
	bool isXMinus = x - 1 >= 0;
	bool isYPlus = y + 1 < _height;
	bool isYMinus = y - 1 >= 0;

	if (isXPlus)
	{
		int indexNext = Utility::IndexCall(x + 1, y, _width);
		OpenAroundCell(indexNext);

		if (isYPlus)
		{
			indexNext = Utility::IndexCall(x + 1, y + 1, _width);
			OpenAroundCell(indexNext);
		}

		if (isYMinus)
		{
			indexNext = Utility::IndexCall(x + 1, y - 1, _width);
			OpenAroundCell(indexNext);
		}

	}

	if (isXMinus)
	{
		int indexNext = Utility::IndexCall(x - 1, y, _width);
		OpenAroundCell(indexNext);

		if (isYPlus)
		{
			indexNext = Utility::IndexCall(x - 1, y + 1, _width);
			OpenAroundCell(indexNext);
		}

		if (isYMinus)
		{
			indexNext = Utility::IndexCall(x - 1, y - 1, _width);
			OpenAroundCell(indexNext);
		}
	}

	if (isYPlus)
	{
		int indexNext = Utility::IndexCall(x, y + 1, _width);
		OpenAroundCell(indexNext);
	}

	if (isYMinus)
	{
		int indexNext = Utility::IndexCall(x, y - 1, _width);
		OpenAroundCell(indexNext);
	}
}

/// <summary>
/// ゲームオーバー
/// </summary>
void Minesweeper::SetGameOver()
{
	_isGameOver = true;
}

/// <summary>
/// セルを開ける
/// </summary>
/// <param name="index"></param>
void Minesweeper::OpenCell(int index)
{
	if (_isInitialized == false)
	{
		InitializeOpenCell(index);
		SetBomb();
		_isInitialized = true;
	}

	auto& cell = _cells[index];
	if (cell._displayCellStatus == Minesweeper::DisplayCellStatus::Empty)
	{
		if (cell._isBomb)
		{
			cell._isOpened = true;
			SetGameOver();
		}
		else
		{
			OpenAroundCell(index);
		}
	}

	if (CheckGameClear())
	{
		_isGameClear = true;
	}
}

/// <summary>
/// フラグを建てる
/// </summary>
/// <param name="index"></param>
void Minesweeper::SetFlag(int index)
{
	auto& cell = _cells[index];

	switch (cell._displayCellStatus)
	{
	case Minesweeper::DisplayCellStatus::Empty:
		cell._displayCellStatus = Minesweeper::DisplayCellStatus::Flag;
		break;
	case Minesweeper::DisplayCellStatus::Flag:
		cell._displayCellStatus = Minesweeper::DisplayCellStatus::Hold;
		break;
	case Minesweeper::DisplayCellStatus::Hold:
		cell._displayCellStatus = Minesweeper::DisplayCellStatus::Empty;
		break;
	}
}

/// <summary>
/// クリアチェック
/// </summary>
/// <returns></returns>
bool Minesweeper::CheckGameClear()
{
	int count = 0;
	for (const CellStatus& cell : _cells)
	{
		if (cell._isOpened == false)
		{
			count++;
		}
	}

	return count == _bombCount;
}

/// <summary>
/// 初回のセル表示
/// </summary>
void Minesweeper::InitializeOpenCell(int cellIndex)
{
	int y = cellIndex / _width;
	int x = cellIndex - y * _width;

	bool isXPlus = x + 1 < _width;
	bool isXMinus = x - 1 >= 0;
	bool isYPlus = y + 1 < _height;
	bool isYMinus = y - 1 >= 0;
	_cells[cellIndex]._isOpened = true;

	if (isXPlus)
	{
		int indexNext = Utility::IndexCall(x + 1, y, _width);
		_cells[indexNext]._isOpened = true;

		if (isYPlus)
		{
			indexNext = Utility::IndexCall(x + 1, y + 1, _width);
			_cells[indexNext]._isOpened = true;
		}

		if (isYMinus)
		{
			indexNext = Utility::IndexCall(x + 1, y - 1, _width);
			_cells[indexNext]._isOpened = true;
		}
	}

	if (isXMinus)
	{
		int indexNext = Utility::IndexCall(x - 1, y, _width);
		_cells[indexNext]._isOpened = true;

		if (isYPlus)
		{
			indexNext = Utility::IndexCall(x - 1, y + 1, _width);
			_cells[indexNext]._isOpened = true;
		}

		if (isYMinus)
		{
			indexNext = Utility::IndexCall(x - 1, y - 1, _width);
			_cells[indexNext]._isOpened = true;
		}
	}

	if (isYPlus)
	{
		int indexNext = Utility::IndexCall(x, y + 1, _width);
		_cells[indexNext]._isOpened = true;
	}

	if (isYMinus)
	{
		int indexNext = Utility::IndexCall(x, y - 1, _width);
		_cells[indexNext]._isOpened = true;
	}
}

/// <summary>
/// 爆弾セット
/// </summary>
void Minesweeper::SetBomb()
{
	int cellCount = _width * _height;

	std::list<int> shuffleTable;
	for (int i = 0; i < cellCount; ++i)
	{
		if (_cells[i]._isOpened)
		{
			_cells[i]._isOpened = false;
			continue;
		}

		shuffleTable.push_back(i);
	}

	for (int i = 0; i < _bombCount; ++i)
	{
		int random = (int)ofRandom(shuffleTable.size());
		auto itr = shuffleTable.begin();
		for (int j = 0; j < random; ++j)
		{
			itr++;
		}
		int index = *itr;
		_cells[index]._isBomb = true;
		shuffleTable.erase(itr);

		int y = index / _width;
		int x = index - y * _width;

		bool isXPlus = x + 1 < _width;
		bool isXMinus = x - 1 >= 0;
		bool isYPlus = y + 1 < _height;
		bool isYMinus = y - 1 >= 0;

		if (isXPlus)
		{
			AddBombCount(x + 1, y);
			if (isYPlus)
			{
				AddBombCount(x + 1, y + 1);
			}

			if (isYMinus)
			{
				AddBombCount(x + 1, y - 1);
			}
		}

		if (isXMinus)
		{
			AddBombCount(x - 1, y);
			if (isYPlus)
			{
				AddBombCount(x - 1, y + 1);
			}

			if (isYMinus)
			{
				AddBombCount(x - 1, y - 1);
			}
		}

		if (isYPlus)
		{
			AddBombCount(x, y + 1);
		}

		if (isYMinus)
		{
			AddBombCount(x, y - 1);
		}
	}
}

