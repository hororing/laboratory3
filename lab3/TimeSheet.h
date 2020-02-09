#pragma once

#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		
		~TimeSheet();

		void AddTime(int timeInHours);

		int GetTimeEntry(unsigned int index) const;

		int GetTotalTime() const;

		float GetAverageTime() const;

		float GetStandardDeviation() const;

		const std::string& GetName() const;
		// �� char*�� ������ std::string&���� ����ϴ°ɱ�?

	private:
		//�ʿ信 ���� private ������ �޼��带 �߰��ϼ���
		int lastIndex;
		int* mTime;
		std::string mName;
		int mMaxEntries;
		 
	};
}