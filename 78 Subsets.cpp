/*
78 Subsets 
Given a set of distinct integers, S, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
//Solution 1 非递归解法：集合中的元素，每增加一个都是在前一个的基础上，依次添加一个元素
class Solution {
public:
    void addEle(vector<vector<int> > &res,int added){//参数如果不加&作为引用参数，容器内的数据不会发生改变 
    	int n=res.size();
    	for(int i=0;i<n;i++){
    		vector<int> temp(res[i]);
    		temp.push_back(added);
    		res.push_back(temp);
    	}
    }

    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        vector<int> temp;
        res.push_back(temp);
        for(int i=0;i<S.size();i++){
        	addEle(res,S[i]);
    	}
        for(int i=0;i<res.size();i++){
        	for(int j=0;j<res[i].size();j++){
        		cout<<res[i][j]<<" ";
    		}
    		cout<<endl;
    	}
    	return res;
    }
};

//Solution 2 递归解法，每个元素都是要考虑两种情况，被添加和不被添加
class Solution {
public:
    vector<vector<int> > res;
    void dfs(int level,vector<int> v,vector<int> &S){
    	if(level == S.size()){
    		res.push_back(v);
    		return ;
    	}
    	vector<int> v1(v);		//包含第level个元素 
    	v1.push_back(S[level]); //不包含第level个元素 
    	dfs(level+1,v1,S);
    	dfs(level+1,v,S);
    }
    vector<vector<int> > subsets(vector<int> &S) {
    	sort(S.begin(),S.end());
    	vector<int> v1;
    	dfs(0,v1,S);
    	return res;
    }
};