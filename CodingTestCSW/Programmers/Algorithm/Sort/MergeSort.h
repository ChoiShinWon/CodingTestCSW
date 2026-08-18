#pragma once
#include <iostream>
#include <vector>

using namespace std;


/*
 * [알고리즘] 병합 정렬 (Merge Sort)
 *
 * - 시간 복잡도: O(N log N) (최선, 평균, 최악 모두 동일)
 * - 공간 복잡도: O(N) (병합 과정에서 임시 배열 할당 필요)
 * - 안정성: 안정 정렬 
 */

class MergeSort
{
private:
	// 두 부분 배열을 정렬하며 하나로 병합하는 로직 (외부에서 호출 불가)
	void Merge(vector<int>& arr, int left, int mid, int right)
	{
		vector<int> temp; // 병합 결과를 담을 임시 배열
		int l = left; // 왼쪽 진영의 탐색 시작점
		int r = mid + 1; // 오른쪽 진영의 탐색 시작점

		// 양쪽 그룹을 비교하며 더 작은 값부터 temp에 순서대로 삽입
		while (l <= mid && r <= right)
		{
			if (arr[l] <= arr[r])
			{
				temp.push_back(arr[l]);
				l++;
			}
			else
			{
				temp.push_back(arr[r]);
				r++;
			}
		}
		
		// 왼쪽 진영에 남은 데이터가 있다면 모두 삽입
		while (l <= mid)
		{
			temp.push_back(arr[l]);
			l++;
		}

		// 오른쪽 진영에 남은 데이터가 있다면 모두 삽입
		while (r <= right)
		{
			temp.push_back(arr[r]);
			r++;
		}

		// 완성된 임시 배열을 원본 배열의 원래 위치에 덮어쓰기
		for (int i = 0; i < temp.size(); i++)
		{
			arr[left + i] = temp[i];
		}

	}

public:
	// 배열을 반으로 계속 쪼개는 재귀 함수 (외부에서 호출하는 메인 정렬 함수)
	void Sort(vector<int>& arr, int left, int right)
	{
	    // 원소가 1개 이하면 더 이상 쪼갤 필요가 없으므로 함수 종료
		if (left >= right) return;

		int mid = (left + right) / 2; // 중앙 분할 선 계산

		// 반으로 쪼개서 각각 재귀 호출
		Sort(arr, left, mid); // 왼쪽 진영 쪼개기
		Sort(arr, mid + 1, right); // 오른쪽 진영 쪼개기

		// 다 쪼개고 돌아오면 병합 시작
		Merge(arr, left, mid, right);
	}

	// 테스트 실행 함수
	void ExecuteTest()
	{
		vector<int> testData = { 37, 27, 43, 3, 9, 82, 10 };

		cout << "=== 병합 정렬 실행 결과 === " << "\n";
		cout << "정렬 전: ";
		for (int num : testData)
		{
			cout << num << " ";
		}
		cout << "\n";

		// 정렬 실행
		Sort(testData, 0, testData.size() - 1);
		cout << "정렬 후: ";
		for (int num : testData)
		{
			cout << num << " ";
		}
		
	}
};