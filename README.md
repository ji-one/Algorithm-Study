# ✏️ algorithm-study
- 알고리즘 문제 코드 기록
- 알고리즘 사이트 (![Baekjoon Online Judge](https://www.acmicpc.net/), ![Programmers](https://programmers.co.kr/learn/challenges?tab=all_challenges))
- Language : `C++`

---

### Algorithm
<details>
<summary>Dynamic Programming</summary>
<div markdown="1">
  
- 큰문제를 작은 문제로 나누어 푸는 것이다.  
- DP는 작은 부분에서 반복되는 것을 이용하여 풀이 ex) 항상 f(3) = 2  
-> Divide and Conquer(분할 정복)은 반복이 일어나지 않는 점이 다르다.  
- 프로그래밍 방법  
  ```
    1. 모든 작은 문제들은 한번만 풀고, 작은 문제의 답을 메모한다.
    2. 보다 큰문제를 풀때 앞서 구한 답을 이용하여 해결한다.
   ```
- Memoization? -> dp 에서 중요한 개념  
  ```
    1. 작은 문제들이 반복되고 이 문제들의 결과는 같기 때문에 작은 문제의 결과값을 저장하고 다시 사용한다.
    2. 함수의 값을 계산한 뒤 계산된 값을 배열에 저장하는 방식.
  ```
- dp[0], dp[1], dp[2], dp[3] ... 나아가다 보면 규칙이 발견된다.
이를 이용하여 점화식을 도출해낼 수 있다.

</div>
</details>
<details>
<summary>Binary Search</summary>
<div markdown="1">
  
- 오름차순으로 정렬된 리스트에서 특정한 값의 위치를 찾는 알고리즘.
- 정렬된 리스트의 중간 값을 임의의 값으로 선택하여, 찾고자 하는 키 값과 비교하는 방식.
- 시간 복잡도 : log n
- 방식
  ```
    1. 정렬되어 있어야한다.
    2. left, right, mid 값을 정한다.
    3. mid 값과 key 값을 비교한다.
    4. 비교시 mid 값보다 key 값이 높으면 left를 mid + 1 값으로 만들고,
    낮으면 right를 mid - 1 값으로 만든다.
    5. left > right 될때까지 2~4번을 반복하여 key값을 찾는다.
  ```
</div>
</details>

</div>
</details>
<details>
<summary>Brute-Force</summary>
<div markdown="1">
  
- 문제를 해결하기 위해 모든 가능한 경우의 수를 직접 조합 및 대입하여 해보는 방법.
- 단점 : 시간적 제한과 자원의 제약이 있다.

</div>
</details>

</div>
</details>
<details>
<summary>DFS</summary>
<div markdown="1">
  
- 시작 노드에서부터 해당 노드의 자식 노드로 끝까지 내려가며 검색하는 방식.
- 주로 2차 행렬 넓이 구하기, 완전 탐색 문제 등에 자주 이용.
- 미로 탐색시 한 방향으로 이동하다가 더 이상 갈 수 없게 되면 가장 가까운 갈림길로 돌아와서 다른 방향으로 다시 탐색을 진행하는 방식.
- DFS가 BFS 보다 좀 더 간단하다
- 단순 검색 속도 자체는 BFS 비해서 느리다.
- 어떤 노드를 방문했었는지 여부를 반드시 검사해야 한다.
- 스택을 이용하여 구현 가능
- 재귀를 이용하여 구현 가능
- 시간 복잡도 (N: 정점수, E: 간선수)
1. 인접 리스트로 표현된 그래프: O(N+E)
2. 인접 행렬로 표현된 그래프: O(N^2)

```
void dfs(int v){
	visit[v] = 1;
	cout << v << ' ';
	for(int i=1; i<=n; i++){
		if(graph[v][i] == 1 && visit[i] == 0){
			dfs(i);
		}
	}
}
```

</div>
</details>

</div>
</details>
<details>
<summary>BFS</summary>
<div markdown="1">
  
- 시작 노드에서 인접한 노드를 먼저 탐색하는 방식.
- 두 노드 사이의 최단경로 혹은 임의의 경로를 찾고 싶을 때 이용.
- 어떤 노드를 방문했었는지 여부를 반드시 검사해야 한다.
- BFS가 DFS보다 좀 더 복잡하다.
- 큐를 이용하여 구현 가능
- 시간 복잡도(N: 정점수, E: 간선수)
1. 인접 리스트로 표현된 그래프: O(N+E)
2. 인접 행렬로 표현된 그래프: O(N^2)

```
void bfs(int v){
	visit[v] = 1;
	queue<int> q;
	q.push(v);
	
	while(!q.empty()){
		int c = q.front();
		q.pop();
		cout << c << ' ';
		for(int i=1; i<=n; i++){
			if(graph[c][i] == 1 && visit[i] == 0){
				q.push(i);
				visit[i] = 1;
			}
		}
	}
}
```

</div>
</details>

---

### Contributors
| [ji-one](https://github.com/ji-one)     | [Dongwook9696](https://github.com/Dongwook9696) |
| ----------------------------------------------- | ----------------------------------------- |
