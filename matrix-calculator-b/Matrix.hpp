#include <iostream>
#include <ostream>
#include <string>
#include <stdexcept>
#include <vector>

using namespace std;
namespace zich {

    class Matrix {


        int _row;
        int _col;

    public:
        vector<double> _mat;
        int get_row  () const{ return this ->_row ;}
        int get_col () const { return this ->_col ;}
        void set_row(int row) {
            if(row <=0){
                throw runtime_error("need positive value");
            }
            this ->_row = row;}
        void set_col(int col) {
            if(col <=0){
                throw runtime_error("need positive value");
            }
            this ->_col = col;}


        Matrix(const vector<double> &_mat, int _row , int _col);

        ~Matrix();

        Matrix operator+(Matrix const &other) const ;

        Matrix & operator+=( Matrix const &other) ;

        Matrix& operator+();

        Matrix operator-(Matrix const &other) const ;

        Matrix & operator-=(const Matrix& other)  ;

        Matrix& operator-();

        bool operator>(const  Matrix& other) const  ;

        bool operator>=(const Matrix& other) const ;

        bool operator<( const Matrix& other) const;

        bool operator<=(const Matrix& other) const ;


        bool operator!=( const Matrix& other) const ;

        Matrix operator++(int) ;

        Matrix &operator++() ;

        Matrix &  operator--() ;

        Matrix operator--(int) ;

        Matrix operator*(double temp);

        Matrix& operator*=(double temp);

        Matrix operator*(Matrix const &other);

        Matrix operator*=( Matrix const &other) ;

        friend bool operator==(const Matrix& other1 ,const Matrix& other2) ;

        friend std::ostream &operator<<(std::ostream &ans, const Matrix  &mat);

        friend Matrix operator*(double const &other1,  const Matrix &other2);

        friend std::istream &operator>>(istream &input, Matrix &mat);

    };
}