#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right)
{
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main()
{
	int input1, input2;		//�Է��ϴ� ����
	int realnum;		//1�� ���� ����
	int count = 1;		//���� ���� ���� ���� ����(����Ŭ ����)
	int a[100000];
	char continueChar = 'y';

	while (continueChar == 'y')
	{
		cin >> input1 >> input2;

		for (int i = input1; i < input2 + 1; i++)
		{
			realnum = i;
			count = 1;

			while (realnum != 1)
			{
				if (realnum % 2 == 0)
				{
					realnum = realnum / 2;
				}

				else
				{
					realnum = realnum * 3 + 1;
				}

				count++;
			}

			a[i] = count;

			//cout << a[i] << endl;
		}

		quickSort(a, input1, input2);

		cout << input1 << " " << input2 << " " << a[input2] << endl;

		cout << "��� �Ͻðڽ��ϱ�?  y or n" << endl;
		cin >> continueChar;
	}

	return 0;
}