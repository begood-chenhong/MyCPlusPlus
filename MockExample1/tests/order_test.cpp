#include "../../MockExample1/lib/order.hpp"          /*product code under test*/

#include "../../MockExample1/tests/mail_service_mock.hpp"  /*mock used for test*/
#include "../../MockExample1/tests/warehouse_mock.hpp"     /*mock used for test*/
#include "../../MockExample1/tests/mail_service_mock.hpp"  /*mock used for test*/
#include "gmock/gmock.h"
#include "gtest/gtest.h"



using ::testing::Return;
using ::testing::_; // Matcher for parameters
using ::testing::InSequence;

TEST(OrderTest, Fill)
{
	// Testing Scenario1:
	/*
	 * Step02.1: create some mock objects;
	 */
    MockWarehouse warehouse;
    std::shared_ptr<MockMailService> mailService = std::make_shared<MockMailService>();
    
    /*
     * Step02.2: create object Under Test;
     */
    Order order(50, "Talisker");
    order.setMailService(mailService);
    
    /*
     * Step02.3: specify the whole testing scenario by specifying its expectations and behavior using an intuitive syntax:
     * which mock object;
     * which methods will be called? in which order? how many times?
     * with what arguments?
     * what will they return? etc
     */
    // Define outputValue MockObject(method, method's input parameters). This example is worth reading carefully and understanding well.
    /* In fact, these below 3 EXPECT_CALL has one to one relationship (100% percent match with the call flow) in/with the Order::fill() calling.
     * bool Order::fill(Warehouse &warehouse)
		{
			if (warehouse.hasInventory(this->quantity, this->product))
			{
				// ...
				warehouse.remove(this->quantity, this->product);
				this->mailService->send("Order filled.");

				return true;
			}
			else
			{
				// ...
				this->mailService->send("Order not filled.");

				return false;
			}
		}
     */
    /*
     * gMock requires expectations to be set before the mock functions are called, otherwise the behavior is undefined.
     * This means EXPECT_CALL() should be read as expecting that a call will occur in the future, not that a call has occurred.
     * Why does gMock work like that? Well, specifying the expectation beforehand allows gMock to report a violation as soon as it rises,
     * when the context (stack trace, etc) is still available. This makes debugging much easier.
     */
    {
		InSequence seq;
		EXPECT_CALL(warehouse, hasInventory(50, "Talisker")) // Define input parameter's values
			.Times(1)                                        // Define what method be called.
			.WillOnce(Return(true));                         // Define what value will be returned.

		EXPECT_CALL(warehouse, remove(50, "Talisker"))
			.Times(1);

		EXPECT_CALL(*mailService, send(_)) // Not making assumptions on the message send ...
			.Times(1);
    }
    /*
     * Step03: trigger the whole testing scenario (then you exercise code that uses the mock objects). gMock will catch any violation to the expectations as soon as it arises.
     */
    ASSERT_TRUE(order.fill(warehouse)); // When I write gmock testing program, I can check this call, identify the code sequence that I want to check, then write the above EXPECT_CALL sentences.


    // Testing Scenario2:
    // Report the same testing procedure as above, but use different initial parameters and scenario.
	/*
	 * Step02.1: create some mock objects;
	 */
    MockWarehouse warehouse2;
    std::shared_ptr<MockMailService> mailService2 = std::make_shared<MockMailService>();

    /*
     * Step02.2: create object Under Test;
     */
    Order order2(100, "Talisker");
    order2.setMailService(mailService2);

    /*
     * Step02.3: specify the whole testing scenario by specifying its expectations and behavior using an intuitive syntax:
     * which mock object;
     * which methods will be called? in which order? how many times?
     * with what arguments?
     * what will they return? etc
     */
    EXPECT_CALL(warehouse2, hasInventory(100, "Talisker"))
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_CALL(*mailService2, send(_)) // Not making assumptions on the message send ...
        .Times(1);

    /*
     * Step03: trigger the whole testing scenario (then you exercise code that uses the mock objects). gMock will catch any violation to the expectations as soon as it arises.
     */
    ASSERT_FALSE(order2.fill(warehouse2));
}

/** \brief Main test entrance point. 
 * \param[in] argc
 * \param[in] argv
 */
int main(int argc, char** argv) {
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}

