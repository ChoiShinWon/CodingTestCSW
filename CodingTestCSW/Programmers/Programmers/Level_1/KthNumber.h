#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // 정렬(sort)을 사용하기 위해 필수

using namespace std;


// 문제: K 번째 수 (Level 1)
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/42748
//접근 방식: 주어진 배열을 지정된 범위만큼 자르고, 정렬한 뒤, k번째 원소 추출.

class KthNumber
{
public:
	vector<int> solution(vector<int> array, vector<vector<int>> commands)
	{
		vector<int> answer;

		// 인덱스가 필요 없을 때는 범위 기반 for문과 const 참조를 사용하여 복사 비용 절감
		for (const auto& command : commands)
		{
			int startIdx = command[0] - 1;
			// end 구간 바로 앞까지 들어가기 때문에 -1 안함
			int endIdx = command[1];
			int targetIdx = command[2] - 1;

			// 시작 인덱스 부터 끝 인덱스까지 추출
			vector<int> slicedArray(array.begin() + startIdx, array.begin() + endIdx);

			
			// 추출한 배열을 정렬
			/*sort(slicedArray.begin(), slicedArray.end());*/

			answer.push_back(slicedArray[targetIdx]);
		}
		return answer;
	}

	void ExecuteTest()
	{
		vector<int> testArray = { 1, 5, 2, 6, 3, 7, 4 };
		vector<vector<int>> testCommands = { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} };

		cout << "K번째 수 실행 결과: ";
		vector<int> result = solution(testArray, testCommands);
		for (int num : result)
		{
			cout << num << " ";
		}
	}
};