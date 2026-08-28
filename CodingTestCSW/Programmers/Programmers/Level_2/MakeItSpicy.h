#pragma once
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
* [프로그래머스 Lv2] 더 맵게 (Make it Spicy)
* 
* - 시간 복잡도: O(N log N) (원소 N개를 매번 push/pop, 각 연산이 O(log N))
* - 공간 복잡도: O(N) (모든 원소를 힙에 담아야 하므로)
* - 사용 자료구조: 최소 힙(Min Heap) - priority_queue<int, vector<int>, greater<int>>
* - 핵심 아이디어: 가장 안 매운 음식 2개를 계속 꺼내서 섞은 뒤 다시 힙에 넣는다.
*                 섞어서 만든 새 값도 다시 힙 안에서 다른 값들과 경쟁하며 제자리를 찾는다.
*                 힙의 최솟값(top)이 K이상이 되는 순간, 모든 음식이 K이상이 됐다는 뜻이다.
* - 예외 처리: 원소가 1개만 남았는데도 top이 K보다 작으면 더 섞을 수 없으므로 -1 반환
*
*/

class MakeItSpicy
{
public:
	// scoville: 각 음식의 스코빌 지수 배열, K: 원하는 최소 스코빌 지수
	// 반환값: 모든 음식을 K 이상으로 만들기 위해 섞은 횟수 (불가능하면 -1)
	int Solution(vector<int> scoville, int K)
	{
		int answer = 0;
		priority_queue<int, vector<int>, greater<int>> minHeap;

		// 1. 모든 스코빌 지수를 최소 힙에 담기
		for (int i = 0; i < scoville.size(); ++i)
		{
			minHeap.push(scoville[i]);
		}

		// 2. 힙의 최솟값(top)이 K보다 작은 동안 계속 반복
		while (minHeap.top() < K)
		{
			int min1 = minHeap.top();
			minHeap.pop();

			if (minHeap.empty()) return -1;

			int min2 = minHeap.top();
			minHeap.pop();

			// 3. 공식대로 새 값을 만들어 다시 힙에 push (최솟값 갱신0
			int newVal = min1 + (min2 * 2);
			minHeap.push(newVal);

			answer++;
		}
		return answer;
	}

	void ExecuteTest()
	{
		vector<int> testData = { 1, 2, 3, 9, 10, 12 };
		int K = 7;

		cout << "==== [더 맵게] 실행 결과 ==== \n";
		cout << "입력 배열: ";
		for (int num : testData) { cout << num << " "; }
		cout << "\nK = " << K << "\n";

		int result = Solution(testData, K);

		cout << "섞은 횟수: " << result << "\n";
	}
};
