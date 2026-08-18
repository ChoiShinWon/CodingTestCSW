#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 문제: 행렬의 곱셈 (Level 2)
// 링크: https://school.programmers.co.kr/learn/courses/30/lessons/12949
// 접근 방식: 3중 for문을 이용한 행렬 곱셈 구현. 결과 행렬의 크기는 (A의 행) x (B의 열)
// 시간 복잡도 O(N x M x K) - 최대 100 x 100 배열이므로 100^3 = 100만번 연산

class MatrixMultiplication
{
public:

	vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
	{
		// arr1 을 (N x K), arr2를 (K x M)이라고 가정할 때:
		// N: 최종 결과 행렬의 행(Row) 개수 (앞 행렬의 행)
		int rowSize = arr1.size();

		// M: 최종 결과 행렬의 열(Column) 개수 (뒤 행렬의 열)
		int colSize = arr2[0].size();

		// K: 두 행렬을 내적하기 위해 순회해야 하는 공통 차원
		// 앞 행렬의 열 개수이자, 뒤 행렬의 행 개수. 즉 arr1[0].size() == arr2.size()
		int innerSize = arr1[0].size();

		vector<vector<int>> answer(rowSize, vector<int>(colSize, 0));
		
		// i 루프: 앞 행렬(A)에서 계산할 행을 하나 고정
		for (int i = 0; i < rowSize; ++i)
		{
			// j 루프: 뒤 행렬(B)에서 계산할 열을 하나 고정
			for (int j = 0; j < colSize; ++j)
			{
				// k 루프: 고정된 A의 행과 B의 열의 원소들을 1:1로 매칭하여 곱하고 결과값에 더함
				for (int k = 0; k < innerSize; ++k)
				{
					answer[i][j] += arr1[i][k] * arr2[k][j];
				}
			}
		}
		return answer;
	}

	void ExecuteTest()
	{
		vector<vector<int>> testArr1 = { {1, 4}, {3, 2}, {4, 1} };
		vector<vector<int>> testArr2 = { {3, 3}, {3, 3} };

		cout << "==== 행렬의 곱셈 실행 결과 ==== " << endl;
		vector<vector<int>> result = solution(testArr1, testArr2);

		for (const auto& row : result)
		{
			for (int num : row)
			{
				cout << num << " ";
			}
			cout << "\n";
		}
		cout << "\n(예상 정답: \n15 15\n15 15\n15 15)\n" << endl;
	}
};