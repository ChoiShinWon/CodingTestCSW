#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* [프로그래머스] 길 찾기 게임 (2019 카카오 개발자 겨울 인턴십) Level 3
* 
* - 핵심: 2차원 좌표 (x, y)를 이용해 이진 탐색 트리(BST)를 직접 구축하는 문제
* - Y좌표: 트리의 레벨(높이), Y가 클수록 부모 노드
* - X좌표: 이진 탐색 트리의 대소 비교 기준. 부모의 X보다 작으면 왼쪽, 크면 오른쪽 자식
* - 트리 구축 후 전위 순회(루트 -> 왼쪽 -> 오른쪽)와 후위 순회(왼쪽 -> 오른쪽 -> 루트)를 수행하여 결과를 반환
*/

// 1. 노드 구조체 정의
struct Node
{
	int id; // 노드 번호
	int x, y; // 좌표
	Node* left; // 왼쪽 자식 포인터
	Node* right; // 오른쪽 자식 포인터
	// 생성자
	Node(int id, int x, int y) : id(id), x(x), y(y), left(nullptr), right(nullptr) {}
};

class PathFindingGame
{
private:
	// 2. 커스텀 정렬 기준 (Y좌표가 내림차순, Y가 같으면 X좌표 오름차순)
	static bool CompareNodes(Node* a, Node* b)
	{
		if (a->y == b->y)
		{
			return a->x < b->x;
		}

		return a->y < b->y;
	}

	// 3. 트리에 노드를 삽입하는 재귀 함수
	void InsertNode(Node* parent, Node* child)
	{
		// X좌표가 부모보다 작으면 왼쪽으로
		if (child->x < parent->x)
		{
			if (parent->left == nullptr)
				parent->left = child; // 부모의 왼쪽이 비었다면 빈자리에 자식 대입
			else
				InsertNode(parent->left, child); // 자리가 있으면 더 타고 내려감
		}

		// X좌표가 부모보다 크면 오른쪽으로
		else
		{
			if (parent->right == nullptr)
				parent->right = child; // 부모의 오른쪽이 비었다면 마찬가지로 빈자리에 자식 대입
			else
				InsertNode(parent->right, child); // 자리가 있으면 더 타고 내려감
		}
	}

	// 전위 순회
	void PreOrder(Node* node, vector<int>& result)
	{
		if (node == nullptr) return;
		result.push_back(node->id); // Root 방문
		PreOrder(node->left, result); // Left
		PreOrder(node->right, result); // Right
	}

	// 후위 순회
	void PostOrder(Node* node, vector<int> result)
	{
		if (node == nullptr) return;
		PostOrder(node->left, result); // Left
		PostOrder(node->right, result); // Right
		result.push_back(node->id); // Root 방문
	}

	// 동적 할당된 트리의 메모리 해제하는 함수(후위 순회)
	void DeleteTree(Node* node)
	{
		if (node == nullptr) return;
		DeleteTree(node->left);
		DeleteTree(node->right);
		delete node;
	}
public:
	// 프로그래머스 제출용 solution 함수
	vector<vector<int>> solution(vector<vector<int>> nodeinfo)
	{
		vector<Node*> nodes;

		// 1. 주어진 배열을 Node 객체(포인터) 배열로 변환
		for (int i = 0; i < nodeinfo.size(); i++)
		{
			// 노드 번호는 1번부터 시작하므로 i + 1
			nodes.push_back(new Node(i + 1, nodeinfo[i][0], nodeinfo[i][1]));
		}

		// 2. Y좌표 기준으로 노드들을 정렬하여 루트 노드 찾기
		sort(nodes.begin(), nodes.end(), CompareNodes);

		// 정렬 후 0번 인덱스가 무조건 트리의 루트가 됨
		Node* root = nodes[0];

		// 3. 루트를 기준으로 나머지 노드들을 트리에 ㅅ ㅏㅂ입
		for (int i = 1; i < nodes.size(); i++)
		{
			InsertNode(root, nodes[i]);
		}

		// 4. 순회 돌리기
		vector<vector<int>> answer(2);  // answer[0]은 전위, answer[1]은 후위
		PreOrder(root, answer[0]);
		PostOrder(root, answer[1]);

		// 5. 메모리 누수 방지를 위해 트리 삭제
		DeleteTree(root);

		return answer;
	}

	void ExecuteTest()
	{
		vector<vector<int>> nodeinfo = {
			{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1},
			{1, 3}, {8, 6}, {7, 2}, {2, 2}
		};

		vector<vector<int>> result = solution(nodeinfo);

		cout << "==== [길 찾기 게임] 실행 결과 ==== \n";

		cout << "전위 순회: ";
		for (int id : result[0]) cout << id << " ";
		cout << "\n(예상 정답: 7 4 6 9 1 8 5 2 3)\n\n";

		cout << "후위 순회: ";
		for (int id : result[1]) cout << id << " ";
		cout << "\n(예상 정답: 9 6 5 8 1 4 3 2 7)\n\n";
	}
};