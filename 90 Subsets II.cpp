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
//Solution 1 �ǵݹ�
class Solution {
public:
    void addEle(vector<vector<int> > &res,vector<int> &S,int index,int dulcun){//�����������&��Ϊ���ò����������ڵ����ݲ��ᷢ���ı� 
    	int n=res.size();
    	if(n==1){//��һ��Ԫ�أ�ֱ�ӷŽ�ȥ 
    		vector<int> temp(res[0]);
    		temp.push_back(S[index]);
    		res.push_back(temp);
    		return ;
    	} 
    	for(int i=0;i<n;i++){
    		vector<int> temp(res[i]);//�ж�temp�Ƿ���S[index]���Ԫ�أ�����о����
    		if(dulcun>0){//��ǰdulcun��Ԫ����ͬ����ʱ��Ҫ�����ظ������ 
    			int last = temp.size();
    			if(last>=dulcun){
    				if(temp[last-dulcun]==S[index]){//��Ϊ������ģ��������������dulcunԪ����ͬʱ���ſ��Բ���
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
        int dulcun=0;//���ַ�ǰ���е��ظ����� 
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

//�ݹ�
class Solution {
public:
    vector<vector<int> > res;
    void subsetsCore(vector<int> &S, int start, vector<int> &v){
        if(start == S.size()) { res.push_back(v); return;}
        if(v.size() == 0 || v[v.size()-1] != S[start]){    //v�����һ��Ԫ�غ͵�start��Ԫ�ز�ͬ��˵�������֧��һ��û������Ԫ�أ����������
            vector<int> v2(v);
            subsetsCore(S, start+1, v2);//���ӵ�start��Ԫ�� 
        }
        v.push_back(S[start]);
        subsetsCore(S, start+1, v);//�ӵ�start��Ԫ�� 
    }
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<int> v;
    	sort(S.begin(), S.end());
        subsetsCore(S, 0, v);
        return res;
    }
};