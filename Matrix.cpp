#include "Matrix.hpp"
using namespace std;

namespace zich

{
    //constructor for Matrix
    Matrix::Matrix(vector<double> v, int row, int col)
    {
        if (col * row != v.size() || col <= 0 || row <= 0)
        {
            throw invalid_argument("incorrect input");
        }
        this->col = col;
        this->row = row;
        this->mat = v;
        vector<vector<double>> tmp((size_t)row, vector<double>((size_t)col, 0.0));
        this->twoDmat = tmp;
        size_t count = 0;
        for (size_t i = 0; i < row; i++)
        {
            for (size_t j = 0; j < col; j++)
            {
                this->twoDmat[i][j] = v.at(count);
                count++;
            }
        }
    }
    //operators on 2 Matrix:

    Matrix operator-(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        vector<double> v(a.mat.size(), 0.0);
        Matrix ab(v, a.row, a.col);

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                ab.twoDmat[i][j] = a.twoDmat[i][j] - b.twoDmat[i][j];
            }
        }

        return ab;
    }
    Matrix operator+(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        vector<double> v(a.mat.size(), 0.0);
        Matrix ab(v, a.row, a.col);

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                ab.twoDmat[i][j] = a.twoDmat[i][j] + b.twoDmat[i][j];
            }
        }

        return ab;
    }
Matrix operator*(const Matrix &a, const Matrix &b)
    {
        if (a.col != b.row)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        size_t size = (size_t)(a.row * b.col);
        vector<double> v(size, 0.0);
        Matrix mul(v, a.row, b.col);

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < b.col; j++)
            {
                for (size_t k = 0; k < b.row; k++)
                {
                    mul.twoDmat[i][j] += a.twoDmat[i][k] * b.twoDmat[k][j];
                }
            }
        }
        return mul;
    }

//operators on one Matrix:
    Matrix operator*(double n, const Matrix &a)
    {
        vector<double> v(a.mat.size(), 0.0);
        Matrix a_(v, a.row, a.col);

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a_.twoDmat[i][j] = (a.twoDmat[i][j]) * (n);
            }
        }

        return a_;
    }


    Matrix operator-(const Matrix &a)
    {
        vector<double> v(a.mat.size(), 0.0);
        Matrix a_(v, a.row, a.col);

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a_.twoDmat[i][j] = (a.twoDmat[i][j]) * (-1);
            }
        }

        return a_;
    }
    Matrix operator+(const Matrix &a)
    {
        vector<double> v(a.mat.size(), 0.0);
        Matrix a_(v, a.row, a.col);

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a_.twoDmat[i][j] = (a.twoDmat[i][j]) * (1);
            }
        }

        return a_;
    }
    //operators for change one Matrix:
    void operator*=(Matrix &a, double n)
    {

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a.twoDmat[i][j] = (a.twoDmat[i][j]) * (n);
            }
        }

    }
    void operator-=(Matrix &a, double n)
    {
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a.twoDmat[i][j] = (a.twoDmat[i][j]) * (n);
            }
        }

    }
    
    
    void operator++(Matrix &a)
    {

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a.twoDmat[i][j] = a.twoDmat[i][j] + 1;
            }
        }
    }
    void operator--(Matrix &a)
    {
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a.twoDmat[i][j] = a.twoDmat[i][j] - 1;
            }
        }
    }
    void operator+=(Matrix &a, double n)
    {

        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                a.twoDmat[i][j] = (a.twoDmat[i][j]) + (n);
            }
        }
    }



    //comparsion operators:
    bool operator>=(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.twoDmat[i][j] < b.twoDmat[i][j])
                    return false;
            }
        }
        return true;
    }
    bool operator<=(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.twoDmat[i][j] > b.twoDmat[i][j])
                    return false;
            }
        }
        return true;
    }
    bool operator<(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.twoDmat[i][j] >= b.twoDmat[i][j])
                    return false;
            }
        }
        return true;
    }
    bool operator>(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.twoDmat[i][j] <= b.twoDmat[i][j])
                    return false;
            }
        }
        return true;
    }
    bool operator==(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            throw invalid_argument("this two matrix are not the same size");
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.twoDmat[i][j] != b.twoDmat[i][j])
                    return false;
            }
        }
        return true;
    }
    bool operator!=(const Matrix &a, const Matrix &b)
    {
        if (a.row != b.row || a.col != b.col)
        {
            return true;
        }
        for (size_t i = 0; i < a.row; i++)
        {
            for (size_t j = 0; j < a.col; j++)
            {
                if (a.twoDmat[i][j] == b.twoDmat[i][j])
                    return false;
            }
        }
        return true;
    }
    
    

    // cout and cin operatos:
    istream &operator>>(istream &in, const Matrix &m)
    {
        // for (size_t i = 0; i < m.row; ++i)
        // {
            
        //     for (size_t j = 0; j < m.col; ++j)
        //     {
        //         in >> m.twoDmat[i][j];
        //     }
        // }
         return in;
    }
    ostream &operator<<(ostream &out, const Matrix &m)
    {
        for (size_t i = 0; i < m.row; ++i)
        {
            out << "[";
            out << m.twoDmat[i][0];
            for (size_t j = 1; j < m.col; ++j)
            {
                out << " " << m.twoDmat[i][j];
            }
            out << "]";
            out << endl;
        }
        return out;
    }

} // namespace zich
