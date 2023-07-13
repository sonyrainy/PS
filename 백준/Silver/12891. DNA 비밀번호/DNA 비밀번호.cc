#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string passward;
	int size, range, answer = 0, A, C, G, T;
    //크기, 찾는 범위, 정답 수, A, C, G, T 값
	int cA = 0, cC = 0, cG = 0, cT = 0;
    //각각의 최소 숫자 값
    
	cin >> size >> range >> passward >> A >> C >> G >> T;

	for (int i = 0; i < range; i++)
	{
		if (passward[i] == 'A')
		{
			cA++;
		}
		else if (passward[i] == 'C')
		{
			cC++;
		}
		else if (passward[i] == 'G')
		{
			cG++;
		}
		else if (passward[i] == 'T')
		{
			cT++;
		}
	}
    // 초기 값 입력
    
	if (A <= cA && C <= cC && G <= cG && T <= cT)
	{
		answer++;
	}
    // 초기 값 검사

	for (int i = range; i < size; i++)
	{
		if (passward[i] == 'A')
		{
			cA++;
		}
		else if (passward[i] == 'C')
		{
			cC++;
		}
		else if (passward[i] == 'G')
		{
			cG++;
		}
		else if (passward[i] == 'T')
		{
			cT++;
		}
        // 패스워드 다음 값을 받아오고, 어떤 문자인지 확인하다.
        
		if (passward[i - range] == 'A')
		{
			cA--;
		}
		else if (passward[i - range] == 'C')
		{
			cC--;
		}
		else if (passward[i - range] == 'G')
		{
			cG--;
		}
		else if (passward[i - range] == 'T')
		{
			cT--;
		}
        // 범위를 벗어난 문자의 값을 삭제시킨다.
        
		if (A <= cA && C <= cC && G <= cG && T <= cT)
		{
			answer++;
		}
        // 값 재검사
	}

	cout << answer << "\n";

	return 0;
}