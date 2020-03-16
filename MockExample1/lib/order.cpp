/*
 * order.cpp
 *
 *  Created on: Mar 8, 2020
 *      Author: echnhog
 */

#include "../../MockExample1/lib/order.hpp"

/** \brief Constructor.
 * \param[in] quantity quantity requested
 * \param[in] product product name requested
 */
Order::Order(int quantity, std::string product)
{
	this->quantity = quantity;
	this->product = product;
}

/** \brief Set the mail service to use.
 * \param[in] mailService the mail service to attach
 */
void Order::setMailService(std::shared_ptr<MailService> mailService)
{
	this->mailService = mailService;
}

/** \brief Fill the order given the warehouse.
 * \param[in] warehouse the warehouse to use
 * \return whether the operation was successful
 */
/*
bool Order::fill(Warehouse &warehouse)
{
	if (warehouse.hasInventory(quantity, product))
	{
		// ...
		warehouse.remove(quantity, product);
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
bool Order::fill(Warehouse &warehouse)
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


