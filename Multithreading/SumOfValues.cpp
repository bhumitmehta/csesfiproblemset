//calculateWithStd.cpp

#include <chrono>
#include <iostream>
#include <random>
#include <vector>
#include <numeric>
#include <mutex>

constexpr long long size = 100000000;

int main(){

  std::cout << std::endl;

  std::vector<int> randValues;
  randValues.reserve(size);

  // random values
  std::random_device seed;
  std::mt19937 engine(seed());
  std::uniform_int_distribution<> uniformDist(1, 10);
  for (long long i = 0 ; i < size ; ++i) 
       randValues.push_back(uniformDist(engine));
 
  const auto sta = std::chrono::steady_clock::now();
  
    const auto sum = std::accumulate(randValues.begin(), 
                                               randValues.end(), 0);
  const std::chrono::duration<double> dur = 
        std::chrono::steady_clock::now() - sta;
        
  std::cout << "Time for mySumition " << dur.count() 
            << " seconds" << std::endl;
  std::cout << "Result: " << sum << std::endl;


  auto sta2 = std::chrono::steady_clock::now();
  
  unsigned long long sum2 = {};
  for (auto n: randValues) sum2 += n;
 
  const std::chrono::duration<double> dur2 = 
        std::chrono::steady_clock::now() - sta2;
        
  std::cout << "Time for mySumition " << dur2.count() 
            << " seconds" << std::endl;
  std::cout << "Result: " << sum2 << std::endl;

  std::cout << std::endl;

  for (long long i = 0 ; i < size ; ++i) 
       randValues.push_back(uniformDist(engine));

       
  const auto sta3 = std::chrono::steady_clock::now();
  
  std::mutex myMutex;
  unsigned long long sum3 = {};
  for (auto i: randValues){
    std::lock_guard<std::mutex> myLockGuard(myMutex);
    sum3 += i;
  }
 
  const std::chrono::duration<double> dur3 = 
        std::chrono::steady_clock::now() - sta3;
        
  std::cout << "Time for mySummation with mutex " << dur3.count() 
            << " seconds" << std::endl;
  std::cout << "Result: " << sum3 << std::endl;
  std::cout << "Result: " << sum << std::endl;


}