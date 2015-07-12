// --------------------------------
// projects/c++/deque/TestDeque.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// http://www.cplusplus.com/reference/deque/deque/

// --------
// includes
// --------

#include <deque>     // deque
#include <stdexcept> // invalid_argument, out_of_range

#include "gtest/gtest.h"

#include "Deque.h"

// -----
// Using
// -----

using namespace std;

using testing::Test;
using testing::Types;

// -----
// Types
// -----

template <typename T>
struct Deque_Fixture : Test {
    typedef T                               deque_type;
    typedef typename deque_type::value_type value_type;};

typedef Types<
               deque<int>,
            my_deque<int>>
        deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);

// -----
// Tests
// -----

TYPED_TEST(Deque_Fixture, test_5) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    ASSERT_EQ(x.size(),     10);

    x.resize(5);
    ASSERT_EQ(x.size(),      5);

    x.resize(8);
    ASSERT_EQ(x.size(),      8);

    x.resize(15);
    ASSERT_EQ(x.size(),     15);

    x.resize(50);
    ASSERT_EQ(x.size(),     50);}

TYPED_TEST(Deque_Fixture, test_6) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    x[0] = 2;
    x[1] = 3;
    x[2] = 4;
    ASSERT_EQ(x[ 1], 3);
//  ASSERT_EQ(x[10], 3);
    try {
        ASSERT_EQ(x.at(10), 3);
        ASSERT_TRUE(false);}
    catch (const out_of_range&)
        {}}

TYPED_TEST(Deque_Fixture, test_7) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(2);
    x.push_back(3);
    ASSERT_EQ(x.size(),     5);

    x.pop_back();
    ASSERT_EQ(x.size(),     4);}

TYPED_TEST(Deque_Fixture, test_8) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    ASSERT_EQ(x.size(),     3);

    const deque_type y(x);
    ASSERT_EQ(y.size(),     3);

    ASSERT_EQ(x, y);}

TYPED_TEST(Deque_Fixture, test_9) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10, 2);
    deque_type       y(20, 3);
    ASSERT_EQ(y.size(),     20);

    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(y.size(),     10);

    ASSERT_EQ(x, y);}

TYPED_TEST(Deque_Fixture, test_10) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(15, 2);
    deque_type       y(10, 3);
    ASSERT_EQ(y.size(),     10);

    y.push_back(3);
    ASSERT_EQ(y.size(),     11);

    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(y.size(),     15);

    ASSERT_EQ(x, y);}

TYPED_TEST(Deque_Fixture, test_11) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(20, 2);
    deque_type       y(10, 3);
    ASSERT_EQ(y.size(),     10);

    ASSERT_TRUE(x != y);
    y = x;
    ASSERT_EQ(y.size(),     20);

    ASSERT_EQ(x, y);}


// ------------
// operator ==
// ------------


TYPED_TEST(Deque_Fixture, equal_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
	x.push_back(5);

	deque_type y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
	y.push_back(5);

	ASSERT_TRUE(x==y);}

TYPED_TEST(Deque_Fixture, equal_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(11);
    x.push_back(12);
    x.push_back(13);
    x.push_back(14);
	x.push_back(15);

	deque_type y;
    y.push_back(11);
    y.push_back(12);
    y.push_back(13);
    y.push_back(14);
	y.push_back(15);

	ASSERT_TRUE(x==y);}

TYPED_TEST(Deque_Fixture, equal_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
	x.push_back(5);

	deque_type y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(4);
	y.push_back(5);

	ASSERT_FALSE(x==y);}

// ------------
// operator <
// ------------


TYPED_TEST(Deque_Fixture, lt_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
	x.push_back(5);

	deque_type y;
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
	y.push_back(5);

	ASSERT_FALSE(x<y);}
	
TYPED_TEST(Deque_Fixture, lt_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(11);
    x.push_back(12);
    x.push_back(13);
    x.push_back(14);
	x.push_back(15);

	deque_type y;
    y.push_back(11);
    y.push_back(12);
    y.push_back(13);
    y.push_back(15);
	y.push_back(15);

	ASSERT_TRUE(x<y);}

TYPED_TEST(Deque_Fixture, lt_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
	x.push_back(5);

	deque_type y;
    y.push_back(10);

	ASSERT_TRUE(x<y);}
TYPED_TEST(Deque_Fixture, lt_4) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);

	deque_type y;
    y.push_back(1);
    y.push_back(2);

	ASSERT_TRUE(x<y);}

// -----------------------
// constructor (allocator)
// -----------------------


TYPED_TEST(Deque_Fixture, consta_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x;
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),0);}
	
// TYPED_TEST(Deque_Fixture, consta_2) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x();
//     ASSERT_TRUE(x.empty());
//     ASSERT_EQ(x.size(),0);}

// TYPED_TEST(Deque_Fixture, consta_3) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x();
//     ASSERT_TRUE(x.empty());
//     ASSERT_EQ(x.size(),0);}

// ----------------
// constructor 2
// ----------------
TYPED_TEST(Deque_Fixture, const2_1){
	typedef typename TestFixture::deque_type deque_type;
    typedef typename TestFixture::value_type  value_type;

    deque_type x(10);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                                10);
    ASSERT_EQ(count(x.begin(), x.end(), value_type()), 10);
}
TYPED_TEST(Deque_Fixture, const2_2){
	typedef typename TestFixture::deque_type deque_type;
    typedef typename TestFixture::value_type  value_type;

    deque_type x(300);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                                300);
    ASSERT_EQ(count(x.begin(), x.end(), value_type()), 300);
}
TYPED_TEST(Deque_Fixture, const2_3){
	typedef typename TestFixture::deque_type deque_type;
    typedef typename TestFixture::value_type  value_type;

    deque_type x(0);
    ASSERT_TRUE(x.empty());
    ASSERT_EQ(x.size(),                                0);
    ASSERT_EQ(count(x.begin(), x.end(), value_type()), 0);
}

TYPED_TEST(Deque_Fixture, const2_4){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10, 4003);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                     10);
    ASSERT_EQ(count(x.begin(), x.end(), 4003), 10);
}
TYPED_TEST(Deque_Fixture, const2_5){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(2003, 2);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                     2003);
    ASSERT_EQ(count(x.begin(), x.end(), 2), 2003);
}
TYPED_TEST(Deque_Fixture, const2_6){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(1000, 234);
    ASSERT_FALSE(x.empty());
    ASSERT_EQ(x.size(),                     1000);
    ASSERT_EQ(count(x.begin(), x.end(), 234), 1000);
}


// ----------------
// constructor 3
// ----------------

TYPED_TEST(Deque_Fixture, const3_1){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(1000, 234);
    deque_type y(x);
    ASSERT_EQ(x, y);
}

TYPED_TEST(Deque_Fixture, const3_2){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10, 4003);
    deque_type y(x);
    ASSERT_EQ(x, y);
}
TYPED_TEST(Deque_Fixture, const3_3){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(1000);
    deque_type y(x);
    ASSERT_EQ(x, y);
}

// ----------------
// destructor~
// ----------------

// TYPED_TEST(Deque_Fixture, destruct_1){
// 	typedef typename TestFixture::deque_type deque_type;

//     deque_type x(100, 234);
//     deque_type y(0);
//     x. ~deque_type();
//     ASSERT_EQ(x, y);
// }

// TYPED_TEST(Deque_Fixture, destruct_2){
// 	typedef typename TestFixture::deque_type deque_type;

//     deque_type x(10);
//     deque_type y(0);
// 	x. ~deque_type();

//     ASSERT_EQ(x, y);
// }
// TYPED_TEST(Deque_Fixture, destruct_3){
// 	typedef typename TestFixture::deque_type deque_type;

//     deque_type x(1000);
//     deque_type y(0);
//     x. ~deque_type();
//     ASSERT_EQ(x, y);
// }

// -------------------
// operator = (assign)
// -------------------
TYPED_TEST(Deque_Fixture, assign_1){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(1000, 234);
    deque_type y = x;
    ASSERT_EQ(x, y);
}

TYPED_TEST(Deque_Fixture, assign_2){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10, 4003);
    deque_type y = x;
    ASSERT_EQ(x, y);
}
TYPED_TEST(Deque_Fixture, assign_3){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(1000);
    deque_type y = x;
    ASSERT_EQ(x, y);
}

// -------------------
// operator [] (access)
// -------------------
TYPED_TEST(Deque_Fixture, access_1){
	typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x[2], 2);
}

TYPED_TEST(Deque_Fixture, access_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x[5], 5);
}
TYPED_TEST(Deque_Fixture, access_3){
	typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x[0], 0);
}



// TYPED_TEST(Deque_Fixture, iterator_test_1) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type::iterator x(3);
// 	++x;
//     ASSERT_EQ(x, 4);
// 	++x;
// 	++x;
// 	ASSERT_EQ(x, 6);}