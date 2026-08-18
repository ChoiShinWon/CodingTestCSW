#pragma once
#include <iostream>
#include <vector>

using namespace std;
/*
* [알고리즘] 퀵 정렬 (Quick Sort)
* [개념 및 동작 원리]
* 1. 기준이 되는 값(Pivot, 피벗)을 하나 설정한다.
* 2. 피벗을 기준으로 '작은 값은 왼쪽으로, 큰 값은 오른쪽으로' 진영을 나눈다.
* 3, 쪼개진 양쪽 진영에 대해 더 이상 쪼갤 수 없을 때까지 1~2번 과정을 재귀적으로 반복한다.
* -> 피벗을 제자리에 꽂아 넣으며 정렬해 나가는 분할 정복 알고리즘이다.
* 
* - 시간 복잡도: 평균 O(N log N), 최악 O(N^2)
* - 공간 복잡도 O(log N) (재귀 호출에 따른 스택 메모리 사용)
* - 안전성: 불안정 정렬
*/
class QuickSort
{
public:
	// 재귀함수이므로 시작 인덱스와 끝 인덱스를 인자로 받아줌
	void Sort(vector<int>& arr, int start, int end)
	{
		// 데이터가 1개 이하면 이미 정렬된 것이므로 재귀 종료
		if (start >= end) return;

		int pivot = arr[(start + end) / 2]; // 가운데 원소를 피벗으로 세팅
		int left = start;
		int right = end;

		// left와 right가 엇갈릴 때까지 반복
		while (left <= right)
		{
			// 왼쪽에서는 피벗보다 '크거나 같은' 숫자를 찾을 때까지 전진
			while (arr[left] < pivot) left++;

			// 오른쪽에서는 피벗보다 '작거나 같은'' 숫자를 찾을 때까지 후진
			while (arr[right] > pivot) right--;

			// 찾았다면, 둘이 엇갈리지 않았다면 자리를 바꾼다
			if (left <= right)
			{
				swap(arr[left], arr[right]);
				left++;
				right--;
			}
		}

		// 분할 정복 (쪼개진 양쪽 진영에 대해 다시 재귀 호출)
		// 루프를 탈출했다면 left와 right가 완전히 엇갈린 상태(right < left)가 된다
		// 이로 인해 피벗을 기준으로 배열이 [start ~ right] (작은 값 그룹)와 [left ~ end] (큰 값 그룹)로 나뉜다.
		if (start < right) Sort(arr, start, right); // 왼쪽 진영 재귀
		if (left < end) Sort(arr, left, end); // 오른쪽 진영 재귀
	}

	void ExecuteTest()
	{
		vector<int> testData = { 5, 3, 8, 4, 9, 1, 6 };

		cout << "=== [퀵 정렬] 실행 결과 === \n";
		cout << "정렬 전: ";
		for (int num : testData)
		{
			cout << num << " ";
		}
		cout << "\n";
		
		// 퀵 정렬 실행
		Sort(testData, 0, testData.size() - 1);

		cout << "정렬 후: ";
		for (int num : testData)
		{
			cout << num << " ";
		}
		cout << "\n";
	}
};