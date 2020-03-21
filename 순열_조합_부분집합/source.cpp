#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;


int numbers[6] = { 1,2,3,4,5,6 };
int result[6] = { 0, };
vector <int> result_v;
int check[6] = { 0, };
int flag[6] = { 0, };;

//��� ���� ..  �̿� n=��ü ��, r=���� ��, idx�� ����
void permu(int n, int r, int idx) {

	if (idx == r) {
		for (int i = 0; i < r; ++i) printf("%d ", result[i]);
		printf("\n");
		return;

	}

	for (int i = 0; i < n; ++i) {

		if (!check[i]) {
			check[i] = 1;
			result[idx] = numbers[i];
			permu(n, r, idx + 1);
			check[i] = 0;
		}

	}
}

//��� ����1 .. 
void combi1(int n, int r, int s, int idx) {

	if (idx == r) {
		for (int i = 0; i < r; ++i) printf("%d ", result[i]);
		printf("\n");
	}

	for (int i = s; i < n; ++i) {
		result[idx] = numbers[i];
		combi1(n, r, i + 1, idx + 1);
	}
}

//��� ����2..
void combi2(int n, int r, int s, int idx) {

	if (idx == r) {
		for (int i = 0; i < r; ++i) { printf("%d ", result[i]); }
		printf("\n");
		return;
	}

	if (s >= n) { return; }  //�ڡڡ�

	result[idx] = numbers[s];
	combi2(n, r, s + 1, idx + 1);
	//result[idx] = numbers[s];
	combi2(n, r, s + 1, idx);

}


//��� n=��ü ��, r=���� ��, idx�� ����
void Re_permu(int n, int r, int idx) {

	if (idx == r) {
		for (int i = 0; i < r; ++i) printf("%d ", result[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; ++i) {

		result[idx] = numbers[i];
		Re_permu(n, r, idx + 1);

	}
}

//���
void Re_combi1(int n, int r, int s, int idx) {

	if (idx == r) {
		for (int i = 0; i < r; ++i) { printf("%d ", result[i]); }
		printf("\n");
		return;
	}

	if (s >= n) { return; }

	result[idx] = numbers[s];
	Re_combi1(n, r, s, idx + 1);
	result[idx] = numbers[s + 1];
	Re_combi1(n, r, s + 1, idx);

}

void Re_combi2(int n, int r, int s, int idx) {
	if (idx == r) {
		for (int i = 0; i < r; i++) {
			cout << result[i] << ' ';
		}
		cout << endl;
		return;
	}
	if (s >= n) return;

	for (int i = s; i < n; i++)
	{
		result[idx] = numbers[i];
		Re_combi2(n, r, i, idx + 1);
	}
}


//���
void Power_set1(int n, int depth) {

	if (depth == n) {

		for (int i = 0; i < n; ++i) if (flag[i]) printf("%d ", numbers[i]);

		printf("\n");

		return;

	}

	flag[depth] = 1;

	Power_set1(n, depth + 1);

	flag[depth] = 0;

	Power_set1(n, depth + 1);


}

//���̳ʸ� ī����
void Power_set2(int n) {
	for (int i = 0; i < (1 << (n)); ++i) {
		for (int j = 0; j<n; ++j) {
			if (i & (1 << j))	printf("%d ", numbers[j]);
		}
		printf("\n");
	}
}

int main() {




	int num, x;

	cout << "0: ����, 1:����, 2:�ߺ�����, 3:�ߺ�����, 4:������" << endl;
	cout << "���ϴ� ����� �����ϼ���. (0~5)" << endl;
	cin >> num;

	if (num != 4) {
		cout << "1~6������ ���� �� �̰� ���� ������ ������ �����ϼ��� : " << endl;
		cin >> x;
	}

	switch (num) {
	case 0: {
		// 1. ���� _ 4�� �̱� nPr => 6P4 = 6! / (6-2)! = 6*5
		cout << "����" << '\n';
		permu(6, x, 0);
		cout << '\n';
		break;
	}

	case 1:
		// 2. ����
		cout << "����1" << '\n';
		combi1(6, x, 0, 0);
		cout << '\n';

		cout << "����2" << '\n';
		combi2(6, x, 0, 0);
		cout << '\n';
		break;
	case 2:
		// 3. �ߺ� ����
		cout << "�ߺ� ����" << '\n';
		Re_permu(6, x, 0);
		cout << '\n';
		break;
	case 3:
		// 4. �ߺ� ����
		cout << "�ߺ� ����1" << '\n';
		Re_combi1(6, x, 0, 0);
		cout << '\n';

		cout << "�ߺ� ����2" << '\n';
		Re_combi2(6, x, 0, 0);
		cout << '\n';
		break;
	case 4:
		// 5. Power set
		cout << "������1" << '\n';
		Power_set1(6, 0);
		cout << '\n';

		cout << "������2" << '\n';
		Power_set2(6);
		cout << '\n';
		break;

	}

	return 0;
}