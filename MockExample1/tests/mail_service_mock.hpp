/*
 * main_service_mock.hpp
 *
 *  Created on: Mar 9, 2020
 *      Author: echnhog
 */

#ifndef MOCKEXAMPLE1_TESTS_MAIL_SERVICE_MOCK_HPP_
#define MOCKEXAMPLE1_TESTS_MAIL_SERVICE_MOCK_HPP_

#include "../../MockExample1/lib/mail_service.hpp"
#include "gmock/gmock.h"


/** \brief Mock for the mail service interface.
 * \author David Stutz
 */
class MockMailService : public MailService
{
public:
    MockMailService()
    {

    }

    MOCK_METHOD1(send, void(std::string));
};

#endif /* MOCKEXAMPLE1_TESTS_MAIL_SERVICE_MOCK_HPP_ */
