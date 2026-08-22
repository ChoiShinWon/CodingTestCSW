#pragma once
#include <iostream>
#include <vector>

using namespace std;

/*
* [알고리즘] 삽입 정렬
* 
* [개념 및 동작 원리]
* 1. 두 번째 원소부터 시작하여, 그 앞의 '이미 정렬된 배열 부분'과 비교한다.
* 2. 자신이 들어갈 올바른 위치를 찾을 때까지 앞의 원소들을 뒤로 한칸씩 밀어낸다.
* 3. 알맞은 자리를 찾으면 그 위치에 자신을 '삽입' 한다.
* 
* - 시간 복잡도: 평균 / 최악 O(N^2), 최선 O(N) (이미 거의 정렬된 경우)
* - 공간 복잡도: O(1) (제자리 정렬)
* - 안정성: 안정 정렬
* 
* - 데이터의 크기가 아주 작을때는 퀵/병합정렬보다 오히려 빠름
*/
class InsertionSort
{
public:
	void Sort(vector<int>& arr)
	{
		int n = arr.size();

		// 0번은 이미 정렬되어 있다고 하고, 1번 인덱스부터 끝까지 순회
		for (int i = 1; i < n; i++)
		{
			int key = arr[i]; // 이번 턴에 올바른 자리에 꽂아 넣을 데이터
			int j = i - 1; // key의 바로 왼쪽 인덱스부터 역방향 탐색 시작

			// 1. 왼쪽으로 가면서 key보다 큰 놈들은 전부 오른쪽으로 한칸씩 밀어버린다.
			while (j >= 0 && arr[j] > key)
			{
				arr[j + 1] = arr[j]; // 오른쪽으로 밀기
				j--; // 더 왼쪽으로 이동
			}

			// 2. 루프가 끝난 자리(j+1)가 바로 key가 들어갈 알맞은 자리
			arr[j + 1] = key;
		}

	}

	void ExecuteTest()
	{
		vector<int> testData = { 5, 3, 4, 1, 2 };

		cout << "==== [삽입 정렬] 실행 결과 ==== \n";
		cout << "정렬 전: ";
		for (int num : testData)
		{
			cout << num << " ";
		}
		cout << "\n";

		Sort(testData);
		
		cout << "정렬 후: ";
		for (int num : testData)
		{
			cout << num << " ";
		}
	}
};