# [Silver IV] 체스판 다시 칠하기 - 1018 

[문제 링크](https://www.acmicpc.net/problem/1018) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

브루트포스 알고리즘

### 제출 일자

2025년 3월 3일 16:00:24

### 문제 설명

<p>지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 지민이는 이 보드를 잘라서 8×8 크기의 체스판으로 만들려고 한다.</p>

<p>체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고, 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.</p>

<p>보드가 체스판처럼 칠해져 있다는 보장이 없어서, 지민이는 8×8 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 당연히 8*8 크기는 아무데서나 골라도 된다. 지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N과 M이 주어진다. N과 M은 8보다 크거나 같고, 50보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. B는 검은색이며, W는 흰색이다.</p>

### 출력 

 <p>첫째 줄에 지민이가 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.</p>

### 설계
<p>M * N 크기의 직사각형이 단위 정사각형으로 이루어져 있다. 이 중 모든 8 * 8 크기의 체스판을 만드려고 할 때, 새로 칠해야할 정사각형의 수는 특별한 규칙 없이 직접 해봐야 안다. 즉, 브루트포스이다.</p>

<p>체스판의 맨 위 왼쪽이 W일 때의 결과를 start_w_result, B일 때의 결과를 start_b_result라고 하면, 체스판의 행이 2로 나누어 떨어질 때는 맨 위 행과 같아야 하고, 나누어 떨어지지 않을 때는 다른 행과 같아야 한다. 예를 들어, start_w_result는 2로 나누어 떨어지는 행과 WBWBWBWB를 비교해야 하고, 2로 나누어 떨어지지 않는 행은 BWBWBWBW와 비교해야 한다. 비교 후, 다르다면 다시 칠해야 하는 정사각형 개수에 추가하고, 둘 중 최솟값을 최종 결과와 비교한다.</p>
