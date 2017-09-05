#include <iostream>

using namespace std;

class person
{
private:
    int age;
    string name;
    int salary;

public:
    void setname(string newname);
    void setsalary(int money);
    void display();
};

void person::setname(string newname)
{
    name=newname;
}

void person::setsalary(int money)
{
    salary=money;
}

void person::display()
{
    cout<<"name: "<<name<<endl;
    cout<<"salary: "<<salary<<endl;
}

// 基类
class Shape
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// 派生类
class Rectangle: public Shape
{
   public:
      int getArea()
      {
         return (width * height);
      }
};

class printData
{
   public:
      void print(int i) {
        cout << "Printing int: " << i << endl;
      }

      void print(double  f) {
        cout << "Printing float: " << f << endl;
      }

      void print(char* c) {
        cout << "Printing character: " << c << endl;
      }
};

int main()
{
    person A;
    string name;
    int salary;
    cout<<"please input the name:";
    cin>>name;
    cout<<endl;
    cout<<"please input the salary:";
    cin>>salary;
    cout<<endl;
    A.setname(name);
    A.setsalary(salary);
    A.display();


    Rectangle Rect;
    Rect.setWidth(5);
    Rect.setHeight(7);
    // 输出对象的面积
    cout << "Total area: " << Rect.getArea() << endl;


    printData pd;
    // Call print to print integer
    pd.print(5);
    // Call print to print float
    pd.print(500.263);
    // Call print to print character
    pd.print("Hello C++");

    //cout << "Hello world!" << endl;
    return 0;
}
