#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
* [알고리즘] 힙 정렬 
* 
* - 시간 복잡도: O(N log N) (최선, 평균, 최악 모두 동일)
* - 공간 복잡도: O(1) (추가 배열 없이 제자리 정렬)
* - 안전성: 불안정 정렬
* - 완전 이진 트리의 특성을 활용한 정렬이다.
* - 병합 정렬처럼 항상 O (N log N)을 보장하면서도, 추가 메모리(임시 배열)을 사용하지 않는다는 엄청난 장점이 있음.
* - 속도가 아주 빠르다
* - 가장 비용이 높거나 낮은 하나를 빠르게 뽑아낼 때 이 힙 구조를 사용한다.
*/

class HeapSort
{
private:
	// 특정 노드를 기준으로 그 아래 자식듩을 확인하여 최대 힙(부모>자식) 구조를 복구하는 함수
	// n은 지금 내가 힙으로 인정하고 조작할 배열의 길이를 의미한다.
	// i는 지금 내가 쳐다보고 있는 노드를  뜻한다.
	// 최대 힙 구조를 만드는 함수
	void Heapify(vector<int>& arr, int n, int i)
	{
		int largest = i; // 일단 현재 노드(부모)가 가장 크다고 가정
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		// 1. 왼쪽 자식이 배열 범위 내에 있고, 현재 가장 큰 값보다 더 크다면 타겟 변경
		if (left < n && arr[left] > arr[largest])
		{
			largest = left;
		}

		// 2. 오른쪽 자식이 배열 범위 내에 있고, 현재 가장 큰 값보다 더 크다면 타겟 변경
		if (right < n && arr[right] > arr[largest])
		{
			largest = right;
		}

		// 3. 자식 중에 부모 (초기 i) 보다 큰 녀석이 발견되었다면 자리를 바꿈
		if (largest != i)
		{
			swap(arr[i], arr[largest]);

			// 자리가 바뀌면서 밑에 있던 트리가 망가졌을 수 있으므로,
			// 바뀐 자리(largest)를 기준으로 다시 밑으로 내려가며 복구
			Heapify(arr, n, largest);
		}
	}

public:
	void Sort(vector<int>& arr)
	{
		int n = arr.size();

		// 초기 배열을 최대 힙으로 빌드하기
		// 맨 밑바닥 노드들은 자식이 없으므로 검사할 필요 없음
		// 부모 노드가 존재하는 마지막 인덱스 (n / 2 - 1) 부터 루트(0)까지 역순으로 힙 구성
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			Heapify(arr, n, i);
		}

		// 루트(가장 큰 값)를 맨 뒤로 뽑아내고 트리를 다시 복구
		for (int i = n - 1; i > 0; i--)
		{
			// 현재 루트(제일 큰 값)를 정렬되지 않은 배열의 맨 끝과 스왑
			swap(arr[0], arr[i]);

			// 맨 끝으로 간 큰 값은 놔두고(사이즈를 i로 줄임)
			// 엉뚱한 값이 올라간 루트(0번)을 기준으로 다시 최대 힙 복구
			Heapify(arr, i, 0);
		}
	}

	void ExecuteTest()
	{
		vector<int> testData = { 4, 10, 3, 5, 1 };

		cout << "==== [Heap Sort] 실행 결과 ==== \n";
		cout << "정렬 전: ";
		for (int num : testData) { cout << num << " "; }
		cout << "\n";

		Sort(testData);

		cout << "정렬 후: ";
		for (int num : testData) { cout << num << " "; }
		cout << "\n(예상 정답: 1 3 4 5 10)\n\n";
	}
};