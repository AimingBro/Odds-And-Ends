#include <bits/stdc++.h>

using namespace std;

int paper[12][12];
int r,c;

//90도 우측 회전 : 전치행렬 후 좌우 반전
//90도 좌측 회전 : 전치행렬 후 상하 반전
void rotate()
{
	int transposed [15][15];
	int tmp;

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			transposed [j][i] = paper[i][j];

	swap(r,c);

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			paper[i][j] = transposed[i][c - 1 - j];
}

void print_paper()
{
	for(int i = 0; i < r; i++)
	{
		for(int j = 0; j < c; j++)
		{
			cout << paper[i][j] << ' ';
		}
		cout << "\n";
	}

}

int main(void) {
 	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> r >> c;
    for(int i = 0; i < r; i++)
      for(int j = 0; j < c; j++)
        cin >> paper[i][j];
	print_paper();
    rotate(); // 90도
	print_paper();
    rotate(); // 180도
	print_paper();
    rotate(); // 270도
	print_paper();
	return (0);
}
