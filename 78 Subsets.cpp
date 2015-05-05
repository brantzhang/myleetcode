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
//Solution 1 �ǵݹ�ⷨ�������е�Ԫ�أ�ÿ����һ��������ǰһ���Ļ����ϣ��������һ��Ԫ��
class Solution {
public:
    void addEle(vector<vector<int> > &res,int added){//�����������&��Ϊ���ò����������ڵ����ݲ��ᷢ���ı� 
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

//Solution 2 �ݹ�ⷨ��ÿ��Ԫ�ض���Ҫ�����������������ӺͲ������
class Solution {
public:
    vector<vector<int> > res;
    void dfs(int level,vector<int> v,vector<int> &S){
    	if(level == S.size()){
    		res.push_back(v);
    		return ;
    	}
    	vector<int> v1(v);		//������level��Ԫ�� 
    	v1.push_back(S[level]); //��������level��Ԫ�� 
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