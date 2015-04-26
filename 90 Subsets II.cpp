/*
90 Subsets II
Given a collection of integers that might contain duplicates, S, return all possible subsets.
Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
//Solution 1 非递归
class Solution {
public:
    void addEle(vector<vector<int> > &res,vector<int> &S,int index,int dulcun){//参数如果不加&作为引用参数，容器内的数据不会发生改变 
    	int n=res.size();
    	if(n==1){//第一个元素，直接放进去 
    		vector<int> temp(res[0]);
    		temp.push_back(S[index]);
    		res.push_back(temp);
    		return ;
    	} 
    	for(int i=0;i<n;i++){
    		vector<int> temp(res[i]);//判断temp是否有S[index]这个元素，如果有就添加
    		if(dulcun>0){//和前dulcun个元素相同，此时需要考虑重复的情况 
    			int last = temp.size();
    			if(last>=dulcun){
    				if(temp[last-dulcun]==S[index]){//因为是有序的，所以如果倒数第dulcun元素相同时，才可以插入
    					temp.push_back(S[index]);
    					res.push_back(temp);
    					continue;
    				}
    			}
    			
    			continue;
    		}
    		temp.push_back(S[index]);
    		res.push_back(temp);
    	}
    }
    
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(),S.end());
        vector<vector<int> > res;
        vector<int> temp;
        res.push_back(temp);
        int dulcun=0;//该字符前面有的重复数量 
        for(int i=0;i<S.size();i++){
        	if(i>0){
        		if(S[i] == S[i-1]){
        			dulcun++;
    			}else{
    				dulcun = 0;
    			}
    		}
        	addEle(res,S,i,dulcun);
    	}
    	return res;
    }
};

//递归
class Solution {
public:
    vector<vector<int> > res;
    void subsetsCore(vector<int> &S, int start, vector<int> &v){
        if(start == S.size()) { res.push_back(v); return;}
        if(v.size() == 0 || v[v.size()-1] != S[start]){    //v中最后一个元素和第start个元素不同，说明这个分支上一次没有新添元素，不能在添加
            vector<int> v2(v);
            subsetsCore(S, start+1, v2);//不加第start个元素 
        }
        v.push_back(S[start]);
        subsetsCore(S, start+1, v);//加第start个元素 
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> v;
    	sort(S.begin(), S.end());
        subsetsCore(S, 0, v);
        return res;
    }
};