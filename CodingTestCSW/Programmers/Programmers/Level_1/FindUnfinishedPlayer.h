#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
/*
* [프로그래머스 Lv1] 완주하지 못한 선수
* 
* - 시간 복잡도: O(N) (participants, completion을 각각 한 번씩만 순회 + 마지막 map 순회)
* - 공간 복잡도: O(N) (모든 참가자 이름을 map에 담아야 하므로)
* - 사용 자료구조: 해시 테이블 (unordered_map<string, int>)
* - 핵심 아이디어: participant에 있는 이름은 전부 +1, completion에 있는 이름은 전부 -1,
*                 완주한 사람은 +1과 -1이 상돼되어 0이 되고,
*                 완주하지 못한 사람만 값이 0이 아닌 채로 남는다.
* - 주의: [] 연산자는 없는 키에 접근하면 몰래 0으로 새로 만들어버리는 함정이 있다.
*         이 문제는 completion이 participant에 포함된다라는 조건이 보장되므로, completion을 순회하며 --할 때 안전하게 사용 가능하다.
*/
class FindUnfinishedPlayer
{
public:
	// participant: 참가자 이름 배열, completion: 완주자 이름 배열
	// 반환값: 완주하지 못한 선수의 이름
	string Solution(vector<string> participant, vector<string> completion)
	{
		string answer = "";
		unordered_map<string, int> Count;

		// 1. 참가자들을 우선 Count에 하나씩 카운트
		for (int i = 0; i < participant.size(); ++i)
		{
			Count[participant[i]]++;
		}

		// 2. 완주자는 값을 1씩 뺀다 (completion은 participant에 포함되어 있으므로 [] 함정에서 안전)
		for (int i = 0; i < completion.size(); ++i)
		{
			Count[completion[i]]--;
		}

		// 3. 값이 0이 아니고 남아있는 사람 = 완주하지 못한 사람
		for (const auto& person : Count)
		{
			if (person.second != 0)
			{
				answer = person.first;
				break;
			}
		}

		return answer;
	}

	void ExecuteTest()
	{
		vector<string> testParticipant = { "leo", "kiki", "eden" };
		vector<string> testCompletion = { "eden", "kiki" };

		cout << "==== [완주하지 못한 선수] 실행 결과 ==== \n";
		cout << "참가자: ";
		for (const string& name : testParticipant) { cout << name << " "; }
		cout << "\n완주자: ";
		for (const string& name : testCompletion) { cout << name << " "; }
		cout << "\n";

		string result = Solution(testParticipant, testCompletion);

		cout << "완주하지 못한 선수: " << result << "\n";
		cout << "(예상 정답: leo)\n\n";
	}
};