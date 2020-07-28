#include <iostream>
using namespace std;

//利用层序遍历
//class Solution {
//public:
//	int TreeDepth(TreeNode* pRoot) {
//		if (pRoot == nullptr)
//			return 0;
//		//创建一个队列
//		queue<TreeNode*> q;
//		q.push(pRoot);
//		//循环条件:当队列不为空
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
		//先整体异或
		int result = data[0];
		for (int i = 1; i < data.size(); i++) {
			result ^= data[i];
		}
		//异或出的结果肯定不为0,比特位为1的位置说明两个数字对应比特位不同,由此分为两组
		int flag = 1;
		int length = sizeof(int);
		//找到第一个为1的比特位
		for (int i = 0; i < length; i++) {
			if ((flag << i)&result) {
				flag <<= i;
				break;
			}
		}
		//分组
		*num1 = 0;
		*num2 = 0;
		for (int i = 0; i < data.size(); i++) {
			//对应比特位是否为1分为两组
			if (flag & data[i])
				*num1 ^= data[i];
			else
				*num2 ^= data[i];
		}
	}
};