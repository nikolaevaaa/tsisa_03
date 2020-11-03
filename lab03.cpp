#include <iostream>
#include <iomanip>
#include <cmath>

double func (int x)
{
    double f=cos(x)*tanh(x);
    return f;
}

double funcm (int x)
{
    double fm=cos(x)*tanh(x)*sin(5*x);
    return fm;
}

void print(const int it, const double T,
               const double val, const double f) {
    std::cout << "| " << std::setw(4) << it
         << "| " << std::setw(10) << T
         << "| " << std::setw(12) << val
         << "| " << std::setw(14) << f << "|"<<std::endl;
}


int main()
{
    std::cout << "Simulated Annealing" << std::endl;
    std::cout<<"Min of function f(x) "<<std::endl;
    std::cout << std::left << std::string(50, '-') << '\n'
         << "| " << std::setw(4) << "N"
         << "| " << std::setw(10) << "T"
         << "| " << std::setw(12) << "x"
         << "| " << std::setw(14) << "f(x)" << "|"<<std::endl
         << std::string(50, '-') << std::endl;
    double tmin = 0.01;
    double tmax = 10000.0, xi = 0.0, res = 0.0,a=7,b=11;
    int N = 1;
    double x0 = 0, x = (double)(rand() % 25001) / 10000 + 1.5;
    res = func(x);
    while (tmax > tmin)
    {
        xi = (double)(rand() % 25001) / 10000 + 1.5;
        double df = func(xi) - func(x);
        if (df <= 0)
        {
            x0 = xi;
            x = xi;
            res = func(x0);
        }
        else
        {
            double probability = (double)(a + rand() * 1./RAND_MAX * (b - a));
            double P = exp(-df / tmax);
            if (probability < P)
            {
                x0 = xi;
                x = xi;
                res = func(x0);
            }
        }

        print(N,tmax ,x0, func(x0) );
        tmax = tmax * 0.95;
        N++;

    }
    std::cout << std::endl << "Result: Xmin = " << x0 << "   Fmin = " << res << std::endl;



    std::cout<<"\nMin of function f(x)*sin(5x) "<<std::endl;
    std::cout << std::left << std::string(50, '-') << '\n'
              << "| " << std::setw(4) << "N"
              << "| " << std::setw(10) << "T"
              << "| " << std::setw(12) << "x"
              << "| " << std::setw(14) << "f(x)" << "|"<<std::endl
              << std::string(50, '-') << std::endl;

     tmin = 0.01;
     tmax = 10000.0;
     xi = 0.0;
     res = 0.0;
     a=7;
     b=11;
   N = 1;
     x0 = 0;
     x = (double)(rand() % 25001) / 10000 + 1.5;
    res = funcm(x);
    while (tmax > tmin)
    {
        xi = (double)(rand() % 25001) / 10000 + 1.5;
        double df = funcm(xi) - funcm(x);
        if (df <= 0)
        {
            x0 = xi;
            x = xi;
            res = funcm(x0);
        }
        else
        {
            double probability = (double)(a + rand() * 1./RAND_MAX * (b - a));
            double P = exp(-df / tmax);
            if (probability < P)
            {
                x0 = xi;
                x = xi;
                res = funcm(x0);
            }
        }

        print(N,tmax ,x0, funcm(x0) );
        tmax = tmax * 0.95;
        N++;

    }
    std::cout << std::endl << "Result: Xmin = " << x0 << "   Fmin = " << res << std::endl;


    return 0;
}