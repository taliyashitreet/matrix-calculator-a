#include "doctest.h"
#include "Matrix.hpp"
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;
using namespace zich;

TEST_CASE("Good Input")
{
    vector<double> v1 = {11, 3, 7, 11};
    vector<double> v_1 = {-11, -3, -7, -11};
    vector<double> v2 = {8, 0, 1, 0, 3, 5};
    vector<double> v3 = {88, 9, 26, 56, 33, 62};
    Matrix a{v1, 2, 2};
    Matrix a_{v_1,2,2};
    Matrix b{v2, 2, 3};
    Matrix c{v3, 2, 3};
    CHECK(a * b == c);
    CHECK((-a)==(a_));
    CHECK((+a)==(a));
    CHECK(a>a_);
    CHECK(a>=a_);
    (a+=4);
    CHECK(a!= c);
    v1.push_back(6);
    v1.push_back(4);
    Matrix d{v1, 2, 3};
    v3 = {19, 3, 8, 11, 9, 9};
    Matrix e{v3, 2, 3};
    CHECK((d + b) == e);
    (b*=7.2);
    CHECK(b!= c);
    CHECK_NOTHROW(a * b);
    CHECK_NOTHROW(d + b);
    CHECK_NOTHROW(b + c);
    CHECK_NOTHROW(b - c);
}
TEST_CASE("incorrect size")
{
    vector<double> v1 = {11, 3, 7, 11};
    vector<double> v2 = {8, 0, 1, 0, 3, 5};
    vector<double> v3 = {88, 9, 26, 56, 33, 62};
    Matrix a{v1, 2, 2};
    Matrix b{v2, 2, 3};
    Matrix c{v3, 2, 3};
    CHECK_THROWS(a+b);
    CHECK_THROWS(a-c);
    CHECK_THROWS(b*c);
 }
TEST_CASE("incorrect input"){
    vector<double> v1 = {11, 3, 7, 11};
    CHECK_THROWS(Matrix a(v1,-2,-3));
    CHECK_THROWS(Matrix a(v1,-2,2));
    CHECK_THROWS(Matrix a(v1,2,-2));
    CHECK_THROWS(Matrix a(v1,3,2));
    CHECK_THROWS(Matrix a(v1,8,9));

}