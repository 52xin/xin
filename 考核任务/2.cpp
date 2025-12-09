//#include<iostream>
//using namespace std;
//
//class Rectangle
//{
//public:
//	double length, width;
//	Rectangle(double l = 0, double w = 0)
//	{
//		length = l;
//		width = w;
//	};
//	double area() const 
//	{ 
//		return length * width;
//	};
//	void display() const
//	{
//		cout << "length" << length << endl;
//		cout << "width" << width << endl;
//		cout << "area" << length * width << endl;
//		cout << "-------------------------------------------" << endl;
//	};
//	bool operator>(const Rectangle& other )
//const{
//		return this->area() > other.area();
//	 }
//};
//int main() 
//{   
//	Rectangle rect1(3.3, 6.5);
//	Rectangle rect2(4.0, 2);   
//	Rectangle rect3(3, 3);  
//	// 使用重载后的 > 运算符比较面积
//	if (rect2 > rect1) 
//	{
//		//rect1.display();
//		//rect2.display();
//		cout << "rect2的面积更大" << endl;
//	}
//	else 
//	{
//		cout << "rect1的面积更大" << endl;
//	}
//	if (rect3 > rect2)
//	{
//		//rect3.display();
//		//rect2.display();
//		cout << "rect3的面积更大" << endl;
//	}
//	else
//	{
//		cout << "rect2的面积更大" << endl;
//	}
//	return 0;
//}

