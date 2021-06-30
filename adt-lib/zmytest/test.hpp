
#ifndef MYTEST_HPP
#define MYTEST_HPP

#include <iostream>
#include <string>
#include <random>
#include <stdexcept>

#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../matrix/csr/matrixcsr.hpp"
#include "../matrix/vec/matrixvec.hpp"


using namespace lasd;

/* ************************************************************************** */

void MainMenu();
void OperationMenuMatrixInt();
void OperationMenuMatrixFloat();
void OperationMenuMatrixString();
void ChooseTheView();
void MultiplyLessThan(const int&, const void*, void*);
void DoubleN(int&, void*);
void SumFloatGreatherThan(const float&, const void*, void*);
void CubeNegativeN(float&, void*);
void ConcatenationLessEqualThan(const std::string&, const void*, void*);
void ConcatenateAtTop(std::string&, void*);

template<typename Data>
void PrintData(Data&, void*);
/* ************************************************************************** */


#endif
