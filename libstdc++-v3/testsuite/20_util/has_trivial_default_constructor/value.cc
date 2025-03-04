// { dg-options "-std=gnu++11" }
// { dg-do compile }

// 2004-12-26  Paolo Carlini  <pcarlini@suse.de>
//
// Copyright (C) 2004-2015 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING3.  If not see
// <http://www.gnu.org/licenses/>.

// 4.5.3 Type properties

#include <type_traits>
#include <testsuite_tr1.h>

void test01()
{
  using std::has_trivial_default_constructor;
  using namespace __gnu_test;

  // Positive tests.
  static_assert(test_category<has_trivial_default_constructor, int>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		float>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		EnumType>(true), "");
  static_assert(test_category<has_trivial_default_constructor, int*>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int(*)(int)>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int (ClassType::*)>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int (ClassType::*) (int)>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int[2]>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		float[][3]>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		EnumType[2][3][4]>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int*[3]>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int(*[][2])(int)>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int (ClassType::*[2][3])>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		int (ClassType::*[][2][3]) (int)>(true), "");
  static_assert(test_category<has_trivial_default_constructor,
		ClassType>(true), "");

  // Negative tests.
  static_assert(test_category<has_trivial_default_constructor,
		void>(false), "");  
}
