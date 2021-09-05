#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

ifstream input_fp("cross.inp");   
ofstream output_fp("cross.out");

int N;
vector<int> line;
vector<int> opt;

void input_data(){
	input_fp >> N;
	int temp;
	for(int i=0; i<N; i++){
		input_fp >> temp;
		line.push_back(temp);
	}
	for(int i=0; i<N; i++){
		input_fp >> temp;
		for(int j=0; j<N; j++){
			if(line[j] == temp){
				opt.push_back(j);
			}
		}
	}
}
int calc_data(){
	int cnt = 0;
	for(int i=0; i<N; i++){
		for(int x=0; x<i; x++){
			if(opt[x] > opt[i]){
				cnt++;
			}
		}
		for(int y=N-1; y>i; y--){
			if(opt[y] < opt[i]){
				cnt++;
			}
		}
	}
	return cnt/2;
}

int main(){
	int T;
	input_fp >> T;
	for(int i=0; i<T; i++){
		input_data();
		output_fp << "Case " << i+1 << ": " << calc_data() << endl;
		line.clear();
		opt.clear();
	}
	return 0;
}

/*


�����ʿ� �ڱ⺸�� ���� ������ ���� + ���ʿ� �ڱ⺸�� ū ������ ���� = ��������
 
3 4 1 2
�� �� �������� ���� 8, �ߺ��� ������ /2 �ؼ� 4.

5 1 3 6 2 4
4 6 2 3 1 5

6 5 4 2 3 1 
5 5 5 4 4 5 ... 28 / 2 = 14

*/
