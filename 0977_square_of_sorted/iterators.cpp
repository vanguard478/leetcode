#include<iostream>
#include<vector>

int main(){
  std::vector<int> vec = {9,2,4,5,6,7};
  auto itr =vec.begin();

  // Get the address being pointed to by the iterator
  int* address = &(*itr);

  std::cout << "Value: " << *itr << std::endl;
  std::cout << "Address: " << address << std::endl;
auto left = vec.begin();
auto right = prev(vec.end());
  while(left<=right){
    std::cout<<" "<<*left;
    left++;
  }
  std::cout<<std::endl;
}