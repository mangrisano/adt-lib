
#ifndef MATRIXTEST_HPP
#define MATRIXTEST_HPP

#include "../../matrix/matrix.hpp"

/* ************************************************************************** */

template <typename Mat>
void EqualMatrix(unsigned int& testnum, unsigned int& testerr, const Mat& mat1, const Mat& mat2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two matrices are " << ((tst = (mat1 == mat2)) ? "" : "not ") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Mat>
void NonEqualMatrix(unsigned int& testnum, unsigned int& testerr, const Mat& mat1, const Mat& mat2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two matrices are " << ((tst = (mat1 != mat2)) ? "not " : "") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

template <typename Data>
void GetRowNumber(unsigned int& testnum, unsigned int& testerr, const lasd::Matrix<Data>& mat, bool chk, unsigned long rows) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The row number is \"" << mat.RowNumber() << "\": ";
    std::cout << ((tst = ((mat.RowNumber() == rows) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void SetRowNumber(unsigned int& testnum, unsigned int& testerr, lasd::Matrix<Data>& mat, bool chk, unsigned long rows) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Setting the row number to \"" << rows << "\": ";
    mat.RowResize(rows);
    std::cout << ((tst = ((mat.RowNumber() == rows) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void GetColumnNumber(unsigned int& testnum, unsigned int& testerr, const lasd::Matrix<Data>& mat, bool chk, unsigned long cols) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The column number is \"" << mat.ColumnNumber() << "\": ";
    std::cout << ((tst = ((mat.ColumnNumber() == cols) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void SetColumnNumber(unsigned int& testnum, unsigned int& testerr, lasd::Matrix<Data>& mat, bool chk, unsigned long cols) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Setting the column number to \"" << cols << "\": ";
    mat.ColumnResize(cols);
    std::cout << ((tst = ((mat.ColumnNumber() == cols) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void ExistsCell(unsigned int& testnum, unsigned int& testerr, const lasd::Matrix<Data>& mat, bool chk, unsigned long row, unsigned long col) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The cell (" << row << ", " << col << ") " << ((tst = mat.ExistsCell(row, col)) ? "does" : "does not") << " exist: ";
    std::cout << ((tst = (tst == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void GetCell(unsigned int& testnum, unsigned int& testerr, const lasd::Matrix<Data>& mat, bool chk, unsigned long row, unsigned long col, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Cell (" << row << ", " << col << ") with value \"" << mat(row, col) << "\": ";
    std::cout << ((tst = ((mat(row, col) == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::out_of_range exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void SetCell(unsigned int& testnum, unsigned int& testerr, lasd::Matrix<Data>& mat, bool chk, unsigned long row, unsigned long col, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Setting cell (" << row << ", " << col << ") to value \"" << val << "\": ";
    mat(row, col) = val;
    std::cout << ((tst = ((mat(row, col) == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::out_of_range exc) {
    std::cout << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

#endif
