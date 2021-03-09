#pragma once
#include <string>

namespace Utility
{
	/// <summary>
	/// 安全な解放
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="p"></param>
	template <typename T>
	inline
	void SafeDelete(T*& p)
	{
		if (p == nullptr)
		{
			return;
		}

		delete p;
		p = nullptr;
	}

	/// <summary>
	/// インデックス計算
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="paramMaxX"></param>
	/// <returns></returns>
	int IndexCall(int x, int y, int paramMaxX);

	/// <summary>
	/// msec → 文字列
	/// </summary>
	/// <param name="msec"></param>
	/// <returns></returns>
	std::string MsecToTimeString(double msec);

}	// namespace Utility

