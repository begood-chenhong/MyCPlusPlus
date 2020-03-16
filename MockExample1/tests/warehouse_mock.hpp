/*
 * warehouse_mock.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: echnhog
 */

#ifndef MOCKEXAMPLE1_TESTS_WAREHOUSE_MOCK_HPP_
#define MOCKEXAMPLE1_TESTS_WAREHOUSE_MOCK_HPP_


#include "../../MockExample1/lib/warehouse.hpp"
#include "gmock/gmock.h"


/** \brief Mock for the warehouse interface.
 * \author David Stutz
 */
class MockWarehouse : public Warehouse
{
public:

    // see https://github.com/google/googletest/blob/master/googlemock/docs/ForDummies.md
    /*
     * Step01: describe interface by using gmock MACRO (only define input and output data type. Doesn't defien value).
     * you use some simple macros to describe the interface you want to mock, and they will expand to the implementation of your mock class;
     *
     */
	MOCK_CONST_METHOD2(hasInventory, bool(int, std::string));
    MOCK_METHOD2(remove, void(int, std::string));
};


#endif /* MOCKEXAMPLE1_TESTS_WAREHOUSE_MOCK_HPP_ */
