#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
    double re;
    double im;

public:

    Complex(double a = 0, double b = 0): re(a), im(b){};

    Complex(double a): re(a), im(0.){};

    Complex operator + (const Complex & right){
        return Complex(re + right.re, im + right.im);
    };

    Complex operator - (const Complex & right){
        return Complex(re - right.re, im - right.im);
    };

    Complex operator * (const Complex & right){
        return Complex(re * right.re - im * right.im,re * right.im + im * right.re);
    };

    Complex operator / (const Complex & right){

        const double denominator = right.re * right.re +
                right.im * right.im;
        return Complex((re * right.re + im * right.im) / denominator,
                       (im * right.re - re * right.im) / denominator);
    };
    Complex operator + (const double right){
        return Complex(re + right,im);
    };

    Complex operator - (const double right){
        return Complex(re - right, im );
    };

    Complex operator * (const double right){
        return Complex(re*right, im*right);
    };

    Complex operator / (const double right){
        return Complex(re/right, im/right);
    };

    friend Complex operator+ (const double left, const Complex& right){
        return Complex(left + right.re, right.im);
    }

    friend Complex operator- (const double left, const Complex& right){
        return Complex(left - right.re, -right.im);
    }

    friend Complex operator* (const double left, const Complex& right){
        return Complex(left * right.re, left * right.im);
    }

    friend Complex operator/ (const double left, const Complex& right){
        const double denominator = right.re * right.re +
                                   right.im * right.im;
        return Complex(left * right.re / denominator,
                       -left * right.im / denominator);
    }

    friend std::ostream & operator <<(std::ostream & os, Complex const & number){
        os<<number.re<<" "<<number.im<<endl;
        return os;
    }

    bool operator ==(const Complex &right)const{
        return re == right.re && im == right.im;
    }

    bool operator !=(const Complex &right)const{
        return re != right.re || im != right.im;
    }


    void swap(Complex &b){
        std::swap(re,b.re);
        std::swap(im, b.im);
    };

    Complex & operator = (const Complex & right){
        if(this != &right){
            Complex(right).swap(*this);
        }
        return *this;
    };

    Complex& operator= (const double val)
    {
        re = val;
        im = 0.;
        return *this;
    }

    double abs() const {
        return sqrt(im*im + re*re);
    }


};