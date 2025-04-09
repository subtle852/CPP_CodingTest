#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

string result;

string solution(int n, int k, vector<string> cmd) 
{
	vector<int> prev(n), next(n);
	vector<bool> isDeleted(n, false);
	stack<int> restore;

	for (int i = 0; i < n; i++) {
		prev[i] = i - 1;
		next[i] = i + 1;
	}

	for (string c : cmd) 
	{
		if (c[0] == 'U') 
		{
			int x = stoi(c.substr(2));

			while (x--) 
				k = prev[k];
		}
		else if (c[0] == 'D') 
		{
			int x = stoi(c.substr(2));

			while (x--) 
				k = next[k];
		}
		else if (c[0] == 'C') 
		{
			isDeleted[k] = true;
			restore.push(k);

			if (prev[k] != -1) // 앞뒤 연결
				next[prev[k]] = next[k];

			if (next[k] != n) // 앞뒤 연결
				prev[next[k]] = prev[k];

			k = (next[k] == n) ? prev[k] : next[k]; // 마지막원소인 경우 k--
		}
		else if (c[0] == 'Z') 
		{
			int z = restore.top(); 
			restore.pop();
			isDeleted[z] = false;

			if (prev[z] != -1) // 앞뒤 연결 복구
				next[prev[z]] = z;

			if (next[z] != n) // 앞뒤 연결 복구
				prev[next[z]] = z;
		}
	}

	string result(n, 'O');
	for (int i = 0; i < n; i++)
		if (isDeleted[i]) result[i] = 'X';

	return result;
}


int main()
{
	int n, k;
	vector<string> cmd;

	n = 6;
	k = 3;
	//cmd = { "D 2", "C", "U 3", "C", "D 4" , "C", "U 2", "Z", "Z" };
	//cmd = { "D 2", "C", "U 3", "C", "D 4" , "C", "U 2", "Z", "Z", "U 1", "C" };
	cmd = { "U 2", "C", "D 3", "C", "Z", "U 1", "C" };

	string answer = solution(n, k, cmd);
	cout << answer;

}
