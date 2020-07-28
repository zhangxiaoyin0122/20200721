#include <iostream>
using namespace std;

//���ò������
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot) {
//		if (pRoot == nullptr)
//			return 0;
//		//����һ������
//		queue<TreeNode*> q;
//		q.push(pRoot);
//		//ѭ������:�����в�Ϊ��
//		int depth = 0;
//		while (!q.empty()) {
//			depth++;
//			int size = q.size();
//			for (int i = 0; i < size; i++) {
//				TreeNode* root = q.front();
//				q.pop();
//				if (root->left)
//					q.push(root->left);
//				if (root->right)
//					q.push(root->right);
//			}
//		}
//		return depth;
//	}
//};
//
//class Solution {
//public:
//	vector<vector<int> > FindContinuousSequence(int sum) {
//		vector<vector<int>> result;
//		int low = 1;
//		int high = 2;
//		while (low < high) {
//			int temp = (low + high)*(high - low + 1) / 2;
//			if (temp == sum) {
//				vector<int> v;
//				for (int i = low; i <= high; i++) {
//					v.push_back(i);
//				}
//				result.push_back(v);
//				low++;
//			}
//			else if (temp < sum) {
//				high++;
//			}
//			else {
//				low++;
//			}
//		}
//		return result;
//	}
//};

int main() {
	int length = sizeof(int);
	cout << length << endl;

	return 0;
}

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2) {
		if (num1 == nullptr || num2 == nullptr)
			return;
		//���������
		int result = data[0];
		for (int i = 1; i < data.size(); i++) {
			result ^= data[i];
		}
		//�����Ľ���϶���Ϊ0,����λΪ1��λ��˵���������ֶ�Ӧ����λ��ͬ,�ɴ˷�Ϊ����
		int flag = 1;
		int length = sizeof(int);
		//�ҵ���һ��Ϊ1�ı���λ
		for (int i = 0; i < length; i++) {
			if ((flag << i)&result) {
				flag <<= i;
				break;
			}
		}
		//����
		*num1 = 0;
		*num2 = 0;
		for (int i = 0; i < data.size(); i++) {
			//��Ӧ����λ�Ƿ�Ϊ1��Ϊ����
			if (flag & data[i])
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}
};