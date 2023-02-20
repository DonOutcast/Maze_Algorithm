#ifndef MATRIX_H
#define MATRIX_H

#include <cmath>
#include <utility>
#include <stdexcept>

namespace s21 {

template<class T>
class Matrix final {

public:
  Matrix();
  Matrix(int rows, int cols);
  Matrix(const Matrix& other);
  Matrix(Matrix&& other) noexcept;
  ~Matrix();
  auto operator=(const Matrix& other) -> Matrix&;

public:
  auto sum_matrix(const Matrix& other) -> void;
  auto sub_matrix(const Matrix& other) -> void;
  auto mul_number(double num) -> void;
  auto mul_matrix(const Matrix& other) -> void;
  [[nodiscard]] auto eq_matrix(const Matrix& other) const -> bool;
  [[nodiscard]] auto transpose() const -> Matrix;
  [[nodiscard]] auto calc_complements() const -> Matrix;
  [[nodiscard]] auto determinant() const  -> double;
  [[nodiscard]] auto inverse_matrix() const -> Matrix;
  auto resize(int rows, int cols) -> void;
  auto clear() -> void;
  auto fill(const T& value) -> void;

public:
  [[nodiscard]] auto rows() const -> int;
  [[nodiscard]] auto cols() const -> int;
  auto operator()(int i, int j) -> T&;

  template<T> friend auto operator+(const Matrix<T>& lhs, const Matrix<T>& rhs) -> Matrix<T>;
  template<T> friend auto operator-(const Matrix<T>& lhs, const Matrix<T>& rhs) -> Matrix<T>;
  template<T> friend auto operator*(const Matrix<T>& lhs, const Matrix<T>& rhs) -> Matrix<T>;
  template<T> friend auto operator*(const Matrix<T>& lhs, double rhs) -> Matrix<T>;
  template<T> friend auto operator*(double lhs, const Matrix<T>& rhs) -> Matrix<T>;
  template<T> friend auto operator==(const Matrix<T>& lhs, const Matrix<T>& rhs) -> bool;
  template<T> friend auto operator+=(Matrix<T>& lhs, const Matrix<T>& rhs) -> void;
  template<T> friend auto operator-=(Matrix<T>& lhs, const Matrix<T>& rhs) -> void;
  template<T> friend auto operator*=(Matrix<T>& lhs, const Matrix<T>& rhs) -> void;
  template<T> friend auto operator*=(Matrix<T>& lhs, double rhs) -> void;

private:
  auto newMatrixWithoutRowAndCol(const Matrix& other, int row, int col) -> void;
  auto memoryFree() -> void;

private:
    static constexpr int standardSize = 3;

private:
    int m_rows   {};
    int m_cols   {};
    T** m_matrix {};

};

} // s21

#include "matrix.cc"

#endif  // MATRIX_H
