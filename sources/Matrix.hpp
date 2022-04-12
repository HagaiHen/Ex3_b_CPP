#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace zich {
    
    class Matrix {
        private:
            vector<double> vec;
            int rows;
            int cols;

        public:
            Matrix operator+(const Matrix& other);
            Matrix operator-(const Matrix& other);
            Matrix operator-();
            Matrix operator+();
            Matrix& operator--();
            Matrix& operator++();
            Matrix operator--(int flag);
            Matrix operator++(int flag);
            Matrix operator*(const Matrix& other);
            friend Matrix operator*(double n, const Matrix &other);
            friend Matrix operator*(int n, const Matrix &other);
            friend Matrix operator*(const Matrix &other, double n); 
            friend Matrix operator*(const Matrix &other, int n);            
            friend Matrix operator*(const Matrix &mat1, const Matrix &mat2);            
            Matrix operator*=(int n);
            Matrix operator*=(const Matrix &other);
            Matrix operator+=(const Matrix &other);
            Matrix operator-=(const Matrix &other);
            friend istream& operator>>(istream &is, Matrix &mat);
            friend ostream& operator<<(ostream& os, const Matrix& mat);
            friend bool operator<=(const Matrix &mat1, const Matrix &mat2);
            friend bool operator<(const Matrix &mat1, const Matrix &mat2);
            friend bool operator>=(const Matrix &mat1, const Matrix &mat2);
            friend bool operator>(const Matrix &mat1, const Matrix &mat2);
            friend bool operator==(const Matrix &mat1, const Matrix &mat2);
            friend bool operator!=(const Matrix &mat1, const Matrix &mat2);
            Matrix(vector<double> vec, int rows, int cols);
            Matrix(const Matrix& other);

	};

}
