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
    typedef typename deque_type::value_type value_type;
    typedef typename deque_type::size_type size_type;};

typedef Types<
               deque<int>,
            my_deque<int>>
        deque_types;

TYPED_TEST_CASE(Deque_Fixture, deque_types);

// -----
// Tests
// -----

// TYPED_TEST(Deque_Fixture, test_5) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x(10);
//     ASSERT_EQ(x.size(),     10);

//     x.resize(5);
//     ASSERT_EQ(x.size(),      5);

//     x.resize(8);
//     ASSERT_EQ(x.size(),      8);

//     x.resize(15);
//     ASSERT_EQ(x.size(),     15);

//     x.resize(50);
//     ASSERT_EQ(x.size(),     50);}

// TYPED_TEST(Deque_Fixture, test_6) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x(10);
//     x[0] = 2;
//     x[1] = 3;
//     x[2] = 4;
//     ASSERT_EQ(x.at(1), 3);
// //  ASSERT_EQ(x[10], 3);
//     try {
//         ASSERT_EQ(x.at(10), 3);
//         ASSERT_TRUE(false);}
//     catch (const out_of_range&)
//         {}}

// TYPED_TEST(Deque_Fixture, test_7) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x;
//     x.push_back(2);
//     x.push_back(3);
//     x.push_back(4);
//     x.push_back(2);
//     x.push_back(3);
//     ASSERT_EQ(x.size(),     5);

//     x.pop_back();
//     ASSERT_EQ(x.size(),     4);}

// TYPED_TEST(Deque_Fixture, test_8) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x;
//     x.push_back(2);
//     x.push_back(3);
//     x.push_back(4);
//     ASSERT_EQ(x.size(),     3);

//     const deque_type y(x);
//     ASSERT_EQ(y.size(),     3);

//     ASSERT_EQ(x, y);}

// TYPED_TEST(Deque_Fixture, test_9) {
//     typedef typename TestFixture::deque_type deque_type;

//     const deque_type x(10, 2);
//     deque_type       y(20, 3);
//     ASSERT_EQ(y.size(),     20);

//     ASSERT_TRUE(x != y);
//     y = x;
//     ASSERT_EQ(y.size(),     10);

//     ASSERT_EQ(x, y);}

// TYPED_TEST(Deque_Fixture, test_10) {
//     typedef typename TestFixture::deque_type deque_type;

//     const deque_type x(15, 2);
//     deque_type       y(10, 3);
//     ASSERT_EQ(y.size(),     10);

//     y.push_back(3);
//     ASSERT_EQ(y.size(),     11);

//     ASSERT_TRUE(x != y);
//     y = x;
//     ASSERT_EQ(y.size(),     15);

//     ASSERT_EQ(x, y);}

// TYPED_TEST(Deque_Fixture, test_11) {
//     typedef typename TestFixture::deque_type deque_type;

//     const deque_type x(20, 2);
//     deque_type       y(10, 3);
//     ASSERT_EQ(y.size(),     10);

//     ASSERT_TRUE(x != y);
//     y = x;
//     ASSERT_EQ(y.size(),     20);

//     ASSERT_EQ(x, y);}


// -----------------------------
// my_deque
// -----------------------------

// ----------
// capacity
// ----------

// TEST(Deque_Fixture, capacity){
//     my_deque<int> x(10, 2);
//     ASSERT_EQ(x.capacity(), 10);
// }


// ------------
// operator ==
// ------------


TYPED_TEST(Deque_Fixture, equal_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
	x.push_back(5);

	deque_type y(10);
    y.push_back(1);
    y.push_back(2);
    y.push_back(3);
    y.push_back(4);
	y.push_back(5);

    deque_type z(10);
    z.push_back(1);
    z.push_back(2);
    z.push_back(3);
    z.push_back(4);
    z.push_back(5);


    ASSERT_EQ(x.size(), 15);

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
    ASSERT_EQ(count(x.begin(), x.end(), 4003), 10);

}
TYPED_TEST(Deque_Fixture, const3_3){
	typedef typename TestFixture::deque_type deque_type;

    const deque_type x(1000);
    deque_type y(x);
    ASSERT_TRUE(y.size() == x.size());
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
    int i = 0;
    deque_type x;
    while (i <49){
        x.push_back(i++);
    }
    

    ASSERT_EQ(x[2], 2);
}

TYPED_TEST(Deque_Fixture, access_2){
    typedef typename TestFixture::deque_type deque_type;

    int i = 0;
    deque_type x;
    while (i <49){
        x.push_back(i++);
    }

    ASSERT_EQ(x[5], 5);
}
TYPED_TEST(Deque_Fixture, access_3){
	typedef typename TestFixture::deque_type deque_type;

    int i = 0;
    deque_type x;
    while (i <49){
        x.push_back(i++);
    }

    ASSERT_EQ(x[0], 0);
}

// -------------------
// at ()
// -------------------

TYPED_TEST(Deque_Fixture, at_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x.at(3), 3);
}

TYPED_TEST(Deque_Fixture, at_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x.at(0), 0);
}

TYPED_TEST(Deque_Fixture, at_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(-5);
    x.push_back(2);
    x.push_back(-3);
    x.push_back(4);
    x.push_back(-5);

    ASSERT_EQ(x.at(3), -3);
}

// -------------------
// back ()
// -------------------

TYPED_TEST(Deque_Fixture, back_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x.back(), 5);
}

TYPED_TEST(Deque_Fixture, back_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
 

    ASSERT_EQ(x.back(), 2);
}

TYPED_TEST(Deque_Fixture, back_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);
    x.pop_back();

    ASSERT_EQ(x.back(), 4);
}

// -------------------
// begin ()
// -------------------

TYPED_TEST(Deque_Fixture, begin_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    auto y = x.begin();

    ASSERT_TRUE(x.begin() == y);
}

TYPED_TEST(Deque_Fixture, begin_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    auto y = x.begin();
    ASSERT_TRUE(x.begin() == y);
}

TYPED_TEST(Deque_Fixture, begin_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_front(0);
    x.push_front(1);
    auto y = x.begin();

    ASSERT_TRUE(x.begin() == y);
}

// -------------------
// clear ()
// -------------------

TYPED_TEST(Deque_Fixture, clear_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.clear();

    ASSERT_EQ(x.size(), 0);
}

TYPED_TEST(Deque_Fixture, clear_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.clear();

    ASSERT_EQ(x.size(), 0);
}

TYPED_TEST(Deque_Fixture, clear_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.clear();

    ASSERT_EQ(x.size(), 0);
}

// -------------------
// empty ()
// -------------------

TYPED_TEST(Deque_Fixture, empty_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.clear();

    ASSERT_EQ(x.empty(), true);
}

TYPED_TEST(Deque_Fixture, empty_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    ASSERT_EQ(x.empty(), true);
}

TYPED_TEST(Deque_Fixture, empty_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);

    ASSERT_EQ(x.empty(), false);
}

// -------------------
// end ()
// -------------------

TYPED_TEST(Deque_Fixture, end_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    auto y = x.end();

    ASSERT_TRUE(y == x.end());
}

TYPED_TEST(Deque_Fixture, end_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;

    auto y = x.end();

    ASSERT_TRUE(y == x.end());
}

TYPED_TEST(Deque_Fixture, end_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    auto y = x.end();

    ASSERT_TRUE(y == x.begin());
}

// -----------
// erase
// ----------
TYPED_TEST(Deque_Fixture, erase_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(1);
    x.erase(x.begin());

    ASSERT_EQ(x.size(), 0);
}

TYPED_TEST(Deque_Fixture, erase_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.erase(x.begin());

    ASSERT_EQ(x.size(), 4);
    //ASSERT_EQ(x.begin(), 4);
}

TYPED_TEST(Deque_Fixture, erase_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(-1000);
    x.erase(x.end());

    ASSERT_EQ(x.size(), 0);
}



// -----------
// front
// -----------
TYPED_TEST(Deque_Fixture, front_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    auto y = x.front();

    ASSERT_TRUE(0 == y);
}

TYPED_TEST(Deque_Fixture, front_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_front(5);

    auto y = x.front();
    ASSERT_TRUE(5 == y);
}

TYPED_TEST(Deque_Fixture, front_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_front(0);
    x.push_front(1);
    auto y = x.front();

    ASSERT_TRUE(1 == y);
}



// -------------
// insert
// -------------

TYPED_TEST(Deque_Fixture, insert_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    x.insert(x.begin()+3, -1);

    ASSERT_TRUE(x.at(3) == -1);
}

TYPED_TEST(Deque_Fixture, insert_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10, 2);
    x.insert(x.begin()+3, 0);
    ASSERT_TRUE(x.at(3) == 0);
}

TYPED_TEST(Deque_Fixture, insert_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    x.push_front(1);
    x.insert(x.end()-3, 8);

    ASSERT_EQ(x.at(8), 8);
}


// -------------
// pop_back
// -------------
TYPED_TEST(Deque_Fixture, pop_back_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    x.pop_back();

    ASSERT_EQ(x.back(), 4);
    ASSERT_EQ(x.size(), 5);
}

TYPED_TEST(Deque_Fixture, pop_back_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10, 2);
    x.push_back(1);
    x.push_back(3);
    x.pop_back();
    ASSERT_EQ(x.back(), 1);
    ASSERT_EQ(x.size(), 11);
}

TYPED_TEST(Deque_Fixture, pop_back_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    x.push_front(11);
    x.push_front(11);
    x.pop_back();

    ASSERT_EQ(x.back(), 0);
    ASSERT_EQ(x.size(), 11);
}


// --------------
// pop_front
// --------------

TYPED_TEST(Deque_Fixture, pop_front_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    x.pop_front();

    ASSERT_EQ(x.front(), 1);
    ASSERT_EQ(x.size(), 5);
}

TYPED_TEST(Deque_Fixture, pop_front_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10, 2);
    x.push_front(1);
    x.push_back(3);
    x.pop_front();
    ASSERT_EQ(x.front(), 2);
    ASSERT_EQ(x.size(), 11);
}

TYPED_TEST(Deque_Fixture, pop_front_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    x.push_front(11);
    x.push_front(11);
    x.pop_front();

    ASSERT_EQ(x.front(), 11);
    ASSERT_EQ(x.size(), 11);
}


// --------------
// push_back
// --------------
TYPED_TEST(Deque_Fixture, push_back_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    // x.push_back(0);
    // x.push_back(1);
    // x.push_back(2);
    // x.push_back(3);
    // x.push_back(4);
    // x.push_back(5);
    int i = 0;
    while (i < 40){
        x.push_back(i++);
    }

    ASSERT_EQ(x.at(0), 0);
    ASSERT_EQ(x.at(1), 1);
    ASSERT_EQ(x.at(2), 2);
    ASSERT_EQ(x.at(3), 3);
    ASSERT_EQ(x.at(4), 4);
    ASSERT_EQ(x.at(5), 5);
    ASSERT_EQ(x.size(), 40);
}

TYPED_TEST(Deque_Fixture, push_back_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5, 2);
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);

    ASSERT_EQ(x.at(0), 2);
    ASSERT_EQ(x.at(1), 2);
    ASSERT_EQ(x.at(2), 2);
    ASSERT_EQ(x.at(3), 2);
    ASSERT_EQ(x.at(4), 2);
    ASSERT_EQ(x.at(5), 0);
    ASSERT_EQ(x.at(6), 1);
    ASSERT_EQ(x.at(7), 2);
    ASSERT_EQ(x.at(8), 3);
    ASSERT_EQ(x.at(9), 4);
    ASSERT_EQ(x.size(), 10);
}

TYPED_TEST(Deque_Fixture, push_back_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    x.push_back(5);

    ASSERT_EQ(x.at(0), 0);
    ASSERT_EQ(x.at(1), 0);
    ASSERT_EQ(x.at(2), 0);
    ASSERT_EQ(x.at(3), 0);
    ASSERT_EQ(x.at(4), 0);
    ASSERT_EQ(x.at(5), 1);
    ASSERT_EQ(x.at(6), 2);
    ASSERT_EQ(x.at(7), 3);
    ASSERT_EQ(x.at(8), 4);
    ASSERT_EQ(x.at(9), 5);
    ASSERT_EQ(x.size(), 10);
}


// --------------
// push_front
// --------------
TYPED_TEST(Deque_Fixture, push_front_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_front(0);
    x.push_front(1);
    x.push_front(2);
    x.push_front(3);
    x.push_front(4);
    x.push_front(5);

    ASSERT_EQ(x.at(0), 5);
    ASSERT_EQ(x.at(1), 4);
    ASSERT_EQ(x.at(2), 3);
    ASSERT_EQ(x.at(3), 2);
    ASSERT_EQ(x.at(4), 1);
    ASSERT_EQ(x.at(5), 0);
    ASSERT_EQ(x.size(), 6);
}

TYPED_TEST(Deque_Fixture, push_front_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5, 2);
    x.push_front(0);
    x.push_front(1);
    x.push_front(2);
    x.push_front(3);
    x.push_front(4);

    ASSERT_EQ(x.at(0), 4);
    ASSERT_EQ(x.at(1), 3);
    ASSERT_EQ(x.at(2), 2);
    ASSERT_EQ(x.at(3), 1);
    ASSERT_EQ(x.at(4), 0);
    ASSERT_EQ(x.at(5), 2);
    ASSERT_EQ(x.at(6), 2);
    ASSERT_EQ(x.at(7), 2);
    ASSERT_EQ(x.at(8), 2);
    ASSERT_EQ(x.at(9), 2);
    ASSERT_EQ(x.size(), 10);
}

TYPED_TEST(Deque_Fixture, push_front_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5);
    x.push_front(1);
    x.push_front(2);
    x.push_front(3);
    x.push_front(4);
    x.push_front(5);

    ASSERT_EQ(x.at(0), 5);
    ASSERT_EQ(x.at(1), 4);
    ASSERT_EQ(x.at(2), 3);
    ASSERT_EQ(x.at(3), 2);
    ASSERT_EQ(x.at(4), 1);
    ASSERT_EQ(x.at(5), 0);
    ASSERT_EQ(x.at(6), 0);
    ASSERT_EQ(x.at(7), 0);
    ASSERT_EQ(x.at(8), 0);
    ASSERT_EQ(x.at(9), 0);
    ASSERT_EQ(x.size(), 10);
}

// ---------------
// resize
// ---------------
TYPED_TEST(Deque_Fixture, resize_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    x.resize(3);
    ASSERT_EQ(x.size(), 3);
}

TYPED_TEST(Deque_Fixture, resize_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5, 2);
    x.resize(10);
    ASSERT_EQ(x.size(), 10);
}

TYPED_TEST(Deque_Fixture, resize_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5);
    x.resize(5);
    ASSERT_EQ(x.size(), 5);
}


// ---------------
// size
// ---------------

TYPED_TEST(Deque_Fixture, size_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(1000);

    ASSERT_EQ(x.size(), 1000);
}

TYPED_TEST(Deque_Fixture, size_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(5, 2);

    ASSERT_EQ(x.size(), 5);
}

TYPED_TEST(Deque_Fixture, size_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;

    ASSERT_EQ(x.size(), 0);
}

// ---------------
// swap 
// ---------------

TYPED_TEST(Deque_Fixture, swap_1){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(1);
    deque_type y(1);
    x.push_front(5);
    y.push_front(8);
    swap(x, y);

    ASSERT_EQ(x.front(), 8);
    ASSERT_EQ(y.front(), 5);
}

TYPED_TEST(Deque_Fixture, swap_2){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10, 7);
    deque_type y(5, 3);
    swap(x, y);

    ASSERT_EQ(x.front(), 3);
    ASSERT_EQ(y.front(), 7);
}

TYPED_TEST(Deque_Fixture, swap_3){
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);
    deque_type y(10);
    swap(x, y);

    ASSERT_EQ(x.front(), y.front());
    ASSERT_EQ(x.back(), y.back());
}



// -----------------------------------------
// iterator tests
// -----------------------------------------

// -------
// ==
// -------

TYPED_TEST(Deque_Fixture, it_equal_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);

    typename deque_type::iterator y = x.begin();
    typename deque_type::iterator z = x.begin();
    ++y;
    ASSERT_FALSE(y==z);
    --y;
    ASSERT_TRUE(y==z);}

TYPED_TEST(Deque_Fixture, it_equal_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10, 11);

    typename deque_type::iterator y = x.begin()+5;
    typename deque_type::iterator z = x.begin();
    ++z;
    ++z;
    ++z;
    ++z;
    ++z;
    ASSERT_TRUE(y == z);}

TYPED_TEST(Deque_Fixture, it_equal_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);

    typename deque_type::iterator y = x.begin();
    typename deque_type::iterator z = x.begin();
    ASSERT_TRUE(y==z);}


// -------------
// constructor
// -------------

TYPED_TEST(Deque_Fixture, it_construct_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);

    typename deque_type::iterator y = x.begin();
    ++y;
    ASSERT_EQ(*y, 1);
    ++y;
    ++y;
    ASSERT_EQ(*y, 3);}

TYPED_TEST(Deque_Fixture, it_construct_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10, 11);

    typename deque_type::iterator y = x.begin()+5;
    ++y;
    ASSERT_EQ(*y, 11);
    ++y;
    ++y;
    ASSERT_EQ(*y, 11);}

TYPED_TEST(Deque_Fixture, it_construct_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x(10);

    typename deque_type::iterator y = x.begin();
    ++y;
    ASSERT_EQ(*y, 0);
    ++y;
    ++y;
    ASSERT_EQ(*y, 0);}

// TYPED_TEST(Deque_Fixture, iterator_test_4) {
//     typedef typename TestFixture::deque_type deque_type;

//     deque_type x(10);
//     x[0] = 0;
//     x[1] = 1;
//     x[2] = 2;
//     x[3] = 3;
//     x[4] = 4;
//     x[5] = 5;
//     x[6] = 6;
    
//     typename deque_type::iterator y(&x, 3);
//     ++y;
//     ASSERT_EQ(*y, 4);
//     ++y;
//     ++y;
//     ASSERT_EQ(*y, 6);}

// -------------
// reference *
// -------------

TYPED_TEST(Deque_Fixture, it_reference_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);

    typename deque_type::iterator y = x.begin();
    ASSERT_EQ(*y, 0);
    ++y;
    ++y;
    ASSERT_EQ(*y, 2);}

TYPED_TEST(Deque_Fixture, it_reference_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    ASSERT_EQ(*y, 0);
    ++y;
    ++y;
    ASSERT_EQ(*y, 2);}

TYPED_TEST(Deque_Fixture, it_reference_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    ASSERT_EQ(*y, 0);
    ++y;
    ++y;
    ASSERT_EQ(*y, 2);}


// -------------
// prefix ++
// -------------

TYPED_TEST(Deque_Fixture, it_incr_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(7);
    x.push_back(3);
    x.push_back(5);
    x.push_back(1);
    x.push_back(-2);

    typename deque_type::iterator y = x.begin();
    ASSERT_EQ(*y, 7);
    ++y;
    ++y;
    ++y;
    ++y;
    ASSERT_EQ(*y, -2);}

TYPED_TEST(Deque_Fixture, it_incr_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    ASSERT_EQ(*y, 0);
    ++y;
    ++y;
    ASSERT_EQ(*y, 2);}

TYPED_TEST(Deque_Fixture, it_incr_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    ASSERT_EQ(*y, 0);
    ++y;
    ASSERT_EQ(*y, 1);
    ++y;
    ASSERT_EQ(*y, 2);
    ++y;
    ASSERT_EQ(*y, 3);
    ++y;
    ASSERT_EQ(*y, 4);
}


// -------------
// prefix --
// -------------

TYPED_TEST(Deque_Fixture, it_decr_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(7);
    x.push_back(3);
    x.push_back(5);
    x.push_back(1);
    x.push_back(-2);

    typename deque_type::iterator y = x.end()-1;
    ASSERT_EQ(*y, -2);
    --y;
    --y;
    --y;
    --y;
    ASSERT_EQ(*y, 7);}

TYPED_TEST(Deque_Fixture, it_decr_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.end()-1;
    ASSERT_EQ(*y, 4);
    --y;
    --y;
    ASSERT_EQ(*y, 2);}

TYPED_TEST(Deque_Fixture, it_decr_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.end()-1;
    ASSERT_EQ(*y, 4);
    --y;
    ASSERT_EQ(*y, 3);
    --y;
    ASSERT_EQ(*y, 2);
    --y;
    ASSERT_EQ(*y, 1);
    --y;
    ASSERT_EQ(*y, 0);
}

// -------------
// +=
// -------------
TYPED_TEST(Deque_Fixture, it_pluseq_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin()+3;
    typename deque_type::iterator z = x.begin();
    z+=3;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, it_pluseq_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    typename deque_type::iterator z = x.begin();
    z+=0;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, it_pluseq_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    typename deque_type::iterator z = x.begin()+2;
    z+=-2;
    ASSERT_TRUE(y==z);
    
}


// -------------
// -=
// -------------
TYPED_TEST(Deque_Fixture, it_minuseq_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin()+3;
    typename deque_type::iterator z = x.begin();
    y-=3;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, it_minuseq_2) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin();
    typename deque_type::iterator z = x.begin();
    z-=0;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, it_minuseq_3) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type x;
    x.push_back(0);
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);


    typename deque_type::iterator y = x.begin()+2;
    typename deque_type::iterator z = x.begin();
    z -= -2;
    ASSERT_TRUE(y==z);
    
}



// -----------------------------------------
// const_iterator tests
// -----------------------------------------

// -------
// ==
// -------

TYPED_TEST(Deque_Fixture, const_it_equal_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type dummy;
    dummy.push_back(0);
    dummy.push_back(1);
    dummy.push_back(2);
    dummy.push_back(3);
    dummy.push_back(4);

    const deque_type x = dummy;

    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator e = x.end();
    typename deque_type::const_iterator copy = x.begin();
    typename deque_type::const_iterator z = x.begin();
    ++y;
    ASSERT_FALSE(y==z);
    --y;
    ASSERT_TRUE(y==z);
    ASSERT_TRUE(equal(y, e, copy));
}

TYPED_TEST(Deque_Fixture, const_it_equal_2) {
    typedef typename TestFixture::deque_type deque_type;



    const deque_type x(10,-3);

    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator e = x.end();
    typename deque_type::const_iterator copy = x.begin();
    typename deque_type::const_iterator z = x.begin();
    ++y;
    ASSERT_FALSE(y==z);
    --y;
    ASSERT_TRUE(y==z);
    ASSERT_TRUE(equal(y, e, copy));
}

TYPED_TEST(Deque_Fixture, const_it_equal_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);

    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator e = x.end();
    typename deque_type::const_iterator copy = x.begin();
    typename deque_type::const_iterator z = x.begin();
    ++y;
    ASSERT_FALSE(y==z);
    --y;
    ASSERT_TRUE(y==z);
    ASSERT_TRUE(equal(y, e, copy));
}



// -------------
// constructor
// -------------

TYPED_TEST(Deque_Fixture, const_it_construct_1) {
    typedef typename TestFixture::deque_type deque_type;

    deque_type dummy;
    dummy.push_back(-4);
    dummy.push_back(-3);
    dummy.push_back(-2);
    dummy.push_back(-1);
    dummy.push_back(0);


    const deque_type x = dummy;

    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator e = x.end();
    typename deque_type::const_iterator copy = x.begin();
    ASSERT_TRUE(equal(y, e, copy));
    ++y;
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ASSERT_EQ(*y, -1);
    }

TYPED_TEST(Deque_Fixture, const_it_construct_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);

    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator e = x.end();
    typename deque_type::const_iterator copy = x.begin();
    ASSERT_TRUE(equal(y, e, copy));
    ++y;
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ASSERT_EQ(*y, -3);
    }

TYPED_TEST(Deque_Fixture, const_it_construct_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-134);

    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator e = x.end();
    typename deque_type::const_iterator copy = x.begin();
    ASSERT_TRUE(equal(y, e, copy));
    ++y;
    ASSERT_EQ(*y, -134);
    ++y;
    ++y;
    ASSERT_EQ(*y, -134);
    }


// -------------
// reference *
// -------------

TYPED_TEST(Deque_Fixture, const_it_reference_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);

    typename deque_type::const_iterator y = x.begin();
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ASSERT_EQ(*y, -3);}

TYPED_TEST(Deque_Fixture, const_it_reference_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin();
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ASSERT_EQ(*y, -3);}

TYPED_TEST(Deque_Fixture, const_it_reference_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin();
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ASSERT_EQ(*y, -3);}


// -------------
// prefix ++
// -------------

TYPED_TEST(Deque_Fixture, const_it_incr_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);

    typename deque_type::const_iterator y = x.begin();
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ++y;
    ++y;
    ASSERT_EQ(*y, -3);}

TYPED_TEST(Deque_Fixture, const_it_incr_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin();
    ASSERT_EQ(*y, -3);
    ++y;
    ++y;
    ASSERT_EQ(*y, -3);}

TYPED_TEST(Deque_Fixture, const_it_incr_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin();
    ASSERT_EQ(*y, -3);
    ++y;
    ASSERT_EQ(*y, -3);
    ++y;
    ASSERT_EQ(*y, -3);
    ++y;
    ASSERT_EQ(*y, -3);
    ++y;
    ASSERT_EQ(*y, -3);
}


// -------------
// prefix --
// -------------

TYPED_TEST(Deque_Fixture, const_it_decr_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);

    typename deque_type::const_iterator y = x.end()-1;
    ASSERT_EQ(*y, -3);
    --y;
    --y;
    --y;
    --y;
    ASSERT_EQ(*y, -3);}

TYPED_TEST(Deque_Fixture, const_it_decr_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.end()-1;
    ASSERT_EQ(*y, -3);
    --y;
    --y;
    ASSERT_EQ(*y, -3);}

TYPED_TEST(Deque_Fixture, const_it_decr_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.end()-1;
    ASSERT_EQ(*y, -3);
    --y;
    ASSERT_EQ(*y, -3);
    --y;
    ASSERT_EQ(*y, -3);
    --y;
    ASSERT_EQ(*y, -3);
    --y;
    ASSERT_EQ(*y, -3);
}

// -------------
// +=
// -------------
TYPED_TEST(Deque_Fixture, const_it_pluseq_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin()+3;
    typename deque_type::const_iterator z = x.begin();
    z+=3;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, const_it_pluseq_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator z = x.begin();
    z+=0;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, const_it_pluseq_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator z = x.begin()+2;
    z+=-2;
    ASSERT_TRUE(y==z);
    
}


// -------------
// -=
// -------------
TYPED_TEST(Deque_Fixture, const_it_minuseq_1) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(100,20);


    typename deque_type::const_iterator y = x.begin()+3;
    typename deque_type::const_iterator z = x.begin();
    y-=3;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, const_it_minuseq_2) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,3002);


    typename deque_type::const_iterator y = x.begin();
    typename deque_type::const_iterator z = x.begin();
    z-=0;
    ASSERT_TRUE(y==z);
    
}

TYPED_TEST(Deque_Fixture, const_it_minuseq_3) {
    typedef typename TestFixture::deque_type deque_type;

    const deque_type x(10,-3);


    typename deque_type::const_iterator y = x.begin()+2;
    typename deque_type::const_iterator z = x.begin();
    z -= -2;
    ASSERT_TRUE(y==z);
    
}





