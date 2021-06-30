
#ifndef BSTTEST_HPP
#define BSTTEST_HPP

#include "../../bst/bst.hpp"

/* ************************************************************************** */

template <typename Data>
void EqualBST(unsigned int& testnum, unsigned int& testerr, const lasd::BST<Data>& bst1, const lasd::BST<Data>& bst2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two bsts are " << ((tst = (bst1 == bst2)) ? "" : "not ") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void NonEqualBST(unsigned int& testnum, unsigned int& testerr, const lasd::BST<Data>& bst1, const lasd::BST<Data>& bst2) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") The two bsts are " << ((tst = (bst1 != bst2)) ? "not " : "") << "equal: ";
    std::cout << (tst ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

template <typename Data>
void InsertC(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, const Data& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Insertion in the bst of the value \"" << val << "\": ";
    bst.Insert(val);
    std::cout << "Correct!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void InsertM(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, const Data& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Insertion in the bst of the value \"" << val << "\": ";
    bst.Insert(std::move(val));
    std::cout << "Correct!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Remove(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, const Data& val) {
  testnum++;
  bool tst = true;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Removal from the bst of the value \"" << val << "\": ";
    bst.Remove(val);
    std::cout << "Correct!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << "\"" << exc.what() << "\": " << "Error!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Min(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Min of the bst with value \"" << bst.Min() << "\": ";
    std::cout << ((tst = ((bst.Min() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void RemoveMin(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove min from the the bst: ";
    bst.RemoveMin();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void MinNRemove(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") MinNRemove from the bst with value \"" << bst.Min() << "\": ";
    std::cout << ((tst = ((bst.MinNRemove() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Max(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Max of the bst with value \"" << bst.Max() << "\": ";
    std::cout << ((tst = ((bst.Max() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void RemoveMax(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove max from the the bst: ";
    bst.RemoveMax();
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void MaxNRemove(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") MaxNRemove from the bst with value \"" << bst.Max() << "\": ";
    std::cout << ((tst = ((bst.MaxNRemove() == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Predecessor(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& prd, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Predecessor of " << prd << " with value \"" << bst.Predecessor(prd) << "\": ";
    std::cout << ((tst = ((bst.Predecessor(prd) == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void RemovePredecessor(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& prd) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove predecessor of " << prd << " from the the bst: \"" << bst.Predecessor(prd) << "\": ";
    bst.RemovePredecessor(prd);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void PredecessorNRemove(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& prd, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove predecessor of " << prd << " from the the bst: \"" << bst.Predecessor(prd) << "\": ";
    std::cout << ((tst = ((bst.PredecessorNRemove(prd) == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void Successor(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& prd, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Successor of " << prd << " with value \"" << bst.Successor(prd) << "\": ";
    std::cout << ((tst = ((bst.Successor(prd) == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void RemoveSuccessor(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& prd) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove successor of " << prd << " from the the bst: \"" << bst.Successor(prd) << "\": ";
    bst.RemoveSuccessor(prd);
    std::cout << ((tst = chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

template <typename Data>
void SuccessorNRemove(unsigned int& testnum, unsigned int& testerr, lasd::BST<Data>& bst, bool chk, const Data& prd, const Data& val) {
  bool tst;
  testnum++;
  try {
    std::cout << " " << testnum << " (" << testerr << ") Remove successor of " << prd << " from the the bst: \"" << bst.Successor(prd) << "\": ";
    std::cout << ((tst = ((bst.SuccessorNRemove(prd) == val) == chk)) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::length_error exc) {
    std::cout << "\"" << exc.what() << "\": " << ((tst = !chk) ? "Correct" : "Error") << "!" << std::endl;
  } catch(std::exception exc) {
    tst = false;
    std::cout << std::endl << "Wrong exception: " << exc.what() << "!" << std::endl;
  }
  testerr += (1 - (unsigned int) tst);
}

/* ************************************************************************** */

#endif
