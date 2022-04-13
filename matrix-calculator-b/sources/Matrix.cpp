#include "../Matrix.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <sstream>
#include <fstream>

using namespace zich;

namespace zich {

    Matrix::Matrix(const vector<double> &_mat, int _row=0 , int _col=0 ) {
        if(_row *_col !=_mat.size() || _row<= 0 ||  _col<= 0){
            throw runtime_error("the size is nor correct");
        }
//        this->set_col(_col);
//        this->set_row(_row);
//        this->_mat = _mat;
        this->_row =_row;
        this->_col=_col;
        this->_mat = _mat;
    }

    Matrix::~Matrix() {}

    Matrix  Matrix::operator+(Matrix const &other) const {
        //errors
        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");
        }

        vector<double> a;
        int x = this->get_row() * this->get_col();
        for (unsigned long i = 0; i < x; ++i) {
            a.push_back(this->_mat.at(i) + other._mat.at(i));
        }

        Matrix new_mat{a, this->get_row(), this->get_col()};
        return new_mat;
    }

    Matrix &Matrix::operator+() {
        return *this;
    }

    Matrix &Matrix::operator+=(const Matrix &other) {
        return (*this = *this + other);
    }


    Matrix Matrix::operator-(const Matrix &other) const {
        //errors
        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");

        }


        vector<double> a;
        int x = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x; i++) {
            a.push_back(this->_mat.at(i) - other._mat.at(i));
        }

        Matrix new_mat{a, this->get_row(), this->get_col()};
        return new_mat;

    }

    Matrix &Matrix::operator-=(const Matrix &other) {
        return (*this = *this - other);
    }

    Matrix &Matrix::operator-() {
        int x = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x; ++i) {
            this->_mat.at(i) *= -1;
        }
        return *this;
    }

    bool Matrix::operator >( const Matrix &other)  const{
        //errors
        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");
        }

        double sum_a=0;
        double sum_b=0;

        int x1 = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x1; i++) {
            sum_a += this->_mat.at(i);
        }
        for (unsigned long i = 0; i < x1; i++) {
            sum_b += other._mat.at(i);
        }
        return (sum_a > sum_b);

    }

    bool Matrix::operator>=(const Matrix &other)const  {
        //errors
        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");
        }

        double sum_a=0 ;
        double sum_b=0;

        int x1 = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x1; i++) {
            sum_a += this->_mat.at(i);
        }
        for (unsigned long i = 0; i < x1; i++) {
            sum_b += other._mat.at(i);
        }
        return (sum_a >= sum_b);
    }

    bool Matrix::operator<( const Matrix &other) const {
        //errors
        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");
        }

        double sum_a =0;
        double sum_b =0;

        int x1 = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x1; i++) {
            sum_a += this->_mat.at(i);
        }
        for (unsigned long i = 0; i < x1; i++) {
            sum_b += other._mat.at(i);
        }
        return (sum_a < sum_b);
    }

    bool Matrix::operator<=(const Matrix &other) const {
        //errors
        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");
        }

        double sum_a=0;
        double sum_b=0;

        int x1 = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x1; i++) {
            sum_a += this->_mat.at(i);
        }
        for (unsigned long i = 0; i < x1; i++) {
            sum_b +=other._mat.at(i);
        }
        return (sum_a <= sum_b);
    }

    bool Matrix::operator!=( const Matrix &other)const  {

        if (this->get_row() != other.get_row() || this->get_col() != other.get_col()) {
            throw runtime_error("The number of rows and columns is not equal");
        }

        double sum_a = 0;
        double sum_b = 0;

        int x1 = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x1; i++) {
            sum_a += this->_mat.at(i);
        }
        for (unsigned long i = 0; i < x1; i++) {
            sum_b += other._mat.at(i);
        }
        return (sum_a != sum_b);
    }

    Matrix &Matrix::operator++() {
        int x = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x; ++i) {
            this->_mat.at(i) ++;
        }
        return *this;
    }



    Matrix Matrix::operator++(int) {
        Matrix a = *this;
        int x = this->get_row() * this->get_col();
        for (unsigned long i = 0; i < x; ++i) {
            this->_mat.at(i)++;
        }
        return a;
    }

    Matrix &Matrix::operator--() {
        int x = this->get_row() * this->get_col();

        for (unsigned long i = 0; i < x; ++i) {
            this->_mat.at(i) --;
        }
        return *this;
    }



    Matrix Matrix::operator--(int) {
        Matrix a = *this;
        int x = this->get_row() * this->get_col();
        for (unsigned long i = 0; i < x; ++i) {
            this->_mat.at(i)--;
        }
        return a;
    }

    Matrix Matrix::operator*(double temp) {

        vector<double> a;
        int x = this->get_row() * this->get_col();
        for (unsigned long i = 0; i < x; ++i) {
            a.push_back(this->_mat.at(i) * temp);
        }

        Matrix new_mat{a, this->get_row(), this->get_col()};
        return new_mat;
    }

    Matrix &Matrix:: operator*=(double temp){
        int x = this->get_row()*this->get_col();
        for (unsigned long i = 0; i < x; ++i) {
            this->_mat.at(i) *= temp;
        }
        return *this;
    }

    Matrix Matrix::operator*=( Matrix const &other) {

        if (this->get_col() != other.get_row()) {
            throw runtime_error("col not equall to row");
        }
        *this = (*this) * other;
        return *this;
    }

    bool operator==(const Matrix& other1 ,const Matrix& other2)  {
        if(other1.get_row() != other2.get_row() || other1.get_col() != other2.get_col()) {
            throw runtime_error("this is not the same size");
        }
        for(unsigned long i = 0; i < other1.get_col()*other1.get_row(); i++) {
            if(other1._mat.at(i) != other2._mat.at(i)) {
                return false;
            }
        }
        return true;

    }

    Matrix Matrix::operator*(Matrix const &other) {
        vector<double> a;
        double x = 0;
        if (this->get_col() != other.get_row()) {
            throw runtime_error("matrix should have the same size");
        }

        for (unsigned long i = 0; i < this->get_row(); i++) {

            for (unsigned long j = 0; j < other.get_col(); j++) {

                 x = 0;
                for (unsigned long c = 0; c < other.get_row(); c++) {
                    x += this->_mat.at(i * (unsigned long) (this->get_col()) + c) *
                           other._mat.at(j + c * (unsigned long) (other.get_col()));
                }
                a.push_back(x);
            }
        }
        Matrix mat_ans{a, this->get_row(), other.get_col()};
        return mat_ans;

    }

    Matrix operator*(double const &other1, Matrix const &other2){
        vector<double> a;
        int x = other2.get_row() * other2.get_col();

        for (unsigned long i = 0; i < x; ++i) {
            a.push_back(other2._mat.at(i) * other1);
        }

        Matrix new_mat{a, other2.get_row(), other2.get_col()};
        return new_mat;
    }
    std::istream &operator>>(istream &input, Matrix &mat) {

        vector<double> a;
        int num_col =0;
        int num_row=0;
        unsigned long i = 0;
        double num= 0;
        string String_num;

        //get the input
        string s;
        getline(input,s);
        s+='\n';

        if(s[0]!='[' || s[s.length()-2]!=']' ||s.size() <=1){
            throw runtime_error("cheack your string ");
        }


        while(s[i]!='\n'){

            if(s[i]=='['){

                num_row=num_row+ 1;
            }
            else{

                if(isdigit(s[i])!=0){

                    while(isdigit(s[i])!=0  ){
                        String_num += s[i];
                        i++;
                    }
                    num=stod(String_num);
                    a.push_back(num);
                    num_col++;
                    String_num.clear();
                }
                String_num.clear();


                if(s[i]==']') {

                    if(i!= s.length()-2){
                        num_col=0;
                    }

                }

                if( (s[i]==' ' && s[i+1]==',') ||(s[i]==',' && s[i+1]!=' ') ||( (s[i]==']' && s[i+1]!=',') && (s[i]==']' && s[i+1]!='\n') )){
                    throw runtime_error("check your string");
                }
            }
            i++;
        }

        const int x =11;
        for (unsigned long j = 0; j < a.size(); ++j) {
            if(a[j]==x){
                throw runtime_error("not good");
            }
        }

        mat._mat = a;
        mat.set_row(num_row);
        mat.set_col(num_col) ;
        return input;

    }
    ostream &operator<<(ostream &ans, const Matrix &mat) {
        unsigned long i = 0;

        for ( i = 0; i < mat.get_row(); i++) {
            ans << '[';
            for (unsigned long j = 0; j < mat.get_col(); j++) {
                if(j==mat.get_col()-1){
                    ans << mat._mat.at((i * (unsigned long)mat.get_col()) + j) ;
                    ans << ']';
                } else{
                    ans <<mat._mat.at((i * (unsigned long)mat.get_row()) + j) << ' ';
                }
            }
            if(i!=mat.get_row()-1){ans << '\n'; }

        } return ans ;
    }



}


//      int main() {
//     vector<double> vec = {0,0};
//     vector<double> vec2 = {1,1};
//     Matrix mat1 = Matrix(vec,1,2);
//     Matrix mat2 = Matrix(vec2,1,2);
//     bool t = (mat1++) == mat2;
//
//     Matrix C =   mat2 -mat2;
//   // mat1+=mat2;
//   //bool t =mat1 >mat1;
//     int x  = C.get_row() * C.get_col();
//     for(int i = 0; i < x; i++) {
//         std::cout << C._mat.at(i) << endl;}
//  //std::cout << t << endl;
//     return 0;
//     }



