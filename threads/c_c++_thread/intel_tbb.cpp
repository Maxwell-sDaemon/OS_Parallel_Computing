/*
 * if you download oneapi, 
 * https://software.intel.com/content/www/us/en/develop/documentation/installation-guide-for-intel-oneapi-toolkits-linux/top/installation/install-using-package-managers/apt.html
 * */

#include <oneapi/dpl/execution>
#include <oneapi/dpl/algorithm>
#include <iostream>
#include <vector>

int main() { 
	  std::vector<std::string> v = { " Hello ", " Parallel STL! " };
	  std::for_each(dpl::execution::par, v.begin(), v.end(), [](std::string& s) { std::cout << s << std::endl; }); 
	  return 0;
}
