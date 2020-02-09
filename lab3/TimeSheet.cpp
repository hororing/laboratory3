#include "TimeSheet.h"
#include <iostream>
#include <string>



namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
	{
		mTime = new int[lastIndex+3];
		mName = name;
		mMaxEntries = maxEntries;
		std::cout << mName << " " << maxEntries << std::endl;
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mTime;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (1 <= timeInHours < mMaxEntries)
		{
			mTime[lastIndex] = timeInHours;
			std::cout << mTime[lastIndex] << "시간이 추가되었습니다." << std::endl;
			lastIndex++;
		}
		
		
			

		//• 각 직원은 매일 본인이 일한 시간을 기록합니다. 이 때 호출하는
		/*함수가 AddTime() 메서드 입니다.
			• 직원이 하루에 근무할 수 있는 시간은 최소 1 시간, 최대 10 시간입니다.
			만약 유효한 범위를 벗어나는 시간을 기록하려고 하면 AddTime() 메서드는
			아무 일도 하지 않습니다.*/

	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (mTime[index] != '\0')
		{
			return mTime[index];
		}
		else
		{
			return -1;
		}

		/*사장님은 일 단위로 직원이 근무한 시간을 조회할 수 있습니다.이
			때, GetTimeEntry() 메서드를 호출합니다.
			• GetTimeEntry() 함수는 색인 위치에 시간 값이 존재하지 않으면 - 1 을
			반환해야 합니다.*/
	}

	int TimeSheet::GetTotalTime() const
	{
		int totalTime = 0;
		for (int i = 0; i <= (lastIndex-1); i++)
		{
			totalTime = totalTime + mTime[i];
		}

		return totalTime;

		/*봉급을 주려면 직원이 총 몇 시간을 일했는지 알아야
			겠죠 ? .GetTotalTime() 메서드는 현재 프로젝트에서 직원이 그동안 기록한
			총 시간을 반환해야 합니다*/
	}

	float TimeSheet::GetAverageTime() const
	{
		
		float totalTime = GetTotalTime();
		float averageTime = totalTime / lastIndex;
		/*회사는 직원의 평균 근무 시간에 대한 통계를 내고자 합니다.
			그러므로 GetAverageTime() 메서드는 직원이 하루에 평균 몇 시간을
			일하는지 반환해야 합니다.*/
		return averageTime;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float StandardDeviation = 0;
		float average = GetAverageTime();


		for (int i = 0; i < lastIndex; i++)
		{
			float a = (mTime[i] - average) / lastIndex;
			std::cout << "표준편차 / " << a << std::endl;
			StandardDeviation = abs(StandardDeviation + a);
			std::cout << "표준편차 / " << StandardDeviation << std::endl;
		}

		/*회사는 직원의 근무 시간이 얼마나 들쭉날쭉 한 지 통계를 내고 싶어합니다.
			표준 편차를 구하면 되겠군요 ? GetStandardDeviation() 메서드는 근무시간
			기록표에 기록된 시간의 표준 편차를 반환해야 합니다.*/
		return StandardDeviation;
	}

	const std::string& TimeSheet::GetName() const
	{
		return mName;
	}

}