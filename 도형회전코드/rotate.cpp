#include <bits/stdc++.h>
using namespace std;

int paper[12][12];
int r,c;

void rotate(){
  int tmp[12][12];

  	for(int i = 0; i < r; i++)
    	for(int j = 0; j < c; j++)
      		tmp[i][j] = paper[i][j];

  	for(int i = 0; i < c; i++)           //r,c 순서 반대
    	for(int j = 0; j < r; j++)
      		paper[i][j] = tmp[r-1-j][i];  //i,j 순서 반대

  	swap(r, c);
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
