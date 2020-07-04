#include <iostream>
#include <iomanip>

using namespace std;

int x, y;

class Matrix {
public:
	Matrix(int x, int y);
	Matrix(const Matrix& T);
	friend Matrix operator +(Matrix&, Matrix&);
	friend Matrix operator -(Matrix&, Matrix&);
	friend Matrix operator *(Matrix&, Matrix&);
	friend Matrix operator /(Matrix&, Matrix&);
	const Matrix& operator = (const Matrix& T);
	void input();
	void display();
	~Matrix();
private:
	int m;
	int n;
	double** a;
};

Matrix::Matrix(int x, int y)
{
	m = x;
	n = y;
	a = new double* [x];
	for (int i = 0; i < x; i++) {
		a[i] = new double[y];
	}
}

Matrix::Matrix(const Matrix& T)
{
	m = T.m;
	n = T.n;
	a = new double* [x];
	for (int i = 0; i < x; ++i) {
		a[i] = new double[y];
		for (int j = 0; j < y; ++j) {
			a[i][j] = T.a[i][j];
		}
	}
}

const Matrix& Matrix::operator = (const Matrix& T)
{
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			a[i][j] = T.a[i][j];
		}
	}
	return (*this);
}

void Matrix::input()
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
}

void Matrix::display()
{
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << setw(4) << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Matrix operator +(Matrix& A, Matrix& B)
{
	Matrix temp(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			temp.a[i][j] = A.a[i][j] + B.a[i][j];
		}
	}
	return temp;
}

Matrix operator -(Matrix& A, Matrix& B)
{
	Matrix temp(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			temp.a[i][j] = A.a[i][j] - B.a[i][j];
		}
	}
	return temp;
}

Matrix operator *(Matrix& A, Matrix& B)
{
	Matrix temp(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			temp.a[i][j] = A.a[i][j] * B.a[i][j];
		}
	}
	return temp;
}

Matrix operator /(Matrix& A, Matrix& B)
{
	Matrix temp(x, y);
	for (int i = 0; i < x; ++i) {
		for (int j = 0; j < y; ++j) {
			temp.a[i][j] = A.a[i][j] / B.a[i][j];
		}
	}
	return temp;
}

Matrix::~Matrix()
{
	for (int i = 0; i < m; i++)
	{
		delete[] a[i];
		a[i] = NULL;
	}
	delete[] a;
	a = NULL;
}

int main()
{
	cout << "ÇëÊäÈë¾ØÕóÎ¬¶È" << endl;
	cin >> x >> y;
	cout << "ÇëÊäÈë¾ØÕóAÔªËØ" << endl;
 	Matrix M1(x, y);
	M1.input();
	M1.display();
	cout << "ÇëÊäÈë¾ØÕóBÔªËØ" << endl;
	Matrix M2(x, y);
	M2.input();
	M2.display();
	Matrix M3(x, y);
	M3 = M1 + M2;
	cout << "Matrix C = Matrix A + Matrix B :" << endl;
	M3.display();
	M3 = M1 - M2;
	cout << "Matrix C = Matrix A - Matrix B :" << endl;
	M3.display();
	M3 = M1 * M2;
	cout << "Matrix C = Matrix A .* Matrix B :" << endl;
	M3.display();
	M3 = M1 / M2;
	cout << "Matrix C = Matrix A ./ Matrix B :" << endl;
	M3.display();
	return 0;
}