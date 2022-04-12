#include <string>
#include <iostream>
#include "Matrix.hpp"

namespace zich {
    
    Matrix::Matrix(vector<double> vec, int rows, int cols) {
        if (rows <= 0 || cols <= 0 || rows*cols != vec.size()) {
            throw "invalid matrix";
        }
        this->vec = std::move(vec);
        this->rows = rows;
        this->cols = cols;
        //cout << &this->vec << " " << &this->rows << " " << &this->cols << endl;
    }

    Matrix::Matrix(const Matrix& other) {
        for (int i = 0; i < other.vec.size(); i++) {
            this->vec.push_back(other.vec[(double)i]);    
        }
        this->rows = other.rows;
        this->cols = other.cols;
        //cout << &this->vec << " " << &this->rows << " " << &this->cols << endl;
    }

    zich::Matrix& zich::Matrix::operator--() {
        for (int i = 0; i < vec.size(); i++) {
            double tmp = this->vec[(double)i];
            tmp--; 
            this->vec[(double)i] = tmp;
        }
        return *this;
    }

    zich::Matrix& zich::Matrix::operator++() {
        for (int i = 0; i < vec.size(); i++) {
            double tmp = this->vec[(double)i];
            tmp++; 
            this->vec[(double)i] = tmp;
        }
        return *this;
    }

    zich::Matrix zich::Matrix::operator++(int flag) {
    Matrix m = *this;
    this->operator++();
    return m;
    }

    zich::Matrix zich::Matrix::operator--(int flag) {
    Matrix m = *this;
    this->operator--();
    return m;
    }

    zich::Matrix Matrix::operator+(const Matrix& other) {
        Matrix ans{this->vec, this->rows, this->cols};
        if (this->cols != other.cols || this->rows != other.rows) {
            throw "The matrices do not match";
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*ans.cols) + j] = (this->vec[(double)(i*this->cols) + j] + other.vec[(double)(i*other.cols) + j]); 
            }
        }
        return ans;
        
    }

    zich::Matrix Matrix::operator-(const Matrix& other) {
        Matrix ans{this->vec, this->rows, this->cols};
        if (this->cols != other.cols || this->rows != other.rows) {
            throw "The matrices do not match";
        }
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*ans.cols) + j] = (this->vec[(double)(i*this->cols) + j] - other.vec[(double)(i*other.cols) + j]); 
            }
        }
        return ans;
    }

    zich::Matrix Matrix::operator-() {
        Matrix ans{this->vec, this->rows, this->cols};
        for (int i = 0; i <ans.rows; i++) {
            for (int j = 0; j < ans.cols; j++) {
                ans.vec[(double) (i*ans.cols) + j] = (-1) * ans.vec[(double) (i*ans.cols) + j];
            }
        }
        return ans;
    }

    zich::Matrix Matrix::operator+() {
        return *this;
    }

    zich::Matrix operator*(double n, const Matrix &other) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;
    }

    zich::Matrix operator*(int n, const Matrix &other) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;

    }
    
    zich::Matrix operator*(const Matrix &other, double n) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;
    }

    zich::Matrix operator*(const Matrix &other, int n) {
        Matrix ans{other.vec, other.rows, other.cols};
        for (int i = 0; i <other.rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                ans.vec[(double) (i*other.cols) + j] = n * other.vec[(double) (i*other.cols) + j];
            }
        }
        return ans;

    }

    zich::Matrix Matrix::operator*(const Matrix& other) {
        if (this->cols != other.rows) {
            throw "The matrices do not match";
        }
        double sum = 0;
        vector<double> v((double) this->rows * other.cols);
        //cout << this->rows << " " << other.cols << endl;
        Matrix ans{v, this->rows, other.cols};
        for (int i = 0; i < this->rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < other.rows; k++) {
                    //cout << ((i*other.cols) + j) << "<-" << ((i*this->cols) + k) << "*" << ((k*other.cols) + j) << endl;
                    ans.vec[(double) (i*other.cols) + j] += this->vec[(double) (i*this->cols) + k] * other.vec[(double) (k*other.cols) + j];
                }
            }
        }
        //cout << "ans:" << endl << ans << endl;
        return ans;
    }

    zich::Matrix operator*(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.rows) {
            throw "The matrices do not match";
        }
        double sum = 0;
        //cout << mat1.rows << endl << mat2.cols << endl;
        vector<double> v((double) mat1.rows * mat2.cols);
        Matrix ans{v, mat1.rows, mat2.cols};
        for (int i = 0; i < mat1.rows; i++) {
            for (int j = 0; j < mat2.cols; j++) {
                for (int k = 0; k < mat2.rows; k++) {
                    ans.vec[(double) (i*mat2.cols) + j] += mat1.vec[(double) (i*mat1.rows) + j] * mat2.vec[(double) (i*mat2.rows) + k];
                }
            }
        }   
        //cout << ans << endl;
        return ans;

    }
    

    zich::Matrix Matrix::operator*=(int n) {
        *this = zich::operator*(*this, n);
        return *this;

    }

    zich::Matrix Matrix::operator*=(const Matrix& other) {
        *this = zich::operator*(*this, other);
        return *this;
    }

    zich::Matrix zich::Matrix::operator+=(const Matrix& other) {
        *this = operator+(other);
        return *this;
    }

    zich::Matrix zich::Matrix::operator-=(const Matrix& other) {
        *this = operator-(other);
        return *this;
    }

    ostream& operator<<(ostream& os, const Matrix& mat) {
        for (int i = 0; i < mat.rows; i++) {
            os <<  "[";
            for (int j = 0; j < mat.cols; j++) {
                if (j+1 < mat.cols) {
                    os << mat.vec[(double)(i*mat.cols) + j] << " ";
                } else {
                    os << mat.vec[(double)(i*mat.cols) + j];

                }
            }
            if (i+1 < mat.rows) {
                os << "]" << endl;
            } else {
                os << "]";

            }
        }
        return os;
    }

    istream& operator>>(istream& is, Matrix& mat) {
        string str;
        getline(is, str);
        string num;
        size_t i = 0;
        size_t c = 0;
        //cout << mat.rows*mat.cols << endl;
        while (c < mat.rows*mat.cols && i < str.size()) {
            if (str[i] == '[') {
                //cout<<i<<endl;
                i++;
                //cout<<i<<endl;
                while (str[i] != ']' && i < str.size()) {
                    if (str[i] != ' ') {
                        num.insert(num.end(), str[i++]);
                    } else {
                        mat.vec[c++] = stod(num);
                        num.clear();
                        i++;
                    }
                    //cout<<i<<endl;
                    //cout<<num<<endl;
                }
                //cout << num << endl;
                
                //cout << "c = " << c << endl;
                
            } else {
                if (str[i] == ',' || str[i] == ' ') {
                    //cout << i << endl;
                    if (str[i] == ',' && str[i+1] != ' ') {
                        throw "invalid Matrix";
                    }
                    i++;
                } else {
                    if (str[i] == ']') {
                        i++;
                    } else {
                        throw "invalid matrix";
                    }
                }
            }
        }
        if (i < str.size()-1) {
            throw "invalid matrix";
        }
        cout << str[str.size()-1] << endl; 
        if (str[str.size()-1] != ']') {
            throw "invalid matrix";
        }
        if (c < mat.rows*mat.cols) {
            throw "invalid matrix";
        }
        //cout << mat << endl;
        return is;
    }

    bool operator<=(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows) {
            throw "invalid matrix";
        }
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat1.vec.size(); i++) {
            sum1 += mat1.vec[(double) i];
        }
        for (int i = 0; i < mat2.vec.size(); i++) {
            sum2 += mat2.vec[(double) i];
        }
        return (sum1 <= sum2);
    }
    bool operator<(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows) {
            throw "invalid matrix";
        }
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat1.vec.size(); i++) {
            sum1 += mat1.vec[(double) i];
        }
        for (int i = 0; i < mat2.vec.size(); i++) {
            sum2 += mat2.vec[(double) i];
        }
        return (sum1 < sum2);

    }
    bool operator>=(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows) {
            throw "invalid matrix";
        }
        double sum1 = 0;
        double sum2 = 0;
        for (int i = 0; i < mat1.vec.size(); i++) {
            sum1 += mat1.vec[(double) i];
        }
        for (int i = 0; i < mat2.vec.size(); i++) {
            sum2 += mat2.vec[(double) i];
        }
        return (sum1 >= sum2);

    }
    bool operator>(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows) {
            throw "invalid matrix";
        }
        double sum1 = 0; 
        double sum2 = 0;
        for (int i = 0; i < mat1.vec.size(); i++) {
            sum1 += mat1.vec[(double) i];
        }
        for (int i = 0; i < mat2.vec.size(); i++) {
            sum2 += mat2.vec[(double) i];
        }
        if (sum1 > sum2) {
            return true;
        }
        return (sum1 > sum2);

    }
    bool operator==(const Matrix &mat1, const Matrix &mat2) {
        if (mat1.cols != mat2.cols || mat1.rows != mat2.rows) {
            throw "invalid matrix";
        }
        for (int i = 0; i < mat2.rows; i++) {
            for (int j = 0; j < mat2.cols; j++) {
                if (mat1.vec[(double)(i*mat1.cols) + j] != mat2.vec[(double)(i*mat2.cols) + j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool operator!=(const Matrix &mat1, const Matrix &mat2) {
        return !(operator==(mat1, mat2));
    }

}




