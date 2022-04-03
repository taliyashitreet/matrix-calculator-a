#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <vector>
#include <iostream>
using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        vector<double> mat;
        int row, col;

    public:
        Matrix(vector<double> v, int col, int row)
        {
            if(col*row != v.size() || col<=0 || row<=0){
                throw invalid_argument("incorrect input");
            }
            this->col = col;
            this->row = row;
            this->mat = v;
        }
        Matrix(){}

        friend Matrix operator-(const Matrix &a, const Matrix &b);
        friend Matrix operator+(const Matrix &a, const Matrix &b);
        friend Matrix operator-=(const Matrix &a,double);
        friend Matrix operator-(const Matrix &a);
        friend Matrix operator+(const Matrix &a);
        friend Matrix operator++(const Matrix &a);
        friend Matrix operator--(const Matrix &a);
        friend Matrix operator*=(const Matrix &a, double);
        friend Matrix operator+=(const Matrix &a, double);
        friend bool operator>=(const Matrix &a, const Matrix &b);
        friend bool operator<=(const Matrix &a, const Matrix &b);
        friend bool operator<(const Matrix &a, const Matrix &b);
        friend bool operator>(const Matrix &a, const Matrix &b);
        friend bool operator==(const Matrix &a, const Matrix &b);
        friend bool operator!=(const Matrix &a, const Matrix &b);
        friend istream &operator>>(istream &in, const Matrix &m);
        friend ostream &operator<<(ostream &out, const Matrix &m);
        friend Matrix operator*(double, const Matrix &a);
        friend Matrix operator*(const Matrix &a, const Matrix &b);
    };
}
#endif