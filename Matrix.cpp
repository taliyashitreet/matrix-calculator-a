#include "Matrix.hpp"
using namespace std;

namespace zich
{
    
    Matrix operator-(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return ab;
    }
    Matrix operator-(const Matrix &a)
    {
        return a;
    }
    Matrix operator*=(const Matrix &a,double n)
    {
        return a;
    }
    Matrix operator-=(const Matrix &a,double n)
    {
        Matrix ab;
        return ab;
    }
    Matrix operator+(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return ab;
    }
    Matrix operator+(const Matrix &a)
    {;
        return a;
    }
    Matrix operator++(const Matrix &a)
    {
        Matrix ab;
        return ab;
    }
    Matrix operator--(const Matrix &a)
    {
        Matrix ab;
        return ab;
    }
    Matrix operator+=(const Matrix &a,double n)
    {
        Matrix ab;
        return ab;
    }
    bool operator>=(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return true;
    }
    bool operator<=(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return true;
    }
    bool operator<(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return true;
    }
    bool operator>(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return true;
    }
    bool operator==(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return true;
    }
    bool operator!=(const Matrix &a,const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return true;
    }
    Matrix operator*(double n, const Matrix &a)
    {
        Matrix an;
        return an;
    }
    Matrix operator*(const Matrix &a,const Matrix &b)
    {
        if (a.col != b.row)
        {
            
            throw invalid_argument("this two matrix are not the same size");
        }
        Matrix ab;
        return ab;
    }
    istream &operator>>(istream &in, const Matrix&m){
        return in;
    }
    ostream &operator<<(ostream &out,const Matrix&m){
        return out;
    }

} // namespace zich
