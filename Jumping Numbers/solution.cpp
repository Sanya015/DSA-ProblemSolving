#include <bits/stdc++.h> 
// DFS Based
// T.C.=O(N+NLogN) where K is no of jumping numbers
// S.C.=O(N+LogN) 
void solve(int n, vector<int>&ans, int num){
	if(num<=n){
		int dig=num%10;
		int num1, num2;
		if(dig>0){
			num1=(num*10)+(dig-1);
			if(num1<=n) ans.push_back(num1);
			solve(n, ans, num1);
		} 
		if(dig<9){
			num2=(num*10)+(dig+1);
			if(num2<=n) ans.push_back(num2);
			solve(n, ans, num2);
		} 
	}
}
vector<int> jumpingNumbers(int n)
{
	vector<int> ans;
	for(int i=0; i<10; i++){
		if(i<=n) ans.push_back(i);
	}
	for(int i=1; i<10; i++){
		solve(n, ans, i);
	}
	sort(ans.begin(), ans.end());
	return ans;
}



#include <bits/stdc++.h> 

// BFS
// T.C.=O(N+NLogN) S.C.=O(N)
void bfs(int n, vector<int>& ans, int node){
	queue<int> q;
	q.push(node);
	while(!q.empty()){
		int ele=q.front();
		q.pop();
		if(ele<=n){
			ans.push_back(ele);
			int digit=ele%10;
			if(digit>0){
				int num1=(ele*10)+(digit-1);
				q.push(num1);
			}
			if(digit<9){
				int num2=(ele*10)+(digit+1);
				q.push(num2);
			}
		}
	}

}

vector<int> jumpingNumbers(int n)
{
	vector<int> ans;
	ans.push_back(0);
	for(int i=1; i<10; i++){
		if(i<=n) bfs(n, ans, i);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
