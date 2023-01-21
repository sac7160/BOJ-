#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	
	cin >> n;

	int nums[50];
	int cnt_nums[1001];
	int tmp[1001];
	vector<int>ans;

	for(int i=0; i<1001; i++) 
	{
		cnt_nums[i] = 0;
		tmp[i] = 0;
	}

	for(int i=0; i<n; i++) 
	{
		cin >> nums[i];
		cnt_nums[nums[i]]++;
		tmp[nums[i]]++;
	}

	sort(nums,nums+n);//오름차순 정렬

	int i = 0;

	for(int cnt=0; cnt<n; )///////////////////i는 정렬된수 검사하는 index
	{
		if(cnt_nums[nums[i]] != 0)
		{
			if(cnt_nums[nums[i]+1]==0)
			{
				for(int x=0; x<cnt_nums[nums[i]]; x++) ans.push_back(nums[i]);
				cnt += cnt_nums[nums[i]];
				cnt_nums[nums[i]]=0; //추가
			}
			else if(cnt_nums[nums[i]+1] != 0)
			{
				//2이상 더 큰게 있으면 그냥 그거 하나 추력하고 다음으로
				//없으면 1큰거 전부 출력한 이후 해당 출력
				int index = nums[i]+2;
				while((index<1000)&&(cnt_nums[index]==0))index++;

				if(cnt_nums[index]!=0)
				{
					for(int x=0; x<cnt_nums[nums[i]]; x++) ans.push_back(nums[i]);
					cnt += cnt_nums[nums[i]];
					cnt_nums[nums[i]]=0; //추가
					ans.push_back(index);
					cnt++;
					cnt_nums[index]--;
				}
				else if(cnt_nums[index] == 0 )
				{
					for(int x=0; x<cnt_nums[nums[i]+1]; x++)ans.push_back(nums[i]+1);
					for(int x=0; x<cnt_nums[nums[i]]; x++) ans.push_back(nums[i]);
					cnt = n;
				}
			}
			i += tmp[nums[i]];
		}
		else i++;
		
	}

	for(int z=0; z<n; z++) cout << ans[z] << " ";


}