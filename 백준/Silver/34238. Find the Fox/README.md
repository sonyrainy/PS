# [Silver V] Find the Fox - 34238 

[문제 링크](https://www.acmicpc.net/problem/34238) 

### 성능 요약

메모리: 2156 KB, 시간: 0 ms

### 분류

구현, 브루트포스 알고리즘

### 제출 일자

2025년 9월 5일 21:13:18

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>행 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>열의 글자판이 주어지고, 글자판의 각 칸에는 영어 알파벳 <span style="color:#e74c3c;"><code>F</code></span>, <span style="color:#e74c3c;"><code>O</code></span>, <span style="color:#e74c3c;"><code>X</code></span> 중 하나가 쓰여 있다.</p>

<p>당신은 이 글자판에서 영단어 <span style="color:#e74c3c;"><code>FOX</code></span>를 모두 찾아야 한다. <span style="color:#e74c3c;"><code>FOX</code></span>는 다음과 같은 규칙으로 찾아야 한다.</p>

<ol>
	<li>처음에 알파벳 <span style="color:#e74c3c;"><code>F</code></span>를 선택한다.</li>
	<li>1에서 선택한 <code><span style="color:#e74c3c;">F</span></code>와 상하좌우/대각선으로 인접한 알파벳 <code><span style="color:#e74c3c;">O</span></code>를 선택한다.</li>
	<li>2에서 선택한 <code><span style="color:#e74c3c;">O</span></code>와 상하좌우/대각선으로 인접한 알파벳 <span style="color:#e74c3c;"><code>X</code></span>를 선택한다.</li>
	<li>1, 2, 3 에서 선택한 <span style="color:#e74c3c;"><code>F</code></span>,<span style="color:#e74c3c;"> <code>O</code></span>,<span style="color:#e74c3c;"> <code>X</code></span>가 모두 같은 행, 또는 같은 열, 또는 같은 대각선에 있을 경우 <span style="color:#e74c3c;"><code>FOX</code></span>를 하나 찾은 것이다.</li>
</ol>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/2acbf3ba-96f4-4513-b46b-96a7ce2f2fdc/-/preview/" style="height: 205px; width: 600px;"></p>

<p>위 그림은 <span style="color:#e74c3c;"><code>FOX</code></span>를 바르게 찾은 예시이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/1b223db6-eb5d-45e9-9688-68bcbfb3c937/-/preview/" style="height: 71px; width: 600px;"></p>

<p>위 그림은 <span style="color:#e74c3c;"><code>FOX</code></span>를 바르게 찾은 예시가 아닌 것들이다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/cf47b2dc-5989-45df-bb8b-f3215095991b/-/preview/" style="height: 171px; width: 600px;"></p>

<p>위 그림처럼 알파벳의 배치에 따라 한 알파벳이 여러 개의 <span style="color:#e74c3c;"><code>FOX</code></span>에 포함될 수도 있다. 겹쳐진 <span style="color:#e74c3c;"><code>FOX</code></span>들도 모두 구분해서 세어야 한다.</p>

<p>글자판이 주어지면 <span style="color:#e74c3c;"><code>FOX</code></span>가 모두 몇 개 있는지 구하여라.</p>

### 입력 

 <p>첫째 줄에 글자판의 행과 열의 수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>,</mo><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N,M$</span></mjx-container>이 공백으로 구분되어 주어진다. <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mo class="mjx-n"><mjx-c class="mjx-c28"></mjx-c></mjx-mo><mjx-mn class="mjx-n"><mjx-c class="mjx-c33"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="4"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n"><mjx-c class="mjx-c2C"></mjx-c></mjx-mo><mjx-mi class="mjx-i" space="2"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c31"></mjx-c><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n"><mjx-c class="mjx-c29"></mjx-c></mjx-mo></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mo stretchy="false">(</mo><mn>3</mn><mo>≤</mo><mi>N</mi><mo>,</mo><mi>M</mi><mo>≤</mo><mn>100</mn><mo stretchy="false">)</mo></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$(3 \leq N,M \leq 100)$</span> </mjx-container></p>

<p>둘째 줄부터 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 줄에 걸쳐 글자판의 각 칸에 쓰인 알파벳이 각 행마다 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개 주어진다. 주어지는 알파벳은 모두 영어 알파벳 대문자 <span style="color:#e74c3c;"><code>F</code></span>, <span style="color:#e74c3c;"><code>O</code></span>, <span style="color:#e74c3c;"><code>X</code></span> 중 하나이다.</p>

### 출력 

 <p>첫째 줄에 글자판에서 찾을 수 있는 <span style="color:#e74c3c;"><code>FOX</code></span>의 총 개수를 출력한다.</p>

