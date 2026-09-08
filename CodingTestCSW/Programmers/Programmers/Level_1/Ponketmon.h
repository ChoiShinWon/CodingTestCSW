#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
* [프로그래머스 Lv1] 폰켓몬
* 
* - 시간 복잡도: O(N) (nums를 한 번 순회하며 set에 삽입)
* - 공간 복잡도: O(N) (최악의 경우 모든 원소가 다 다른 종류일 때)
* - 사용 자료구조: 해시 셋 (unordered_set<int>)
* - 핵심 아이디어: 가져갈 수 있는 개수 (N/2)와 "종류의 다양성(unique 개수)" 중
*                 더 작은 값이 곧 도감에 등록 가능한 최대 개수다.
*                 예) 5마리 중 4종류면 -> 2마리(N/2)밖에 못 뽑으니 답은 min(2,4) = 2
*                     10마리 중 2종류면 -> 5마리 뽑을 수 있지만 종류가 2개 뿐이니 답은 min (5,2) = 2
*/

class PonketMon
{
public:
	// nums: 폰켓몬 번호 배열 (한 마리씩, 중복 있음)
	// 반환값: 도감에 등록할 수 있는 최대 종류 수
	int Solution(vector<int> nums)
	{
		int max_pick = nums.size() / 2;

		// nums를 set에 넣는 순간 중복은 자동으로 걸러짐 -> unique한 종류만 남음
		unordered_set<int> unique(nums.begin(), nums.end());

		int type_count = unique.size();

		// 뽑을 수 있는 개수(max_pic)와 실제 종류 수 (type_count) 중 작은 쪽이 정답
		return min(max_pick, type_count);
	}

	void ExecuteTest()
	{
		vector<int> testNums = { 3, 1, 2, 3 };
		cout << "==== [폰켓몬] 실행 결과 ==== \n";
		cout << "번호 목록: ";
		for (int n : testNums) { cout << n << " "; }
		cout << "\n";
		int result = Solution(testNums);
		cout << "도감 등록 가능 최대 종류: " << result << "\n";
		cout << "예상 정답: 2\n\n";
	}
};