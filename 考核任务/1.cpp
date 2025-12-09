//#include<iostream>
//#include<string>
//using namespace std;
//int countword(const string& sentence) //读取句子中单词的总数的函数
//{
//	int count = 0;
//	bool inword = 0;
//	for (char c : sentence) //存储句子，isalpha函数读取字母来确定单词个数
//	{
//		if (isalpha(c))
//		{
//			inword = 1;
//		}
//		else
//		{
//			if(inword)
//			{
//				count++;
//				inword = 0;
//			}
//			
//		}
//	}
//	if (inword == 1) //防止以单词结尾而少记一次
//	{
//		count++;
//		inword = 0;
//	}
//
//	return count;
//}
//int longestwordlength(const string& sentence) //寻找句子中最长单词的函数
//{
//	int length = 0;
//	//bool inword = 0;
//	int maxlength = 0;
//	for (char c : sentence)
//	{
//		if (isalpha(c))
//		{
//			length++;
//			if (length > maxlength)
//			{
//				maxlength = length;
//			}
//		}
//		else
//		{
//			length = 0;
//		}
//	}
//	return maxlength;
//}
//string longestword(const string sentence)//找到最长单词
//{
//	string word;
//	string longestword;
//	int maxlength = 0;
//	for (char c : sentence) {
//		if (isalpha(static_cast<unsigned char>(c))) word += c;
//		else {
//			if (word.size() > maxlength) {
//				maxlength = word.size();
//				longestword = word;
//			}
//			word.clear();
//		}
//	}
//	if (!word.empty() && word.size() > maxlength) longestword = word;
//	return longestword;//防止句子以字母结尾时，最后一个单词没判断
//}
//int main() 
//{
//	string sentence; 
//	cout << "请输入一段英文句子:" << endl;
//	getline(cin, sentence);//getline可读入包含空格的字符串
//	cout << "输入的句子为："<<sentence << endl;
//	cout << "句子的单词总数为:" << countword(sentence) << endl;
//	cout << "句子中最长单词长度:" << longestwordlength(sentence) << endl;
//	cout << "句子中最长单词:" << longestword(sentence) << endl;
//
//	system("pause");
//
//	return 0;
//}