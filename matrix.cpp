#include <iostream>
using namespace std;

template <class T>
class Matrix
{
    int rows, cols;
    T** data;

    void createData();
    void deleteData();
    void createData(int m, int n)
    {
        rows = m;
        cols = n;
        createData();
    }
public:
    ~Matrix()
    {
        deleteData();
    }
    Matrix() : data(0) { }
    Matrix(int m, int n = 0)
    {
        createData(m, n != 0? n : m);
    }
    Matrix(int m, int n, const T *A)
    {
        createData(m, n);
        *this = A;
    }
    Matrix(const Matrix& A)
    {
        data = 0;
        *this = A;
    }
public:
    T & operator()(int i, int j)
    {
        return data[i][j];
    }

    int GetRows() const
    {
        return rows;
    }
    int GetColumns() const
    {
        return cols;
    }

public:
    Matrix& operator=(const T*);
    Matrix& operator=(const Matrix&);
};

template <class T>
Matrix<T>& Matrix<T>::operator=(const T* A)
{
    for (int i = 0, k = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            data[i][j] = A[k++];
        }
    }
    return *this;
}

template <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& A)
{
    deleteData();
    createData(A.rows, A.cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            data[i][j] = A.data[i][j];
    }
    return *this;
}

template <class T>
void Matrix<T>::createData()
{
    data = new T*[rows];
    for (int i = 0; i < rows; i++)
        data[i] = new T[cols];
}

template <class T>
void Matrix<T>::deleteData()
{
    if (data)
    {
        for (int i = 0; i < rows; i++)
            delete[] data[i];
        delete[] data;
    }
}

template <class T>
ostream &operator<<(ostream &left, Matrix<T> &A)
{
    for (int i = 0; i < A.GetRows(); i++)
    {
        for (int j = 0; j < A.GetColumns(); j++)
            left << A(i, j) << '\t';
        left << endl;
    }
    return left;
}

int main()
{
    int m[] = { 4, 2, 3, 0 };
    Matrix<int> A(2);
    A = m;

    Matrix<int> B;
    cout << (B = A) << endl;
    system("pause");

    return 0;
}
