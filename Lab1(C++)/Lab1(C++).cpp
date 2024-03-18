#include <iostream>
#include <math.h>
using namespace std;

double oneDotFourFunction(double x)
{
    return pow(25 * x, 5) - sqrt(pow(x, 2) + x);
}

void taskOne()
{
    cout << "Task 1:\n\n";

    int n, m;

    cout << "Enter n = ";
    cin >> n;
    cout << "Enter m = ";
    cin >> m;

    cout << "\n";
    cout << "----------------------------------------------------------\n\n";


    // Завд 1

    cout << "1.1 task: 'm-++n'\n";
    cout << "Function with actual agruments: '" << m << " - " << " ++" << n << "';\n\n";

    int o = m - ++n;

    cout << "m-++n = " << o << ";\n";
    cout << "Actual agruments after function: m = " << m << "; n = " << n << ";\n\n";

    cout << "----------------------------------------------------------\n\n";

    // Завд 2

    cout << "1.2 task: 'm++>--n'\n";
    cout << "Function with actual agruments: '" << m << "++ > " << "--" << n << "';\n\n";

    bool b = m++ > --n;

    cout << "m++>--n = ";
    if (b) {
        cout << "true;\n";
    }
    else {
        cout << "false;\n";
    }
    cout << "Actual agruments after function: m = " << m << "; n = " << n << ";\n\n";

    cout << "----------------------------------------------------------\n\n";

    // Завд 3

    cout << "1.3 task: 'm--<++n'\n";
    cout << "Function with actual agruments: '" << m << "-- < " << "++" << n << "';\n\n";

    b = m-- < ++n;

    cout << "m--<++n = ";
    if (b) {
        cout << "true;\n";
    }
    else {
        cout << "false;\n";
    }
    cout << "Actual agruments after function: m = " << m << "; n = " << n << ";\n\n";

    cout << "----------------------------------------------------------\n\n";

    // Завд 4

    cout << "1.4 task: '25x^5 - sqrt(x^2 + x)'\n\n";

    cout << "Please enter 5 different values for 'x'\n";

    double xValues[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter ellement number '" << i + 1 << "' for 'x': ";
        cin >> xValues[i];
    }
    cout << "Our 'x' values for testing function: { ";

    for (int i = 0; i < size(xValues); i++)
    {
        if (i == size(xValues) - 1) {
            cout << xValues[i] << " };\n\n";
            break;
        }
        cout << xValues[i] << "; ";
    }

    for (double x : xValues) {
        if ((pow(x, 2) + x) >= 0)
        {
            cout << "x = " << x << ";\n";
            cout << "Function: 25 * " << x << "^5 - sqrt(" << x << "^2 + " << x << ") = ";
            printf("%.2f;\n", oneDotFourFunction(x));
        }
        else {
            cout << "The Function doesn`t work";
        }
    }
    cout << "----------------------------------------------------------\n\n";
}

bool isPointInOurZone(double x, double y) {
    bool isInXInterval = (x >= -1 && x <= 1);
    bool isInYInterval = (y >= -1 && y <= 0);
    bool isInSemiCircle = (sqrt(x * x + y * y) <= 1);

    return isInXInterval && isInYInterval && isInSemiCircle;
}

void taskTwo()
{
    cout << "Task 2:\n\n";

    cout << "For greater testing our function please, enter 5 different points:";
    const int countOfPoints = 5;
    double points[countOfPoints][2];

    cout << "\n\n";

    for (int i = 0; i < countOfPoints; ++i) {
        cout << "Please enter coordinates of " << i + 1 << " point: \n";
        cout << "X1 = ";
        cin >> points[i][0];
        cout << "Y1 = ";
        cin >> points[i][1];

        if (isPointInOurZone(points[i][0], points[i][1])) {
            cout << "Point " << i + 1 << " [ " << points[i][0] << "; " << points[i][1] << " ] include in our zone.\n";
        }
        else {
            cout << "Point " << i + 1 << " [ " << points[i][0] << "; " << points[i][1] << " ] not include in our zone.\n";
        }
    }
    cout << "\n";


    cout << "----------------------------------------------------------\n\n";
}

void taskThree()
{
    cout << "Task 3:\n\n";

    cout << "Our function is: ((a - b)^3 - (a^3 + (3a * b^2))) / ((-3 * a^2 * b) - b^3)\n";
    cout << "Our arguments: a = 100; b = 0.001\n";

    double a = 100, b = 0.001;
    
    double firstSubFunc = pow((a - b), 3);
    double secondSubFunc = pow(a, 3);
    double thirdSubFunc = pow((3 * a * b), 2);
    double fourthSubFunc = secondSubFunc + thirdSubFunc;
    double fifthSubFunc = firstSubFunc - fourthSubFunc;
    double sixthSubFunc = pow((-3 * a), 2);
    double seventhSubFunc = sixthSubFunc * b;
    double eighthSubFunc = pow(b, 3);
    double ninethSubFunc = seventhSubFunc - eighthSubFunc;
    double result = fifthSubFunc / ninethSubFunc;

    cout << "Result of our function is: " << result << "\n";

    cout << "----------------------------------------------------------\n\n";
}

int main()
{
    taskOne();
    taskTwo();
    taskThree();

    return 0;
}
