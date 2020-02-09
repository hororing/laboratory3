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
		// 왜 char*로 받은걸 std::string&으로 출력하는걸까?

	private:
		//필요에 따라 private 변수와 메서드를 추가하세요
		int lastIndex;
		int* mTime;
		std::string mName;
		int mMaxEntries;
		 
	};
}