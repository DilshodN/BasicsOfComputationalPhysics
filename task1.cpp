#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

template<typename T>
void foo()
{
    std::cout << typeid(T).name() << std::endl;
    std::cout << "min num: " << std::numeric_limits<T>::min() <<
    std::endl << "max num: " << std::numeric_limits<T>::max() << std::endl;
    T e = 1;
    int mantis;
    for (mantis = 0; (1 + e/2) != 1; e /= 2, ++mantis);
    std::cout << "e: " << e << std::endl;
    std::cout << "Mantis: " << mantis << std::endl;

    std::cout << "std::numeric_limits::epsilon(): " << std::numeric_limits<T>::epsilon() << std::endl;

    const std::vector<std::pair<T, std::string>> compare =
            {{1, "1"}, {1 + e / 2, "1+e/2"}, {1 + e, "1+e"}, {1 + e + e / 2, "1+e+e/2"}};

    for (std::size_t i = 0; i < compare.size(); ++i)
        for (std::size_t j = i; j < compare.size(); ++j)
            std::cout << std::right << std::setw(7) << compare[i].second << " == "
                      << std::left  << std::setw(7) << compare[j].second << " : "
                      << std::boolalpha << (compare[i].first == compare[j].first) << std::endl;


}

// Optioanl, only for AFTI students
template<unsigned N>
void sumSeries()
{
    std::cout.precision(16);
    std::cout << std::right << std::setw(20) << "Original sum: " <<
    std::left << std::setw(20) << -0.69315 << std::endl;

    // 1
    double sum = 0;
    for(unsigned n = 1; n < N; n++)
    {
        double sign = n % 2 == 0 ? 1 : (-1);
        sum += (sign / n);
    }
    std::cout << std::right << std::setw(20) << "1->N: " <<
    std::left << std::setw(20) << sum << std::endl;

    // 2
    sum = 0;
    for(unsigned n = N; n > 0; n--)
    {
        double sign = n % 2 == 0 ? 1 : (-1);
        sum += (sign / n);
    }
    std::cout << std::right << std::setw(20) << "N->1: " <<
    std::left << std::setw(20) << sum << std::endl;

    // 3
    sum = 0;
    for(unsigned n = 1; n < N; n+=2)
    {
        sum +=  static_cast<double>(-1) / n;
    }
    for(unsigned n = 2; n < N; n+=2)
    {
        sum +=  static_cast<double>(1) / n;
    }
    std::cout << std::right << std::setw(20) << "{1->N} (+) + (-): " <<
    std::left << std::setw(20) << sum << std::endl;

    // 4
    sum = 0;
    double sign = N % 2 == 0 ? 1 : (-1);
    for(unsigned n = N; n != N % 2; n-=2)
    {
        sum += sign / n;
    }
    for(unsigned n = N-1; n != (N % 2 - 1); n-=2)
    {
        sum += (-1) * sign / n;
    }
    std::cout << std::right << std::setw(20) << "{N->1} (+) + (-): " <<
    std::left << std::setw(20) << sum << std::endl;
}

int main() {
    foo<float>();
    sumSeries<10000>();
    return 0;
}
