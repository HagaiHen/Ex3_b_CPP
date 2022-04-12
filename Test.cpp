
#include <string>
#include "doctest.h"
#include "Matrix.hpp"
#include <vector>
using namespace zich;
using namespace std;


TEST_CASE("operator ==") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> z = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> test1 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    Matrix a{identity, 3, 3};
    Matrix b{identity, 3, 3};
    Matrix c{test1, 3,3};
    Matrix zero{z, 3, 3};
    CHECK((a == b));
    CHECK_FALSE((a == zero));
    CHECK_FALSE((b == zero));
    CHECK_FALSE((b == c));
    CHECK_FALSE((a == c));
}

TEST_CASE("operator !=") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> z = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> test1 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    Matrix a{identity, 3, 3};
    Matrix b{identity, 3, 3};
    Matrix c{test1, 3,3};
    Matrix zero{z, 3, 3};
    CHECK_FALSE((a != b));
    CHECK((a != zero));
    CHECK((b != zero));
    CHECK((b != c));
    CHECK((a != c));
}

TEST_CASE("operator +") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {1, 0, 0, 1};
    std::vector<double> z = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> test1 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    std::vector<double> test2 = {1, 0, 0, 0, 1, 0, 0, 0, 0};
    Matrix a{identity, 3, 3};
    Matrix a_2{identity2, 2,2};
    Matrix b{identity, 3, 3};
    Matrix c{test1, 3, 3};
    Matrix d{test2, 3, 3};
    Matrix zero{z, 3, 3};
    CHECK((a + zero == a));
    CHECK_FALSE((a + c == zero));
    CHECK((c + d == a));
    CHECK_FALSE((d + zero == zero));
    CHECK_FALSE((b + a == zero));
    CHECK_THROWS((a + a_2));
    CHECK_THROWS((zero + a_2));
    a+=zero;
    CHECK ((a == a));
    a+=b;
    CHECK((a == 2*b));
}

TEST_CASE("operator -") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity2 = {1, 0, 0, 1};
    std::vector<double> z = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> test1 = {0, 0, 0, 0, 0, 0, 0, 0, 1};
    std::vector<double> test2 = {1, 0, 0, 0, 1, 0, 0, 0, 0};
    Matrix a{identity, 3, 3};
    Matrix a_2{identity2, 2,2};
    Matrix b{identity, 3, 3};
    Matrix c{test1, 3, 3};
    Matrix d{test2, 3, 3};
    Matrix zero{z, 3, 3};
    CHECK((a - zero == a));
    CHECK((a - b == zero));
    CHECK((a - a  == zero));
    CHECK_FALSE((a - c == zero));
    CHECK_FALSE((a - d == zero));
    CHECK_THROWS((a - a_2));
    CHECK_THROWS((zero - a_2));
    CHECK((-a == -b));
    CHECK((+a == a));
    CHECK((-a + b == zero));
    CHECK ((a == -(-a)));
    a-=a;
    CHECK((a==zero));
}

TEST_CASE("operator *") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> iden_01 = {0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1};
    std::vector<double> iden_3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> m1 = {2, 3, 4, 5};
    std::vector<double> m2 = {2, 1, -2, 0};
    std::vector<double> a1 = {-2, 2, -2, 4};
    std::vector<double> a2 = {8, 11, -4, -6};
    Matrix a{identity, 3,3};
    Matrix b{iden_3, 3,3};
    Matrix c{iden_01, 3,3};
    Matrix mul1{m1 ,2,2};
    Matrix mul2{m2 ,2,2};
    Matrix ans1{a1 ,2,2};
    Matrix ans2{a2 ,2,2};
    CHECK_FALSE((a == b));
    CHECK((3*a == b));
    CHECK((3.1*a == b + c));
    CHECK((a*3 == b));
    CHECK((a*3.1 == b + c));
    CHECK((a*b == a*b));
    CHECK_FALSE((mul1 * mul2 == mul2 * mul1));
    CHECK((mul1*mul2 == ans1));
    CHECK((mul2*mul1 == ans2));
    a*=3;
    CHECK((a == b));
    a*=a;
    CHECK((a==3*b));
}

TEST_CASE("operator >") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<double> iden_01 = {0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1};
    std::vector<double> iden_3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> m1 = {3, 3, 4, 5};
    std::vector<double> m2 = {2, 1, -2, 0};
    Matrix a{identity, 3,3};
    Matrix b{iden_3, 3,3};
    Matrix c{iden_01, 3,3};
    Matrix mul1{m1 ,2,2};
    Matrix mul2{m2 ,2,2};
    Matrix one{identity1, 3,3};
    CHECK((a + one > a));
    CHECK((mul1 > mul2));
    CHECK_FALSE((mul2 > mul1));
    CHECK_FALSE((a > 3*a));
    CHECK_FALSE((3*a > b));
}

TEST_CASE("operator >=") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<double> iden_01 = {0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1};
    std::vector<double> iden_3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> m1 = {3, 3, 4, 5};
    std::vector<double> m2 = {3, 1, -2, 0};
    Matrix a{identity, 3,3};
    Matrix b{iden_3, 3,3};
    Matrix c{iden_01, 3,3};
    Matrix mul1{m1 ,2,2};
    Matrix mul2{m2 ,2,2};
    Matrix one{identity1, 3,3};
    CHECK((3*a >= a));
    CHECK((mul1 >= mul2));
    CHECK_FALSE((mul2 >= mul1));
    CHECK_FALSE((a >= 3*a));
    CHECK((3*a >= b));
}

TEST_CASE("operator <") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<double> iden_01 = {0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1};
    std::vector<double> iden_3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> m1 = {3, 3, 4, 5};
    std::vector<double> m2 = {2, 1, -2, 0};
    Matrix a{identity, 3,3};
    Matrix b{iden_3, 3,3};
    Matrix c{iden_01, 3,3};
    Matrix mul1{m1 ,2,2};
    Matrix mul2{m2 ,2,2};
    Matrix one{identity1, 3,3};
    CHECK_FALSE((3*a < a));
    CHECK_FALSE((mul1 < mul2));
    CHECK((mul2 < mul1));
    CHECK(((a - one) < 3*a));
    CHECK_FALSE((3*a < b));
}

TEST_CASE("operator <=") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<double> iden_01 = {0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1};
    std::vector<double> iden_3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> m1 = {3, 3, 4, 5};
    std::vector<double> m2 = {3, 1, -2, 0};
    Matrix a{identity, 3,3};
    Matrix b{iden_3, 3,3};
    Matrix c{iden_01, 3,3};
    Matrix mul1{m1 ,2,2};
    Matrix mul2{m2 ,2,2};
    Matrix one{identity1, 3,3};
    CHECK_FALSE((3*a <= a));
    CHECK_FALSE((mul1 <= mul2));
    CHECK((mul2 <= mul1));
    CHECK(((a - one) <= 3*a));
    CHECK((3*a <= b));
    CHECK((a<=a));
}

TEST_CASE("operator ++, --") {
    std::vector<double> identity = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> identity1 = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<double> z = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector<double> iden_01 = {0.1, 0, 0, 0, 0.1, 0, 0, 0, 0.1};
    std::vector<double> iden_3 = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    std::vector<double> m1 = {3, 3, 4, 5};
    std::vector<double> m2 = {2, 2, 3, 4};
    Matrix a{identity, 3,3};
    Matrix b{iden_3, 3,3};
    Matrix c{iden_01, 3,3};
    Matrix mul1{m1 ,2,2};
    Matrix mul2{m2 ,2,2};
    Matrix zero{z, 3,3};
    Matrix one{identity1, 3,3};
    CHECK((++mul2 == mul1));
    a++;
    CHECK((++zero == one));
    zero--;
    CHECK((zero == --one));

}
