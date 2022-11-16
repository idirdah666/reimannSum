#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double yvalue(double x){
    return sqrt(pow(x,2)+3);
}

double centerReimannSum(double a, double b, int n){
    double sum = 0;
    double h = (b - a) / n;
    for (int i = 0; i < n; i++){
        sum += yvalue(a + (i + 0.5) * h);
    }
    return sum * h;
}

double rightReimannSum(double a, double b, int n)
{
    double sum = 0;
    double width = (b - a) / n;
    for (int i = 1; i <= n; i++)
    {
        sum += yvalue(a + (i * width));
    }
    return sum * width;
}



double sineRightReimannSum(int n)
{
    double a = 0;
    double b = (3 * M_PI)/2;
    double sum = 0;
    double width = (b - a) / n;
    for (int i = 1; i <= n; i++)
    {
        sum += 2.0*sin(a + (i * width));
    }
    return sum * width;
}

double sineMidReimannSum(int n)
{
    double a = 0;
    double b = (3 * M_PI)/2;
    double sum = 0;
    double width = (b - a) / n;
    for (int i = 0; i < n; i++)
    {
        sum += 2.0*sin(a + (i + 0.5) * width);
    }
    return sum * width;
}

double leftReimannSum(double a, double b, int n)
{
    double sum = 0;
    double width = (b - a) / n;
    for (int i = 0; i < n; i++)
    {
        sum += yvalue(a + (i * width));
    }
    return sum * width;
}

int main(){
    cout << "Do you want a left, right, center, or sine reimann sum?" << endl;
    string answer;
    cin >> answer;
    if(answer == "left"){
        cout << "What is the lower bound?" << endl;
        double a;
        cin >> a;
        cout << "What is the upper bound?" << endl;
        double b;
        cin >> b;
        cout << "How many rectangles do you want?" << endl;
        int n;
        cin >> n;
        cout << "The left reimann sum is " << leftReimannSum(a, b, n) << endl;
    }
    else if(answer == "right"){
        cout << "What is the lower bound?" << endl;
        double a;
        cin >> a;
        cout << "What is the upper bound?" << endl;
        double b;
        cin >> b;
        cout << "How many rectangles do you want?" << endl;
        int n;
        cin >> n;
        cout << "The right reimann sum is " << rightReimannSum(a, b, n) << endl;
    }
    else if(answer == "center"){
        cout << "What is the lower bound?" << endl;
        double a;
        cin >> a;
        cout << "What is the upper bound?" << endl;
        double b;
        cin >> b;
        cout << "How many rectangles do you want?" << endl;
        int n;
        cin >> n;
        cout << "The center reimann sum is " << centerReimannSum(a, b, n) << endl;
    }
    else if(answer == "sine"){
        cout << "How many rectangles do you want?" << endl;
        int n;
        cin >> n;
        cout << setprecision(7) << "The right sine reimann sum is " << sineRightReimannSum(n) << endl;
        cout << setprecision(7) << "The center sine reimann sum is " << sineMidReimannSum(n) << endl;
    }
    else{
        cout << "That is not a valid answer." << endl;
    }
    return 0;
}