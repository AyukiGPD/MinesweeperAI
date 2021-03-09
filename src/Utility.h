#pragma once
#include <string>

namespace Utility
{
	/// <summary>
	/// ���S�ȉ��
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
	/// �C���f�b�N�X�v�Z
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="paramMaxX"></param>
	/// <returns></returns>
	int IndexCall(int x, int y, int paramMaxX);

	/// <summary>
	/// msec �� ������
	/// </summary>
	/// <param name="msec"></param>
	/// <returns></returns>
	std::string MsecToTimeString(double msec);

}	// namespace Utility

