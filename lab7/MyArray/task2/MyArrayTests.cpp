#include "stdafx.h"
#include "MyArray.h"
#include <iostream> 
using namespace std;

struct EmptyArray
{
	CMyArray<int> arr;
};

BOOST_FIXTURE_TEST_SUITE(MyArray, EmptyArray)
	BOOST_AUTO_TEST_SUITE(by_default)
		BOOST_AUTO_TEST_CASE(is_empty)
	    {
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		}
		BOOST_AUTO_TEST_CASE(has_0_capacity)
		{
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 0u);
		}
		BOOST_AUTO_TEST_CASE(has_equal_begin_and_end)
		{
			BOOST_CHECK(arr.empty());
		}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_appending_an_item)
		BOOST_AUTO_TEST_CASE(increases_its_size_and_capacity)
		{
			arr.Append(1);
			BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 1u);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 2u);
			arr.Append(3);
			BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
			arr.Append(4);
			BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
		}
		BOOST_AUTO_TEST_CASE(it_becomes_available_at_the_back)
		{
			arr.Append(1);
			BOOST_CHECK_EQUAL(arr.GetBack(), 1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetBack(), 2);
			arr.Append(3);
			BOOST_CHECK_EQUAL(arr.GetBack(), 3);
			arr.Append(4);
			BOOST_CHECK_EQUAL(arr.GetBack(), 4);
		}
BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_copy_construction)
		BOOST_AUTO_TEST_CASE(has_size_capacity_equal_to_size_of_original_array)
		{
			for (auto i = 0; i < 6; ++i)
			{
				arr.Append(i);
			}
			BOOST_CHECK_NE(arr.GetSize(), arr.GetCapacity());

			auto copy(arr);
			BOOST_CHECK_EQUAL(copy.GetSize(), arr.GetSize());
			BOOST_CHECK_EQUAL(copy.GetCapacity(), arr.GetSize());
		}
	BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(after_assignment_construction)
			BOOST_AUTO_TEST_CASE(empty_array_get_items_other_array_is_empty)
				{
					CMyArray<int> arr1({ 0, 1, 2, 3, 4, 5 });
					BOOST_CHECK_EQUAL(arr1.GetSize(), 6u);
					CMyArray<int> arr2(std::move(arr1));
					BOOST_CHECK_EQUAL(arr1.GetSize(), 0u);
					BOOST_CHECK_EQUAL(arr2.GetSize(), 6u);
				}
			
			BOOST_AUTO_TEST_CASE(assign_empty_array)
			{
				CMyArray<int> arr1({});
				BOOST_CHECK_EQUAL(arr1.GetSize(), 0u);
			}
	
			BOOST_AUTO_TEST_CASE(is_correct_assignment_itself)
			{
				int count = 1;
				arr.Append(1);
				arr.Append(2);
				arr.Append(3);
				arr = arr;
				BOOST_CHECK(arr.GetSize() == 3);

				for (auto p = arr.begin(); p != arr.end(); p++, count++)
				{
					BOOST_CHECK(*p == count);
				}
			}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE(after_adding_items)
		BOOST_AUTO_TEST_CASE(can_clear_all_elements)
		{
			arr.Append(0);
			arr.Append(1);
			arr.Append(2);
			BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);

			arr.Clear();
			BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);

			arr.Append(3);
			BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
		}
		struct arrInt
		{
			CMyArray<int> arr1 = { 11, 22, 33, 44 };
		};

		BOOST_FIXTURE_TEST_SUITE(resize_array, arrInt)
			BOOST_AUTO_TEST_CASE(when_new_size_less_then_current_size)
			{
				arr1.Resize(2);
				BOOST_CHECK_EQUAL(arr1.GetSize(), 2u);
				BOOST_CHECK_EQUAL(arr1.GetCapacity(), 4u);
			}
			BOOST_AUTO_TEST_CASE(when_new_size_equal_current_size)
			{
				arr1.Resize(4);
				BOOST_CHECK_EQUAL(arr1.GetSize(), 4u);
				BOOST_CHECK_EQUAL(arr1.GetCapacity(), 8u);
			}
			BOOST_AUTO_TEST_CASE(when_new_size_larger_then_current_size)
			{
				arr1.Resize(1);
				BOOST_CHECK_EQUAL(arr1.GetSize(), 1u);
				BOOST_CHECK_EQUAL(arr1.GetCapacity(), 4u);

				arr1.Resize(4);
				BOOST_CHECK_EQUAL(arr1.GetSize(), 4u);
				BOOST_CHECK_EQUAL(arr1.GetCapacity(), 8u);
			}
			BOOST_AUTO_TEST_CASE(when_add_new_elements)
			{
				arr1.Append(2);
				arr1.Append(3);
				arr1.Append(5);
				arr1.Append(6);
				BOOST_CHECK_EQUAL(arr1.GetSize(), 8u);
				BOOST_CHECK_EQUAL(arr1.GetCapacity(), 8u);
			}
			BOOST_AUTO_TEST_CASE(when_new_size_larger_then_current_capacity)
			{
				arr1.Resize(15);
				BOOST_CHECK_EQUAL(arr1.GetSize(), 15u);
				BOOST_CHECK_EQUAL(arr1.GetCapacity(), 30u);
				BOOST_CHECK_EQUAL(arr1[8], 0);
				BOOST_CHECK_EQUAL(arr1[9], 0);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_CASE(can_get_element_by_index)
		{
			arr.Append(1);
			arr.Append(4);
			arr.Append(7);
			BOOST_CHECK_EQUAL(arr.GetSize(), 3u);
			BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
			BOOST_CHECK_EQUAL(arr[0], 1);
			BOOST_CHECK_THROW(arr[3], std::out_of_range);
		}
	/*	BOOST_AUTO_TEST_CASE(iterators_should_be_dereferenceable)
		{
			CMyArray<int> x;
			x.Append(42);
			*x.begin() = 43;
			//BOOST_CHECK_EQUAL(x[0], 43);
		}*/

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(realize_operators)
	BOOST_AUTO_TEST_CASE(copy_assignment_operator)
	{
		CMyArray<int> arr2;
		arr = arr2;
		BOOST_CHECK_EQUAL(arr.GetSize(), 0u);
		BOOST_CHECK_EQUAL(arr.GetCapacity(), 0u);

		arr2.Append(1);
		arr = arr2;
		BOOST_CHECK_EQUAL(arr.GetSize(), 1u);
		BOOST_CHECK_EQUAL(arr.GetCapacity(), 1u);

		arr.Append(1);
		arr.Append(4);
		arr.Append(7);
		arr2.Append(4);
		arr = arr2;
		BOOST_CHECK_EQUAL(arr.GetSize(), 2u);
		BOOST_CHECK_EQUAL(arr.GetCapacity(), 2u);
	}

	BOOST_AUTO_TEST_CASE(copy_assignment_operator_must_be_able_to_assign_empty_array)
	{
		CMyArray<int> x;
		x.Append(1);
		x.Append(2);
		x.Append(3);
		CMyArray<int> y;
		x = y;
		BOOST_CHECK_EQUAL(x.GetSize(), 0u);
		BOOST_CHECK_EQUAL(x.GetCapacity(), 0u);
	}

	BOOST_AUTO_TEST_CASE(assigment_operator)
	{
		CMyArray<int> arr2 = { 1, 2, 3, 4 };
		arr = std::move(arr2);

		BOOST_CHECK_EQUAL(arr.GetSize(), 4u);
		BOOST_CHECK_EQUAL(arr.GetCapacity(), 4u);
		BOOST_CHECK_EQUAL(arr2.GetSize(), 0u);
		BOOST_CHECK_EQUAL(arr2.GetCapacity(), 0u);
	}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(has_iterators)
		BOOST_AUTO_TEST_CASE(begin_and_end)
		{
			arr.Append(0);
			arr.Append(1);
			arr.Append(2);

			int count = 0;
			for (auto p = arr.begin(); p != arr.end(); p++, count++)
			{
				BOOST_CHECK(*p == count);
			}
		}

		BOOST_AUTO_TEST_CASE(cbegin_and_cend)
		{
			arr.Append(0);
			arr.Append(1);
			arr.Append(2);

			int count = 0;
			for (auto p = arr.cbegin(); p != arr.cend(); p++, count++)
			{
				BOOST_CHECK(*p == count);
			}
		}

		BOOST_AUTO_TEST_CASE(rbegin_and_rend)
		{
			arr.Append(0);
			arr.Append(1);
			arr.Append(2);

			int count = 2;
			for (auto p = arr.rbegin(); p != arr.rend(); p++, count--)
			{
				BOOST_CHECK(*p == count);
			}
		}

	/*	BOOST_AUTO_TEST_CASE(can_sum_iterator_and_number)
		{
			arr.Append(0);
			arr.Append(1);
			arr.Append(2);
		//	BOOST_CHECK_EQUAL(arr.begin() + 1, 1);
			
		}*/

	BOOST_AUTO_TEST_SUITE_END()
BOOST_AUTO_TEST_SUITE_END()