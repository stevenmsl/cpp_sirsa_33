#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol33;

/*
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

tuple<vector<int>, int, int>
testFixture1()
{
  auto input = vector<int>{4, 5, 6, 7, 0, 1, 2};
  return make_tuple(input, 0, 4);
}

/*
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

tuple<vector<int>, int, int>
testFixture2()
{
  auto input = vector<int>{4, 5, 6, 7, 0, 1, 2};
  return make_tuple(input, 3, -1);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.search(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  cout << "Expect to see: " << get<2>(f) << endl;
  Solution sol;
  cout << sol.search(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}