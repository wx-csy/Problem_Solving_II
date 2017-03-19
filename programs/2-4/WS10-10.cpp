#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int x, int y){
    if (x==0) return y;
    return gcd(y%x, x);
}

struct rational{
    int numerator, denominator;

    void reduce(){
        if (denominator == 0){
            throw;
        }
        if (denominator < 0){
            denominator = -denominator;
            numerator = -numerator;
        }
        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
    }

    bool isNegative(){
        return numerator < 0;
    }

    rational(){}

    rational(int _numerator, int _denominator){
        numerator = _numerator;
        denominator = _denominator;
        reduce();
    }

    rational operator + (const rational& addend) const {
        rational ans(numerator * addend.denominator + addend.numerator * denominator,
                     denominator * addend.denominator);
        return ans;
    }

    rational operator - () const {
        rational ans(-numerator, denominator);
        return ans;
    }

    rational operator - (const rational& subtrahend) const {
        rational ans(numerator, denominator);
        ans = ans + (-subtrahend);
        return ans;
    }

    rational operator * (const rational& multiplier) const {
        rational ans(numerator * multiplier.numerator,
                     denominator * multiplier.denominator);
        return ans;
    }

    rational operator / (const rational& divisor) const {
        rational ans(numerator * divisor.denominator,
                     denominator * divisor.numerator);
        return ans;
    }

    bool operator < (const rational& num) const {
        return (*this - num).isNegative();
    }

    friend ostream& operator << (ostream& os, const rational& num){
        if (num.denominator == 1){
            os << num.numerator;
        } else {
            os << num.numerator << '/' << num.denominator;
        }
        return os;
    }
    friend istream& operator >> (istream& is, rational& num){
        is >> num.numerator >> num.denominator;
        num.reduce();
        return is;
    }
};



int main(){
    rational a, b;
    while (cin >> a >> b){
        cout << a + b << ' ';
        cout << a - b << ' ';
        cout << a * b << ' ';
        cout << a / b << ' ';
        cout << ((a<b)?"true":"false") << endl;
    }
    return 0;
}
