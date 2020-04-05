#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout<< arr[i][j];
		}
		cout << endl;
	}*/
int N, M;
int ** arr;
int total_dist;
int final_total_dist;
vector <pair<int, int>> house_pos;
vector <pair<int, int>> chicken_pos;
vector <int> temp_vector;
vector <vector <int>> select_chicken_list;

void DPS_search_for_Combination(int k);
void allocate();
void getposition();
void find_chicken_distance();
void select_M_chicken();

int main() {

	allocate();
	getposition();
	select_M_chicken();
	find_chicken_distance();
	return 0;
}

void allocate() {

	cin >> N >> M;
	arr = new int*[N];
	for (int i = 0; i < N; i++) {
		arr[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
}
void getposition() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				house_pos.push_back(make_pair(i, j));

			}
			else if (arr[i][j] == 2) {
				chicken_pos.push_back(make_pair(i, j));
			}
		}
	}
}


void select_M_chicken() {
	temp_vector.clear();
	DPS_search_for_Combination(0);
	/*for (int i = 0; i < select_chicken_list.size(); i++) {
		for (int k = 0; k < select_chicken_list[i].size(); k++) {
			cout << select_chicken_list[i][k];
		}
		cout << "\n";
	}*/
}
void DPS_search_for_Combination(int idx) {
	if (temp_vector.size() == M ) {
		select_chicken_list.push_back(temp_vector);
	}
	else {
		for (int i = idx; i < chicken_pos.size(); i++)
		{
			if (temp_vector.size() == 0) {
				temp_vector.push_back(i);
				DPS_search_for_Combination(i);
				temp_vector.pop_back();
			}
			else if (temp_vector.back() == i) continue;
			else {
				temp_vector.push_back(i);
				DPS_search_for_Combination(i);
				temp_vector.pop_back();
			}
		}
	}
}
void find_chicken_distance() {
	final_total_dist = 1000000;
	for (int i = 0; i < select_chicken_list.size(); i++) {
		total_dist = 0;
		for (int j = 0; j < house_pos.size(); j++) {
			int min = 1000000;
			int house_row = house_pos.at(j).first;
			int house_col = house_pos.at(j).second;

			for (int k = 0; k < select_chicken_list[i].size(); k++) {
				int idx = select_chicken_list[i][k];
				int chicken_row = chicken_pos.at(idx).first;
				int chicken_col = chicken_pos.at(idx).second;
				int  dist = abs(house_row - chicken_row) + abs(house_col - chicken_col);
				min = min > dist ? dist : min;
			}
			total_dist += min;
		}
		final_total_dist = final_total_dist > total_dist ? total_dist : final_total_dist;
	}
	cout << final_total_dist;
}