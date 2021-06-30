
#include "zlasdtest/test.hpp"

#include "zmytest/test.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() 
{
  std::cout << "Lasd Libraries 2020" << std::endl;
	unsigned short kindoftest;	// 0 for Mogavero's Test, 1 for My Test
	MainMenu();
	std::cout << "What kind of test do you want to run? ";
	std::cin >> kindoftest;
	if (kindoftest == 0)
		lasdtest();
    else if (kindoftest == 1) {
		unsigned short choice; 		// Structure: 0 for Vector, 1 for Yale
		unsigned short typeofdata; 	// 0 for Integer, 1 for Double, 2 for String;
		unsigned short operation;
		unsigned long rows;
		unsigned long cols;

		bool quit = false;
		std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> dist_int(-1000, 1000);
		std::uniform_real_distribution<> dist_float(-1000, 1000);
		char letters[74] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q',
							'r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7',
							'8','9','A','B','C', 'D','E','F','G','H','I','J','K','L','M','N','O',
							'P','Q','R','S','T','U','V','W','X','Y','Z','&','!','?','@','$','%',
							'*','/','+','-','#','~'
							};
		std::uniform_int_distribution<int> dist_string(0, 73);
		std::cout << "What kind of structure do you want to use? [0 for Vector, 1 for Yale] ";
		std::cin >> choice;
		std::cout << "Give me the number of Rows and Cols you want to insert: ";
		std::cin >> rows >> cols;
		std::cout << "What kind of data do you want to use? [0 for Integer, 1 for Double, 2 for String] ";
		std::cin >> typeofdata;

		/* CSR */
		/* Int */
        MatrixCSR<int> matcsrInt(rows, cols);
		for(unsigned long i = 0; i < rows; i++) {
      		for(unsigned long j = 0; j < cols; j++) {
          		matcsrInt(i, j) = dist_int(generator);
      		}
  		}

		/* Float */
        MatrixCSR<float> matcsrFloat(rows, cols);
		for(unsigned long i = 0; i < rows; i++) {
      		for(unsigned long j = 0; j < cols; j++) {
          		matcsrFloat(i, j) = dist_float(generator);
      		}
  		}

		/* String */
        MatrixCSR<std::string> matcsrString(rows, cols);
		for (unsigned long i = 0; i < rows; i++) {
			for (unsigned long j = 0; j < cols; j++) {
				std::string temp = "";
				for (unsigned long s = 0; s < dist_string(generator); s++) {
					temp += letters[dist_string(generator)];
				}
				matcsrString(i, j) = temp;
			}
		}

		/* Vector */
		/* Int */
        MatrixVec<int> matvecInt(rows, cols);
		for(unsigned long i = 0; i < rows; i++) {
      		for(unsigned long j = 0; j < cols; j++) {
          		matvecInt(i, j) = dist_int(generator);
      		}
  		}
		
		/* Float */
        MatrixVec<float> matvecFloat(rows, cols);
		for(unsigned long i = 0; i < rows; i++) {
      		for(unsigned long j = 0; j < cols; j++) {
          		matvecInt(i, j) = dist_float(generator);
      		}
  		}

		/* String */
        MatrixVec<std::string> matvecString(rows, cols);
		for (unsigned long i = 0; i < rows; i++) {
			for (unsigned long j = 0; j < cols; j++) {
				std::string temp = "";
				for (unsigned long s = 0; s < dist_string(generator); s++) {
					temp += letters[dist_string(generator)];
				}
				matvecString(i, j) = temp;
			}
		}

		while (!quit) {
			switch (choice) {
				case 0: {
					if (typeofdata == 0) {
						OperationMenuMatrixInt();
						std::cin >> operation;
						if (operation == 0) {
							unsigned short view;
							ChooseTheView();
							std::cin >> view;
							if (view == 0) {
								std::cout << "Pre Order Traversal..." << std::endl;
								matvecInt.MapPreOrder(&PrintData<int>, nullptr);
							}
							if (view == 1) {
								std::cout << "Post Order Traversal..." << std::endl;
								matvecInt.MapPostOrder(&PrintData<int>, nullptr);
							}
							
						}
						if (operation == 1) {
							int value;
							bool exists = false;
							std::cout << "Checking if a value exists..." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							exists = matvecInt.Exists(value);
							if (exists)
								std::cout << "The value " << value << " exists!" << std::endl;
							else
								std::cout << "The value " << value << "doesnt't exists" << std::endl;
						}
						if (operation == 2) {
							int value;
							int result = 1;
							std::cout << "Multiply all values less than a given integer." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							matvecInt.FoldPreOrder(&MultiplyLessThan, &value, &result);
							std::cout << "The result is: " << result << std::endl;
						}
						if (operation == 3) {
							std::cout << "Double all the values..." << std::endl;
							matvecInt.MapPreOrder(&DoubleN, nullptr);
						}
						if (operation == 4) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::cout << "Give me the row and col you want to read: ";
							std::cin >> row >> col;
							std::cout << "Reading the cell..." << std::endl;
							try {
								std::cout << "The value is: " << matvecInt(row, col) << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 5) {
							unsigned long row = 0;
							unsigned long col = 0;
							int value;
							std::cout << "Give me the row and col you want to insert: ";
							std::cin >> row >> col;
							std::cout << "Give me the value you want to put in: ";
							std::cin >> value;
							std::cout << "Writing in the cell..." << std::endl;	
							try {
								matvecInt(row, col) = value;
								std::cout << "The value inserted!" << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 6) {
							unsigned short res = 0;
							unsigned long newsize;
							std::cout << "0 -> Resize rows." << std::endl;
							std::cout << "1 -> Resize cols." << std::endl;
							std::cout << "What do you want to resize: ";
							std::cin >> res;
							std::cout << "Give me the new size: ";
							std::cin >> newsize;
							if (res == 0) {
								try {
									matvecInt.RowResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}
							if (res == 1) {
								try {
									matvecInt.ColumnResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}

						}
						if (operation == 9) {
							std::cout << "Logging out... " << "\n";
							quit = true;
						}
					}
					if (typeofdata == 1) {
						OperationMenuMatrixFloat();
						std::cin >> operation;
						if (operation == 0) {
							unsigned short view;
							ChooseTheView();
							std::cin >> view;
							if (view == 0) {
								std::cout << "Pre Order Traversal..." << std::endl;
								matvecFloat.MapPreOrder(&PrintData<float>, nullptr);
							}
							if (view == 1) {
								std::cout << "Post Order Traversal..." << std::endl;
								matvecFloat.MapPostOrder(&PrintData<float>, nullptr);
							}
							
						}
						if (operation == 1) {
							float value;
							bool exists = false;
							std::cout << "Checking if a value exists..." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							exists = matvecFloat.Exists(value);
							if (exists)
								std::cout << "The value " << value << " exists!" << std::endl;
							else
								std::cout << "The value " << value << "doesnt't exists" << std::endl;
						}
						if (operation == 2) {
							float value;
							int result = 1;
							std::cout << "Sum all values greater than a given value." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							matvecFloat.FoldPreOrder(&SumFloatGreatherThan, &value, &result);
							std::cout << "The result is: " << result << std::endl;
						}
						if (operation == 3) {
							std::cout << "Cube of a negative number..." << std::endl;
							matvecFloat.MapPreOrder(&CubeNegativeN, nullptr);
						}
						if (operation == 4) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::cout << "Give me the row and col you want to read: ";
							std::cin >> row >> col;
							std::cout << "Reading the cell..." << std::endl;
							try {
								std::cout << "The value is: " << matvecFloat(row, col) << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 5) {
							unsigned long row = 0;
							unsigned long col = 0;
							float value;
							std::cout << "Give me the row and col you want to insert: ";
							std::cin >> row >> col;
							std::cout << "Give me the value you want to put in: ";
							std::cin >> value;
							std::cout << "Writing in the cell..." << std::endl;	
							try {
								matvecFloat(row, col) = value;
								std::cout << "The value inserted!" << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 6) {
							unsigned short res = 0;
							unsigned long newsize;
							std::cout << "0 -> Resize rows." << std::endl;
							std::cout << "1 -> Resize cols." << std::endl;
							std::cout << "What do you want to resize: ";
							std::cin >> res;
							std::cout << "Give me the new size: ";
							std::cin >> newsize;
							if (res == 0) {
								try {
									matvecFloat.RowResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}
							if (res == 1) {
								try {
									matvecFloat.ColumnResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}

						}
						if (operation == 9) {
							std::cout << "Logging out... " << "\n";
							quit = true;
						}
					}
					if (typeofdata == 2) {
						OperationMenuMatrixString();
						std::cin >> operation;
						if (operation == 0) {
							unsigned short view;
							ChooseTheView();
							std::cin >> view;
							if (view == 0) {
								std::cout << "Pre Order Traversal..." << std::endl;
								matvecString.MapPreOrder(&PrintData<std::string>, nullptr);
							}
							if (view == 1) {
								std::cout << "Post Order Traversal..." << std::endl;
								matvecString.MapPostOrder(&PrintData<std::string>, nullptr);
							}
							
						}
						if (operation == 1) {
							std::string value;
							bool exists = false;
							std::cout << "Checking if a value exists..." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							exists = matvecString.Exists(value);
							if (exists)
								std::cout << "The value " << value << " exists!" << std::endl;
							else
								std::cout << "The value " << value << "doesnt't exists" << std::endl;
						}
						if (operation == 2) {
							int value;
							int result = 1;
							std::cout << "Concantenate all values with lenght less than a given number." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							matvecString.FoldPreOrder(&ConcatenationLessEqualThan, &value, &result);
							std::cout << "The result is: " << result << std::endl;
						}
						if (operation == 3) {
							std::string value;
							std::cout << "Concantenate at top..." << std::endl;
							std::cout << "Give me the value: ";
							std::cin >> value;
							matvecString.MapPreOrder(&ConcatenateAtTop, &value);
						}
						if (operation == 4) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::cout << "Give me the row and col you want to read: ";
							std::cin >> row >> col;
							std::cout << "Reading the cell..." << std::endl;
							try {
								std::cout << "The value is: " << matvecString(row, col) << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 5) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::string value;
							std::cout << "Give me the row and col you want to insert: ";
							std::cin >> row >> col;
							std::cout << "Give me the value you want to put in: ";
							std::cin >> value;
							std::cout << "Writing in the cell..." << std::endl;	
							try {
								matvecString(row, col) = value;
								std::cout << "The value inserted!" << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
						}
						if (operation == 6) {
							unsigned short res = 0;
							unsigned long newsize;
							std::cout << "0 -> Resize rows." << std::endl;
							std::cout << "1 -> Resize cols." << std::endl;
							std::cout << "What do you want to resize: ";
							std::cin >> res;
							std::cout << "Give me the new size: ";
							std::cin >> newsize;
							if (res == 0) {
								try {
									matvecString.RowResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}
							if (res == 1) {
								try {
									matvecString.ColumnResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}

						}
						if (operation == 9) {
							std::cout << "Logging out... " << "\n";
							quit = true;
						}
					}					
				break;
				}
				case 1: {
					if (typeofdata == 0) {
						OperationMenuMatrixInt();
						std::cin >> operation;
						if (operation == 0) {
							unsigned short view;
							ChooseTheView();
							std::cin >> view;
							if (view == 0) {
								std::cout << "Pre Order Traversal..." << std::endl;
								matcsrInt.MapPreOrder(&PrintData<int>, nullptr);
							}
							if (view == 1) {
								std::cout << "Post Order Traversal..." << std::endl;
								matcsrInt.MapPostOrder(&PrintData<int>, nullptr);
							}
							
						}
						if (operation == 1) {
							int value;
							bool exists = false;
							std::cout << "Checking if a value exists..." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							exists = matcsrInt.Exists(value);
							if (exists)
								std::cout << "The value " << value << " exists!" << std::endl;
							else
								std::cout << "The value " << value << "doesnt't exists" << std::endl;
						}
						if (operation == 2) {
							int value;
							int result = 1;
							std::cout << "Multiply all values less than a given integer." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							matcsrInt.FoldPreOrder(&MultiplyLessThan, &value, &result);
							std::cout << "The result is: " << result << std::endl;
						}
						if (operation == 3) {
							std::cout << "Double all the values..." << std::endl;
							matcsrInt.MapPreOrder(&DoubleN, nullptr);
						}
						if (operation == 4) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::cout << "Give me the row and col you want to read: ";
							std::cin >> row >> col;
							std::cout << "Reading the cell..." << std::endl;
							try {
								std::cout << "The value is: " << matcsrInt(row, col) << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 5) {
							unsigned long row = 0;
							unsigned long col = 0;
							int value;
							std::cout << "Give me the row and col you want to insert: ";
							std::cin >> row >> col;
							std::cout << "Give me the value you want to put in: ";
							std::cin >> value;
							std::cout << "Writing in the cell..." << std::endl;	
							try {
								matcsrInt(row, col) = value;
								std::cout << "The value inserted!" << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 6) {
							unsigned short res = 0;
							unsigned long newsize;
							std::cout << "0 -> Resize rows." << std::endl;
							std::cout << "1 -> Resize cols." << std::endl;
							std::cout << "What do you want to resize: ";
							std::cin >> res;
							std::cout << "Give me the new size: ";
							std::cin >> newsize;
							if (res == 0) {
								try {
									matcsrInt.RowResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}
							if (res == 1) {
								try {
									matcsrInt.ColumnResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}

						}
						if (operation == 9) {
							std::cout << "Logging out... " << "\n";
							quit = true;
						}
					}
					if (typeofdata == 1) {
						OperationMenuMatrixFloat();
						std::cin >> operation;
						if (operation == 0) {
							unsigned short view;
							ChooseTheView();
							std::cin >> view;
							if (view == 0) {
								std::cout << "Pre Order Traversal..." << std::endl;
								matcsrFloat.MapPreOrder(&PrintData<float>, nullptr);
							}
							if (view == 1) {
								std::cout << "Post Order Traversal..." << std::endl;
								matcsrFloat.MapPostOrder(&PrintData<float>, nullptr);
							}
							
						}
						if (operation == 1) {
							float value;
							bool exists = false;
							std::cout << "Checking if a value exists..." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							exists = matcsrFloat.Exists(value);
							if (exists)
								std::cout << "The value " << value << " exists!" << std::endl;
							else
								std::cout << "The value " << value << "doesnt't exists" << std::endl;
						}
						if (operation == 2) {
							float value;
							int result = 1;
							std::cout << "Sum all values greater than a given value." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							matcsrFloat.FoldPreOrder(&SumFloatGreatherThan, &value, &result);
							std::cout << "The result is: " << result << std::endl;
						}
						if (operation == 3) {
							std::cout << "Cube of a negative number..." << std::endl;
							matcsrFloat.MapPreOrder(&CubeNegativeN, nullptr);
						}
						if (operation == 4) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::cout << "Give me the row and col you want to read: ";
							std::cin >> row >> col;
							std::cout << "Reading the cell..." << std::endl;
							try {
								std::cout << "The value is: " << matcsrFloat(row, col) << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 5) {
							unsigned long row = 0;
							unsigned long col = 0;
							float value;
							std::cout << "Give me the row and col you want to insert: ";
							std::cin >> row >> col;
							std::cout << "Give me the value you want to put in: ";
							std::cin >> value;
							std::cout << "Writing in the cell..." << std::endl;	
							try {
								matcsrFloat(row, col) = value;
								std::cout << "The value inserted!" << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 6) {
							unsigned short res = 0;
							unsigned long newsize;
							std::cout << "0 -> Resize rows." << std::endl;
							std::cout << "1 -> Resize cols." << std::endl;
							std::cout << "What do you want to resize: ";
							std::cin >> res;
							std::cout << "Give me the new size: ";
							std::cin >> newsize;
							if (res == 0) {
								try {
									matcsrFloat.RowResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}
							if (res == 1) {
								try {
									matcsrFloat.ColumnResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}

						}
						if (operation == 9) {
							std::cout << "Logging out... " << "\n";
							quit = true;
						}
					}
					if (typeofdata == 2) {
						OperationMenuMatrixString();
						std::cin >> operation;
						if (operation == 0) {
							unsigned short view;
							ChooseTheView();
							std::cin >> view;
							if (view == 0) {
								std::cout << "Pre Order Traversal..." << std::endl;
								matcsrString.MapPreOrder(&PrintData<std::string>, nullptr);
							}
							if (view == 1) {
								std::cout << "Post Order Traversal..." << std::endl;
								matcsrString.MapPostOrder(&PrintData<std::string>, nullptr);
							}
							
						}
						if (operation == 1) {
							std::string value;
							bool exists = false;
							std::cout << "Checking if a value exists..." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							exists = matcsrString.Exists(value);
							if (exists)
								std::cout << "The value " << value << " exists!" << std::endl;
							else
								std::cout << "The value " << value << "doesnt't exists" << std::endl;
						}
						if (operation == 2) {
							int value;
							int result = 1;
							std::cout << "Concantenate all values with lenght less than a given number." << std::endl;
							std::cout << "Give me a value: ";
							std::cin >> value;
							matcsrString.FoldPreOrder(&ConcatenationLessEqualThan, &value, &result);
							std::cout << "The result is: " << result << std::endl;
						}
						if (operation == 3) {
							std::string value;
							std::cout << "Concantenate at top..." << std::endl;
							std::cout << "Give me the value: ";
							std::cin >> value;
							matcsrString.MapPreOrder(&ConcatenateAtTop, &value);
						}
						if (operation == 4) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::cout << "Give me the row and col you want to read: ";
							std::cin >> row >> col;
							std::cout << "Reading the cell..." << std::endl;
							try {
								std::cout << "The value is: " << matcsrString(row, col) << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							}
							
						}
						if (operation == 5) {
							unsigned long row = 0;
							unsigned long col = 0;
							std::string value;
							std::cout << "Give me the row and col you want to insert: ";
							std::cin >> row >> col;
							std::cout << "Give me the value you want to put in: ";
							std::cin >> value;
							std::cout << "Writing in the cell..." << std::endl;	
							try {
								matcsrString(row, col) = value;
								std::cout << "The value inserted!" << std::endl;
							}
							catch (...) {
								std::cout << "The cell doesn't exists!" << std::endl;
							
						}
						if (operation == 6) {
							unsigned short res = 0;
							unsigned long newsize;
							std::cout << "0 -> Resize rows." << std::endl;
							std::cout << "1 -> Resize cols." << std::endl;
							std::cout << "What do you want to resize: ";
							std::cin >> res;
							std::cout << "Give me the new size: ";
							std::cin >> newsize;
							if (res == 0) {
								try {
									matcsrString.RowResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}
							if (res == 1) {
								try {
									matcsrString.ColumnResize(newsize);
									std::cout << "The operation is completed!" << std::endl;
								}
								catch (...) {
									std::cout << "Resizing failed!" << std::endl;
								}
							}

						}
						if (operation == 9) {
							std::cout << "Logging out... " << "\n";
							quit = true;
						}
					}	
				}
				break;
				}
			}
		}
	}
	else {
		std::cout << "Logging out... " << "\n";
		return 0;
	}
	
	return 0;
}
	
