#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

int main(){
	int T;
	cin>>T;

	for(int i=0; i<T; i++)
	{
		int h,w;
		cin>>h>>w;

		string line;
		vector<vector<char>> map; 
		queue<pair<int,int>> start_point;
		list<pair<char,pair<int,int>>> doors;
		bool has_key[26] = {false};
		vector<vector<int>> visited(h,vector<int>(w,0));

		int result = 0;

		for(int j=0; j<h; j++) //처음 입력 및 테두리 검사사
		{
			cin>>line;
			map.push_back(vector<char>(line.begin(), line.end()));

			if(j == 0 || j == h-1)
			{
				for(int k=0; k<w; k++)
				{
					if(line[k] == '*')
					{
						continue;
					}
					else if(line[k] == '.')
					{
						start_point.push({j,k});
						visited[j][k] = 1;
					}
					else if(line[k] == '$')
					{
						start_point.push({j,k});
						visited[j][k] = 1;
						result++;
					}
					else if(isupper(line[k]))
					{
						doors.push_back(make_pair(line[k],make_pair(j,k)));
					}
					else if(islower(line[k]))
					{
						has_key[line[k] - 'a'] = true;
						start_point.push({j,k});
						visited[j][k] = 1;
					}
					
				}
			}
			else
			{

				if(line[0] == '.')
				{
					start_point.push({j,0});
					visited[j][0] = 1;
				}
				if(line[w-1] == '.')
				{
					start_point.push({j,w-1});
					visited[j][w-1] = 1;
				}
				if(line[0] == '$')
				{
					start_point.push({j,0});
					visited[j][0] = 1;
					result++;
				}
				if(line[w-1] == '$')
				{
					start_point.push({j,w-1});
					visited[j][w-1] = 1;
					result++;
				}
				if(isupper(line[0]))
				{
					doors.push_back(make_pair(line[0],make_pair(j,0)));
				}
				if(isupper(line[w-1]))
				{
					doors.push_back(make_pair(line[w-1],make_pair(j,w-1)));
				}
				if(islower(line[0]))
				{
					if (!has_key[line[0] - 'a']) {
						has_key[line[0] - 'a'] = true;
					}
					start_point.push({j,0});
					visited[j][0] = 1;
				}
				if(islower(line[w-1]))
				{
					if (!has_key[line[w-1] - 'a']) {
						has_key[line[w-1] - 'a'] = true;
					}
					start_point.push({j,w-1});
					visited[j][w-1] = 1;
				}

			}
		}

		cin>>line;

		if(line != "0")
		{
			for(const auto& key : line){
				has_key[key - 'a'] = true;
			}
		}

		// for(int j=0; j<26; j++)
		// {
		// 	cout<<has_key[j]<<" "<<endl;
		// }

		for(int j=0; j<26; j++)
		{
			if(!has_key[j]){continue;}
			//cout<<"has_key[j]: "<<j<<endl;
			for (auto it = doors.begin(); it != doors.end(); )
			{
				if (it->first == j+'A')
				{
					map[it->second.first][it->second.second] = '.';
					visited[it->second.first][it->second.second] = 1;
					start_point.push({ it->second.first, it->second.second });
					it = doors.erase(it); // 열린 문은 제거
				}
				else
				{
					++it;
				}
			}
		}

		int dx[4] = {-1, 1, 0, 0};
		int dy[4] = {0, 0 ,-1, 1};

		bool new_key_obtained = true;

		while (new_key_obtained) {

    		new_key_obtained = false;

			while(!start_point.empty())
			{
				// cout<<start_point.size()<<endl;
				// cout<<start_point.front().first<<", "<<start_point.front().second<<endl;

				pair<int,int> xy = start_point.front();
				start_point.pop();
				int xx = xy.first;
				int yy = xy.second;
				visited[xx][yy] = 1;

				for(int j=0; j<4; j++)
				{
					int next_xx = xx + dx[j];
					int next_yy = yy + dy[j];

					if(!(next_xx >=0 && next_xx < h && next_yy >=0 && next_yy < w)){continue;}

					if(visited[next_xx][next_yy] || map[next_xx][next_yy] == '*'){continue;}

					char next_char = map[next_xx][next_yy];

					if(next_char == '.')
					{
						start_point.push({next_xx,next_yy});
						visited[next_xx][next_yy] = 1;
					}
					else if(next_char == '$')
					{
						result++;
						map[next_xx][next_yy] = '.';
						start_point.push({next_xx,next_yy});
						visited[next_xx][next_yy] = 1;
					}
					else if(isupper(next_char)) // 문이면
					{
						if (has_key[tolower(next_char) - 'a']) {
							map[next_xx][next_yy] = '.';
							start_point.push({next_xx, next_yy});
							visited[next_xx][next_yy] = 1;
						}
						else {
							doors.push_back(make_pair(next_char,make_pair(next_xx,next_yy)));
						}
					}
					else //열쇠면
					{
						if (!has_key[next_char - 'a']) {
							has_key[next_char - 'a'] = true;
							new_key_obtained = true;
						}
						map[next_xx][next_yy] = '.';
						start_point.push({next_xx,next_yy});
						visited[next_xx][next_yy] = 1;
					}
				}
			}

			// for(const auto& line : visited)
			// {
			// 	for(const auto& v : line)
			// 	{
			// 		cout<<v;
			// 	}
			// 	cout<<endl;
			// }
			if (new_key_obtained) {
				for (auto it = doors.begin(); it != doors.end(); ) {
					if (has_key[tolower(it->first) - 'a']) {
						int x = it->second.first;
						int y = it->second.second;
						map[x][y] = '.';

						if (!visited[x][y]) {
							start_point.push({x, y});
							visited[x][y] = 1;
						}
						it = doors.erase(it);
					} else {
						++it;
					}
				}
			}
		}

		// for(const auto& line : visited)
		// {
		// 	for(const auto& v : line)
		// 	{
		// 		cout<<v;
		// 	}
		// 	cout<<endl;
		// }


		cout<<result<<endl;

	}

	return 0;
}
