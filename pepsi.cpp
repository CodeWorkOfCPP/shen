			#include<iostream>
			#include<string>
			using namespace std;
			/***************饮料类的基本实现******************/
			/****
				
				 Author：shen
				 Date：2019/01/19/22:13
					*/
			class beverage {
			private:
				int choice;
				double price_1;  //pepsi价格
				double price_2;
				double protein;//蛋白质含量
				double energy;//能量含量
				double  fat;//脂肪含量
				double sugar;//碳水化合物含量
				double saturated_fatty_acids;//饱和脂肪酸含量
				
			protected:
				int stars = 0;
				string Name_beverage_1 = "Pepsi";
				string Name_beverage_2 = "七喜- 7 up";

			public:

				beverage() {
					price_1 = 7.0; price_2 = 6.9; protein = 0.0; energy = 0.0; //构造函数 初始化各项数据
					fat = 0.0;	  sugar = 0.0; 
					saturated_fatty_acids = 0.0;
					cout << "欢迎使用饮料服务 请输入 1或 2来选择您所需要的饮料";
					cin >> choice;
				}

				void show_bever_Name();//显示饮料的名字
				void show_price();//显示饮料价格
				void show_basic_ingredient();//显示基本的成分
				double total_price(int num1,int num2);//求解饮料的总消费
				void server(int stars);

				~beverage() { std::cout << "欢迎光临饮料服务，请对本次服务进行点评。";
								std::cin >> stars;
								server(stars);
				};//析构函数
			};
			void  beverage::show_bever_Name() {
				if (choice == 1)
					cout << "你选择了" << Name_beverage_1<<"\n";
				else
					cout << "你选择了" << Name_beverage_2<<"\n";
			}
			void beverage::show_price() {
				if (choice == 1)cout << "Pepsi 的价格是 " << price_1<<"\n";
				else
					cout << "7 UP 的价格是" << price_2<<"\n";
			}
			void beverage::show_basic_ingredient() {
				if (choice == 1) {
					energy = 190;
					sugar = 11.2;
					cout << "Pepsi 营养成分表如下:\n";
				}
				else {
					cout << "7 up 营养成分表如下:\n";
					energy = 131;
					sugar = 7.7;
				}
				cout << "每100毫升\n";
				cout << "能量" << energy << "千焦\n";
				cout << "蛋白质" << protein << "克\n";
				cout<<"脂肪"<<fat<<"克\n";
				cout<<"碳水化合物"<<sugar<<"克\n";
				cout<<"饱和脂肪酸"<<saturated_fatty_acids<<"克\n";

			}
			double beverage:: total_price( int num1, int num2) {
				return price_1 * num1 + price_2 * num2;
			}
			void beverage:: server(int stars) {
				if (stars < 3)
					cout << "非常抱歉让您失望了\n";
				else
					cout << "谢谢您的支持\n";
			}
			int main() {

				beverage* b1 = new beverage();
				b1->show_bever_Name();
				b1->show_price();
				b1->show_basic_ingredient();
				system("pause");
			}