# [Silver V] 팩토리얼 0의 개수 - 1676 

[문제 링크](https://www.acmicpc.net/problem/1676) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

수학

### 제출 일자

2025년 3월 4일 11:39:42

### 문제 설명

<p>N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)</p>

### 출력 

 <p>첫째 줄에 구한 0의 개수를 출력한다.</p>

### 설계
<p>문제 이해를 잘못 했었다. N=3일 때, 3,2,1에서 0이 아닌 수가 나올 때까지가 아니라 3!=6에서 0이 아닌 수가 나올 때까지의 0의 개수를 구해야 한다. 0의 개수는 2와 5의 개수에 의해서 결정되는데, 2는 5보다 무조건 많다. 따라서, 5의 개수를 구해야 한다.</p>
<p>팩토리얼을 구성하는 수가 5로 나누어 떨어지면, 개수에 추가한다. 단, N=0일 경우, 나눈 결과도 계속 5로 나누어 떨어지므로 조건에 추가해야 한다.</p>
