#include <iostream>
#include <vector>
using namespace std;
#define lenght_mas 25

template <typename T>
void print_mas(T mas)
{
	cout << mas[0];
	for (int i = 1; i < lenght_mas; i++)
		cout << ' ' << mas[i];
	cout << '\n';
}

void natural_merge(vector<int>& vect1, vector<int>& vect2)
{
	for (int i = 0; i < vect2.size(); i++)
	{
		vect1.push_back(vect2[i]);
		for (int j = vect1.size() - 1; j > 0; j--)
		{
			if (vect1[j] < vect1[j - 1])
			{
				swap(vect1[j], vect1[j - 1]);
			}
			else
			{
				break;
			}
		}
	}
}
void natural_merge_sort(int* mas)
{
	vector <vector<int>> series;
	vector<int> new_series;
	for (int i = 0; i <= lenght_mas - 1; i++)
	{
		if (i == lenght_mas - 1)
		{
			new_series.push_back(mas[i]);
			series.push_back(new_series);
			new_series.clear();
		}
		else
		{
			new_series.push_back(mas[i]);
			if (mas[i] > mas[i + 1])
			{
				series.push_back(new_series);
				new_series.clear();
			}
		}
	}
	while (series.size() != 1)
	{
		natural_merge(series[0], series[series.size() - 1]);
		series.pop_back();
	}
	for (int i = 0; i < lenght_mas; i++)
	{
		mas[i] = series[0][i];
	}
}

int main()
{
	srand(time(0));
	int mas_natural_merge[25] = {};
	for (int i = 0; i < lenght_mas; i++) {
		mas_natural_merge[i] = rand() % 100 - 50;
	}
	print_mas(mas_natural_merge);
	natural_merge_sort(mas_natural_merge);
	print_mas(mas_natural_merge);
}

