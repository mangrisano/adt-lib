#include "../zlasdtest/test.hpp"
#include "test.hpp"

void MainMenu()
{
	std::cout << "\n";
  	std::cout << "------------MAIN MENU-------------" << std::endl;
  	std::cout << "- Press 0 to choose Mogavero's Test" << std::endl;
  	std::cout << "- Press 1 to choose Student's Test" << std::endl;
  	std::cout << "- Press 2 to exit" << std::endl;
}

void OperationMenuMatrixInt()
{
 	std::cout << "What kind of operation do you want to do?" << std::endl;
	std::cout << "0 -> Show the Tree in: PreOrder, PostOrder." << std::endl;
	std::cout << "1 -> Check if a value exists." << std::endl;
	std::cout << "2 -> Multiply all values less than a given integer." << std::endl;
	std::cout << "3 -> Double all the values." << std::endl;
	std::cout << "4 -> Read the cell." << std::endl;
	std::cout << "5 -> Write in the cell." << std::endl;
	std::cout << "6 -> Resize the matrix." << std::endl;
	std::cout << "9 -> EXIT!" << "\n";
}

void OperationMenuMatrixFloat()
{
 	std::cout << "What kind of operation do you want to do?" << std::endl;
	std::cout << "0 -> Show the Tree in: PreOrder, PostOrder." << std::endl;
	std::cout << "1 -> Check if a value exists." << std::endl;
	std::cout << "2 -> Sum all values greater than a given number." << std::endl;
	std::cout << "3 -> (-n)^3 all the values." << std::endl;
	std::cout << "4 -> Read the cell." << std::endl;
	std::cout << "5 -> Write in the cell." << std::endl;
	std::cout << "6 -> Resize the matrix." << std::endl;
	std::cout << "9 -> EXIT!" << "\n";
}

void OperationMenuMatrixString()
{
 	std::cout << "What kind of operation do you want to do?" << std::endl;
	std::cout << "0 -> Show the Tree in: PreOrder, PostOrder." << std::endl;
	std::cout << "1 -> Check if a value exists." << std::endl;
	std::cout << "2 -> Concantenate all values with lenght less than a given number." << std::endl;
	std::cout << "2 -> Concantenate at top." << std::endl;
	std::cout << "4 -> Read the cell." << std::endl;
	std::cout << "5 -> Write in the cell." << std::endl;
	std::cout << "6 -> Resize the matrix." << std::endl;
	std::cout << "9 -> EXIT!" << "\n";
}

void ChooseTheView() 
{
 	std::cout << "What kind of visit do you want to do?" << std::endl;
	std::cout << "0 -> PreOrder." << std::endl;
	std::cout << "1 -> PostOrder." << std::endl;

}

void MultiplyLessThan(const int& value, const void* par, void* acc) 
{ 
    if (value < *((int*) par)) {
        *((int*) acc) *= value;
    }
}

void DoubleN(int& value, void* par)
{
	value = 2 * value;
}

void SumFloatGreatherThan(const float& value, const void* par, void* acc) 
{
	if (value > *((float*) par)) {
		*((float*) acc) += value;
	}
}

void CubeNegativeN(float& value, void* par)
{
	value = -(value * value * value);
}

void ConcatenationLessEqualThan(const std::string& string, const void* par, void* acc) 
{
    if (string.length() <= *((int*) par)) {
        *((std::string*) acc) += string;
    }
}

void ConcatenateAtTop(std::string& st, void* par) {
	std::string top = *((std::string*) par);
	st = top + st;
}

template<typename Data>
void PrintData(Data& value, void* par) {
    std::cout << "[ " << value << " ] ";
}

template<>
void PrintData(int& value, void* param) {
    if (param == nullptr) {
        std::cout << value << "\n";
    }
}

template<>
void PrintData(float& value, void* param) {
    if (param == nullptr) {
        std::cout << value << "\n";
    }
}

template<>
void PrintData(std::string& value, void* param) {
    if (param == nullptr) {
        std::cout << value << "\n";
    }
}