// CDA TEST FILE

#include "../src/CDA.cpp"
#include <iostream>
#include "catch.hpp"

TEST_CASE("Empty array is created correctly") {
  CDA<int> x;
  REQUIRE(x.Length() == 0);
  REQUIRE(x.Capacity() == 1);
  REQUIRE(x.Ordered() == false);
}

TEST_CASE("Size constructor is initiated correctly") {
  CDA<int> x(20);
  REQUIRE(x.Length() == 20);
  REQUIRE(x.Capacity() == 20);
  REQUIRE(x.Ordered() == false);
  CDA<int> y(40);
  REQUIRE(y.Length() == 40);
  REQUIRE(y.Capacity() == 40);
  REQUIRE(y.Ordered() == false);
}

TEST_CASE("Copy constructor functions correctly") {
  CDA<int> x;
  for (int i = 0; i < 100; ++i) x.AddEnd(i);
  CDA<int> y(x);
  for (int i = 0; i < x.Length(); ++i) {
    CHECK(x[i] == y[i]);
  }
}

TEST_CASE("Move constructor functions correctly") {
  CDA<int> x;
  for (int i = 0; i < 100; ++i) x.AddEnd(i);
  CDA<int> y(x);
  for (int i = 0; i < x.Length(); ++i) {
    CHECK(x[i] == y[i]);
  }
}

TEST_CASE("Values are added to the end correctly, can be retrieved") {
  CDA<int> x;
  x.AddEnd(5);
  REQUIRE((x.Capacity() == 1 && x.Length() == 1));
  x.AddEnd(7);
  REQUIRE((x.Capacity() == 2 && x.Length() == 2));
  x.AddEnd(1);
  REQUIRE((x.Capacity() == 4 && x.Length() == 3));
  x.AddEnd(3);
  REQUIRE((x.Capacity() == 4 && x.Length() == 4));
  x.AddEnd(10);
  REQUIRE((x.Capacity() == 8 && x.Length() == 5));
  REQUIRE(x[0] == 5);
  REQUIRE(x[1] == 7);
  REQUIRE(x[2] == 1);
  REQUIRE(x[3] == 3);
  REQUIRE(x[4] == 10);
}

TEST_CASE("Values are deleted from the end correctly") {
  CDA<int> x;
  x.AddEnd(5);
  x.AddEnd(7);
  x.AddEnd(1);
  x.AddEnd(3);
  x.AddEnd(10);
  x.DelEnd();
  x.DelEnd();
  REQUIRE(x.Capacity() == 4);
  REQUIRE(x.Length() == 3);
}

TEST_CASE("SetOrdered works") {
  CDA<int> x;
  x.AddEnd(5);
  x.AddEnd(10);
  x.AddEnd(15);
  x.AddEnd(20);
  REQUIRE(x.SetOrdered() == 1);
  REQUIRE(x.Ordered());
  CDA<int> y;
  y.AddEnd(10);
  y.AddEnd(5);
  y.AddEnd(32);
  REQUIRE(y.SetOrdered() == -1);
  REQUIRE(!y.Ordered());
}

TEST_CASE("Clear works") {
  CDA<int> x;
  x.AddEnd(5);
  x.AddEnd(10);
  x.AddEnd(15);
  x.AddEnd(20);
  x.Clear();
  REQUIRE(x.Length() == 0);
  REQUIRE(x.Capacity() == 1);
}

TEST_CASE("Quick select (sorted) works") {
  CDA<int> x;
  x.AddEnd(2);
  x.AddEnd(4);
  x.AddEnd(4);
  x.AddEnd(6);
  x.AddEnd(8);
  x.SetOrdered();
  REQUIRE(x.Select(1) == 2);
}

TEST_CASE("Quick select (unsorted) works") {
  // TODO: Implement
  // CDA<int> x;
  // x.AddEnd(4);
  // x.AddEnd(2);
  // x.AddEnd(6);
  // x.AddEnd(4);
  // x.AddEnd(8);
  // x.SetOrdered();
  // REQUIRE(x.Select(1) == 2);
}

TEST_CASE("Values can be added to the front, as well") {
  CDA<int> x;
  x.AddEnd(5);     // Will add 5 to the one spot.
  x.AddEnd(7);     // Will double the capacity, and add 7 to the end.
  x.AddEnd(1);     // Will double the capacity, to 4, and add 1 to the end.
  x.AddEnd(3);     // Will add 3 to the end.
  x.AddEnd(10);    // Will double the capacity, to 8, and add 10 to the end.
  x.AddFront(9);   // Will put the 9 at the end of capacity, and update front
  x.AddFront(42);  // Will put the 42 at index 7, cap = 8, size = 7
  x.AddFront(69);  // Will put the 69 at index 6, cap = 8, size = 8
  REQUIRE(x[0] == 69);
  REQUIRE(x[1] == 42);
  REQUIRE(x[2] == 9);
  REQUIRE(x[3] == 5);
  REQUIRE(x[4] == 7);
  REQUIRE(x[5] == 1);
}

TEST_CASE("Values can be removed from the front, as well") {
  CDA<int> x;
  x.AddEnd(5);   // Will add 5 to the one spot.
  x.AddEnd(7);   // Will double the capacity, and add 7 to the end.
  x.AddEnd(1);   // Will double the capacity, to 4, and add 1 to the end.
  x.AddEnd(3);   // Will add 3 to the end.
  x.AddEnd(10);  // Will double the capacity, to 8, and add 10 to the end.
  x.DelFront();
  REQUIRE(x[0] == 7);
  REQUIRE(x[1] == 1);
  x.AddFront(32);
  REQUIRE(x[0] == 32);
}

// TEST_CASE("QuickSort works") {
//   CDA<int> x;
//   x.AddEnd(10);
//   x.AddEnd(5);
//   x.AddFront(-2);
//   x.AddFront(28);
//   x.AddEnd(38);
//   x.AddEnd(38);
//   x.AddFront(38);
//   x.QuickSort();
//   REQUIRE(x[0]==-2);
//   // REQUIRE(x[6]==38);
// }
