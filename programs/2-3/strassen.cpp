#include <iostream>
using namespace std;

template <typename T>
struct matrix{
private:
    unsigned _size;
    T** _ptr;
public:
    inline unsigned size(){
        return _size;
    }

    T* operator [](unsigned x){
        return _ptr[x];
    }
    matrix(unsigned n){
        _size = n;
        _ptr = new T*[n];
        for (unsigned i=0; i<n; i++)
            _ptr[i] = new T[n];
    }

    ~matrix(){
        for (unsigned i=0; i<_size; i++){
            delete[] _ptr[i];
        }
        delete _ptr;
    }

    matrix<T>& zero(){
        for (unsigned i=0; i<_size; i++)
            for (unsigned j=0; j<_size; j++){
                _ptr[i][j] = 0;
            }
        return *this;
    }

    matrix<T>& operator += (matrix<T>& mat){
        if (_size != mat.size()){
            throw;
        }
        for (unsigned i=0; i < mat.size(); i++){
            for (unsigned j=0; j < mat.size(); j++){
                _ptr[i][j] += mat[i][j];
            }
        }
        return *this;
    }

    matrix<T>& operator -= (matrix<T>& mat){
        if (_size != mat.size()){
            throw;
        }
        for (unsigned i=0; i < mat.size(); i++){
            for (unsigned j=0; j < mat.size(); j++){
                _ptr[i][j] -= mat[i][j];
            }
        }
        return *this;
    }

    friend ostream& operator << (ostream& os, matrix<T>& mat){
        for (unsigned i=0; i < mat.size(); i++){
            for (unsigned j=0; j < mat.size(); j++){
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        return os;
    }
};

template <typename T>
void strassen(matrix<T>& A, matrix<T>& B, matrix<T>& ans){
    if (A.size() != B.size() || A.size() != ans.size()){
        throw;
    }
    if (A.size() == 1){
        ans[0][0] = A[0][0] * B[0][0];
        return;
    }
    if (A.size() % 2 != 0){
        throw;
    }
    unsigned n = A.size();
    matrix<T> a11(n/2), a12(n/2), a21(n/2), a22(n/2);

    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            a11[i][j] = A[i][j];
        }
    }
    for (int i=0; i<n/2; i++){
        for (int j=n/2; j<n; j++){
            a12[i][j-n/2] = A[i][j];
        }
    }

    for (int i=n/2; i<n; i++){
        for (int j=0; j<n/2; j++){
            a21[i-n/2][j] = A[i][j];
        }
    }

    for (int i=n/2; i<n; i++){
        for (int j=n/2; j<n; j++){
            a22[i-n/2][j-n/2] = A[i][j];
        }
    }

    matrix<T> b11(n/2), b12(n/2), b21(n/2), b22(n/2);

    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            b11[i][j] = B[i][j];
        }
    }

    for (int i=0; i<n/2; i++){
        for (int j=n/2; j<n; j++){
            b12[i][j-n/2] = B[i][j];
        }
    }

    for (int i=n/2; i<n; i++){
        for (int j=0; j<n/2; j++){
            b21[i-n/2][j] = B[i][j];
        }
    }

    for (int i=n/2; i<n; i++){
        for (int j=n/2; j<n; j++){
            b22[i-n/2][j-n/2] = B[i][j];
        }
    }

    matrix<T> s1(n/2), s2(n/2), s3(n/2), s4(n/2), s5(n/2), s6(n/2), s7(n/2), s8(n/2), s9(n/2), s10(n/2);
    (s1.zero()+=b12)-=b22;
    (s2.zero()+=a11)+=a12;
    (s3.zero()+=a21)+=a22;
    (s4.zero()+=b21)-=b11;
    (s5.zero()+=a11)+=a22;
    (s6.zero()+=b11)+=b22;
    (s7.zero()+=a12)-=a22;
    (s8.zero()+=b21)+=b22;
    (s9.zero()+=a11)-=a21;
    (s10.zero()+=b11)+=b12;

    matrix<T> p1(n/2), p2(n/2), p3(n/2), p4(n/2), p5(n/2), p6(n/2), p7(n/2);
    strassen(a11, s1, p1);
    strassen(s2, b22, p2);
    strassen(s3, b11, p3);
    strassen(a22, s4, p4);
    strassen(s5, s6, p5);
    strassen(s7, s8, p6);
    strassen(s9, s10, p7);

    matrix<T> c11(n/2), c12(n/2), c21(n/2), c22(n/2);
    (((c11.zero()+=p5)+=p4)-=p2)+=p6;
    (c12.zero()+=p1)+=p2;
    (c21.zero()+=p3)+=p4;
    (((c22.zero()+=p5)+=p1)-=p3)-=p7;

    for (int i=0; i<n/2; i++){
        for (int j=0; j<n/2; j++){
            ans[i][j] = c11[i][j];
        }
    }

    for (int i=0; i<n/2; i++){
        for (int j=n/2; j<n; j++){
            ans[i][j] = c12[i][j-n/2];
        }
    }

    for (int i=n/2; i<n; i++){
        for (int j=0; j<n/2; j++){
            ans[i][j] = c21[i-n/2][j];
        }
    }

    for (int i=n/2; i<n; i++){
        for (int j=n/2; j<n; j++){
            ans[i][j] = c22[i-n/2][j-n/2];
        }
    }
}
#include <cstdlib>
matrix<int> mat(4), mat2(4), mat3(4);
int main(){
    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            mat[i][j] = rand()%10, mat2[i][j] = rand()%10;

    cout << mat << mat2;
    strassen(mat, mat2, mat3);
    cout << mat3;
    return 0;
}
