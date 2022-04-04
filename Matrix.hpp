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
        vector<vector<double>> twoDmat;

    public:
        // int getRow(){
        //     return this->row;
        // }
        // int getCol(){
        //     return this->col;
        // }
        // vector<vector<double> > getMat(){
        //     return this->twoDmat;
        // }

        Matrix(vector<double> v, int row, int col);
        Matrix() {}
        // Operators between 2 Matrix:
        friend Matrix operator-(const Matrix &a, const Matrix &b);
        friend Matrix operator+(const Matrix &a, const Matrix &b);
        friend Matrix operator*(const Matrix &a, const Matrix &b);
        // operators on one Matrix:
        friend Matrix operator-(const Matrix &a);
        friend Matrix operator+(const Matrix &a);
        friend Matrix operator*(double, const Matrix &a);
        // operators for change one Matrix:
        friend void operator++(Matrix &a);
        friend void operator--(Matrix &a);
        friend void operator*=(Matrix &a, double);
        friend void operator-=(Matrix &a, double);
        friend void operator+=(Matrix &a, double);
        // Comparison operators:
        friend bool operator>=(const Matrix &a, const Matrix &b);
        friend bool operator<=(const Matrix &a, const Matrix &b);
        friend bool operator<(const Matrix &a, const Matrix &b);
        friend bool operator>(const Matrix &a, const Matrix &b);
        friend bool operator==(const Matrix &a, const Matrix &b);
        friend bool operator!=(const Matrix &a, const Matrix &b);
        // cout and cin operatos:
        friend istream &operator>>(istream &in, const Matrix &m);
        friend ostream &operator<<(ostream &out, const Matrix &m);
    };
}
#endif